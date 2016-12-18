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

enum TIPO { FUNCAO = -1, BASICO = 0, VETOR = 1, MATRIZ = 2 };

struct Tipo {
  string tipo_base;
  TIPO ndim;
  int inicio[MAX_DIM];
  int fim[MAX_DIM];
  vector<Tipo> retorno; // usando vector por dois motivos:
  // 1) Para não usar ponteiros
  // 2) Para ser genérico. Algumas linguagens permitem mais de um valor
  //    de retorno.
  vector<Tipo> params;
  
  Tipo() {} // Construtor Vazio
  
  Tipo( string tipo ) {
    tipo_base = tipo;
    ndim = BASICO;
  }
  
  Tipo( string base, int inicio, int fim  ) {
    tipo_base = base;
    ndim = VETOR;
    this->inicio[0] = inicio;
    this->fim[0] = fim;
  }
  
  Tipo( string base, int inicio_1, int fim_1, int inicio_2, int fim_2  ) {
    tipo_base = base;
    ndim = MATRIZ;
    this->inicio[0] = inicio_1;
    this->fim[0] = fim_1;
    this->inicio[1] = inicio_2;
    this->fim[1] = fim_2;
  }
  
  Tipo( Tipo retorno, const vector<Tipo> params ) {
    ndim = FUNCAO;
    this->retorno.push_back( retorno );
    this->params = params;
  } 
};

struct Atributos {
  string v, c; // Valor, tipo e código gerado.
  Tipo t;
  vector<string> lista_str; // Uma lista auxiliar de strings.
  vector<Tipo> lista_tipo; // Uma lista auxiliar de tipos.
  
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
void insere_var_ts( string nome_var, Tipo tipo );
void insere_funcao_ts( string nome_func, Tipo retorno, vector<Tipo> params );
Tipo consulta_var_ts( string nome_var );
Tipo consulta_funcao_ts( string nome_var );
string declara_var( string nome, Tipo tipo, bool ln=true );
string declara_funcao( string nome, Tipo retorno, vector<string> nomes, vector<Tipo> tipos );

void empilha_ts();
void desempilha_ts();

string gera_nome_var_temp( string tipo );
string gera_label( string tipo );
string gera_teste_limite_array( Tipo tipoArray, string indice_1, string indice_2 = "");

void debug( string producao, Atributos atr );
int toInt( string valor );
string toString( int n );

Atributos gera_codigo_operador( Atributos s1, string opr, Atributos s3 );
Atributos gera_codigo_if( Atributos expr, string cmd_then, string cmd_else );

string traduz_nome_tipo_variavel( string tipo_cute );
string traduz_nome_tipo_cute( string tipo_lex );

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
// Funcoes
%token TK_FUNCTION TK_RETURN
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

S : PROGRAM DECLS MAIN 
    {
      cout << includes << endl;
      cout << $2.c << endl;
      cout << $3.c << endl;
    }
  ;
  
PROGRAM : TK_PROGRAM TK_ID ';' 
          { $$.c = ""; 
            empilha_ts(); }
        ; 

DECLS : DECL DECLS
        { $$.c = $1.c + $2.c; }
      | 
        { $$.c = ""; }
      ;  

DECL : VARS
       { $$.c = $1.c; }
     | FUNCTION
       { $$.c = $1.c; }
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
        
        for( int i = 0; i < $2.lista_str.size(); i++ ) {
          $$.c += declara_var( $2.lista_str[i], tipo );
          insere_var_ts( $2.lista_str[i], tipo );
        }
      }
    | TIPO IDS '[' TK_INTEIRO TK_PTPT TK_INTEIRO ']' 
      {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( $1.v ), 
                          toInt( $4.v ), toInt( $6.v ) );
        
        $$ = Atributos();
        
        for( int i = 0; i < $2.lista_str.size(); i++ ) {
          $$.c += declara_var( $2.lista_str[i], tipo );
          insere_var_ts( $2.lista_str[i], tipo );
        }
      }
    |  TIPO IDS '[' TK_INTEIRO TK_PTPT TK_INTEIRO ']' '[' TK_INTEIRO TK_PTPT TK_INTEIRO ']'
      {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( $1.v ), 
                          toInt( $4.v ), toInt( $6.v ),
			  toInt( $9.v ), toInt( $11.v ) );
        
        $$ = Atributos();
        
        for( int i = 0; i < $2.lista_str.size(); i++ ) {
          $$.c += declara_var( $2.lista_str[i], tipo );
          insere_var_ts( $2.lista_str[i], tipo );
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
        $$.lista_str.push_back( $3.v ); }
    | TK_ID 
      { $$ = Atributos();
        $$.lista_str.push_back( $1.v ); }
    ;          

