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
#line 1 "src/parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "traduc.h"
int yyparse();
int yylex();
int yyerror(char *s);
extern int lineno;
extern int c;
extern char linebuf[500];
Node *arbre;

#line 80 "src/parser.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_SRC_PARSER_H_INCLUDED
# define YY_YY_SRC_PARSER_H_INCLUDED
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
    NUM = 258,
    CHARACTER = 259,
    IDENT = 260,
    TYPE = 261,
    EQ = 262,
    ORDER = 263,
    OR = 264,
    AND = 265,
    ADDSUB = 266,
    RETURN = 267,
    IF = 268,
    PRINT = 269,
    READC = 270,
    READE = 271,
    VOID = 272,
    WHILE = 273,
    else_priority = 274,
    ELSE = 275
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "src/parser.y" /* yacc.c:355  */

    Node *node;
    char id[100];
    char type[100];
    int num;
    char caractere;
    char comp[100];
    char addsub;
    char cond_logical[100];
    char condition[100];
    char print[100];
    char read[100];
    char boucle[100];

#line 156 "src/parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 173 "src/parser.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,     2,     2,    30,    32,     2,
      24,    25,    23,     2,    22,     2,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    21,
       2,    28,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    49,    49,    62,    72,    74,    81,    90,    96,   106,
     111,   117,   123,   135,   149,   158,   161,   167,   179,   193,
     204,   218,   229,   234,   236,   241,   247,   253,   257,   264,
     274,   283,   289,   293,   296,   299,   301,   306,   310,   315,
     319,   329,   333,   349,   353,   363,   367,   372,   377,   382,
     386,   395,   399,   405,   408,   412,   416,   419,   424,   433,
     437,   445,   449,   451,   456
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "CHARACTER", "IDENT", "TYPE",
  "EQ", "ORDER", "OR", "AND", "ADDSUB", "RETURN", "IF", "PRINT", "READC",
  "READE", "VOID", "WHILE", "else_priority", "ELSE", "';'", "','", "'*'",
  "'('", "')'", "'{'", "'}'", "'='", "'/'", "'%'", "'!'", "'&'", "$accept",
  "Prog", "DeclVars", "Declarateurs", "DeclFoncts", "DeclFonct",
  "EnTeteFonct", "Parametres", "ListTypVar", "Corps", "SuiteInstr",
  "Instr", "Exp", "TB", "FB", "M", "E", "T", "F", "LValue", "Arguments",
  "ListExp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    59,    44,    42,    40,    41,   123,   125,    61,    47,
      37,    33,    38
};
# endif

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -92,    15,    10,   -92,    -2,    36,    44,   -92,    37,    62,
      66,    -3,    68,     9,   -92,   -92,   -92,    52,    84,   -92,
      17,    52,    62,    90,   107,    26,   -92,    91,    93,    52,
     -92,   112,    95,    84,    42,    41,   -92,   116,   -92,   117,
      97,   -92,   -92,   -92,   119,   101,     2,   102,   103,   104,
     105,   106,   -92,   126,   -92,   -92,   -92,   108,   -92,    47,
     -92,   -92,     6,   -92,   -92,   109,     6,   -92,   127,     6,
       6,   129,    39,   125,   130,   131,   132,    89,   -92,   -92,
       6,     6,   133,   135,     6,   -92,    61,     6,   -92,   136,
     137,   120,   122,     6,   -92,   118,    71,   -92,   -92,     6,
     -92,     6,     6,     6,     6,     6,     6,     6,    74,    80,
     123,   124,    82,   -92,    69,   -92,   134,     6,   128,     6,
     -92,   125,   130,   131,   132,    89,   -92,   -92,   -92,    88,
     138,   139,   140,    88,   -92,   -92,   137,   -92,   141,   142,
     -92,   -92,   -92,   -92,   -92,    88,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     2,    10,     0,     7,
       0,     0,     0,     0,     9,     4,    11,     0,     8,     3,
       0,     0,     0,     0,    23,     0,    15,     0,    16,     0,
       5,     0,     0,     0,     0,     0,    19,     0,    12,     0,
       0,     6,    14,     7,     0,    59,     0,     0,     0,     0,
       0,     0,    35,     0,    23,    21,    22,     0,    20,     0,
      13,     8,    62,    54,    55,    59,     0,    33,     0,     0,
       0,     0,     0,    37,    39,    41,    43,    45,    49,    56,
       0,     0,     0,     0,     0,    60,     0,     0,    17,     0,
      64,     0,    61,    62,    50,    60,     0,    51,    52,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,    18,     0,     0,     0,    62,
      53,    36,    38,    40,    42,    44,    46,    47,    48,     0,
       0,     0,     0,     0,    24,    31,    63,    57,     0,    28,
      27,    26,    25,    30,    58,     0,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   143,   -92,   -92,   144,   -92,    -9,   -92,   -92,
      98,   -48,   -45,    48,    50,    54,    51,    53,   -62,   -35,
     -91,   -92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    11,     6,     7,     8,    27,    28,    16,
      35,    56,    90,    73,    74,    75,    76,    77,    78,    79,
      91,    92
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    72,   118,     9,    94,    63,    64,    65,    97,    63,
      64,    65,    32,    66,    22,     3,     4,    66,    19,    20,
      40,    10,    30,    67,    96,    68,    69,     5,   138,    68,
      69,    36,    23,    70,    71,   108,   109,    70,    71,   112,
      31,    12,   114,   126,   127,   128,    45,    43,    99,    37,
      13,    57,    88,    46,    47,    48,    49,    50,    25,    51,
     100,     5,    52,    15,    53,    44,    45,    54,    55,    26,
      89,    18,   136,    46,    47,    48,    49,    50,    99,    51,
      99,   139,    52,    99,    53,   143,    17,    54,   113,    99,
     134,    99,    21,    45,    57,    33,   120,   146,    57,   129,
      46,    47,    48,    49,    50,   130,    51,   133,    29,    52,
      57,    53,   105,    34,    54,    39,    38,    41,   106,   107,
      42,    58,    60,    59,    61,    62,    80,    81,    82,    83,
      84,    85,    95,    93,    98,   101,    87,   102,   110,   103,
     111,   115,   119,   104,   117,   116,    99,   121,   131,   132,
      14,   122,    86,   137,   124,   135,   123,   125,    24,   140,
     141,   142,   145,     0,     0,     0,   144
};

