/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "trabalho.y" /* yacc.c:339  */

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
  int arg;
  int inicio[MAX_DIM];
  int fim[MAX_DIM];
  vector<Tipo> retorno; // usando vector por dois motivos:
  // 1) Para não usar ponteiros
  // 2) Para ser genérico. Algumas linguagens permitem mais de um valor
  //    de retorno.
  vector<Tipo> params;
  vector<string> names;
  
  Tipo() {} // Construtor Vazio
  
  Tipo( string tipo, int arg=0 ) {
    tipo_base = tipo;
    ndim = BASICO;
    this->arg = arg;
  }
  
  Tipo( string base, int inicio, int fim, int arg=0  ) {
    if( inicio > fim )
      erro( "nome_variavel[n1..n2], onde n1 <= n2." );
    tipo_base = base;
    ndim = VETOR;
    this->inicio[0] = inicio;
    this->fim[0] = fim;
    this->arg = arg;
  }
  
  Tipo( string base, int inicio_1, int fim_1, int inicio_2, int fim_2, int arg=0 ) {
    if( inicio_1 > fim_1 || inicio_2 > fim_2 )
      erro( "nome_variavel[r1..r2][c1..c2], onde r1 <= r2 && c1 <= c2." );
    tipo_base = base;
    ndim = MATRIZ;
    this->inicio[0] = inicio_1;
    this->fim[0] = fim_1;
    this->inicio[1] = inicio_2;
    this->fim[1] = fim_2;
    this->arg = arg;
  }
  
  Tipo( Tipo retorno, const vector<Tipo> params, const vector<string> names, int arg=0 ) {
    ndim = FUNCAO;
    this->retorno.push_back( retorno );
    this->params = params;
    this->names = names;
    this->arg = arg;
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
void insere_var_rc_ts( string nome_var );
void insere_funcao_ts( string nome_func, Tipo retorno, vector<Tipo> params, vector<string> names );
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

string colunas = "";

#define YYSTYPE Atributos


#line 200 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_PROGRAM = 258,
    TK_BEGIN = 259,
    TK_END = 260,
    TK_MBEGIN = 261,
    TK_MEND = 262,
    TK_ATRIB = 263,
    TK_REFERENCE = 264,
    TK_IF = 265,
    TK_ELSE = 266,
    TK_MAIG = 267,
    TK_MEIG = 268,
    TK_DIF = 269,
    TK_EQUAL = 270,
    TK_AND = 271,
    TK_OR = 272,
    TK_FOR = 273,
    TK_WHILE = 274,
    TK_DOWHILE = 275,
    TK_SWITCH = 276,
    TK_FUNCTION = 277,
    TK_RETURN = 278,
    TK_PTPT = 279,
    TK_INT = 280,
    TK_CHAR = 281,
    TK_BOOL = 282,
    TK_DOUBLE = 283,
    TK_STRING = 284,
    TK_TEXTO = 285,
    TK_ID = 286,
    TK_INTEIRO = 287,
    TK_REAL = 288,
    TK_WRITELN = 289,
    TK_WRITE = 290,
    TK_READ = 291
  };
#endif
/* Tokens.  */
#define TK_PROGRAM 258
#define TK_BEGIN 259
#define TK_END 260
#define TK_MBEGIN 261
#define TK_MEND 262
#define TK_ATRIB 263
#define TK_REFERENCE 264
#define TK_IF 265
#define TK_ELSE 266
#define TK_MAIG 267
#define TK_MEIG 268
#define TK_DIF 269
#define TK_EQUAL 270
#define TK_AND 271
#define TK_OR 272
#define TK_FOR 273
#define TK_WHILE 274
#define TK_DOWHILE 275
#define TK_SWITCH 276
#define TK_FUNCTION 277
#define TK_RETURN 278
#define TK_PTPT 279
#define TK_INT 280
#define TK_CHAR 281
#define TK_BOOL 282
#define TK_DOUBLE 283
#define TK_STRING 284
#define TK_TEXTO 285
#define TK_ID 286
#define TK_INTEIRO 287
#define TK_REAL 288
#define TK_WRITELN 289
#define TK_WRITE 290
#define TK_READ 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 320 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   425

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,     2,    43,     2,     2,
      48,    49,    41,    39,    47,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      37,     2,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   173,   178,   181,   184,   186,   190,   193,
     196,   207,   221,   236,   237,   238,   239,   240,   243,   246,
     251,   255,   255,   255,   260,   260,   268,   274,   276,   280,
     292,   295,   301,   309,   317,   325,   325,   331,   340,   342,
     344,   347,   348,   349,   350,   351,   352,   355,   356,   359,
     381,   383,   387,   394,   400,   406,   423,   440,   472,   474,
     476,   478,   480,   482,   484,   486,   488,   490,   492,   494,
     496,   498,   500,   510,   513,   514,   516,   518,   528,   544,
     574,   641,   654,   661,   668
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PROGRAM", "TK_BEGIN", "TK_END",
  "TK_MBEGIN", "TK_MEND", "TK_ATRIB", "TK_REFERENCE", "TK_IF", "TK_ELSE",
  "TK_MAIG", "TK_MEIG", "TK_DIF", "TK_EQUAL", "TK_AND", "TK_OR", "TK_FOR",
  "TK_WHILE", "TK_DOWHILE", "TK_SWITCH", "TK_FUNCTION", "TK_RETURN",
  "TK_PTPT", "TK_INT", "TK_CHAR", "TK_BOOL", "TK_DOUBLE", "TK_STRING",
  "TK_TEXTO", "TK_ID", "TK_INTEIRO", "TK_REAL", "TK_WRITELN", "TK_WRITE",
  "TK_READ", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "'['",
  "']'", "','", "'('", "')'", "'!'", "$accept", "S", "PROGRAM", "DECLS",
  "DECL", "VARS", "VAR", "TIPO", "IDS", "MAIN", "FUNCTION", "$@1", "$@2",
  "CORPO", "$@3", "CABECALHO", "OPC_PARAM", "PARAMS", "PARAM", "BLOCO",
  "$@4", "RETURN", "CMDS", "CMD", "LOOP", "CMD_FOR", "CMD_IF", "WRITELN",
  "WRITE", "READ", "ATRIB", "E", "F", "EXPRS", "NOME_VAR", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    60,    62,    43,
      45,    42,    47,    37,    59,    91,    93,    44,    40,    41,
      33
};
# endif

