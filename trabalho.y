%{
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int yylex();
void yyerror( const char* st );
void erro( string msg );

// Faz o mapeamento dos tipos dos operadores
map< string, string > tipo_opr;

// Pilha de variáveis temporárias para cada bloco
vector< string > var_temp;

#define MAX_DIM 2 

struct Tipo {
  string tipo_base;
  int ndim;
  int inicio[MAX_DIM];
  int fim[MAX_DIM];
  
  Tipo() {} // Construtor Vazio
  
  Tipo( string tipo ) {
    tipo_base = tipo;
    ndim = 0;
  }
  
  Tipo( string base, int inicio, int fim  ) {
    tipo_base = base;
    ndim = 1;
    this->inicio[0] = inicio;
    this->fim[0] = fim;
  }
  
  Tipo( string base, int inicio_1, int fim_1, int inicio_2, int fim_2  ) {
    tipo_base = base;
    ndim = 2;
    this->inicio[0] = inicio_1;
    this->fim[0] = fim_1;
    this->inicio[1] = inicio_2;
    this->fim[1] = fim_2;
  }
};

struct Atributos {
  string v, c; // Valor, tipo e código gerado.
  Tipo t;
  vector<string> lista; // Uma lista auxiliar.
  
  Atributos() {} // Constutor vazio
  Atributos( string valor ) {
    v = valor;
  }

  Atributos( string valor, Tipo tipo ) {
    v = valor;
    t = tipo;
  }
};

// Declarar todas as funções que serão usadas.
void insere_ts( string nome_var, Tipo tipo );
Tipo consulta_ts( string nome_var );

string gera_nome_var_temp( string tipo );
string gera_label( string tipo );
string gera_teste_limite_array( Tipo tipoArray, string indice_1, string indice_2 = "");

void debug( string producao, Atributos atr );
int toInt( string valor );
string toString( int n );

Atributos gera_codigo_operador( Atributos s1, string opr, Atributos s3 );
Atributos gera_codigo_if( Atributos expr, string cmd_then, string cmd_else );

string traduz_nome_tipo_variavel( string tipo_pascal );
string declara_variavel( string nome, Tipo tipo );

string includes = 
"#include <iostream>\n"
"#include <stdio.h>\n"
"#include <stdlib.h>\n"
"#include <string.h>\n"
"\n"
"using namespace std;\n";


#define YYSTYPE Atributos

%}
// Program
%token TK_PROGRAM
// Inicio e fim de bloco
%token TK_BEGIN TK_END TK_MBEGIN TK_MEND
// Atribuicoes
%token TK_ATRIB
// Condicoes
%token TK_IF TK_ELSE
// Comparacoes
%token TK_MAIG TK_MEIG TK_DIF TK_EQUAL TK_AND TK_OR
// Loops
%token TK_FOR TK_WHILE TK_DOWHILE TK_SWITCH
// X .. Y => X ate Y
%token TK_PTPT
// Tokens para tipar a variavel
%token TK_INT TK_CHAR TK_BOOL TK_DOUBLE TK_STRING
// Tokens candidatos a ser nome de variavel
%token TK_TEXTO TK_ID TK_INTEIRO TK_REAL
// Print
%token TK_WRITELN TK_WRITE

%left TK_AND
%nonassoc '<' '>' TK_MAIG TK_MEIG '=' TK_DIF 
%left '+' '-'
%left '*' '/'

%%

S : PROGRAM VARS MAIN 
    {
      cout << includes << endl;
      cout << $2.c << endl;
      cout << $3.c << endl;
    }
  ;
  
PROGRAM : TK_PROGRAM TK_ID ';' 
          { $$.c = ""; }
        ; 
     
VARS : VAR ';' VARS
       { $$.c = $1.c + $3.c; }
     | 
       { $$.c = ""; }
     ;     
     