static const yytype_int16 yycheck[] =
{
      35,    46,    93,     5,    66,     3,     4,     5,    70,     3,
       4,     5,    21,    11,     5,     0,     6,    11,    21,    22,
      29,    23,     5,    21,    69,    23,    24,    17,   119,    23,
      24,     5,    23,    31,    32,    80,    81,    31,    32,    84,
      23,     5,    87,   105,   106,   107,     5,     5,     9,    23,
       6,    86,     5,    12,    13,    14,    15,    16,     6,    18,
      21,    17,    21,    26,    23,    23,     5,    26,    27,    17,
      23,     5,   117,    12,    13,    14,    15,    16,     9,    18,
       9,   129,    21,     9,    23,   133,    24,    26,    27,     9,
      21,     9,    24,     5,   129,     5,    25,   145,   133,    25,
      12,    13,    14,    15,    16,    25,    18,    25,    24,    21,
     145,    23,    23,     6,    26,    22,    25,     5,    29,    30,
      25,     5,    25,     6,     5,    24,    24,    24,    24,    24,
      24,     5,     5,    24,     5,    10,    28,     7,     5,     8,
       5,     5,    24,    11,    22,    25,     9,    99,    25,    25,
       6,   101,    54,    25,   103,    21,   102,   104,    15,    21,
      21,    21,    20,    -1,    -1,    -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    35,     0,     6,    17,    37,    38,    39,     5,
      23,    36,     5,     6,    38,    26,    42,    24,     5,    21,
      22,    24,     5,    23,    35,     6,    17,    40,    41,    24,
       5,    23,    40,     5,     6,    43,     5,    23,    25,    22,
      40,     5,    25,     5,    23,     5,    12,    13,    14,    15,
      16,    18,    21,    23,    26,    27,    44,    52,     5,     6,
      25,     5,    24,     3,     4,     5,    11,    21,    23,    24,
      31,    32,    45,    46,    47,    48,    49,    50,    51,    52,
      24,    24,    24,    24,    24,     5,    43,    28,     5,    23,
      45,    53,    54,    24,    51,     5,    45,    51,     5,     9,
      21,    10,     7,     8,    11,    23,    29,    30,    45,    45,
       5,     5,    45,    27,    45,     5,    25,    22,    53,    24,
      25,    46,    47,    48,    49,    50,    51,    51,    51,    25,
      25,    25,    25,    25,    21,    21,    45,    25,    53,    44,
      21,    21,    21,    44,    25,    20,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    36,    36,    37,
      37,    38,    39,    39,    39,    40,    40,    41,    41,    41,
      41,    42,    43,    43,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    45,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    50,    50,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    52,
      52,    53,    53,    54,    54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     0,     3,     4,     1,     2,     2,
       1,     2,     5,     6,     5,     1,     1,     4,     5,     2,
       3,     4,     2,     0,     4,     5,     5,     5,     5,     7,
       5,     5,     3,     2,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     3,     1,     1,     1,     4,     5,     1,
       2,     1,     0,     3,     1
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
#line 49 "src/parser.y" /* yacc.c:1646  */
    {
                                (yyval.node) = makeNode(Program);
                                Node *tmp = makeNode(VarDeclList);
                                Node *tmp2 = makeNode(FunDeclList);
                                addChild((yyval.node), tmp);
                                addChild(tmp, (yyvsp[-1].node));
                                addChild((yyval.node), tmp2);
                                addChild(tmp2, (yyvsp[0].node));
                                /*printTree($$);*/
                                arbre = (yyval.node); 
                            }
#line 1355 "src/parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 62 "src/parser.y" /* yacc.c:1646  */
    {
                                        if(strcmp((yyvsp[-2].type), "int") == 0){
                                            (yyval.node) = makeNode(Int);
                                        }
                                        else{
                                            (yyval.node) = makeNode(Char);
                                        }
                                        addSibling((yyval.node), (yyvsp[-3].node));
                                        addChild((yyval.node), (yyvsp[-1].node));
                                    }
#line 1370 "src/parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 72 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1376 "src/parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 74 "src/parser.y" /* yacc.c:1646  */
    {
                                (yyval.node) = makeNode(VarDec);
                                addSibling((yyval.node), (yyvsp[-2].node));
                                Node *node = makeNode(Identifier);
                                strcpy(node->u.identifier, (yyvsp[0].id));
                                addChild((yyval.node), node);
                            }
#line 1388 "src/parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 81 "src/parser.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = makeNode(VarDec);
                                    addSibling((yyval.node), (yyvsp[-3].node));
                                    Node *node = makeNode(Pointeur);
                                    addChild((yyval.node), node);
                                    Node *node_id = makeNode(Identifier);
                                    strcpy(node_id->u.identifier, (yyvsp[0].id));
                                    addChild(node, node_id);
                                }