#define YYPACT_NINF -71

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-71)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,    -5,    20,   197,     8,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,    42,   197,   -71,     9,    25,   -71,   -71,   -11,
      53,   -71,   -71,   -11,    27,    18,    45,    69,   -71,    70,
     -71,    46,    48,    32,   -71,   -71,   322,   -71,    57,   -71,
      34,   -71,   322,   -71,   375,    58,    -2,    36,    40,    50,
     -71,   -71,    96,    56,   322,   -71,   -71,   -71,   -71,   -71,
     -71,    81,   -71,    -4,    74,    77,   103,   -71,   -26,   -71,
     -71,   375,   375,    54,   -71,   -71,   -71,   117,   375,   375,
     375,   375,    58,   -71,   322,   -71,    83,    99,    86,   -71,
     -11,   375,   141,   375,    72,   102,   296,   322,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   296,   191,   140,   153,    98,   -71,   104,   -71,
     112,   -71,   281,   -71,   201,   -71,   296,     2,   -71,   143,
     354,   354,   354,   354,   361,   361,   354,   354,     4,     4,
     -71,   -71,   -71,   347,    -1,   -71,   -71,   -71,   118,   114,
     -71,   115,   375,   -71,   150,   375,   375,   375,   138,   125,
     375,   296,   159,    95,   296,   236,   132,   -71,   246,   322,
     322,   164,   127,   -71,   169,   170,   375,   -71,   -71,   -71,
     296
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     0,     1,    21,    14,    16,    15,
      13,    17,     0,     5,     6,     0,     0,     7,     3,     0,
       0,     2,     4,     9,    19,    10,     0,     0,    35,     0,
       8,     0,     0,     0,    24,    22,    40,    20,     0,    18,
       0,    26,    40,    23,     0,     0,     0,     0,     0,     0,
      46,    45,     0,     0,    40,    48,    47,    42,    41,    43,
      44,     0,    28,     0,     0,    30,     0,    77,    84,    75,
      76,     0,     0,     0,    73,    74,    84,     0,     0,     0,
       0,     0,     0,    36,    40,    39,     0,     0,    31,    27,
       0,     0,     0,     0,     0,     0,    72,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,    38,    11,    34,
       0,    29,     0,    25,     0,    81,    83,     0,    71,     0,
      66,    65,    68,    67,    69,    70,    63,    64,    58,    59,
      60,    61,    62,     0,     0,    52,    53,    54,     0,    32,
      37,    78,     0,    80,    50,     0,     0,     0,     0,     0,
       0,    82,     0,     0,    56,     0,     0,    33,     0,    40,
      40,     0,     0,    79,     0,     0,     0,    12,    51,    49,
      57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   -71,   163,   -71,   161,    51,   -15,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,    97,   -71,   165,
     -71,   -71,   -42,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -70,   -71,   -71,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    12,    13,    14,    50,    16,    25,    21,
      17,    19,    43,    35,    42,    27,    41,    64,    65,    51,
      36,    92,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    73,    74,   127,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    95,    96,     1,    26,    87,    78,   156,   112,   113,
     114,   115,    85,    77,     7,     8,     9,    10,    11,    93,
       5,   122,    94,   124,   126,    63,     4,    88,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   117,    79,   157,   108,   109,   110,    20,   152,
     116,   153,    18,    23,    15,   129,    24,    28,    97,     7,
       8,     9,    10,    11,    15,    32,    98,    99,   100,   101,
     102,   103,    31,    34,    15,    63,    33,    37,    38,    39,
      40,    61,   161,    62,    80,   163,   164,   165,    81,    76,
     168,   104,   105,   106,   107,   108,   109,   110,    82,   170,
      84,    83,    67,    68,    69,    70,   180,    98,    99,   100,
     101,   102,   103,    86,    98,    99,   100,   101,   102,   103,
      71,   125,    72,    89,    90,   111,    91,   174,   175,   118,
     119,   120,   104,   105,   106,   107,   108,   109,   110,   104,
     105,   106,   107,   108,   109,   110,   123,   147,   154,   148,
     158,   128,    98,    99,   100,   101,   102,   103,   149,   159,
     160,   162,   166,   169,   172,    98,    99,   100,   101,   102,
     103,   167,   176,   177,   178,   179,    22,   104,   105,   106,
     107,   108,   109,   110,    30,    29,     0,   121,     0,   145,
     104,   105,   106,   107,   108,   109,   110,     0,     0,     0,
       0,     0,   146,    98,    99,   100,   101,   102,   103,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,     6,
       0,     0,     7,     8,     9,    10,    11,     0,   104,   105,
     106,   107,   108,   109,   110,     0,     0,   144,   104,   105,
     106,   107,   108,   109,   110,     0,     0,   151,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
       0,     0,   171,   104,   105,   106,   107,   108,   109,   110,
       0,     0,   173,    98,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   150,    28,     0,     0,     0,
       0,     0,    44,   104,   105,   106,   107,   108,   109,   110,
      45,     0,     0,     0,     0,     0,     0,     7,     8,     9,
      10,    11,     0,    46,     0,     0,    47,    48,    49,    98,
      99,   100,   101,   102,   103,     0,    -1,    -1,    -1,    -1,
       0,   155,     0,    98,    99,   100,   101,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,   106,   107,   108,   109,   110,   104,   105,
     106,   107,   108,   109,   110,    67,    68,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,     0,    72
};