VAR : TIPO IDS
      {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( $1.v ) ); 
        
        $$ = Atributos();
        
        for( int i = 0; i < $2.lista.size(); i++ ) {
          $$.c += declara_variavel( $2.lista[i], tipo );
          insere_ts( $2.lista[i], tipo );
        }
      }
    | TIPO IDS '[' TK_INTEIRO TK_PTPT TK_INTEIRO ']' 
      {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( $1.v ), 
                          toInt( $4.v ), toInt( $6.v ) );
        
        $$ = Atributos();
        
        for( int i = 0; i < $2.lista.size(); i++ ) {
          $$.c += declara_variavel( $2.lista[i], tipo );
          insere_ts( $2.lista[i], tipo );
        }
      }
    |  TIPO IDS '[' TK_INTEIRO TK_PTPT TK_INTEIRO ']' '[' TK_INTEIRO TK_PTPT TK_INTEIRO ']'
      {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( $1.v ), 
                          toInt( $4.v ), toInt( $6.v ),
			  toInt( $9.v ), toInt( $11.v ) );
        
        $$ = Atributos();
        
        for( int i = 0; i < $2.lista.size(); i++ ) {
          $$.c += declara_variavel( $2.lista[i], tipo );
          insere_ts( $2.lista[i], tipo );
        }
      }
    ;

TIPO : TK_DOUBLE
     | TK_INT
     | TK_BOOL
     | TK_CHAR
     | TK_STRING
     ;
    
IDS : IDS ',' TK_ID 
      { $$  = $1;
        $$.lista.push_back( $3.v ); }
    | TK_ID 
      { $$ = Atributos();
        $$.lista.push_back( $1.v ); }
    ;          

MAIN :  TK_MBEGIN BLOCO TK_MEND
       { $$.c = "int main()\n" + $2.c; } 
     ;
     
BLOCO : TK_BEGIN { var_temp.push_back( "" );} CMDS TK_END
        { string vars = var_temp[var_temp.size()-1];
          var_temp.pop_back();
          $$.c = "{\n" + vars + $3.c + "}\n"; }
      ;  
      
CMDS : CMD ';' CMDS
       { $$.c = $1.c + $3.c; }
     | LOOP CMDS
       { $$.c = $1.c + $2.c; }
     | { $$.c = ""; }
     ;  
     
CMD : WRITE
    | WRITELN
    | ATRIB
    | BLOCO
    | VARS
    ;

LOOP : CMD_IF
     | CMD_FOR
	 ;

CMD_FOR : TK_FOR NOME_VAR TK_ATRIB E TK_PTPT E TK_BEGIN CMDS TK_END
          { 
            string var_fim = gera_nome_var_temp( $2.t.tipo_base );
            string label_teste = gera_label( "teste_for" );
            string label_fim = gera_label( "fim_for" );
            string condicao = gera_nome_var_temp( "b" );
          
            // Falta verificar os tipos... perde ponto se não o fizer.
            $$.c =  $4.c + $6.c +
                    "  " + $2.v + " = " + $4.v + ";\n" +
                    "  " + var_fim + " = " + $6.v + ";\n" +
                    label_teste + ":;\n" +
                    "  " +condicao+" = "+$2.v + " > " + var_fim + ";\n" + 
                    "  " + "if( " + condicao + " ) goto " + label_fim + 
                    ";\n" +
                    $8.c +
                    "  " + $2.v + " = " + $2.v + " + 1;\n" +
                    "  goto " + label_teste + ";\n" +
                    label_fim + ":;\n";  
          }
        ;
    
CMD_IF : TK_IF E TK_BEGIN CMDS TK_END
         { $$ = gera_codigo_if( $2, $4.c, "" ); }  
       | TK_IF E TK_BEGIN CMDS TK_END TK_ELSE TK_BEGIN CMDS TK_END 
         { $$ = gera_codigo_if( $2, $4.c, $8.c ); }  
       ;

WRITELN : TK_WRITELN '(' E ')' 
          { $$.c = $3.c + 
                   "  cout << " + $3.v + ";\n"
                   "  cout << endl;\n";
          }
        ;

WRITE : TK_WRITE '(' E ')' 
          { $$.c = $3.c + 
                   "  cout << " + $3.v + ";\n";
          }
        ;
  