#line 1402 "src/parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 90 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.node) = makeNode(VarDec);
                Node *node = makeNode(Identifier);
                strcpy(node->u.identifier, (yyvsp[0].id));
                addChild((yyval.node), node);
            }
#line 1413 "src/parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 96 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = makeNode(VarDec);
                    Node *node = makeNode(Pointeur);
                    addChild((yyval.node), node);
                    Node *node_id = makeNode(Identifier);
                    strcpy(node_id->u.identifier, (yyvsp[0].id));
                    addChild(node, node_id);
                }
#line 1426 "src/parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 106 "src/parser.y" /* yacc.c:1646  */
    {
                                (yyval.node) = makeNode(FunDec);
                                addSibling((yyval.node), (yyvsp[-1].node));
                                addChild((yyval.node), (yyvsp[0].node));
                            }
#line 1436 "src/parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 111 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = makeNode(FunDec);
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1445 "src/parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 117 "src/parser.y" /* yacc.c:1646  */
    {
                            (yyval.node) = (yyvsp[-1].node);
                            addSibling((yyval.node), (yyvsp[0].node));
                        }
#line 1454 "src/parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 123 "src/parser.y" /* yacc.c:1646  */
    {
                                        if(strcmp((yyvsp[-4].type), "int") == 0){
                                            (yyval.node) = makeNode(Int);
                                        }
                                        else{
                                            (yyval.node) = makeNode(Char);
                                        }
                                        Node *node = makeNode(Identifier);
                                        strcpy(node->u.identifier, (yyvsp[-3].id));
                                        addChild((yyval.node), node);
                                        addChild((yyval.node), (yyvsp[-1].node));
                                    }