static const yytype_int16 yycheck[] =
{
      42,    71,    72,     3,    19,     9,     8,     8,    78,    79,
      80,    81,    54,    45,    25,    26,    27,    28,    29,    45,
       0,    91,    48,    93,    94,    40,    31,    31,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    84,    45,    45,    41,    42,    43,     6,    47,
      82,    49,    44,    44,     3,    97,    31,     4,     4,    25,
      26,    27,    28,    29,    13,    47,    12,    13,    14,    15,
      16,    17,    45,     4,    23,    90,    31,     7,    32,    31,
      48,    24,   152,    49,    48,   155,   156,   157,    48,    31,
     160,    37,    38,    39,    40,    41,    42,    43,    48,     4,
      44,     5,    30,    31,    32,    33,   176,    12,    13,    14,
      15,    16,    17,    32,    12,    13,    14,    15,    16,    17,
      48,    49,    50,    49,    47,     8,    23,   169,   170,    46,
      31,    45,    37,    38,    39,    40,    41,    42,    43,    37,
      38,    39,    40,    41,    42,    43,     5,    49,     5,    45,
      32,    49,    12,    13,    14,    15,    16,    17,    46,    45,
      45,    11,    24,     4,    32,    12,    13,    14,    15,    16,
      17,    46,     8,    46,     5,     5,    13,    37,    38,    39,
      40,    41,    42,    43,    23,    20,    -1,    90,    -1,    49,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    49,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    22,
      -1,    -1,    25,    26,    27,    28,    29,    -1,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,     4,    -1,    -1,    -1,
      -1,    -1,    10,    37,    38,    39,    40,    41,    42,    43,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    -1,    31,    -1,    -1,    34,    35,    36,    12,
      13,    14,    15,    16,    17,    -1,    12,    13,    14,    15,
      -1,    24,    -1,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    37,    38,    39,    40,    41,    42,    43,    37,    38,
      39,    40,    41,    42,    43,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    52,    53,    31,     0,    22,    25,    26,    27,
      28,    29,    54,    55,    56,    57,    58,    61,    44,    62,
       6,    60,    54,    44,    31,    59,    58,    66,     4,    70,
      56,    45,    47,    31,     4,    64,    71,     7,    32,    31,
      48,    67,    65,    63,    10,    18,    31,    34,    35,    36,
      57,    70,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    24,    49,    58,    68,    69,    73,    30,    31,    32,
      33,    48,    50,    82,    83,    85,    31,    85,     8,    45,
      48,    48,    48,     5,    44,    73,    32,     9,    31,    49,
      47,    23,    72,    45,    48,    82,    82,     4,    12,    13,
      14,    15,    16,    17,    37,    38,    39,    40,    41,    42,
      43,     8,    82,    82,    82,    82,    85,    73,    46,    31,
      45,    68,    82,     5,    82,    49,    82,    84,    49,    73,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    46,    49,    49,    49,    45,    46,
      44,    46,    47,    49,     5,    24,     8,    45,    32,    45,
      45,    82,    11,    82,    82,    82,    24,    46,    82,     4,
       4,    46,    32,    46,    73,    73,     8,    46,     5,     5,
      82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    57,    58,    58,    58,    58,    58,    59,    59,
      60,    62,    63,    61,    65,    64,    66,    67,    67,    68,
      68,    69,    69,    69,    69,    71,    70,    72,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      77,    77,    78,    79,    80,    81,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    83,    83,    83,    83,    83,    83,
      83,    83,    84,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     0,     1,     1,     3,     0,
       2,     7,    12,     1,     1,     1,     1,     1,     3,     1,
       3,     0,     0,     5,     0,     5,     3,     3,     2,     3,
       1,     2,     4,     6,     3,     0,     4,     3,     3,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     9,
       5,     9,     4,     4,     4,     3,     6,     9,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     4,     7,
       4,     3,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 165 "trabalho.y" /* yacc.c:1646  */
    {
      cout << includes << endl;
      cout << colunas << endl;
      cout << (yyvsp[-1]).c << endl;
      cout << (yyvsp[0]).c << endl;
    }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 174 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = ""; 
            empilha_ts(); }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 179 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 181 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = ""; }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 185 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 187 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 191 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c; }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 193 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = ""; }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 197 "trabalho.y" /* yacc.c:1646  */
    {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( (yyvsp[-1]).v ) );
        
        (yyval) = Atributos();
        
        for( int i = 0; i < (yyvsp[0]).lista_str.size(); i++ ) {
          (yyval).c += declara_var( (yyvsp[0]).lista_str[i], tipo );
          insere_var_ts( (yyvsp[0]).lista_str[i], tipo );
        }
      }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 208 "trabalho.y" /* yacc.c:1646  */
    {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( (yyvsp[-6]).v ), 
                          toInt( (yyvsp[-3]).v ), toInt( (yyvsp[-1]).v ) );

        if( tipo.tipo_base == "s" )
          erro("Aiiee!! esta linguagem nao suporta array de strings... dicupaa"); 
        
        (yyval) = Atributos();
        
        (yyval) = Atributos();
        (yyval).c += declara_var( (yyvsp[-5]).v, tipo );
        insere_var_ts( (yyvsp[-5]).v, tipo );
      }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 222 "trabalho.y" /* yacc.c:1646  */
    {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( (yyvsp[-11]).v ), 
                          toInt( (yyvsp[-8]).v ), toInt( (yyvsp[-6]).v ),
			  toInt( (yyvsp[-3]).v ), toInt( (yyvsp[-1]).v ) );

        if( tipo.tipo_base == "s" )
          erro("Aiiee!! esta linguagem nao suporta matriz de strings... dicupaa");
        
        (yyval) = Atributos();
        (yyval).c += declara_var( (yyvsp[-10]).v, tipo );
        insere_var_ts( (yyvsp[-10]).v, tipo );
      }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 244 "trabalho.y" /* yacc.c:1646  */
    { (yyval)  = (yyvsp[-2]);
        (yyval).lista_str.push_back( (yyvsp[0]).v ); }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 247 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributos();
        (yyval).lista_str.push_back( (yyvsp[0]).v ); }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 252 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = "int main() { \n" + (yyvsp[-1]).c + "}\n"; }
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 255 "trabalho.y" /* yacc.c:1646  */
    { empilha_ts(); }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 255 "trabalho.y" /* yacc.c:1646  */
    { desempilha_ts(); }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 256 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + " {\n" + (yyvsp[-1]).c + 
                    "  return Result;\n}\n"; }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 260 "trabalho.y" /* yacc.c:1646  */
    { var_temp.push_back( "" );}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 261 "trabalho.y" /* yacc.c:1646  */
    { 
          string vars = var_temp[var_temp.size()-1];
          var_temp.pop_back();
          (yyval).c = "  " + declara_var( "Result", consulta_var_ts( "Result" ) );
          (yyval).c += vars + (yyvsp[-2]).c + (yyvsp[-1]).c; }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 269 "trabalho.y" /* yacc.c:1646  */
    {
              Tipo tipo = Tipo( traduz_nome_tipo_variavel( (yyvsp[-2]).v ) );
              (yyval).c = declara_funcao( (yyvsp[-1]).v, tipo, (yyvsp[0]).lista_str, (yyvsp[0]).lista_tipo ); }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 275 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 277 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributos(); }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 281 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c; 
           // Concatenar as listas.
           (yyval).lista_tipo = (yyvsp[-2]).lista_tipo;
           (yyval).lista_tipo.insert( (yyval).lista_tipo.end(), 
                                 (yyvsp[0]).lista_tipo.begin(),  
                                 (yyvsp[0]).lista_tipo.end() ); 
           (yyval).lista_str = (yyvsp[-2]).lista_str;
           (yyval).lista_str.insert( (yyval).lista_str.end(), 
                                (yyvsp[0]).lista_str.begin(),  
                                (yyvsp[0]).lista_str.end() ); 
         }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 296 "trabalho.y" /* yacc.c:1646  */
    {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( (yyvsp[-1]).v ), 1 );
        (yyval).lista_str.push_back((yyvsp[0]).v);
        (yyval).lista_tipo.push_back( tipo );
      }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 302 "trabalho.y" /* yacc.c:1646  */
    {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( (yyvsp[-3]).v ),
			  -200, 200, 1 );
        tipo.ndim = BASICO;
        (yyval).lista_str.push_back((yyvsp[-2]).v + "[]");
        (yyval).lista_tipo.push_back( tipo );
      }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 310 "trabalho.y" /* yacc.c:1646  */
    {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( (yyvsp[-5]).v ), 
                          -200, 200,
			  -200, 200, 1 );
        (yyval).lista_str.push_back((yyvsp[-4]).v);
        (yyval).lista_tipo.push_back( tipo );
      }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 318 "trabalho.y" /* yacc.c:1646  */
    {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( (yyvsp[-2]).v ), 1 );
        (yyval).lista_str.push_back("&" + (yyvsp[0]).v);
        (yyval).lista_tipo.push_back( tipo );
      }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 325 "trabalho.y" /* yacc.c:1646  */
    { var_temp.push_back( "" );}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 326 "trabalho.y" /* yacc.c:1646  */
    { string vars = var_temp[var_temp.size()-1];
          var_temp.pop_back();
          (yyval).c = vars + (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 332 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c;
           if( (yyvsp[-1]).t.tipo_base == "s" )
             (yyval).c += "  strcpy( Result, " + (yyvsp[-1]).v + " );\n";
           else
             (yyval).c += "  Result = " + (yyvsp[-1]).v + ";\n";
         }
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 341 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c; }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 343 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 344 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = ""; }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 360 "trabalho.y" /* yacc.c:1646  */
    { 
            string var_fim = gera_nome_var_temp( (yyvsp[-7]).t.tipo_base );
            string label_teste = gera_label( "teste_for" );
            string label_fim = gera_label( "fim_for" );
            string condicao = gera_nome_var_temp( "b" );
          
            // Falta verificar os tipos... perde ponto se não o fizer.
            (yyval).c =  (yyvsp[-5]).c + (yyvsp[-3]).c +
                    "  " + (yyvsp[-7]).v + " = " + (yyvsp[-5]).v + ";\n" +
                    "  " + var_fim + " = " + (yyvsp[-3]).v + ";\n" +
                    label_teste + ":;\n" +
                    "  " +condicao+" = "+(yyvsp[-7]).v + " > " + var_fim + ";\n" + 
                    "  " + "if( " + condicao + " ) goto " + label_fim + 
                    ";\n" +
                    (yyvsp[-1]).c +
                    "  " + (yyvsp[-7]).v + " = " + (yyvsp[-7]).v + " + 1;\n" +
                    "  goto " + label_teste + ";\n" +
                    label_fim + ":;\n";  
          }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 382 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_if( (yyvsp[-3]), (yyvsp[-1]).c, "" ); }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 384 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_if( (yyvsp[-7]), (yyvsp[-5]).c, (yyvsp[-1]).c ); }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 388 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + 
                   "  cout << " + (yyvsp[-1]).v + ";\n"
                   "  cout << endl;\n";
          }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 395 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + 
                   "  cout << " + (yyvsp[-1]).v + ";\n";
          }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 401 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + 
                   "  cin >> " + (yyvsp[-1]).v + ";\n";
          }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 407 "trabalho.y" /* yacc.c:1646  */
    {        
          //Verifica se a variavel existe  
          (yyval).t = consulta_var_ts( (yyvsp[-2]).v );
          //Verifica se o tipo do variavel e do valor a ser atribuido sao compativeis
          if( (yyval).t.tipo_base != (yyvsp[0]).t.tipo_base )
            erro( "Erro de atribuicao... tipos diferentes.\n"
	      "Variavel do tipo: "+ traduz_nome_tipo_cute((yyval).t.tipo_base) + ".\n"
	      "Valor do tipo: "+ traduz_nome_tipo_cute((yyvsp[0]).t.tipo_base) + "." );

          (yyval).c = (yyvsp[0]).c;

          if( (yyval).t.tipo_base == "s" ) 
            (yyval).c += "  strncpy( " + (yyvsp[-2]).v + ", " + (yyvsp[0]).v + ", 256 );\n";
          else
            (yyval).c += "  " + (yyvsp[-2]).v + " = " + (yyvsp[0]).v + ";\n";             
        }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 424 "trabalho.y" /* yacc.c:1646  */
    {
          //Verifica se a variavel existe
          (yyval).t = consulta_var_ts( (yyvsp[-5]).v );
          //Verifica se o tipo do variavel e do valor a ser atribuido sao compativeis
          if( (yyval).t.tipo_base != (yyvsp[0]).t.tipo_base )
            erro( "Erro de atribuicao... tipos diferentes.\n"
	      "Variavel do tipo: "+ traduz_nome_tipo_cute((yyval).t.tipo_base) + ".\n"
	      "Valor do tipo: "+ traduz_nome_tipo_cute((yyvsp[0]).t.tipo_base) + "." );

          (yyval).c = (yyvsp[-3]).c + (yyvsp[0]).c + gera_teste_limite_array( (yyval).t, (yyvsp[-3]).v );

          if( (yyval).t.tipo_base == "s" )
            erro("Poxaannn tem um buguisinhuu! essa variavel nem era pra ter sido criada");
          else
            (yyval).c += "  " + (yyvsp[-5]).v + "[" + (yyvsp[-3]).v + "] = " + (yyvsp[0]).v + ";\n";
        }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 441 "trabalho.y" /* yacc.c:1646  */
    {
          //Verifica se a variavel existe
          (yyval).t = consulta_var_ts( (yyvsp[-8]).v );
          //Verifica se o tipo do variavel e do valor a ser atribuido sao compativeis
          if( (yyval).t.tipo_base != (yyvsp[0]).t.tipo_base ) {
            erro( "Erro de atribuicao... tipos diferentes.\n"
	      "Variavel do tipo: "+ traduz_nome_tipo_cute((yyval).t.tipo_base) + ".\n"
	      "Valor do tipo: "+ traduz_nome_tipo_cute((yyvsp[0]).t.tipo_base) + "." );
          }
          string aux = gera_nome_var_temp( (yyvsp[-6]).t.tipo_base );
          string tam;
          string ope = "";
          if( (yyval).t.arg == 1 ){
            ope =  "  " + aux + " = " + (yyvsp[-8]).v + "_fim2_matriz" + " - " + (yyvsp[-8]).v + "_ini2_matriz;\n";
            ope += "  " + aux + " = " + aux  + " + 1;\n";
            tam = aux;
          }else
            tam = toString((yyval).t.fim[1] - (yyval).t.inicio[1] + 1);

          (yyval).c = (yyvsp[-6]).c + (yyvsp[-3]).c + (yyvsp[0]).c +
                 gera_teste_limite_array( (yyval).t, (yyvsp[-6]).v, (yyvsp[-3]).v ) + 
                 ope +  
		 "  " + aux  + " = " + tam  + "*" + (yyvsp[-6]).v + ";\n" +
		 "  " + aux  + " = " + aux  + "+" + (yyvsp[-3]).v + ";\n";
          if( (yyval).t.tipo_base == "s" )
            erro("Poxaannn tem um buguisinhuu! essa variavel nem era pra ter sido criada");
          else
            (yyval).c += "  " + (yyvsp[-8]).v + "[" + aux + "] = " + (yyvsp[0]).v + ";\n";
        }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 473 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "+", (yyvsp[0]) ); }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 475 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "-", (yyvsp[0]) ); }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 477 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "*", (yyvsp[0]) ); }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 479 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "/", (yyvsp[0]) ); }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 481 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "%", (yyvsp[0]) ); }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 483 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "<", (yyvsp[0]) ); }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 485 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), ">", (yyvsp[0]) ); }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 487 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "<=", (yyvsp[0]) ); }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 489 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), ">=", (yyvsp[0]) ); }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 491 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "==", (yyvsp[0]) ); }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 493 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "!=", (yyvsp[0]) ); }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 495 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "&&", (yyvsp[0]) ); }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 497 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "||", (yyvsp[0]) ); }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 499 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 501 "trabalho.y" /* yacc.c:1646  */
    { 
      if( (yyvsp[0]).t.tipo_base != "b" )
        erro( "Queridinha, voce nao pode negar uma expressaozinha do tipinho " + traduz_nome_tipo_cute( (yyvsp[0]).t.tipo_base ) );
      (yyval).t = Tipo( (yyvsp[0]).t );
      (yyval).v = gera_nome_var_temp( "b" );
      (yyval).c = (yyvsp[0]).c + 
             (yyval).v + " = " + "!" + (yyvsp[0]).v + ";\n";
      
    }
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 515 "trabalho.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; (yyval).t = Tipo( "i" ); (yyval).c = (yyvsp[0]).c; }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 517 "trabalho.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; (yyval).t = Tipo( "d" ); (yyval).c = (yyvsp[0]).c; }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 519 "trabalho.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v;
      (yyval).t = Tipo( "s" );
      if( (yyvsp[0]).v.size() - 2 == 1 ) {
        (yyval).t = Tipo( "c" );
        (yyval).v[0] = '\'';
        (yyval).v[2] = '\'';
      }
      (yyval).c = (yyvsp[0]).c; 
    }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 529 "trabalho.y" /* yacc.c:1646  */
    { 
       Tipo tipoArray = consulta_var_ts( (yyvsp[-3]).v );
       (yyval).t = tipoArray;
       if( tipoArray.ndim != VETOR )
         erro( "Variável " + (yyvsp[-3]).v + " não é array de uma dimensão" );
        
       if( (yyvsp[-1]).t.ndim != BASICO || (yyvsp[-1]).t.tipo_base != "i" )
         erro( "Indice de array deve ser integer de zero dimensão: " +
           (yyvsp[-1]).t.tipo_base + "/" + toString( (yyvsp[-1]).t.ndim ) );

       (yyval).v = gera_nome_var_temp( (yyval).t.tipo_base );
       (yyval).c = (yyvsp[-1]).c +
       gera_teste_limite_array( tipoArray, (yyvsp[-1]).v ) +   
       "  " + (yyval).v + " = " + (yyvsp[-3]).v + "[" + (yyvsp[-1]).v + "];\n";
     }
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 545 "trabalho.y" /* yacc.c:1646  */
    { 
       Tipo tipoArray = consulta_var_ts( (yyvsp[-6]).v );
            
       (yyval).t = tipoArray;
       if( tipoArray.ndim != MATRIZ )
         erro( "Variável " + (yyvsp[-6]).v + " não é array de duas dimensões" );
       
       if( (yyvsp[-4]).t.ndim != BASICO || (yyvsp[-4]).t.tipo_base != "i" || (yyvsp[-1]).t.tipo_base != "i" )
         erro( "Indice de array deve ser integer de zero dimensão: " +
           (yyvsp[-4]).t.tipo_base + "/" + toString( (yyvsp[-4]).t.ndim ) );

       string aux = gera_nome_var_temp( (yyvsp[-1]).t.tipo_base );
       string tam;
       string ope = "";
       if( (yyval).t.arg == 1 ){
         ope =  "  " + aux + " = " + (yyvsp[-6]).v + "_fim2_matriz" + " - " + (yyvsp[-6]).v + "_ini2_matriz;\n";
         ope += "  " + aux + " = " + aux  + " + 1;\n";
         tam = aux;
       }else
         tam = toString((yyval).t.fim[1] - (yyval).t.inicio[1] + 1);

       (yyval).v = gera_nome_var_temp( (yyval).t.tipo_base );
       (yyval).c = (yyvsp[-4]).c +
         gera_teste_limite_array( tipoArray, (yyvsp[-4]).v, (yyvsp[-1]).v ) +
         ope +   
         "  " + aux  + " = " + tam + " * " + (yyvsp[-4]).v + ";\n" +
         "  " + aux  + " = " + aux + " + " + (yyvsp[-1]).v + ";\n" +
         "  " + (yyval).v + " = " + (yyvsp[-6]).v + "[" + aux + "];\n";
     }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 575 "trabalho.y" /* yacc.c:1646  */
    { 
       Tipo tipoArray = consulta_var_ts( (yyvsp[-3]).v );
       (yyval).t = tipoArray;

       (yyval).v = gera_nome_var_temp( (yyval).t.tipo_base );

       if( (yyval).t.params.size() != (yyvsp[-1]).lista_tipo.size() )
         erro( "Numero de argumentos inválido." );
       if( (yyvsp[-1]).lista_str.size() != (yyvsp[-1]).lista_tipo.size() )
         erro( "Nada a veirr tiio!" );

       // Verifica se o tipo do argumento fornecido esta correto
       (yyval).c = (yyvsp[-1]).c + "  " + (yyval).v + " = " + (yyvsp[-3]).v + "( ";

       string error_string = "Argumento invalido, funcao "+(yyvsp[-3]).v+"(";
       string aux1, aux2;
       string atualiza_valor = "";
       bool error_flag = false;
       for( int i = 0; i < (yyvsp[-1]).lista_tipo.size(); i++ ){
         aux1 = traduz_nome_tipo_cute((yyval).t.params[i].tipo_base);
         aux2 = (yyvsp[-1]).lista_str[i];
                
         if( (yyvsp[-1]).lista_tipo[i].tipo_base != (yyval).t.params[i].tipo_base ){
           error_flag = true;
           aux2 = "???";
         }else {
           if( (yyval).t.params[i].ndim == VETOR ) {
             (yyval).t.params[i].inicio[0] = (yyvsp[-1]).lista_tipo[i].inicio[0];
             (yyval).t.params[i].fim[0] = (yyvsp[-1]).lista_tipo[i].fim[0];
           }
           if( (yyval).t.params[i].ndim == MATRIZ ) {
             (yyval).t.params[i].inicio[0] = (yyvsp[-1]).lista_tipo[i].inicio[0];
             (yyval).t.params[i].fim[0] = (yyvsp[-1]).lista_tipo[i].fim[0];
             (yyval).t.params[i].inicio[1] = (yyvsp[-1]).lista_tipo[i].inicio[1];
             (yyval).t.params[i].fim[1] = (yyvsp[-1]).lista_tipo[i].fim[1];
             atualiza_valor += "  " + (yyval).t.names[i] + "_ini1_matriz = " + 
                             toString((yyval).t.params[i].inicio[0]) + ";\n";

             atualiza_valor += "  " + (yyval).t.names[i] + "_ini2_matriz = " + 
                             toString((yyval).t.params[i].inicio[1]) + ";\n";

             atualiza_valor += "  " + (yyval).t.names[i] + "_fim1_matriz = " + 
                             toString((yyval).t.params[i].fim[0]) + ";\n";

             atualiza_valor += "  " + (yyval).t.names[i] + "_fim2_matriz = " + 
                             toString((yyval).t.params[i].fim[1]) + ";\n";
           }
         }

         error_string += " " + aux1 + " " + aux2;
         if( i < (yyvsp[-1]).lista_tipo.size() - 1 )
           error_string += ",";
       }
       error_string += " );";
       if( error_flag )
         erro( error_string );


       //Monta o codigo da chamada da funcao em C assembly
       for( int i = 0; i < (yyvsp[-1]).lista_str.size() - 1; i++ ){
         (yyval).c += (yyvsp[-1]).lista_str[i] + ", ";
       }
       
       (yyval).c += (yyvsp[-1]).lista_str[(yyvsp[-1]).lista_str.size()-1] + " );\n";
       (yyval).c = atualiza_valor + (yyval).c;
     }
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 642 "trabalho.y" /* yacc.c:1646  */
    {
       Tipo tipoArray = consulta_var_ts( (yyvsp[-2]).v );
       (yyval).t = tipoArray;
       (yyval).v = gera_nome_var_temp( (yyval).t.tipo_base );
              
       if( (yyval).t.params.size() != 0 )
         erro( "Esta função possui argumentos" );
       // Verifica se o tipo do argumento fornecido esta correto
       (yyval).c = (yyvsp[0]).c + "  " + (yyval).v + " = " + (yyvsp[-2]).v + "();\n";
     }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 655 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributos();
          (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c;
          (yyval).lista_str = (yyvsp[-2]).lista_str;
          (yyval).lista_tipo = (yyvsp[-2]).lista_tipo;
          (yyval).lista_str.push_back( (yyvsp[0]).v );
          (yyval).lista_tipo.push_back( (yyvsp[0]).t );  }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 662 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributos();
          (yyval).c = (yyvsp[0]).c;
          (yyval).lista_str.push_back( (yyvsp[0]).v ); 
          (yyval).lista_tipo.push_back( (yyvsp[0]).t ); }
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 669 "trabalho.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; (yyval).t = consulta_var_ts( (yyvsp[0]).v ); (yyval).c = (yyvsp[0]).c; }
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2279 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 672 "trabalho.y" /* yacc.c:1906  */

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

  tipo_opr["c+i"] = "c";
  tipo_opr["i+c"] = "c";

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

  // Resultados para o operador "%"
  tipo_opr["i%i"] = "i";
  
  // Resultados para o operador "<"
  // numero x numero
  tipo_opr["i<i"] = "b";
  tipo_opr["i<d"] = "b";
  tipo_opr["d<i"] = "b";
  tipo_opr["d<d"] = "b";

  // numero x letra
  tipo_opr["c<i"] = "b";
  tipo_opr["i<c"] = "b";

  // letra x letra
  tipo_opr["c<c"] = "b";
  tipo_opr["c<s"] = "b";
  tipo_opr["s<c"] = "b";
  tipo_opr["s<s"] = "b";

  // Resultados para o operador ">"
  // numero x numero
  tipo_opr["i>i"] = "b";
  tipo_opr["i>d"] = "b";
  tipo_opr["d>i"] = "b";
  tipo_opr["d>d"] = "b";

  // numero x letra
  tipo_opr["c>i"] = "b";
  tipo_opr["i>c"] = "b";

  // letra x letra
  tipo_opr["c>c"] = "b";
  tipo_opr["c>s"] = "b";
  tipo_opr["s>c"] = "b";
  tipo_opr["s>s"] = "b";

  // Resultados para o operador "<="
  // numero x numero
  tipo_opr["i<=i"] = "b";
  tipo_opr["i<=d"] = "b";
  tipo_opr["d<=i"] = "b";
  tipo_opr["d<=d"] = "b";

  // numero x letra
  tipo_opr["c<=i"] = "b";
  tipo_opr["i<=c"] = "b";

  // letra x letra
  tipo_opr["c<=c"] = "b";
  tipo_opr["c<=s"] = "b";
  tipo_opr["s<=c"] = "b";
  tipo_opr["s<=s"] = "b";


  // Resultados para o operador ">="
  // numero x numero
  tipo_opr["i>=i"] = "b";
  tipo_opr["i>=d"] = "b";
  tipo_opr["d>=i"] = "b";
  tipo_opr["d>=d"] = "b";

  // numero x letra
  tipo_opr["c>=i"] = "b";
  tipo_opr["i>=c"] = "b";

  // letra x letra
  tipo_opr["c>=c"] = "b";
  tipo_opr["c>=s"] = "b";
  tipo_opr["s>=c"] = "b";
  tipo_opr["s>=s"] = "b";

  // Resultados para o operador "And"
  tipo_opr["b&&b"] = "b";

  // Resultados para o operador "Or"
  tipo_opr["b||b"] = "b";
  
  // Resultados para o operador "Equal"
  // numero x numero
  tipo_opr["i==i"] = "b";
  tipo_opr["i==d"] = "b";
  tipo_opr["d==i"] = "b";
  tipo_opr["d==d"] = "b";
  // numero x letra
  tipo_opr["c==i"] = "b";
  tipo_opr["i==c"] = "b";
  // letra x letra
  tipo_opr["c==c"] = "b";
  tipo_opr["c==s"] = "b";
  tipo_opr["s==c"] = "b";
  tipo_opr["s==s"] = "b";
  // boolean x boolean
  tipo_opr["b==b"] = "b";


  // Resultados para o operador "Dif"
  // numero x numero
  tipo_opr["i!=i"] = "b";
  tipo_opr["i!=d"] = "b";
  tipo_opr["d!=i"] = "b";
  tipo_opr["d!=d"] = "b";
  // numero x letra
  tipo_opr["c!=i"] = "b";
  tipo_opr["i!=c"] = "b";
  // letra x letra
  tipo_opr["c!=c"] = "b";
  tipo_opr["c!=s"] = "b";
  tipo_opr["s!=c"] = "b";
  tipo_opr["s!=s"] = "b";
  // boolean x boolean
  tipo_opr["b!=b"] = "b";
}

