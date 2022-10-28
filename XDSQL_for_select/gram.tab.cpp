/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "gram.y"

#include"InitSQL.h"
#include"QueryProcessor.h"
#include<stdio.h>
#include<string.h>
extern int yylex(void);
void yyerror(const char* );
bool exitflag;


/* Line 371 of yacc.c  */
#line 79 "gram.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "gram.tab.h".  */
#ifndef YY_YY_GRAM_TAB_H_INCLUDED
# define YY_YY_GRAM_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     CREATE = 259,
     DROP = 260,
     USE = 261,
     SELECT = 262,
     INSERT = 263,
     DELETE = 264,
     UPDATE = 265,
     FROM = 266,
     WHERE = 267,
     INTO = 268,
     VALUES = 269,
     SET = 270,
     NEWLINE = 271,
     DATABASE = 272,
     DATABASES = 273,
     TABLE = 274,
     null = 275,
     LIKE = 276,
     IN = 277,
     EXISTS = 278,
     TABLES = 279,
     SHOW = 280,
     EXIT = 281,
     BYE = 282,
     CHAR = 283,
     ID = 284,
     STRING = 285,
     INTNUMBER = 286,
     OR = 287,
     AND = 288,
     NOT = 289
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 12 "gram.y"

    /* ID和变量类型 */
	struct values* value;

	/* 建表语句使用类型 */
	struct coltype* coltype;
	struct col* col;
	struct createTablesql* createTablesql;

	/* 插入语句使用类型 */
	struct datanode* datanode;
	struct insertsql* insertsql;


	/* 查询语句使用类型 */
	struct tablecol* tablecol;
	struct tablecolconf* tablecolconf;
	struct condition* condition;
	int comp_op;
	struct comparator* comparator;
	struct selectsql* selectsql;

	/* 更新语句使用类型 */
	struct setconf* setconf;
	struct updatesql* updatesql;

	/* 删除语句使用类型 */
	struct deletesql* deletesql;