MAIN :  TK_MBEGIN BLOCO TK_MEND
       { $$.c = "int main() { \n" + $2.c + "}\n"; }
     ; 

FUNCTION : TK_FUNCTION { empilha_ts(); } CABECALHO CORPO { desempilha_ts(); }
           { $$.c = $3.c + " {\n" + $4.c + 
                    "  return Result;\n}\n"; } 
         ;

CORPO : TK_BEGIN { var_temp.push_back( "" );} CMDS RETURN TK_END
        { 
          string vars = var_temp[var_temp.size()-1];
          var_temp.pop_back();
          $$.c = "  " + declara_var( "Result", consulta_var_ts( "Result" ) );
          $$.c += vars + $3.c + $4.c; }
      ; 

CABECALHO : TIPO TK_ID OPC_PARAM
            {
              Tipo tipo = Tipo( traduz_nome_tipo_variavel( $1.v ) );
              $$.c = declara_funcao( $2.v, tipo, $3.lista_str, $3.lista_tipo );
            }
          ;

OPC_PARAM : '(' PARAMS ')'
            { $$ = $2; }
          |
            { $$ = Atributos(); }
          ;

PARAMS : PARAM ',' PARAMS 
         { $$.c = $1.c + $3.c; 
           // Concatenar as listas.
           $$.lista_tipo = $1.lista_tipo;
           $$.lista_tipo.insert( $$.lista_tipo.end(), 
                                 $3.lista_tipo.begin(),  
                                 $3.lista_tipo.end() ); 
           $$.lista_str = $1.lista_str;
           $$.lista_str.insert( $$.lista_str.end(), 
                                $3.lista_str.begin(),  
                                $3.lista_str.end() ); 
         }
       | PARAM
       ;  
         
PARAM : TIPO TK_ID 
      {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( $1.v ) );
        $$.lista_str.push_back($2.v);
        $$.lista_tipo.push_back( tipo );
      }
    ;
     
BLOCO : TK_BEGIN { var_temp.push_back( "" );} CMDS TK_END
        { string vars = var_temp[var_temp.size()-1];
          var_temp.pop_back();
          $$.c = vars + $3.c + $4.c; }
      ;