// Uma tabela de símbolos para cada escopo
vector< map< string, Tipo > > ts;
map< string, Tipo > aux_ts;

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

void insere_var_rc_ts( string nome_var ) {
  if( aux_ts.find( nome_var ) != aux_ts.end() )
    erro( "Variável já declarada: " + nome_var + 
          " (" + aux_ts[ nome_var ].tipo_base + ")" );
    
  aux_ts[ nome_var ] = Tipo( "i" );
  colunas += "int " + nome_var + "_ini1_matriz" + ";\n";
  colunas += "int " + nome_var + "_ini2_matriz" + ";\n";
  colunas += "int " + nome_var + "_fim1_matriz" + ";\n";
  colunas += "int " + nome_var + "_fim2_matriz" + ";\n";
}

void insere_var_ts( string nome_var, Tipo tipo ) {
  if( ts[ts.size()-1].find( nome_var ) != ts[ts.size()-1].end() )
    erro( "Variável já declarada: " + nome_var + 
          " (" + ts[ts.size()-1][ nome_var ].tipo_base + ")" );
    
  ts[ts.size()-1][ nome_var ] = tipo;
}

void insere_funcao_ts( string nome_func,Tipo retorno, vector<Tipo> params, vector<string> names ) {
  if( ts[ts.size()-2].find( nome_func ) != ts[ts.size()-2].end() )
    erro( "Função já declarada: " + nome_func );
    
  Tipo aux = Tipo( retorno );
  aux.retorno.push_back( Tipo( retorno ) );
  aux.params = params;
  aux.names = names;
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
  string aux = gera_nome_var_temp( "s" );
  
  ss.c = s1.c + s3.c;

  if( s1.t.ndim == VETOR ) {
    erro( s1.c );
  }

  if( s1.t.tipo_base == "s" && s3.t.tipo_base == "s" ) {  
    if( opr == "+" )
      ss.c += "  strncpy( " + ss.v + ", " + s1.v + ", 256 );\n" +
              "  strncat( " + ss.v + ", " + s3.v + ", 256 );\n";
    if( opr == "==" || opr == ">" || opr == "<" || opr == ">=" || opr == "<=" || opr == "!=" )
      ss.c += "  " + ss.v + " = strcmp( " + s1.v + ", " + s3.v + " ) " + opr + " 0;\n";

  }
  else if( s1.t.tipo_base == "s" && s3.t.tipo_base == "c" ) {
    if( opr == "+" )
      ss.c += aux + "[ 0 ] = " + s3.v + ";\n" +
              aux + "[ 1 ] = " + "'" + "\\" + "0" + "'" + ";\n" +
              "  strncpy( " + ss.v + ", " + s1.v + ", 256 );\n" +
              "  strncat( " + ss.v + ", " + aux + ", 256 );\n";
  }else if( s1.t.tipo_base == "c" && s3.t.tipo_base == "s" ) {
    if( opr == "+" )
      ss.c += aux + "[ 0 ] = " + s1.v + ";\n" +
              aux + "[ 1 ] = " + "'" + "\\" + "0" + "'" + ";\n" +
              "  strncpy( " + ss.v + ", " + aux + ", 256 );\n" +
              "  strncat( " + ss.v + ", " + s3.v + ", 256 );\n";
  }else
    ss.c += "  " + ss.v + " = " + s1.v + " " + opr + " " + s3.v + ";\n"; 
  
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
              
    case VETOR: if( tipo.arg == 0 )
                  indice = "[" + toString( 
                    (tipo.fim[0]-tipo.inicio[0]+1) *  
                    (tipo.tipo_base == "s" ? 256 : 1)
                  ) + "]";
                 else
                  indice = "[]";
            break; 
            
    case MATRIZ: if( tipo.arg == 0)
                   indice = "[" + toString( 
                     (tipo.fim[0]-tipo.inicio[0]+1) *
                     (tipo.fim[1]-tipo.inicio[1]+1) *
                     (tipo.tipo_base == "s" ? 256 : 1)
                   ) + "]";
                 else
                   indice = "[]";
            break;
    
    default:
       erro( "Bug muito sério..." );
  } 
  if( ln ) 
    return em_C[ tipo.tipo_base ] + nome + indice + ";\n";
  return em_C[ tipo.tipo_base ] + nome + indice;
}