/* Line 387 of yacc.c  */
#line 188 "gram.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_GRAM_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 216 "gram.tab.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,     2,    47,     2,     2,
      31,    32,    45,    43,    29,    44,    33,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
      38,    37,    39,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    34,    35,    36,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      43,    48,    53,    55,    59,    63,    71,    73,    77,    79,
      82,    84,    86,    91,    96,   106,   115,   119,   123,   125,
     129,   131,   133,   135,   139,   143,   147,   151,   154,   158,
     160,   167,   173,   175,   177,   181,   183,   187,   189,   193,
     195,   198,   200,   204,   208,   211,   215,   219,   221,   223,
     226,   229,   231,   234,   236,   238,   245,   251,   255,   257,
     261,   267
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    -1,    50,    51,    -1,    16,    -1,    52,
      16,    -1,    59,    -1,    72,    -1,    66,    -1,    82,    -1,
      85,    -1,    65,    -1,    53,    -1,    58,    -1,    54,    -1,
      57,    -1,    55,    -1,    26,    -1,    27,    -1,     4,    17,
      56,    30,    -1,     5,    17,    56,    30,    -1,     6,    17,
      56,    30,    -1,    34,    -1,    25,    18,    30,    -1,    25,
      24,    30,    -1,     4,    19,    60,    31,    61,    32,    30,
      -1,    34,    -1,    61,    29,    62,    -1,    62,    -1,    63,
      64,    -1,    34,    -1,     3,    -1,    28,    31,    36,    32,
      -1,     5,    19,    60,    30,    -1,     8,    13,    60,    67,
      14,    31,    69,    32,    30,    -1,     8,    13,    60,    14,
      31,    69,    32,    30,    -1,    31,    68,    32,    -1,    68,
      29,    63,    -1,    63,    -1,    69,    29,    70,    -1,    70,
      -1,    71,    -1,    35,    -1,    71,    43,    71,    -1,    71,
      44,    71,    -1,    71,    45,    71,    -1,    71,    46,    71,
      -1,    44,    71,    -1,    31,    71,    32,    -1,    36,    -1,
       7,    73,    11,    76,    77,    30,    -1,     7,    73,    11,
      76,    30,    -1,    45,    -1,    74,    -1,    74,    29,    75,
      -1,    75,    -1,    60,    33,    63,    -1,    63,    -1,    76,
      29,    60,    -1,    60,    -1,    12,    78,    -1,    79,    -1,
      78,    41,    78,    -1,    78,    40,    78,    -1,    42,    78,
      -1,    31,    78,    32,    -1,    81,    80,    81,    -1,    38,
      -1,    39,    -1,    38,    37,    -1,    39,    37,    -1,    37,
      -1,    48,    37,    -1,    70,    -1,    75,    -1,    10,    60,
      15,    83,    77,    30,    -1,    10,    60,    15,    83,    30,
      -1,    83,    29,    84,    -1,    84,    -1,    75,    37,    70,
      -1,     9,    11,    60,    77,    30,    -1,     9,    11,    60,
      30,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,    98,   102,   103,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   127,
     130,   133,   136,   139,   146,   149,   156,   158,   165,   167,
     175,   177,   182,   188,   190,   196,   203,   205,   215,   221,
     228,   230,   238,   248,   255,   262,   269,   276,   281,   282,
     284,   290,   297,   302,   308,   315,   317,   323,   330,   340,
     347,   349,   352,   367,   382,   397,   401,   417,   418,   419,
     420,   421,   422,   424,   430,   437,   443,   450,   457,   461,
     469,   474
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "CREATE", "DROP", "USE", "SELECT",
  "INSERT", "DELETE", "UPDATE", "FROM", "WHERE", "INTO", "VALUES", "SET",
  "NEWLINE", "DATABASE", "DATABASES", "TABLE", "null", "LIKE", "IN",
  "EXISTS", "TABLES", "SHOW", "EXIT", "BYE", "CHAR", "','", "';'", "'('",
  "')'", "'.'", "ID", "STRING", "INTNUMBER", "'='", "'<'", "'>'", "OR",
  "AND", "NOT", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "$accept",
  "start", "line", "statement", "createdb", "dropdb", "usedb", "dbname",
  "showdb", "showtable", "createsql", "tablename", "cols", "col",
  "colname", "coltype", "dropsql", "insertsql", "insertcolnames",
  "colnames", "values", "value", "cal", "selectsql", "tablecolconf",
  "tablecols", "tablecol", "tables", "whereconf", "conditions",
  "condition", "comp_op", "comparator", "updatesql", "setconfs", "setconf",
  "deletesql", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    44,
      59,    40,    41,    46,   284,   285,   286,    61,    60,    62,
     287,   288,   289,    43,    45,    42,    47,    37,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    61,    62,
      63,    64,    64,    65,    66,    66,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    78,    78,    78,    78,    78,    79,    80,    80,    80,
      80,    80,    80,    81,    81,    82,    82,    83,    83,    84,
      85,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     1,     3,     3,     7,     1,     3,     1,     2,
       1,     1,     4,     4,     9,     8,     3,     3,     1,     3,
       1,     1,     1,     3,     3,     3,     3,     2,     3,     1,
       6,     5,     1,     1,     3,     1,     3,     1,     3,     1,
       2,     1,     3,     3,     2,     3,     3,     1,     1,     2,
       2,     1,     2,     1,     1,     6,     5,     3,     1,     3,
       5,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       4,     0,    17,    18,     3,     0,    12,    14,    16,    15,
      13,     6,    11,     8,     7,     9,    10,     0,     0,     0,
       0,     0,    30,    52,     0,    57,     0,    53,    55,     0,
       0,    26,     0,     0,     0,     5,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      19,     0,    20,    33,    21,    30,    56,    59,     0,    54,
       0,     0,     0,     0,    81,     0,     0,     0,    78,     0,
      28,     0,     0,    51,     0,     0,    38,     0,     0,     0,
      42,    49,     0,     0,    73,    41,    74,    60,    61,     0,
      80,     0,     0,    76,     0,     0,     0,    31,     0,    29,
      58,    50,     0,     0,    40,     0,    36,     0,    41,     0,
      64,    47,     0,     0,     0,     0,     0,     0,    71,    67,
      68,     0,     0,    79,    77,    75,    27,    25,     0,     0,
       0,     0,    37,     0,    48,    65,    43,    44,    45,    46,
      63,    62,    69,    70,    72,    66,     0,    39,    35,     0,
      32,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    14,    15,    16,    17,    18,    47,    19,    20,
      21,    34,    79,    80,    35,   109,    22,    23,    72,    87,
     113,    94,    95,    24,    36,    37,    96,    68,    75,    97,
      98,   132,    99,    25,    77,    78,    26
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -86
static const yytype_int8 yypact[] =
{
     -86,    63,   -86,    94,    97,    -1,    -9,    24,    45,    48,
     -86,   -12,   -86,   -86,   -86,    71,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,    81,    48,    81,
      48,    81,    33,   -86,    59,   -86,   110,    93,   -86,    48,
      48,   -86,   108,    95,    96,   -86,   -86,    98,    99,   101,
     102,   103,    90,    48,   100,     3,    -7,   100,   -86,   -86,
     -86,    90,   -86,   -86,   -86,   -86,   -86,   -86,    -2,   -86,
     104,    90,   113,    49,   -86,   106,    92,    17,   -86,    21,
     -86,     5,    48,   -86,   107,     8,   -86,    25,   109,    49,
     -86,   -86,    49,    50,   -86,    58,   -86,    77,   -86,   -24,
     -86,     8,   100,   -86,   111,    90,   112,   -86,   114,   -86,
     -86,   -86,    50,    78,   -86,    90,   -86,     8,    32,    65,
     -86,    74,    50,    50,    50,    50,    49,    49,   -86,   115,
     116,   117,    64,   -86,   -86,   -86,   -86,   -86,   119,    32,
       8,   118,   -86,    80,   -86,   -86,    74,    74,   -86,   -86,
     105,   -86,   -86,   -86,   -86,   -86,   124,   -86,   -86,   120,
     -86,   -86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -86,   -86,   -86,   -86,   -86,   -86,   -86,     9,   -86,   -86,
     -86,    -8,   -86,    34,   -50,   -86,   -86,   -86,   -86,   -86,
      26,   -82,   -63,   -86,   -86,   -86,    -6,   -86,   -59,   -85,
     -86,   -86,     6,   -86,   -86,    42,   -86
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -27
static const yytype_int16 yytable[] =
{
      38,    42,    66,   114,   119,    73,    43,   120,   107,    84,
      73,    81,    44,   128,   129,   130,    31,    70,   104,   133,
      48,    86,    50,    74,   131,    32,   118,    82,    83,    73,
     121,    55,    56,   108,    71,   114,    33,    39,    49,   112,
      51,   150,   151,    90,    91,    67,   102,   103,    69,   139,
     105,    76,    93,   106,   115,    81,    40,   116,   157,   146,
     147,   148,   149,     2,   144,   142,   -26,     3,     4,     5,
       6,     7,     8,     9,   110,   122,   123,   124,   125,    10,
      89,   112,    41,    32,    90,    91,    91,    45,    11,    12,
      13,    92,    52,    93,    93,   112,    76,   145,    32,    90,
      91,   122,   123,   124,   125,   126,   127,   140,    93,   140,
     141,    27,   159,    28,    29,    46,    30,   126,   127,   124,
     125,    53,    54,    57,    65,    58,    59,    88,    60,   101,
      61,    62,    63,    64,    32,    85,   100,   111,   155,   136,
     117,   135,   137,   143,   134,   138,   127,     0,   158,     0,
     161,     0,   152,   153,   154,   156,   160
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-86)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       6,     9,    52,    85,    89,    12,    18,    92,     3,    68,
      12,    61,    24,    37,    38,    39,    17,    14,    77,   101,
      28,    71,    30,    30,    48,    34,    89,    29,    30,    12,
      93,    39,    40,    28,    31,   117,    45,    13,    29,    31,
      31,   126,   127,    35,    36,    53,    29,    30,    54,   112,
      29,    57,    44,    32,    29,   105,    11,    32,   140,   122,
     123,   124,   125,     0,    32,   115,    33,     4,     5,     6,
       7,     8,     9,    10,    82,    43,    44,    45,    46,    16,
      31,    31,    34,    34,    35,    36,    36,    16,    25,    26,
      27,    42,    33,    44,    44,    31,   102,    32,    34,    35,
      36,    43,    44,    45,    46,    40,    41,    29,    44,    29,
      32,    17,    32,    19,    17,    34,    19,    40,    41,    45,
      46,    11,    29,    15,    34,    30,    30,    14,    30,    37,
      31,    30,    30,    30,    34,    31,    30,    30,   132,   105,
      31,    30,    30,   117,   102,    31,    41,    -1,    30,    -1,
      30,    -1,    37,    37,    37,    36,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,     0,     4,     5,     6,     7,     8,     9,    10,
      16,    25,    26,    27,    51,    52,    53,    54,    55,    57,
      58,    59,    65,    66,    72,    82,    85,    17,    19,    17,
      19,    17,    34,    45,    60,    63,    73,    74,    75,    13,
      11,    34,    60,    18,    24,    16,    34,    56,    60,    56,
      60,    56,    33,    11,    29,    60,    60,    15,    30,    30,
      30,    31,    30,    30,    30,    34,    63,    60,    76,    75,
      14,    31,    67,    12,    30,    77,    75,    83,    84,    61,
      62,    63,    29,    30,    77,    31,    63,    68,    14,    31,
      35,    36,    42,    44,    70,    71,    75,    78,    79,    81,
      30,    37,    29,    30,    77,    29,    32,     3,    28,    64,
      60,    30,    31,    69,    70,    29,    32,    31,    71,    78,
      78,    71,    43,    44,    45,    46,    40,    41,    37,    38,
      39,    48,    80,    70,    84,    30,    62,    30,    31,    71,
      29,    32,    63,    69,    32,    32,    71,    71,    71,    71,
      78,    78,    37,    37,    37,    81,    36,    70,    30,    32,
      32,    30
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 97 "gram.y"
    {}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 98 "gram.y"
    {}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 102 "gram.y"
    {printf("\nSQL>>");}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 103 "gram.y"
    {printf("\nSQL>>");}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 107 "gram.y"
    {createTable((yyvsp[(1) - (1)].createTablesql));}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 108 "gram.y"
    {select((yyvsp[(1) - (1)].selectsql));}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 109 "gram.y"
    {insert((yyvsp[(1) - (1)].insertsql));}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 110 "gram.y"
    {update((yyvsp[(1) - (1)].updatesql));}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 111 "gram.y"
    {deletetable((yyvsp[(1) - (1)].deletesql));}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 118 "gram.y"
    {exitflag=true;return 0;}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 119 "gram.y"
    {exitflag=true;return 0;}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 127 "gram.y"
    {createDB((yyvsp[(3) - (4)].value)->name);}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 130 "gram.y"
    {dropDB((yyvsp[(3) - (4)].value)->name);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 133 "gram.y"
    {useDB((yyvsp[(3) - (4)].value)->name);}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 136 "gram.y"
    {	(yyval.value) = (yyvsp[(1) - (1)].value);	}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 139 "gram.y"
    {showDB();}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 146 "gram.y"
    {showTable();}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 150 "gram.y"
    { (yyval.createTablesql) = new struct createTablesql;
		   (yyval.createTablesql)->tablename = (yyvsp[(3) - (7)].value)->name;
		   (yyval.createTablesql)->cols = (yyvsp[(5) - (7)].col);
		 }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 156 "gram.y"
    {(yyval.value) = (yyvsp[(1) - (1)].value);}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 159 "gram.y"
    { (yyval.col) = (yyvsp[(1) - (3)].col);
	  while((yyvsp[(1) - (3)].col)->next != NULL){
	    (yyvsp[(1) - (3)].col) = (yyvsp[(1) - (3)].col)->next;
	  }
	  (yyvsp[(1) - (3)].col)->next = (yyvsp[(3) - (3)].col);
	}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 165 "gram.y"
    {(yyval.col) = (yyvsp[(1) - (1)].col);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 168 "gram.y"
    { (yyval.col) = new struct col;
     (yyval.col)->name = (yyvsp[(1) - (2)].value)->name;
	 (yyval.col)->type = (yyvsp[(2) - (2)].coltype)->type;
	 (yyval.col)->length = (yyvsp[(2) - (2)].coltype)->length;
	 (yyval.col)->next = NULL;
   }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 175 "gram.y"
    {(yyval.value) = (yyvsp[(1) - (1)].value);}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 178 "gram.y"
    { (yyval.coltype) = new struct coltype;
	     (yyval.coltype)->type = 1;
		 (yyval.coltype)->length = 4;
	   }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 183 "gram.y"
    { (yyval.coltype) = new struct coltype;
	     (yyval.coltype)->type = 2;
		 (yyval.coltype)->length = (yyvsp[(3) - (4)].value)->intnum+1;
	   }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 188 "gram.y"
    {dropTable((yyvsp[(3) - (4)].value)->name);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 191 "gram.y"
    { (yyval.insertsql) = new struct insertsql;
		   (yyval.insertsql)->tablename = (yyvsp[(3) - (9)].value)->name;
		   (yyval.insertsql)->colnames = (yyvsp[(4) - (9)].col);
		   (yyval.insertsql)->datanodes = (yyvsp[(7) - (9)].datanode);
		 }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 197 "gram.y"
    { (yyval.insertsql) = new struct insertsql;
		   (yyval.insertsql)->tablename = (yyvsp[(3) - (8)].value)->name;
		   (yyval.insertsql)->colnames = NULL;
		   (yyval.insertsql)->datanodes = (yyvsp[(6) - (8)].datanode);
		 }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 203 "gram.y"
    {(yyval.col) = (yyvsp[(2) - (3)].col);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 206 "gram.y"
    { (yyval.col) = (yyvsp[(1) - (3)].col);
		  struct col* col = new struct col;
		  col->name = (yyvsp[(3) - (3)].value)->name;
		  col->next = NULL;
		  while((yyvsp[(1) - (3)].col)->next != NULL){
	        (yyvsp[(1) - (3)].col) = (yyvsp[(1) - (3)].col)->next;
	      }
		  (yyvsp[(1) - (3)].col)->next = col;
		}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 216 "gram.y"
    { (yyval.col) = new struct col;
		  (yyval.col)->name = (yyvsp[(1) - (1)].value)->name;
		  (yyval.col)->next = NULL;
		}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 222 "gram.y"
    { (yyval.datanode) = (yyvsp[(1) - (3)].datanode);
	    while((yyvsp[(1) - (3)].datanode)->next != NULL){
	      (yyvsp[(1) - (3)].datanode) = (yyvsp[(1) - (3)].datanode)->next;
	    }
	    (yyvsp[(1) - (3)].datanode)->next = (yyvsp[(3) - (3)].datanode); 
	  }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 228 "gram.y"
    { (yyval.datanode) = (yyvsp[(1) - (1)].datanode);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 231 "gram.y"
    { (yyval.datanode) = new struct datanode;
	   (yyval.datanode)->data = new char[4];
	   memcpy_s((yyval.datanode)->data,4,&((yyvsp[(1) - (1)].value)->intnum),4);
	   (yyval.datanode)->type = 1;
	   (yyval.datanode)->length = 4;
	   (yyval.datanode)->next = NULL;
	  }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 239 "gram.y"
    { (yyval.datanode) = new struct datanode;
	   (yyval.datanode)->data = new char[(yyvsp[(1) - (1)].value)->length];
	   memcpy_s((yyval.datanode)->data,(yyvsp[(1) - (1)].value)->length,(yyvsp[(1) - (1)].value)->name,(yyvsp[(1) - (1)].value)->length);
	   (yyval.datanode)->data[(yyvsp[(1) - (1)].value)->length-1] = '\0';
	   (yyval.datanode)->type = 2;
	   (yyval.datanode)->length = (yyvsp[(1) - (1)].value)->length;
	   (yyval.datanode)->next = NULL;
	  }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 249 "gram.y"
    { (yyval.value) = new struct values;
     (yyval.value)->intnum = (yyvsp[(1) - (3)].value)->intnum+(yyvsp[(3) - (3)].value)->intnum;
	 (yyval.value)->length = 4;
	 delete (yyvsp[(1) - (3)].value); 
	 delete (yyvsp[(3) - (3)].value);
    }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 256 "gram.y"
    { (yyval.value) = new struct values;
     (yyval.value)->intnum = (yyvsp[(1) - (3)].value)->intnum-(yyvsp[(3) - (3)].value)->intnum; 
	 (yyval.value)->length = 4; 
	 delete (yyvsp[(1) - (3)].value); 
	 delete (yyvsp[(3) - (3)].value);
    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 263 "gram.y"
    { (yyval.value) = new struct values;
     (yyval.value)->intnum = (yyvsp[(1) - (3)].value)->intnum*(yyvsp[(3) - (3)].value)->intnum; 
	 (yyval.value)->length = 4; 
	 delete (yyvsp[(1) - (3)].value); 
	 delete (yyvsp[(3) - (3)].value);
	}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 270 "gram.y"
    { (yyval.value) = new struct values; 
     (yyval.value)->intnum = (yyvsp[(1) - (3)].value)->intnum/(yyvsp[(3) - (3)].value)->intnum; 
	 (yyval.value)->length = 4; 
	 delete (yyvsp[(1) - (3)].value); 
	 delete (yyvsp[(3) - (3)].value);
	}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 277 "gram.y"
    {(yyval.value)=new struct values;
	(yyval.value)->intnum = -1 * (yyvsp[(2) - (2)].value)->intnum;
	(yyval.value)->length=4;
   }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 281 "gram.y"
    {(yyval.value) = (yyvsp[(2) - (3)].value);}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 282 "gram.y"
    {(yyval.value) = (yyvsp[(1) - (1)].value);}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 285 "gram.y"
    { (yyval.selectsql) = new struct selectsql;
		   (yyval.selectsql)->tablecolconf = (yyvsp[(2) - (6)].tablecolconf);
		   (yyval.selectsql)->tables = (yyvsp[(4) - (6)].tablecol);
		   (yyval.selectsql)->whereconf = (yyvsp[(5) - (6)].condition);
		 }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 291 "gram.y"
    { (yyval.selectsql) = new struct selectsql;
		   (yyval.selectsql)->tablecolconf = (yyvsp[(2) - (5)].tablecolconf);
		   (yyval.selectsql)->tables = (yyvsp[(4) - (5)].tablecol);
		   (yyval.selectsql)->whereconf = NULL;
		 }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 298 "gram.y"
    { (yyval.tablecolconf) = new struct tablecolconf;
			  (yyval.tablecolconf)->isALL = 0;
			  (yyval.tablecolconf)->tablecols = NULL;
			}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 303 "gram.y"
    { (yyval.tablecolconf) = new struct tablecolconf;
			  (yyval.tablecolconf)->isALL = 1;
			  (yyval.tablecolconf)->tablecols = (yyvsp[(1) - (1)].tablecol);
			}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 309 "gram.y"
    { (yyval.tablecol) = (yyvsp[(1) - (3)].tablecol);
	       while((yyvsp[(1) - (3)].tablecol)->next != NULL){
	         (yyvsp[(1) - (3)].tablecol) = (yyvsp[(1) - (3)].tablecol)->next;
	       }
	       (yyvsp[(1) - (3)].tablecol)->next = (yyvsp[(3) - (3)].tablecol); 
		 }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 315 "gram.y"
    {(yyval.tablecol) = (yyvsp[(1) - (1)].tablecol);}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 318 "gram.y"
    { (yyval.tablecol) = new struct tablecol;
		  (yyval.tablecol)->tablename = (yyvsp[(1) - (3)].value)->name;
		  (yyval.tablecol)->colname = (yyvsp[(3) - (3)].value)->name;
		  (yyval.tablecol)->next = NULL;
		}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 324 "gram.y"
    { (yyval.tablecol) = new struct tablecol;
		  (yyval.tablecol)->tablename = NULL;
		  (yyval.tablecol)->colname = (yyvsp[(1) - (1)].value)->name;
		  (yyval.tablecol)->next = NULL;
		}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 331 "gram.y"
    { (yyval.tablecol) = (yyvsp[(1) - (3)].tablecol);
	    while((yyvsp[(1) - (3)].tablecol)->next != NULL){
	       (yyvsp[(1) - (3)].tablecol) = (yyvsp[(1) - (3)].tablecol)->next;
	    }
		(yyvsp[(1) - (3)].tablecol)->next = new struct tablecol;
		(yyvsp[(1) - (3)].tablecol)->next->tablename = (yyvsp[(3) - (3)].value)->name;
		(yyvsp[(1) - (3)].tablecol)->next->colname = NULL;
		(yyvsp[(1) - (3)].tablecol)->next->next = NULL;
	  }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 341 "gram.y"
    { (yyval.tablecol) = new struct tablecol;
	    (yyval.tablecol)->tablename = (yyvsp[(1) - (1)].value)->name;
		(yyval.tablecol)->colname = NULL;
		(yyval.tablecol)->next = NULL;
	  }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 347 "gram.y"
    { (yyval.condition) = (yyvsp[(2) - (2)].condition); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 350 "gram.y"
    { (yyval.condition) = (yyvsp[(1) - (1)].condition);
		  }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 353 "gram.y"
    { (yyval.condition) = new struct condition;
		    (yyval.condition)->comp_op = 0;
		    (yyval.condition)->comp_cond = 1;
		    (yyval.condition)->left_type = 4;
		    (yyval.condition)->left_data = NULL;
		    (yyval.condition)->left_col = NULL;
		    (yyval.condition)->left_col_data = NULL;
		    (yyval.condition)->left_cond = (yyvsp[(1) - (3)].condition);
		    (yyval.condition)->right_type = 4;
		    (yyval.condition)->right_data = NULL;
		    (yyval.condition)->right_col = NULL;
		    (yyval.condition)->right_col_data = NULL;
		    (yyval.condition)->right_cond = (yyvsp[(3) - (3)].condition);
		  }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 368 "gram.y"
    { (yyval.condition) = new struct condition;
		    (yyval.condition)->comp_op = 0;
		    (yyval.condition)->comp_cond = 2;
		    (yyval.condition)->left_type = 4;
		    (yyval.condition)->left_data = NULL;
		    (yyval.condition)->left_col = NULL;
		    (yyval.condition)->left_col_data = NULL;
		    (yyval.condition)->left_cond = (yyvsp[(1) - (3)].condition);
		    (yyval.condition)->right_type = 4;
		    (yyval.condition)->right_data = NULL;
		    (yyval.condition)->right_col = NULL;
		    (yyval.condition)->right_col_data = NULL;
		    (yyval.condition)->right_cond = (yyvsp[(3) - (3)].condition);
		  }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 383 "gram.y"
    { (yyval.condition) = new struct condition;
		    (yyval.condition)->comp_op = 0;
		    (yyval.condition)->comp_cond = 3;
		    (yyval.condition)->left_type = 0;
		    (yyval.condition)->left_data = NULL;
		    (yyval.condition)->left_col = NULL;
		    (yyval.condition)->left_col_data = NULL;
		    (yyval.condition)->left_cond = NULL;
		    (yyval.condition)->right_type = 4;
		    (yyval.condition)->right_data = NULL;
		    (yyval.condition)->right_col = NULL;
		    (yyval.condition)->right_col_data = NULL;
		    (yyval.condition)->right_cond = (yyvsp[(2) - (2)].condition);
		  }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 398 "gram.y"
    { (yyval.condition) = (yyvsp[(2) - (3)].condition);
		  }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 402 "gram.y"
    { (yyval.condition) = new struct condition;
		   (yyval.condition)->comp_op = (yyvsp[(2) - (3)].comp_op);
		   (yyval.condition)->comp_cond = 0;
		   (yyval.condition)->left_type = (yyvsp[(1) - (3)].comparator)->type;
		   (yyval.condition)->left_data = (yyvsp[(1) - (3)].comparator)->data;
		   (yyval.condition)->left_col = (yyvsp[(1) - (3)].comparator)->tablecol;
		   (yyval.condition)->left_col_data = NULL;
		   (yyval.condition)->left_cond = NULL;
		   (yyval.condition)->right_type = (yyvsp[(3) - (3)].comparator)->type;
		   (yyval.condition)->right_data = (yyvsp[(3) - (3)].comparator)->data;
		   (yyval.condition)->right_col = (yyvsp[(3) - (3)].comparator)->tablecol;
		   (yyval.condition)->right_col_data = NULL;
		   (yyval.condition)->right_cond = NULL;
		 }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 417 "gram.y"
    {(yyval.comp_op) = 1;}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 418 "gram.y"
    {(yyval.comp_op) = 2;}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 419 "gram.y"
    {(yyval.comp_op) = 3;}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 420 "gram.y"
    {(yyval.comp_op) = 4;}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 421 "gram.y"
    {(yyval.comp_op) = 5;}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 422 "gram.y"
    {(yyval.comp_op) = 6;}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 425 "gram.y"
    { (yyval.comparator) = new struct comparator;
		    (yyval.comparator)->type = (yyvsp[(1) - (1)].datanode)->type;
			(yyval.comparator)->data = (yyvsp[(1) - (1)].datanode);
			(yyval.comparator)->tablecol = NULL;
		  }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 431 "gram.y"
    { (yyval.comparator) = new struct comparator;
		    (yyval.comparator)->type = 3;
			(yyval.comparator)->data = NULL;
			(yyval.comparator)->tablecol = (yyvsp[(1) - (1)].tablecol);
		  }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 438 "gram.y"
    { (yyval.updatesql) = new struct updatesql;
		   (yyval.updatesql)->tablename = (yyvsp[(2) - (6)].value)->name;
		   (yyval.updatesql)->setconfs = (yyvsp[(4) - (6)].setconf);
		   (yyval.updatesql)->whereconf = (yyvsp[(5) - (6)].condition);
		 }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 444 "gram.y"
    { (yyval.updatesql) = new struct updatesql;
		   (yyval.updatesql)->tablename = (yyvsp[(2) - (5)].value)->name;
		   (yyval.updatesql)->setconfs = (yyvsp[(4) - (5)].setconf);
		   (yyval.updatesql)->whereconf = NULL;
		 }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 451 "gram.y"
    { (yyval.setconf) = (yyvsp[(1) - (3)].setconf);
	       while((yyvsp[(1) - (3)].setconf)->next != NULL){
	         (yyvsp[(1) - (3)].setconf) = (yyvsp[(1) - (3)].setconf)->next;
	       }
	       (yyvsp[(1) - (3)].setconf)->next = (yyvsp[(3) - (3)].setconf);
		}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 458 "gram.y"
    { (yyval.setconf) = (yyvsp[(1) - (1)].setconf);
		}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 462 "gram.y"
    { (yyval.setconf) = new struct setconf;
	     (yyval.setconf)->col = (yyvsp[(1) - (3)].tablecol);
		 (yyval.setconf)->datanode = (yyvsp[(3) - (3)].datanode);
		 (yyval.setconf)->coldatanode = NULL;
		 (yyval.setconf)->next = NULL;
	   }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 470 "gram.y"
    { (yyval.deletesql) = new struct deletesql;
		   (yyval.deletesql)->tablename = (yyvsp[(3) - (5)].value)->name;
		   (yyval.deletesql)->whereconf = (yyvsp[(4) - (5)].condition);
		 }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 475 "gram.y"
    { (yyval.deletesql) = new struct deletesql;
		   (yyval.deletesql)->tablename = (yyvsp[(3) - (4)].value)->name;
		   (yyval.deletesql)->whereconf = NULL;
		 }
    break;


/* Line 1792 of yacc.c  */
#line 2201 "gram.tab.cpp"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 480 "gram.y"







int main()
{
	if(!init()){
		printf("init SQL error\n");
		return 0;
	}
	printf("init SQL ok\n");
	exitflag = false;
	printf("SQL>>");

	while(yyparse())  ;
		

	/*
		if(exitflag){
		
			printf("\nSQL>>");
		}
	*/
	return 0;
}

void yyerror(const char* msg)
{
	printf("语法错误/不支持本条SQL语句\n");
    //printf("%s is error in line\n",msg);
}