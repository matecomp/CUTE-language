/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

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


#line 165 "y.tab.c" /* yacc.c:339  */

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
    TK_IF = 264,
    TK_ELSE = 265,
    TK_MAIG = 266,
    TK_MEIG = 267,
    TK_DIF = 268,
    TK_EQUAL = 269,
    TK_AND = 270,
    TK_OR = 271,
    TK_FOR = 272,
    TK_WHILE = 273,
    TK_DOWHILE = 274,
    TK_SWITCH = 275,
    TK_PTPT = 276,
    TK_INT = 277,
    TK_CHAR = 278,
    TK_BOOL = 279,
    TK_DOUBLE = 280,
    TK_STRING = 281,
    TK_TEXTO = 282,
    TK_ID = 283,
    TK_INTEIRO = 284,
    TK_REAL = 285,
    TK_WRITELN = 286,
    TK_WRITE = 287
  };
#endif
/* Tokens.  */
#define TK_PROGRAM 258
#define TK_BEGIN 259
#define TK_END 260
#define TK_MBEGIN 261
#define TK_MEND 262
#define TK_ATRIB 263
#define TK_IF 264
#define TK_ELSE 265
#define TK_MAIG 266
#define TK_MEIG 267
#define TK_DIF 268
#define TK_EQUAL 269
#define TK_AND 270
#define TK_OR 271
#define TK_FOR 272
#define TK_WHILE 273
#define TK_DOWHILE 274
#define TK_SWITCH 275
#define TK_PTPT 276
#define TK_INT 277
#define TK_CHAR 278
#define TK_BOOL 279
#define TK_DOUBLE 280
#define TK_STRING 281
#define TK_TEXTO 282
#define TK_ID 283
#define TK_INTEIRO 284
#define TK_REAL 285
#define TK_WRITELN 286
#define TK_WRITE 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 277 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   339

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,    45,    38,    36,    43,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      33,    35,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   127,   127,   135,   139,   142,   145,   156,   168,   183,
     184,   185,   186,   187,   190,   193,   198,   202,   202,   208,
     210,   212,   215,   216,   217,   218,   219,   222,   223,   226,
     248,   250,   254,   261,   267,   278,   288,   301,   303,   305,
     307,   309,   311,   313,   315,   317,   319,   321,   323,   325,
     327,   330,   331,   333,   335,   340,   342,   358
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PROGRAM", "TK_BEGIN", "TK_END",
  "TK_MBEGIN", "TK_MEND", "TK_ATRIB", "TK_IF", "TK_ELSE", "TK_MAIG",
  "TK_MEIG", "TK_DIF", "TK_EQUAL", "TK_AND", "TK_OR", "TK_FOR", "TK_WHILE",
  "TK_DOWHILE", "TK_SWITCH", "TK_PTPT", "TK_INT", "TK_CHAR", "TK_BOOL",
  "TK_DOUBLE", "TK_STRING", "TK_TEXTO", "TK_ID", "TK_INTEIRO", "TK_REAL",
  "TK_WRITELN", "TK_WRITE", "'<'", "'>'", "'='", "'+'", "'-'", "'*'",
  "'/'", "';'", "'['", "']'", "','", "'('", "')'", "$accept", "S",
  "PROGRAM", "VARS", "VAR", "TIPO", "IDS", "MAIN", "BLOCO", "$@1", "CMDS",
  "CMD", "LOOP", "CMD_FOR", "CMD_IF", "WRITELN", "WRITE", "ATRIB", "E",
  "F", "NOME_VAR", YY_NULLPTR
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
     285,   286,   287,    60,    62,    61,    43,    45,    42,    47,
      59,    91,    93,    44,    40,    41
};
# endif

#define YYPACT_NINF -39

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-39)))