string declara_funcao( string nome, Tipo tipo, vector<string> nomes, vector<Tipo> tipos ) {
  static map<string, string> em_C = inicializaMapEmC();

  insere_funcao_ts( nome, tipo, tipos, nomes );
  if( em_C[ tipo.tipo_base ] == "" ) 
    erro( "Tipo inválido: " + tipo.tipo_base );
    
  insere_var_ts( "Result", tipo );
    
  if( nomes.size() != tipos.size() )
    erro( "Bug no compilador! Nomes e tipos de parametros diferentes." );
      
  string aux = " ";

  for( int i = 0; i < nomes.size(); i++ ) {
    aux += declara_var( nomes[i], tipos[i], false) + 
           (i == nomes.size()-1 ? " " : ", ");
    if( nomes[i][0] == '&' )
      nomes[i] = nomes[i].substr(1);
    int tam = nomes[i].size()-1;
    while( nomes[i][tam] == '[' || nomes[i][tam] == ']' )
      tam--;
    nomes[i] = nomes[i].substr(0,tam+1);
    insere_var_ts( nomes[i], tipos[i] );
    if( tipos[i].ndim == MATRIZ ) {
        insere_var_rc_ts( nomes[i] );
    }
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
                                             var_teste_fim2 + ";\n" +

                  "  " + var_teste1 + " = " + var_teste1 + " && " + 
                                             var_teste2 + ";\n";

      codigo += "  if( " + var_teste1 + " ) goto " + label_end + ";\n" +
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