#line 1471 "src/parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 135 "src/parser.y" /* yacc.c:1646  */
    {
                                            if(strcmp((yyvsp[-5].type), "int") == 0){
                                                (yyval.node) = makeNode(Int);
                                            }
                                            else{
                                                (yyval.node) = makeNode(Char);
                                            }
                                            Node *node = makeNode(Pointeur);
                                            addChild((yyval.node), node); 
                                            Node *node_id = makeNode(Identifier);
                                            strcpy(node_id->u.identifier, (yyvsp[-3].id));
                                            addChild((yyval.node), node_id);
                                            addChild((yyval.node), (yyvsp[-1].node));
                                    }
#line 1490 "src/parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 149 "src/parser.y" /* yacc.c:1646  */
    {
                                        (yyval.node) = makeNode(Void);
                                        Node *node_id = makeNode(Identifier);
                                        strcpy(node_id->u.identifier, (yyvsp[-3].id));
                                        addChild((yyval.node), node_id);
                                        addChild((yyval.node), (yyvsp[-1].node));
                                    }
#line 1502 "src/parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 158 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.node) = makeNode(ParamList);
            }
#line 1510 "src/parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 161 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = makeNode(ParamList);
                    addChild((yyval.node), (yyvsp[0].node));
                    }
#line 1519 "src/parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 167 "src/parser.y" /* yacc.c:1646  */
    {
                                    if(strcmp((yyvsp[-1].type), "int") == 0){
                                        (yyval.node) = makeNode(Int);
                                    }
                                    else{
                                        (yyval.node) = makeNode(Char);
                                    }
                                    addSibling((yyval.node), (yyvsp[-3].node));
                                    Node *node_id = makeNode(Identifier);
                                    strcpy(node_id->u.identifier, (yyvsp[0].id));
                                    addChild((yyval.node), node_id);                               
                                }
#line 1536 "src/parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 179 "src/parser.y" /* yacc.c:1646  */
    {
                                        if(strcmp((yyvsp[-2].type), "int") == 0){
                                            (yyval.node) = makeNode(Int);
                                        }
                                        else{
                                            (yyval.node) = makeNode(Char);
                                        }
                                        addSibling((yyval.node), (yyvsp[-4].node));
                                        Node *node = makeNode(Pointeur);
                                        addChild((yyval.node), node);
                                        Node *node_id = makeNode(Identifier);
                                        strcpy(node_id->u.identifier, (yyvsp[0].id));
                                        addChild(node, node_id);
                                    }
#line 1555 "src/parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 193 "src/parser.y" /* yacc.c:1646  */
    {
                        if(strcmp((yyvsp[-1].type), "int") == 0){
                            (yyval.node) = makeNode(Int);
                        }
                        else{
                            (yyval.node) = makeNode(Char);
                        }
                        Node *node_id = makeNode(Identifier);
                        strcpy(node_id->u.identifier, (yyvsp[0].id));
                        addChild((yyval.node), node_id);                    
                    }
#line 1571 "src/parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 204 "src/parser.y" /* yacc.c:1646  */
    {
                        if(strcmp((yyvsp[-2].type), "int") == 0){
                            (yyval.node) = makeNode(Int);
                        }
                        else{
                            (yyval.node) = makeNode(Char);
                        }
                        Node *node = makeNode(Pointeur);
                        addChild((yyval.node), node); 
                        Node *node_id = makeNode(Identifier);
                        strcpy(node_id->u.identifier, (yyvsp[0].id));
                        addChild(node, node_id);                     
                    }
#line 1589 "src/parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 218 "src/parser.y" /* yacc.c:1646  */
    {
                                        (yyval.node) = makeNode(Body);
                                        Node *tmp = makeNode(VarDeclList);
                                        Node *tmp2 = makeNode(SuiteInstr);
                                        addChild((yyval.node), tmp);
                                        addChild(tmp, (yyvsp[-2].node));
                                        addChild((yyval.node), tmp2);
                                        addChild(tmp2, (yyvsp[-1].node));                                  
                                    }
#line 1603 "src/parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 229 "src/parser.y" /* yacc.c:1646  */
    {
                            (yyval.node) = makeNode(Instr);
                            addSibling((yyval.node), (yyvsp[-1].node));
                            addChild((yyval.node), (yyvsp[0].node));
                        }
#line 1613 "src/parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 234 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1619 "src/parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 236 "src/parser.y" /* yacc.c:1646  */
    {
                            (yyval.node) = makeNode(Assign);
                            addChild((yyval.node), (yyvsp[-3].node));
                            addChild((yyval.node), (yyvsp[-1].node));
                          }