ATRIB : TK_ID TK_ATRIB E 
        { // Falta verificar se pode atribuir (perde ponto se não fizer).
          $1.t = consulta_ts( $1.v ) ;
          
          if( $1.t.tipo_base == "s" ) 
            $$.c = $3.c + "  strncpy( " + $1.v + ", " + $3.v + ", 256 );\n";
          else
            $$.c = $3.c + "  " + $1.v + " = " + $3.v + ";\n";             

        } 
      | TK_ID '[' E ']' TK_ATRIB E
        { // Falta testar: tipo, limite do array, e se a variável existe
          $1.t = consulta_ts( $1.v ) ;
          if( $1.t.tipo_base != $6.t.tipo_base ) {
             erro( "Atribuicao entre tipos diferentes" );
		  }
          $$.c = $3.c + $6.c +
                 gera_teste_limite_array( $1.t, $3.v ) +   
                 "  " + $1.v + "[" + $3.v + "] = " + $6.v + ";\n";
        }
      | TK_ID '[' E ']' '[' E ']' TK_ATRIB E
        { // Falta testar: tipo, limite do array, e se a variável existe
          $1.t = consulta_ts( $1.v ) ;
          string aux = gera_nome_var_temp( $3.t.tipo_base );
		  string tam = toString($1.t.fim[1] - $1.t.inicio[1] + 1);
          $$.c = $3.c + $6.c + $9.c +
                 gera_teste_limite_array( $1.t, $3.v, $6.v ) +   
				 "  " + aux  + " = " + tam  + "*" + $3.v + ";\n" +
				 "  " + aux  + " = " + aux  + "+" + $6.v + ";\n" +
                 "  " + $1.v + "[" + aux + "] = " + $9.v + ";\n";
        }  
      ;   

E : E '+' E
    { $$ = gera_codigo_operador( $1, "+", $3 ); }
  | E '-' E 
    { $$ = gera_codigo_operador( $1, "-", $3 ); }
  | E '*' E
    { $$ = gera_codigo_operador( $1, "*", $3 ); }
  | E '/' E
    { $$ = gera_codigo_operador( $1, "/", $3 ); }
  | E '<' E
    { $$ = gera_codigo_operador( $1, "<", $3 ); }
  | E '>' E
    { $$ = gera_codigo_operador( $1, ">", $3 ); }
  | E TK_MEIG E
    { $$ = gera_codigo_operador( $1, "<=", $3 ); }
  | E TK_MAIG E
    { $$ = gera_codigo_operador( $1, ">=", $3 ); }
  | E TK_EQUAL E
    { $$ = gera_codigo_operador( $1, "==", $3 ); }
  | E TK_DIF E
    { $$ = gera_codigo_operador( $1, "!=", $3 ); }
  | E TK_AND E
    { $$ = gera_codigo_operador( $1, "&&", $3 ); }
  | E TK_OR E
    { $$ = gera_codigo_operador( $1, "||", $3 ); }
  | '(' E ')'
    { $$ = $2; }
  | F
  ;
  
F : NOME_VAR 
  | TK_INTEIRO 
    { $$.v = $1.v; $$.t = Tipo( "i" ); $$.c = $1.c; }
  | TK_REAL
    { $$.v = $1.v; $$.t = Tipo( "d" ); $$.c = $1.c; }
  | TK_TEXTO
    { $$.v = $1.v; $$.t = Tipo( "s" ); $$.c = $1.c; }
  ;
  
  
NOME_VAR : TK_ID 
             { $$.v = $1.v; $$.t = consulta_ts( $1.v ); $$.c = $1.c; }
         | TK_ID '[' E ']'  
         { 
           Tipo tipoArray = consulta_ts( $1.v );
           $$.t = Tipo( tipoArray.tipo_base );
           if( tipoArray.ndim != 1 )
             erro( "Variável " + $1.v + " não é array de uma dimensão" );
        
           if( $3.t.ndim != 0 || $3.t.tipo_base != "i" )
             erro( "Indice de array deve ser integer de zero dimensão: " +
               $3.t.tipo_base + "/" + toString( $3.t.ndim ) );
        
           $$.v = gera_nome_var_temp( $$.t.tipo_base );
           $$.c = $3.c +
           gera_teste_limite_array( tipoArray, $3.v ) +   
             "  " + $$.v + " = " + $1.v + "[" + $3.v + "];\n";
          }
          | TK_ID '[' E ']' '[' E ']'
          { 
            Tipo tipoArray = consulta_ts( $1.v );
            $$.t = Tipo( tipoArray.tipo_base );
            if( tipoArray.ndim != 2 )
              erro( "Variável " + $1.v + " não é array de duas dimensões" );
        
            if( $3.t.ndim != 0 || $3.t.tipo_base != "i" || $6.t.tipo_base != "i" )
              erro( "Indice de array deve ser integer de zero dimensão: " +
                $3.t.tipo_base + "/" + toString( $3.t.ndim ) );

            string aux = gera_nome_var_temp( $6.t.tipo_base );
		    string tam = toString(tipoArray.fim[1]-tipoArray.inicio[1]+1);
            $$.v = gera_nome_var_temp( $$.t.tipo_base );
            $$.c = $3.c +
              gera_teste_limite_array( tipoArray, $3.v, $6.v ) +   
              "  " + aux  + " = " + tam + " * " + $3.v + ";\n" +
              "  " + aux  + " = " + aux + " + " + $6.v + ";\n" +
              "  " + $$.v + " = " + $1.v + "[" + aux + "];\n";
    }
    // Implementar: vai criar uma temporaria int para o índice e 
    // outra do tipoBase do array para o valor recuperado.  
    ; 
  