#define YYTABLE_NINF -22

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-22)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -18,    14,   -20,   -24,   -39,   -39,   -39,   -39,   -39,
     -39,    17,   -13,    16,   -39,    44,   -39,   -20,   -39,   -30,
     -39,    42,   -39,    21,    23,   264,   -39,    31,   -39,    30,
      25,     0,    10,    11,   -39,   -39,    56,    22,   264,   -39,
     -39,   -39,   -39,   -39,    43,   -39,    34,   -39,   -39,    30,
      52,   -39,   -39,    68,    30,    30,    30,    30,   -39,   264,
     -39,    35,    30,    95,   264,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,   286,   175,
     130,   140,   -39,    37,   182,   -39,    76,   293,   293,   293,
     286,   300,   286,   293,   293,     8,     8,    29,    29,   228,
       1,   -39,   -39,    53,    54,    73,    30,    30,    30,    63,
      30,    89,    88,   286,   189,    65,   221,   264,   264,    90,
      55,   -39,    91,   100,    30,   -39,   -39,   -39,   286
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     0,     1,    10,    12,    11,     9,
      13,     0,     0,     0,     3,     0,     2,     5,    15,     6,
      17,     0,     4,     0,     0,     5,    16,     0,    14,     0,
       0,     0,     0,     0,    26,    25,     0,     0,     5,    28,
      27,    23,    22,    24,     0,    54,    55,    52,    53,     0,
       0,    50,    51,     0,     0,     0,     0,     0,    18,     5,
      20,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,     0,
       0,     0,    19,     7,     0,    49,     0,    44,    43,    46,
      45,    47,    48,    41,    42,    37,    38,    39,    40,     0,
       0,    32,    33,     0,    56,    30,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     5,     5,     0,
       0,    57,     0,     0,     0,     8,    31,    29,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -39,    -2,   -39,   -39,   -39,   -39,    97,   -39,
     -38,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -37,   -39,
      83
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    34,    12,    13,    19,    16,    35,    25,
      36,    37,    38,    39,    40,    41,    42,    43,    50,    51,
      52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    11,     6,     7,     8,     9,    10,     1,    54,   107,
       4,    23,    63,    24,     5,    22,    14,    78,    79,    80,
      81,    82,    68,    15,    70,    84,    86,    17,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    55,   108,    68,    18,    70,    75,    76,    20,    26,
      27,    28,    44,    46,    56,    57,    64,    45,    46,    47,
      48,    58,    59,    65,    66,    67,    68,    69,    70,   112,
     113,   114,    61,   116,    49,    62,    77,    83,   103,   122,
     123,   105,   109,   111,   115,    71,    72,   128,    73,    74,
      75,    76,   118,   117,   120,   110,   126,   125,   124,    65,
      66,    67,    68,    69,    70,   127,    65,    66,    67,    68,
      69,    70,    21,    53,     0,     0,     0,     0,     0,     0,
       0,    71,    72,     0,    73,    74,    75,    76,    71,    72,
       0,    73,    74,    75,    76,     0,     0,     0,     0,     0,
      85,    65,    66,    67,    68,    69,    70,     0,     0,     0,
       0,    65,    66,    67,    68,    69,    70,     0,     0,     0,
       0,     0,     0,    71,    72,     0,    73,    74,    75,    76,
       0,     0,     0,    71,    72,   101,    73,    74,    75,    76,
       0,     0,     0,     0,     0,   102,    65,    66,    67,    68,
      69,    70,     0,    65,    66,    67,    68,    69,    70,     0,
      65,    66,    67,    68,    69,    70,     0,     0,    71,    72,
       0,    73,    74,    75,    76,    71,    72,   100,    73,    74,
      75,    76,    71,    72,   104,    73,    74,    75,    76,     0,
       0,   119,    65,    66,    67,    68,    69,    70,     0,    65,
      66,    67,    68,    69,    70,     0,     0,     0,     0,   106,
       0,     0,     0,     0,    71,    72,     0,    73,    74,    75,
      76,    71,    72,   121,    73,    74,    75,    76,    20,   -21,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,    30,     0,     0,     0,     0,     6,     7,     8,     9,
      10,     0,    31,     0,     0,    32,    33,    65,    66,    67,
      68,    69,    70,     0,   -22,   -22,   -22,    68,     0,    70,
       0,    65,    66,    67,    68,     0,    70,     0,     0,    71,
      72,     0,    73,    74,    75,    76,   -22,   -22,     0,    73,
      74,    75,    76,    71,    72,     0,    73,    74,    75,    76
};