#line 1629 "src/parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 241 "src/parser.y" /* yacc.c:1646  */
    {
                                (yyval.node) = makeNode(ReadE);
                                Node *node_id = makeNode(Identifier);
                                strcpy(node_id->u.identifier, (yyvsp[-2].id));
                                addChild((yyval.node), node_id);                                
                                }
#line 1640 "src/parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 247 "src/parser.y" /* yacc.c:1646  */
    {
                                (yyval.node) = makeNode(ReadC);
                                Node *node_id = makeNode(Identifier);
                                strcpy(node_id->u.identifier, (yyvsp[-2].id));
                                addChild((yyval.node), node_id);
                                }
#line 1651 "src/parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 253 "src/parser.y" /* yacc.c:1646  */
    {
                                (yyval.node) = makeNode(Print);
                                addChild((yyval.node), (yyvsp[-2].node));
                            }
#line 1660 "src/parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 257 "src/parser.y" /* yacc.c:1646  */
    {
                                                        (yyval.node) = makeNode(Condition);
                                                        addChild((yyval.node), (yyvsp[-2].node));
                                                        Node *node = makeNode(ConditionTrue);
                                                        addChild((yyval.node), node);
                                                        addChild(node, (yyvsp[0].node));
                                                    }
#line 1672 "src/parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 264 "src/parser.y" /* yacc.c:1646  */
    {
                                            (yyval.node) = makeNode(Condition);
                                            addChild((yyval.node), (yyvsp[-4].node));
                                            Node *node_if = makeNode(ConditionTrue);
                                            addChild((yyval.node), node_if);
                                            addChild(node_if, (yyvsp[-2].node));
                                            Node *node_else = makeNode(Else);
                                            addChild((yyval.node), node_else);
                                            addChild(node_else, (yyvsp[0].node));
                                        }
#line 1687 "src/parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 274 "src/parser.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = makeNode(WhileBoucle);
                                    Node *node = makeNode(Condition);
                                    addChild((yyval.node), node);
                                    addChild(node, (yyvsp[-2].node));
                                    Node *node_true = makeNode(ConditionTrue);
                                    addChild((yyval.node), node_true);
                                    addChild(node_true, (yyvsp[0].node));
                                }
#line 1701 "src/parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 283 "src/parser.y" /* yacc.c:1646  */
    {
                                        (yyval.node) = makeNode(Identifier);
                                        strcpy((yyval.node)->u.identifier, (yyvsp[-4].id));
                                        Node *node = makeNode(ArgList);                                        
                                        addChild(node, (yyvsp[-2].node));
                                    }
#line 1712 "src/parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 289 "src/parser.y" /* yacc.c:1646  */
    {
                            (yyval.node) = makeNode(Return);
                            addChild((yyval.node), (yyvsp[-1].node));
                          }
#line 1721 "src/parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 293 "src/parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = makeNode(Return);
                    }
#line 1729 "src/parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 296 "src/parser.y" /* yacc.c:1646  */
    {
                            (yyval.node) = (yyvsp[-1].node);
                          }
#line 1737 "src/parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 299 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1743 "src/parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 301 "src/parser.y" /* yacc.c:1646  */
    { 
                    (yyval.node) = makeNode(Or);
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1753 "src/parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 306 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 1761 "src/parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 310 "src/parser.y" /* yacc.c:1646  */
    { 
                    (yyval.node) = makeNode(And);
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1771 "src/parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 315 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            }
#line 1779 "src/parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 319 "src/parser.y" /* yacc.c:1646  */
    {
                    if(strcmp((yyvsp[-1].comp), "==") == 0){
                        (yyval.node) = makeNode(Equal);
                    }
                    else{
                        (yyval.node) = makeNode(NotEqual);
                    }
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[0].node));   
                }
#line 1794 "src/parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 329 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 1802 "src/parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 333 "src/parser.y" /* yacc.c:1646  */
    {
                    if(strcmp((yyvsp[-1].comp), "<") == 0){
                        (yyval.node) = makeNode(Less);
                    }
                    else if (strcmp((yyvsp[-1].comp), "<=") == 0){
                        (yyval.node) = makeNode(LessOrEqual);
                    }
                    else if (strcmp((yyvsp[-1].comp), ">") == 0){
                        (yyval.node) = makeNode(Greater);
                    }
                    else{
                        (yyval.node) = makeNode(GreaterOrEqual);
                    }
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[0].node));   
                }