%%
int nlinha = 1;

#include "lex.yy.c"

int yyparse();

void debug( string producao, Atributos atr ) {
/*
  cerr << "Debug: " << producao << endl;
  cerr << "  t: " << atr.t << endl;
  cerr << "  v: " << atr.v << endl;
  cerr << "  c: " << atr.c << endl;
*/ 
}

void yyerror( const char* st )
{
  printf( "%s", st );
  printf( "Linha: %d, \"%s\"\n", nlinha, yytext );
}

void erro( string msg ) {
  cerr << "Erro: " << msg << endl; 
  fprintf( stderr, "Linha: %d, [%s]\n", nlinha, yytext );
  exit(1);
}

void inicializa_operadores() {
  // Resultados para o operador "+"
  tipo_opr["i+i"] = "i";
  tipo_opr["i+d"] = "d";
  tipo_opr["d+i"] = "d";
  tipo_opr["d+d"] = "d";
  tipo_opr["s+s"] = "s";
  tipo_opr["c+s"] = "s";
  tipo_opr["s+c"] = "s";
  tipo_opr["c+c"] = "s";
 
  // Resultados para o operador "-"
  tipo_opr["i-i"] = "i";
  tipo_opr["i-d"] = "d";
  tipo_opr["d-i"] = "d";
  tipo_opr["d-d"] = "d";
  
  // Resultados para o operador "*"
  tipo_opr["i*i"] = "i";
  tipo_opr["i*d"] = "d";
  tipo_opr["d*i"] = "d";
  tipo_opr["d*d"] = "d";
  
  // Resultados para o operador "/"
  tipo_opr["i/i"] = "d";
  tipo_opr["i/d"] = "d";
  tipo_opr["d/i"] = "d";
  tipo_opr["d/d"] = "d";
  
  // Resultados para o operador "<"
  tipo_opr["i<i"] = "b";
  tipo_opr["i<d"] = "b";
  tipo_opr["d<i"] = "b";
  tipo_opr["d<d"] = "b";
  tipo_opr["c<c"] = "b";
  tipo_opr["i<c"] = "b";
  tipo_opr["c<i"] = "b";
  // Resultados para o operador "<="
  tipo_opr["i<=i"] = "b";
  tipo_opr["i<=d"] = "b";
  tipo_opr["d<=i"] = "b";
  tipo_opr["d<=d"] = "b";
  tipo_opr["c<=c"] = "b";
  tipo_opr["i<=c"] = "b";
  tipo_opr["c<=i"] = "b";
//  tipo_opr["c<s"] = "b";
//  tipo_opr["s<c"] = "b";
//  tipo_opr["s<s"] = "b";

  // Resultados para o operador ">"
  tipo_opr["i>i"] = "b";
  tipo_opr["i>d"] = "b";
  tipo_opr["d>i"] = "b";
  tipo_opr["d>d"] = "b";
  tipo_opr["c>c"] = "b";
  tipo_opr["i>c"] = "b";
  tipo_opr["c>i"] = "b";
  // Resultados para o operador ">="
  tipo_opr["i>=i"] = "b";
  tipo_opr["i>=d"] = "b";
  tipo_opr["d>=i"] = "b";
  tipo_opr["d>=d"] = "b";
  tipo_opr["c>=c"] = "b";
  tipo_opr["i>=c"] = "b";
  tipo_opr["c>=i"] = "b";

  // Resultados para o operador "And"
  tipo_opr["b&&b"] = "b";
  
  // Resultados para o operador "Equal"
  tipo_opr["i==i"] = "b";
  tipo_opr["i==d"] = "b";
  tipo_opr["d==i"] = "b";
  tipo_opr["d==d"] = "b";
  tipo_opr["s==s"] = "b";
  tipo_opr["c==c"] = "b";
  tipo_opr["b==b"] = "b";


  // Resultados para o operador "Dif"
  tipo_opr["i!=i"] = "b";
  tipo_opr["i!=d"] = "b";
  tipo_opr["d!=i"] = "b";
  tipo_opr["d!=d"] = "b";
  tipo_opr["s!=s"] = "b";
  tipo_opr["c!=c"] = "b";
  tipo_opr["b!=b"] = "b";
}