RETURN : TK_RETURN E ';'
         { $$.c = $2.c + "  Result = " + $2.v + ";\n"; }
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
    | VAR
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
          $1.t = consulta_var_ts( $1.v ) ;
          
          if( $1.t.tipo_base == "s" ) 
            $$.c = $3.c + "  strncpy( " + $1.v + ", " + $3.v + ", 256 );\n";
          else if( $1.t.tipo_base == $3.t.tipo_base )
            $$.c = $3.c + "  " + $1.v + " = " + $3.v + ";\n";             
          else
            erro( "Erro de atribuicao... tipos diferentes.\n"
	      "Variavel do tipo: "+ traduz_nome_tipo_cute($1.t.tipo_base) + ".\n"
	      "Valor do tipo: "+ traduz_nome_tipo_cute($3.t.tipo_base) + "." );

        } 
      | TK_ID '[' E ']' TK_ATRIB E
        { 
          $1.t = consulta_var_ts( $1.v ) ;
          if( $1.t.tipo_base != $6.t.tipo_base ) {
            erro( "Erro de atribuicao... tipos diferentes.\n"
	      "Variavel do tipo: "+ traduz_nome_tipo_cute($1.t.tipo_base) + ".\n"
	      "Valor do tipo: "+ traduz_nome_tipo_cute($6.t.tipo_base) + "." );
          }
          $$.c = $3.c + $6.c +
                 gera_teste_limite_array( $1.t, $3.v ) +   
                 "  " + $1.v + "[" + $3.v + "] = " + $6.v + ";\n";
        }
      | TK_ID '[' E ']' '[' E ']' TK_ATRIB E
        { 
          $1.t = consulta_var_ts( $1.v ) ;
          if( $1.t.tipo_base != $9.t.tipo_base ) {
            erro( "Erro de atribuicao... tipos diferentes.\n"
	      "Variavel do tipo: "+ traduz_nome_tipo_cute($1.t.tipo_base) + ".\n"
	      "Valor do tipo: "+ traduz_nome_tipo_cute($9.t.tipo_base) + "." );
          }
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
    { $$ = $1; }
  ;
  
F : NOME_VAR
  | TK_INTEIRO 
    { $$.v = $1.v; $$.t = Tipo( "i" ); $$.c = $1.c; }
  | TK_REAL
    { $$.v = $1.v; $$.t = Tipo( "d" ); $$.c = $1.c; }
  | TK_TEXTO
    { $$.v = $1.v; $$.t = Tipo( "s" ); $$.c = $1.c; }
  ;

EXPRS : EXPRS ',' E
        { $$ = Atributos();
          $$.c = $1.c + $3.c;
          $$.lista_str = $1.lista_str;
          $$.lista_tipo = $1.lista_tipo;
          $$.lista_str.push_back( $3.v );
          $$.lista_tipo.push_back( $3.t );  }
      | E 
        { $$ = Atributos();
          $$.c = $1.c;
          $$.lista_str.push_back( $1.v ); 
          $$.lista_tipo.push_back( $1.t ); }
      ;  
  
NOME_VAR : TK_ID 
             { $$.v = $1.v; $$.t = consulta_var_ts( $1.v ); $$.c = $1.c; }
         | TK_ID '[' E ']'  
         { 
           Tipo tipoArray = consulta_var_ts( $1.v );
           $$.t = tipoArray;
           if( tipoArray.ndim != VETOR )
             erro( "Variável " + $1.v + " não é array de uma dimensão" );
        
           if( $3.t.ndim != BASICO || $3.t.tipo_base != "i" )
             erro( "Indice de array deve ser integer de zero dimensão: " +
               $3.t.tipo_base + "/" + toString( $3.t.ndim ) );
        
           $$.v = gera_nome_var_temp( $$.t.tipo_base );
           $$.c = $3.c +
           gera_teste_limite_array( tipoArray, $3.v ) +   
             "  " + $$.v + " = " + $1.v + "[" + $3.v + "];\n";
          }
          | TK_ID '[' E ']' '[' E ']'
          { 
            Tipo tipoArray = consulta_var_ts( $1.v );
            
            $$.t = tipoArray;
            if( tipoArray.ndim != MATRIZ )
              erro( "Variável " + $1.v + " não é array de duas dimensões" );
        
            if( $3.t.ndim != BASICO || $3.t.tipo_base != "i" || $6.t.tipo_base != "i" )
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
          | TK_ID '(' EXPRS ')' 
            { 
              Tipo tipoArray = consulta_var_ts( $1.v );
              $$.t = tipoArray;

              $$.v = gera_nome_var_temp( $$.t.tipo_base );

              // Verifica se o tipo do argumento fornecido esta correto
              $$.c = $3.c + "  " + $$.v + " = " + $1.v + "( ";
              string error_string = "Argumento invalido, funcao "+$1.v+"(";
              string aux1, aux2;
              bool error_flag = false;
              for( int i = 0; i < $3.lista_tipo.size(); i++ ){
	        aux1 = traduz_nome_tipo_cute($$.t.params[i].tipo_base);
                aux2 = $3.lista_str[i];

                if( $3.lista_tipo[i].tipo_base != $$.t.params[i].tipo_base ){
                  error_flag = true;
                  aux2 = "???";
                }

                error_string += " " + aux1 + " " + aux2;
                if( i < $3.lista_tipo.size() - 1 )
                  error_string += ",";
              }
              error_string += " );";
              if( error_flag )
                erro( error_string );


              //Monta o codigo da chamada da funcao em C assembly
              for( int i = 0; i < $3.lista_str.size() - 1; i++ ){
                $$.c += $3.lista_str[i] + ", ";
              }
        
              $$.c += $3.lista_str[$3.lista_str.size()-1] + " );\n"; 
            }
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

// Uma tabela de símbolos para cada escopo
vector< map< string, Tipo > > ts;

void empilha_ts() {
  map< string, Tipo > novo;
  ts.push_back( novo );
}

void desempilha_ts() {
  ts.pop_back();
}

Tipo consulta_var_ts( string nome_var ) {
  for( int i = ts.size()-1; i >= 0; i-- )
    if( ts[i].find( nome_var ) != ts[i].end() )
      return ts[i][ nome_var ];
    
  erro( "Variável não declarada: " + nome_var );
  
  return Tipo();
}

Tipo consulta_funcao_ts( string nome_func ) {
  for( int i = ts.size()-1; i >= 0; i-- )
    if( ts[i].find( nome_func ) != ts[i].end() )
      return ts[i][ nome_func ];
    
  erro( "Funcao não declarada: " + nome_func );
  
  return Tipo();
}

void insere_var_ts( string nome_var, Tipo tipo ) {
  if( ts[ts.size()-1].find( nome_var ) != ts[ts.size()-1].end() )
    erro( "Variável já declarada: " + nome_var + 
          " (" + ts[ts.size()-1][ nome_var ].tipo_base + ")" );
    
  ts[ts.size()-1][ nome_var ] = tipo;
}

void insere_funcao_ts( string nome_func, 
                       Tipo retorno, vector<Tipo> params ) {
  if( ts[ts.size()-2].find( nome_func ) != ts[ts.size()-2].end() )
    erro( "Função já declarada: " + nome_func );
    
  Tipo aux = Tipo( retorno );
  aux.retorno.push_back( Tipo( retorno ) );
  aux.params = params;
  ts[ts.size()-2][ nome_func ] = aux;

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
  
  var_temp[var_temp.size()-1] += declara_var( nome, Tipo( tipo ) );
  
  return nome;
}

string gera_label( string tipo ) {
  static int n = 0;
  string nome = "l_" + tipo + "_" + toString( ++n );
  
  return nome;
}

Tipo tipo_resultado( Tipo t1, string opr, Tipo t3 ) {
  if( t1.ndim == BASICO && t3.ndim == BASICO ) {
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

string traduz_nome_tipo_cute( string tipo_lex ) {
  
  if( tipo_lex == "i" )
    return "intinho";
  else if( tipo_lex == "b" )
    return "boolzinho";
  else if( tipo_lex == "d" )
    return "dbzinho";  
  else if( tipo_lex == "c" )
    return "charzinho";  
  else if( tipo_lex == "s" )
    return "txtzinho";  
  else 
    erro( "Tipo inválido: " + tipo_lex );
}

string traduz_nome_tipo_variavel( string tipo_cute ) {
  // No caso do Pascal, a comparacao deveria ser case-insensitive
  
  if( tipo_cute == "intinho" )
    return "i";
  else if( tipo_cute == "boolzinho" )
    return "b";
  else if( tipo_cute == "dbzinho" )
    return "d";  
  else if( tipo_cute == "charzinho" )
    return "c";  
  else if( tipo_cute == "txtzinho" )
    return "s";  
  else 
    erro( "Tipo inválido: " + tipo_cute );
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

string declara_var( string nome, Tipo tipo, bool ln ) {
  static map<string, string> em_C = inicializaMapEmC();
  
  if( em_C[ tipo.tipo_base ] == "" )
    erro( "Tipo inválido: " + tipo.tipo_base );
    
  string indice;
   
  switch( tipo.ndim ) {
    case BASICO: indice = (tipo.tipo_base == "s" ? "[256]" : "");
            break;
              
    case VETOR: indice = "[" + toString( 
                  (tipo.fim[0]-tipo.inicio[0]+1) *  
                  (tipo.tipo_base == "s" ? 256 : 1)
                ) + "]";
            break; 
            
    case MATRIZ: indice = "[" + toString( 
                  (tipo.fim[0]-tipo.inicio[0]+1) *
                  (tipo.fim[1]-tipo.inicio[1]+1) *
                  (tipo.tipo_base == "s" ? 256 : 1)
                ) + "]";
            break;
    
    default:
       erro( "Bug muito sério..." );
  } 
  if( ln ) 
    return em_C[ tipo.tipo_base ] + nome + indice + ";\n";
  return em_C[ tipo.tipo_base ] + nome + indice;
}

string declara_funcao( string nome, Tipo tipo, 
                       vector<string> nomes, vector<Tipo> tipos ) {
  static map<string, string> em_C = inicializaMapEmC();

  insere_funcao_ts( nome, tipo, tipos );
  if( em_C[ tipo.tipo_base ] == "" ) 
    erro( "Tipo inválido: " + tipo.tipo_base );
    
  insere_var_ts( "Result", tipo );
    
  if( nomes.size() != tipos.size() )
    erro( "Bug no compilador! Nomes e tipos de parametros diferentes." );
      
  string aux = " ";
  
  for( int i = 0; i < nomes.size(); i++ ) {
    aux += declara_var( nomes[i], tipos[i], false) + 
           (i == nomes.size()-1 ? " " : ", ");  
    insere_var_ts( nomes[i], tipos[i] );  
  }
      
  return em_C[ tipo.tipo_base ] + " " + nome + "(" + aux + ")";
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
  
  if( tipoArray.ndim == VETOR ) {
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

  }else if( tipoArray.ndim == MATRIZ) {
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
