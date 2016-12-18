%{

char* troca_aspas( char* lexema );

%}

DELIM   [\t ]
LINHA   [\n]
NUMERO  [0-9]
LETRA   [A-Za-z_]
INTEIRO "-"?{NUMERO}+
REAL  	"-"?{NUMERO}+("."{NUMERO}+)?
ID      {LETRA}({LETRA}|{NUMERO})*
TEXTO 	"'"([^\n']|'""')*"'"

COMENTARIO ">.<"(.)*">.<"

%%

{LINHA}    	{ nlinha++; }
{DELIM}    	{}
{COMENTARIO}  	{}

"oiee"		{ yylval = Atributos( yytext); return TK_PROGRAM; }
"intinho"	{ yylval = Atributos( yytext); return TK_INT; }
"charzinho"	{ yylval = Atributos( yytext); return TK_CHAR; }
"boolzinho"	{ yylval = Atributos( yytext); return TK_BOOL; }
"dbzinho"  	{ yylval = Atributos( yytext); return TK_DOUBLE; }
"txtzinho" 	{ yylval = Atributos( yytext); return TK_STRING; }
"funcaozinha" 	{ yylval = Atributos( yytext); return TK_FUNCTION; }
"ifinho"  	{ yylval = Atributos( yytext); return TK_IF; }
"elsinho"  	{ yylval = Atributos( yytext); return TK_ELSE; }
"forzinho"  	{ yylval = Atributos( yytext); return TK_FOR; }
"whilinho"  	{ yylval = Atributos( yytext); return TK_WHILE; }
"dowhilinho"  	{ yylval = Atributos( yytext); return TK_DOWHILE; }
"switinho"  	{ yylval = Atributos( yytext); return TK_SWITCH; }
"scanzinho"	{ yylval = Atributos( yytext); return TK_READ; }
"printin" 	{ yylval = Atributos( yytext); return TK_WRITE; }	
"printinln" 	{ yylval = Atributos( yytext); return TK_WRITELN; }	
"[:"		{ yylval = Atributos( yytext); return TK_BEGIN; }
":]"		{ yylval = Atributos( yytext); return TK_END; }
"inicinho"	{ yylval = Atributos( yytext); return TK_MBEGIN; }
"ref-"		{ yylval = Atributos( yytext); return TK_REFERENCE; }
"finzinho"	{ yylval = Atributos( yytext); return TK_MEND; }
"retorninho"	{ yylval = Atributos( yytext); return TK_RETURN; }


".."	   { yylval = Atributos( yytext ); return TK_PTPT; }
"="       { yylval = Atributos( yytext ); return TK_ATRIB; }
"<="       { yylval = Atributos( yytext ); return TK_MEIG; }
">="       { yylval = Atributos( yytext ); return TK_MAIG; }
"!="       { yylval = Atributos( yytext ); return TK_DIF; }
"=="       { yylval = Atributos( yytext ); return TK_EQUAL; }
"and"      { yylval = Atributos( yytext ); return TK_AND; }
"or"      { yylval = Atributos( yytext ); return TK_OR; }


{TEXTO}	   { yylval = Atributos( troca_aspas( yytext ), Tipo( "string" ) ); return TK_TEXTO; }
{ID}	   { yylval = Atributos( yytext ); return TK_ID; }
{INTEIRO}  { yylval = Atributos( yytext, Tipo( "int" ) ); return TK_INTEIRO; }
{REAL}     { yylval = Atributos( yytext, Tipo( "double" ) ); return TK_REAL; }
.	   { yylval = Atributos( yytext ); return *yytext; }

%%

char* troca_aspas( char* lexema ) {
  int n = strlen( lexema );
  lexema[0] = '"';
  lexema[n-1] = '"';
  
  return lexema;
}