map< string, Tipo > ts;

Tipo consulta_ts( string nome_var ) {
  if( ts.find( nome_var ) == ts.end() )
    erro( "Variável não declarada: " + nome_var );
  
  return ts[ nome_var ];
}

void insere_ts( string nome_var, Tipo tipo ) {
  if( ts.find( nome_var ) != ts.end() )
    erro( "Variável já declarada: " + nome_var + 
          " (" + ts[ nome_var ].tipo_base + ")" );
    
  ts[ nome_var ] = tipo;
}

string toString( int n ) {
  char buff[100];
  
  sprintf( buff, "%d", n ); 
  
  return buff;
}

int toInt( string valor ) {
  int aux = -1;
  
  if( sscanf( valor.c_str(), "%d", &aux ) != 1 )
    erro( "Numero inválido: " + valor );
  
  return aux;
}
string gera_nome_var_temp( string tipo ) {
  static int n = 0;
  string nome = "t" + tipo + "_" + toString( ++n );
  
  var_temp[var_temp.size()-1] += declara_variavel( nome, Tipo( tipo ) );
  
  return nome;
}

string gera_label( string tipo ) {
  static int n = 0;
  string nome = "l_" + tipo + "_" + toString( ++n );
  
  return nome;
}

Tipo tipo_resultado( Tipo t1, string opr, Tipo t3 ) {
  if( t1.ndim == 0 && t3.ndim == 0 ) {
    string aux = tipo_opr[ t1.tipo_base + opr + t3.tipo_base ];
  
    if( aux == "" ) 
      erro( "O operador " + opr + " não está definido para os tipos '" +
            t1.tipo_base + "' e '" + t3.tipo_base + "'.");
  
    return Tipo( aux );
  }
  else { // Testes para os operadores de comparacao de array
    return Tipo();
  }  
} 

Atributos gera_codigo_operador( Atributos s1, string opr, Atributos s3 ) {
  Atributos ss;
  
  ss.t = tipo_resultado( s1.t, opr, s3.t );
  ss.v = gera_nome_var_temp( ss.t.tipo_base );
  
  if( s1.t.tipo_base == "s" && s3.t.tipo_base == "s" ) 
    // falta testar se é o operador "+"
    ss.c = s1.c + s3.c + // Codigo das expressões dos filhos da arvore.
           "  strncpy( " + ss.v + ", " + s1.v + ", 256 );\n" +
           "  strncat( " + ss.v + ", " + s3.v + ", 256 );\n";
  else if( s1.t.tipo_base == "s" && s3.t.tipo_base == "c" ) 
    ;
  else if( s1.t.tipo_base == "c" && s3.t.tipo_base == "s" ) 
    ;
  else
    ss.c = s1.c + s3.c + // Codigo das expressões dos filhos da arvore.
           "  " + ss.v + " = " + s1.v + " " + opr + " " + s3.v + ";\n"; 
  
  debug( "E: E " + opr + " E", ss );
  return ss;
}

Atributos gera_codigo_if( Atributos expr, string cmd_then, string cmd_else ) {
  Atributos ss;
  string label_else = gera_label( "else" );
  string label_end = gera_label( "end" );
  
  ss.c = expr.c + 
         "  " + expr.v + " = !" + expr.v + ";\n\n" +
         "  if( " + expr.v + " ) goto " + label_else + ";\n" +
         cmd_then +
         "  goto " + label_end + ";\n" +
         label_else + ":;\n" +
         cmd_else +
         label_end + ":;\n";
         
  return ss;       
}


string traduz_nome_tipo_variavel( string tipo_pascal ) {
  // No caso do Pascal, a comparacao deveria ser case-insensitive
  
  if( tipo_pascal == "intinho" )
    return "i";
  else if( tipo_pascal == "boolzinho" )
    return "b";
  else if( tipo_pascal == "dbzinho" )
    return "d";  
  else if( tipo_pascal == "charzinho" )
    return "c";  
  else if( tipo_pascal == "txtzinho" )
    return "s";  
  else 
    erro( "Tipo inválido: " + tipo_pascal );
}

map<string, string> inicializaMapEmC() {
  map<string, string> aux;
  aux["i"] = "int ";
  aux["b"] = "int ";
  aux["d"] = "double ";
  aux["c"] = "char ";
  aux["s"] = "char ";
  return aux;
}