#line 1823 "src/parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 349 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 1831 "src/parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 353 "src/parser.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-1].addsub) == '+'){
                        (yyval.node) = makeNode(Add);
                    }
                    else{
                        (yyval.node) = makeNode(Sub);
                    }
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1846 "src/parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 363 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 1854 "src/parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 367 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = makeNode(Multiply);
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1864 "src/parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 372 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = makeNode(Div);
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1874 "src/parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 377 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = makeNode(Mod);
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1884 "src/parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 382 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 1892 "src/parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 386 "src/parser.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-1].addsub) == '+'){
                        (yyval.node) = makeNode(Add);
                    }
                    else{
                        (yyval.node) = makeNode(Sub);
                    }
                    addChild((yyval.node), (yyvsp[0].node));   
                }
#line 1906 "src/parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 395 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.node) = makeNode(Not);
                addChild((yyval.node), (yyvsp[0].node));
            }
#line 1915 "src/parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 399 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = makeNode(Adress);
                    Node *node_id = makeNode(Identifier);
                    strcpy(node_id->u.identifier, (yyvsp[0].id));
                    addChild((yyval.node), node_id);
                }
#line 1926 "src/parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 405 "src/parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = (yyvsp[-1].node);
                    }
#line 1934 "src/parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 408 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.node) = makeNode(IntLiteral);
                (yyval.node)->u.integer = (yyvsp[0].num);
            }
#line 1943 "src/parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 412 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = makeNode(CharLiteral);
                    (yyval.node)->u.character = (yyvsp[0].caractere);
                }
#line 1952 "src/parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 416 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.node) = (yyvsp[0].node);
                }
#line 1960 "src/parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 419 "src/parser.y" /* yacc.c:1646  */
    {
                                        (yyval.node) = makeNode(Identifier);
                                        strcpy((yyval.node)->u.identifier, (yyvsp[-3].id));
                                        addChild((yyval.node), (yyvsp[-1].node));
                                }
#line 1970 "src/parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 424 "src/parser.y" /* yacc.c:1646  */
    {
                                        (yyval.node) = makeNode(Pointeur); 
                                        Node *node_id = makeNode(Identifier);
                                        strcpy(node_id->u.identifier, (yyvsp[-3].id));
                                        addChild((yyval.node), node_id);
                                        addChild(node_id, (yyvsp[-1].node));
                                    }
#line 1982 "src/parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 433 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.node) = makeNode(Identifier);
                strcpy((yyval.node)->u.identifier, (yyvsp[0].id));
            }
#line 1991 "src/parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 437 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = makeNode(Pointeur);
                    Node *node = makeNode(Identifier);
                    strcpy(node->u.identifier, (yyvsp[0].id));
                    addChild((yyval.node), node);
                }
#line 2002 "src/parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 445 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.node) = makeNode(ListExpr);
                addChild((yyval.node), (yyvsp[0].node));
                }
#line 2011 "src/parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 449 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2017 "src/parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 451 "src/parser.y" /* yacc.c:1646  */
    {
                            (yyval.node) = makeNode(Expr);
                            addSibling((yyval.node), (yyvsp[-2].node));
                            addChild((yyval.node), (yyvsp[0].node));
                        }
#line 2027 "src/parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 456 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.node) = makeNode(Expr);
                addChild((yyval.node), (yyvsp[0].node));
            }
#line 2036 "src/parser.c" /* yacc.c:1646  */
    break;


#line 2040 "src/parser.c" /* yacc.c:1646  */
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
#line 461 "src/parser.y" /* yacc.c:1906  */


int yyerror(char *s){
	int i;
    if(linebuf != NULL){
	  	fprintf(stderr, "%s near line %d at:\n %s \n", s, lineno, linebuf);
        for (i = 0; i < c - 1; i++){
            printf(" ");
        }
        printf("^\n");
    }
    return 1;
}

int main(int argc, char** argv) {
    if(yyparse() == 0){
        construire_tab(arbre);
        if(erreurs > 0){
            printf("%d erreur(s) détecté(s) dans le programme\n", erreurs);
            return -1;
        }
        else{
            /*afficher_tab();*/
            traduc_into_asm(arbre); /*traduc de l'arbre en fichier asm si celui-ci est correcte*/
        }
        free_tab();
    }
    else if(yyparse() == 1){
        return 1;
    }
    return 0;
}