static const yytype_int8 yycheck[] =
{
      38,     3,    22,    23,    24,    25,    26,     3,     8,     8,
      28,    41,    49,    43,     0,    17,    40,    54,    55,    56,
      57,    59,    14,     6,    16,    62,    64,    40,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    41,    41,    14,    28,    16,    38,    39,     4,     7,
      29,    28,    21,    28,    44,    44,     4,    27,    28,    29,
      30,     5,    40,    11,    12,    13,    14,    15,    16,   106,
     107,   108,    29,   110,    44,    41,     8,    42,    41,   117,
     118,     5,    29,    10,    21,    33,    34,   124,    36,    37,
      38,    39,     4,     4,    29,    41,     5,    42,     8,    11,
      12,    13,    14,    15,    16,     5,    11,    12,    13,    14,
      15,    16,    15,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    33,    34,
      -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      45,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      -1,    -1,    -1,    33,    34,    45,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    11,    12,    13,    14,
      15,    16,    -1,    11,    12,    13,    14,    15,    16,    -1,
      11,    12,    13,    14,    15,    16,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    33,    34,    42,    36,    37,
      38,    39,    33,    34,    42,    36,    37,    38,    39,    -1,
      -1,    42,    11,    12,    13,    14,    15,    16,    -1,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    33,    34,    42,    36,    37,    38,    39,     4,     5,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    -1,    28,    -1,    -1,    31,    32,    11,    12,    13,
      14,    15,    16,    -1,    11,    12,    13,    14,    -1,    16,
      -1,    11,    12,    13,    14,    -1,    16,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    33,    34,    -1,    36,
      37,    38,    39,    33,    34,    -1,    36,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    47,    48,    28,     0,    22,    23,    24,    25,
      26,    49,    50,    51,    40,     6,    53,    40,    28,    52,
       4,    54,    49,    41,    43,    55,     7,    29,    28,     9,
      17,    28,    31,    32,    49,    54,    56,    57,    58,    59,
      60,    61,    62,    63,    21,    27,    28,    29,    30,    44,
      64,    65,    66,    66,     8,    41,    44,    44,     5,    40,
      56,    29,    41,    64,     4,    11,    12,    13,    14,    15,
      16,    33,    34,    36,    37,    38,    39,     8,    64,    64,
      64,    64,    56,    42,    64,    45,    56,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      42,    45,    45,    41,    42,     5,    21,     8,    41,    29,
      41,    10,    64,    64,    64,    21,    64,     4,     4,    42,
      29,    42,    56,    56,     8,    42,     5,     5,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    49,    49,    50,    50,    50,    51,
      51,    51,    51,    51,    52,    52,    53,    55,    54,    56,
      56,    56,    57,    57,    57,    57,    57,    58,    58,    59,
      60,    60,    61,    62,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    65,    65,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     3,     0,     2,     7,    12,     1,
       1,     1,     1,     1,     3,     1,     3,     0,     4,     3,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     9,
       5,     9,     4,     4,     3,     6,     9,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     4,     7
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
#line 128 "trabalho.y" /* yacc.c:1646  */
    {
      cout << includes << endl;
      cout << (yyvsp[-1]).c << endl;
      cout << (yyvsp[0]).c << endl;
    }
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 136 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = ""; }
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 140 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c; }
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 142 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = ""; }
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 146 "trabalho.y" /* yacc.c:1646  */
    {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( (yyvsp[-1]).v ) ); 
        
        (yyval) = Atributos();
        
        for( int i = 0; i < (yyvsp[0]).lista.size(); i++ ) {
          (yyval).c += declara_variavel( (yyvsp[0]).lista[i], tipo );
          insere_ts( (yyvsp[0]).lista[i], tipo );
        }
      }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 157 "trabalho.y" /* yacc.c:1646  */
    {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( (yyvsp[-6]).v ), 
                          toInt( (yyvsp[-3]).v ), toInt( (yyvsp[-1]).v ) );
        
        (yyval) = Atributos();
        
        for( int i = 0; i < (yyvsp[-5]).lista.size(); i++ ) {
          (yyval).c += declara_variavel( (yyvsp[-5]).lista[i], tipo );
          insere_ts( (yyvsp[-5]).lista[i], tipo );
        }
      }
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 169 "trabalho.y" /* yacc.c:1646  */
    {
        Tipo tipo = Tipo( traduz_nome_tipo_variavel( (yyvsp[-11]).v ), 
                          toInt( (yyvsp[-8]).v ), toInt( (yyvsp[-6]).v ),
			  toInt( (yyvsp[-3]).v ), toInt( (yyvsp[-1]).v ) );
        
        (yyval) = Atributos();
        
        for( int i = 0; i < (yyvsp[-10]).lista.size(); i++ ) {
          (yyval).c += declara_variavel( (yyvsp[-10]).lista[i], tipo );
          insere_ts( (yyvsp[-10]).lista[i], tipo );
        }
      }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 191 "trabalho.y" /* yacc.c:1646  */
    { (yyval)  = (yyvsp[-2]);
        (yyval).lista.push_back( (yyvsp[0]).v ); }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 194 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributos();
        (yyval).lista.push_back( (yyvsp[0]).v ); }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 199 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = "int main()\n" + (yyvsp[-1]).c; }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 202 "trabalho.y" /* yacc.c:1646  */
    { var_temp.push_back( "" );}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 203 "trabalho.y" /* yacc.c:1646  */
    { string vars = var_temp[var_temp.size()-1];
          var_temp.pop_back();
          (yyval).c = "{\n" + vars + (yyvsp[-1]).c + "}\n"; }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 209 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c; }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 211 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 212 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = ""; }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 227 "trabalho.y" /* yacc.c:1646  */
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
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 249 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_if( (yyvsp[-3]), (yyvsp[-1]).c, "" ); }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 251 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_if( (yyvsp[-7]), (yyvsp[-5]).c, (yyvsp[-1]).c ); }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 255 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + 
                   "  cout << " + (yyvsp[-1]).v + ";\n"
                   "  cout << endl;\n";
          }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 262 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + 
                   "  cout << " + (yyvsp[-1]).v + ";\n";
          }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 268 "trabalho.y" /* yacc.c:1646  */
    { // Falta verificar se pode atribuir (perde ponto se não fizer).
          (yyvsp[-2]).t = consulta_ts( (yyvsp[-2]).v ) ;
          
          if( (yyvsp[-2]).t.tipo_base == "s" ) 
            (yyval).c = (yyvsp[0]).c + "  strncpy( " + (yyvsp[-2]).v + ", " + (yyvsp[0]).v + ", 256 );\n";
          else
            (yyval).c = (yyvsp[0]).c + "  " + (yyvsp[-2]).v + " = " + (yyvsp[0]).v + ";\n"; 
            
          debug( "ATRIB : TK_ID TK_ATRIB E ';'", (yyval) );
        }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 279 "trabalho.y" /* yacc.c:1646  */
    { // Falta testar: tipo, limite do array, e se a variável existe
          (yyvsp[-5]).t = consulta_ts( (yyvsp[-5]).v ) ;
          if( (yyvsp[-5]).t.tipo_base != (yyvsp[0]).t.tipo_base ) {
             erro( "Atribuicao entre tipos diferentes" );
		  }
          (yyval).c = (yyvsp[-3]).c + (yyvsp[0]).c +
                 gera_teste_limite_array( (yyvsp[-5]).t, (yyvsp[-3]).v ) +   
                 "  " + (yyvsp[-5]).v + "[" + (yyvsp[-3]).v + "] = " + (yyvsp[0]).v + ";\n";
        }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 289 "trabalho.y" /* yacc.c:1646  */
    { // Falta testar: tipo, limite do array, e se a variável existe
          (yyvsp[-8]).t = consulta_ts( (yyvsp[-8]).v ) ;
          string aux = gera_nome_var_temp( (yyvsp[-6]).t.tipo_base );
		  string tam = toString((yyvsp[-8]).t.fim[1] - (yyvsp[-8]).t.inicio[1] + 1);
          (yyval).c = (yyvsp[-6]).c + (yyvsp[-3]).c + (yyvsp[0]).c +
                 gera_teste_limite_array( (yyvsp[-8]).t, (yyvsp[-6]).v, (yyvsp[-3]).v ) +   
				 "  " + aux  + " = " + tam  + "*" + (yyvsp[-6]).v + ";\n" +
				 "  " + aux  + " = " + aux  + "+" + (yyvsp[-3]).v + ";\n" +
                 "  " + (yyvsp[-8]).v + "[" + aux + "] = " + (yyvsp[0]).v + ";\n";
        }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 302 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "+", (yyvsp[0]) ); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 304 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "-", (yyvsp[0]) ); }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 306 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "*", (yyvsp[0]) ); }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 308 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "/", (yyvsp[0]) ); }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 310 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "<", (yyvsp[0]) ); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 312 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), ">", (yyvsp[0]) ); }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 314 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "<=", (yyvsp[0]) ); }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 316 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), ">=", (yyvsp[0]) ); }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 318 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "==", (yyvsp[0]) ); }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 320 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "!=", (yyvsp[0]) ); }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 322 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "&&", (yyvsp[0]) ); }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 324 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "||", (yyvsp[0]) ); }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 326 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 332 "trabalho.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; (yyval).t = Tipo( "i" ); (yyval).c = (yyvsp[0]).c; }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 334 "trabalho.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; (yyval).t = Tipo( "d" ); (yyval).c = (yyvsp[0]).c; }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 336 "trabalho.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; (yyval).t = Tipo( "s" ); (yyval).c = (yyvsp[0]).c; }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 341 "trabalho.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; (yyval).t = consulta_ts( (yyvsp[0]).v ); (yyval).c = (yyvsp[0]).c; }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 343 "trabalho.y" /* yacc.c:1646  */
    { 
           Tipo tipoArray = consulta_ts( (yyvsp[-3]).v );
           (yyval).t = Tipo( tipoArray.tipo_base );
           if( tipoArray.ndim != 1 )
             erro( "Variável " + (yyvsp[-3]).v + " não é array de uma dimensão" );
        
           if( (yyvsp[-1]).t.ndim != 0 || (yyvsp[-1]).t.tipo_base != "i" )
             erro( "Indice de array deve ser integer de zero dimensão: " +
               (yyvsp[-1]).t.tipo_base + "/" + toString( (yyvsp[-1]).t.ndim ) );
        
           (yyval).v = gera_nome_var_temp( (yyval).t.tipo_base );
           (yyval).c = (yyvsp[-1]).c +
           gera_teste_limite_array( tipoArray, (yyvsp[-1]).v ) +   
             "  " + (yyval).v + " = " + (yyvsp[-3]).v + "[" + (yyvsp[-1]).v + "];\n";
          }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 359 "trabalho.y" /* yacc.c:1646  */
    { 
            Tipo tipoArray = consulta_ts( (yyvsp[-6]).v );
            (yyval).t = Tipo( tipoArray.tipo_base );
            if( tipoArray.ndim != 2 )
              erro( "Variável " + (yyvsp[-6]).v + " não é array de duas dimensões" );
        
            if( (yyvsp[-4]).t.ndim != 0 || (yyvsp[-4]).t.tipo_base != "i" || (yyvsp[-1]).t.tipo_base != "i" )
              erro( "Indice de array deve ser integer de zero dimensão: " +
                (yyvsp[-4]).t.tipo_base + "/" + toString( (yyvsp[-4]).t.ndim ) );

            string aux = gera_nome_var_temp( (yyvsp[-1]).t.tipo_base );
		    string tam = toString(tipoArray.fim[1]-tipoArray.inicio[1]+1);
            (yyval).v = gera_nome_var_temp( (yyval).t.tipo_base );
            (yyval).c = (yyvsp[-4]).c +
              gera_teste_limite_array( tipoArray, (yyvsp[-4]).v, (yyvsp[-1]).v ) +   
              "  " + aux  + " = " + tam + " * " + (yyvsp[-4]).v + ";\n" +
              "  " + aux  + " = " + aux + " + " + (yyvsp[-1]).v + ";\n" +
              "  " + (yyval).v + " = " + (yyvsp[-6]).v + "[" + aux + "];\n";
    }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1847 "y.tab.c" /* yacc.c:1646  */
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
#line 382 "trabalho.y" /* yacc.c:1906  */

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