string declara_variavel( string nome, Tipo tipo ) {
  static map<string, string> em_C = inicializaMapEmC();
  
  if( em_C[ tipo.tipo_base ] == "" ) 
    erro( "Tipo inválido: " + tipo.tipo_base );
    
  string indice;
   
  switch( tipo.ndim ) {
    case 0: indice = (tipo.tipo_base == "s" ? "[256]" : "");
            break;
              
    case 1: indice = "[" + toString( 
                  (tipo.fim[0]-tipo.inicio[0]+1) *  
                  (tipo.tipo_base == "s" ? 256 : 1)
                ) + "]";
            break; 
            
    case 2: indice = "[" + toString( 
                  (tipo.fim[0]-tipo.inicio[0]+1) *
                  (tipo.fim[1]-tipo.inicio[1]+1) *
                  (tipo.tipo_base == "s" ? 256 : 1)
                ) + "]";
            break;
    
    default:
       erro( "Bug muito sério..." );
  } 
  
  return em_C[ tipo.tipo_base ] + nome + indice + ";\n";
}

string gera_teste_limite_array( Tipo tipoArray, string indice_1, string indice_2 ) {
  string var_teste_inicio1 = gera_nome_var_temp( "b" );
  string var_teste_fim1 = gera_nome_var_temp( "b" );
  string var_teste_inicio2 = gera_nome_var_temp( "b" );
  string var_teste_fim2 = gera_nome_var_temp( "b" );
  string var_teste1 = gera_nome_var_temp( "b" );
  string var_teste2 = gera_nome_var_temp( "b" );
  string label_end = gera_label( "limite_array_ok" );
  
  string codigo = "";
  
  if( tipoArray.ndim == 1 ) {
  	  codigo = "  " + var_teste_inicio1 + " = " + indice_1 + " >= " +
                  toString( tipoArray.inicio[0] ) + ";\n" +

                  "  " + var_teste_fim1 + " = " + indice_1 + " <= " +
                  toString( tipoArray.fim[0] ) + ";\n" +

                  "  " + var_teste1 + " = " + var_teste_inicio1 + " && " + 
                                             var_teste_fim1 + ";\n";
      codigo += "  if( " + var_teste1 + " ) goto " + label_end + ";\n" +
          "    printf( \"Limite de array ultrapassado: %d <= %d <= %d\", "+
               toString( tipoArray.inicio[0] ) + " ," + indice_1 + ", " +
               toString( tipoArray.fim[0] ) + " );\n" +
               "  cout << endl;\n" + 
               "  exit( 1 );\n" + 
               "  " + label_end + ":;\n";

  }else if( tipoArray.ndim == 2) {
      codigo = "  " + var_teste_inicio1 + " = " + indice_1 + " >= " +
                  toString( tipoArray.inicio[0] ) + ";\n" +

                  "  " + var_teste_fim1 + " = " + indice_1 + " <= " +
                  toString( tipoArray.fim[0] ) + ";\n" +

	              "  " + var_teste_inicio2 + " = " + indice_2 + " >= " +
                  toString( tipoArray.inicio[1] ) + ";\n" +

                  "  " + var_teste_fim2 + " = " + indice_2 + " <= " +
                  toString( tipoArray.fim[1] ) + ";\n" +

                  "  " + var_teste1 + " = " + var_teste_inicio1 + " && " + 
                                             var_teste_fim1 + ";\n" +

                  "  " + var_teste2 + " = " + var_teste_inicio2 + " && " + 
                                             var_teste_fim2 + ";\n";

      codigo += "  if( " + var_teste1 + "&&" + var_teste2 + " ) goto " + label_end + ";\n" +
                "  printf( \"Limite de array ultrapassado: linha(%d <= %d <= %d)\", "+
                toString( tipoArray.inicio[0] ) + " ," + indice_1 + ", " +
                toString( tipoArray.fim[0] ) + " );\n" +
                "  printf( \" e coluna(%d <= %d <= %d)\", "+
                toString( tipoArray.inicio[1] ) + " ," + indice_2 + ", " +
                toString( tipoArray.fim[1] ) + " );\n" +
                "  cout << endl;\n" +
                "  exit( 1 );\n" + 
                "  " + label_end + ":;\n";
  }
  
  return codigo;
}

int main( int argc, char* argv[] )
{
  inicializa_operadores();
  yyparse();
}
