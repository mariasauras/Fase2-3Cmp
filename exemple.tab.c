/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "exemple.y"

#include <stdio.h>
#include <stdlib.h>
#include "symtab.h"
#define MAX_NUM 50
extern FILE *yyout;
extern int yylineno;
extern int yylex();
/*extern void yyerror(char*);*/

/*Array to save the 3AC code*/

char* instructions_buffer[1000];

/* Control Var to generated line number of the instruction and temporally variables*/
unsigned long ln_inst = 1;
unsigned long tmp_cnt = 0;


#line 90 "exemple.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_EXEMPLE_TAB_H_INCLUDED
# define YY_YY_EXEMPLE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 27 "exemple.y"

  /* Les definicions que s'utilitzen al %union han d'estar aqui */
  #include "symtab.h"
  #include "exemple_dades.h"
  #include "exemple_funcions.h"
  

#line 141 "exemple.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN = 258,
    ENDLINE = 259,
    INTEGER = 260,
    ID = 261,
    FLOAT = 262,
    STRING = 263,
    BOOLEAN = 264,
    SUMA = 265,
    RESTA = 266,
    MUL = 267,
    DIV = 268,
    MOD = 269,
    POW = 270,
    OP = 271,
    CP = 272,
    OC = 273,
    CC = 274,
    PC = 275,
    SPACE = 276,
    COMMA = 277,
    OR = 278,
    AND = 279,
    NOT = 280,
    END = 281,
    DDP = 282,
    RETURN = 283,
    FUNC = 284,
    DP = 285,
    GREATERTHAN = 286,
    LESSTHAN = 287,
    GREATEREQ = 288,
    LESSEQ = 289,
    EQ = 290,
    DIF = 291,
    FOR = 292,
    IF = 293,
    ELSE = 294,
    ELSEIF = 295,
    IN = 296,
    WHILE = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "exemple.y"

  cond_list cl;

#line 199 "exemple.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXEMPLE_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

#define YYUNDEFTOK  2
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    98,   106,   108,   116,   117,   118,   121,
     134,   136,   137,   139,   141,   143,   147,   150,   151,   152,
     153,   225,   257,   264,   270,   272,   277,   279,   284,   288,
     290,   295,   297,   306,   314,   316,   317,   319,   327,   336,
     348,   364,   365,   366,   367,   368,   369,   370,   372,   373,
     376,   377,   379,   380,   382,   383,   384,   386,   387,   388,
     389,   391,   392,   394,   395,   396,   397,   398,   399,   400,
     401,   420,   421,   422
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "ENDLINE", "INTEGER", "ID",
  "FLOAT", "STRING", "BOOLEAN", "SUMA", "RESTA", "MUL", "DIV", "MOD",
  "POW", "OP", "CP", "OC", "CC", "PC", "SPACE", "COMMA", "OR", "AND",
  "NOT", "END", "DDP", "RETURN", "FUNC", "DP", "GREATERTHAN", "LESSTHAN",
  "GREATEREQ", "LESSEQ", "EQ", "DIF", "FOR", "IF", "ELSE", "ELSEIF", "IN",
  "WHILE", "$accept", "programa", "function_declaration", "function",
  "parameters", "func_header", "push", "func_return", "main",
  "start_program", "sentences_list", "sentence", "bool_value", "orlist",
  "andlist", "beta", "alpha", "if_sentence", "elseif", "elsee",
  "while_sentence", "for_sentence", "gamma", "rel_op", "matrix_value",
  "matrix", "row", "sumrest", "mullist", "powlist", "valor", "func_call", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-36)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -47,     8,   -28,   -47,    34,   -47,   -47,     9,   -47,    56,
     -47,    46,   -47,    65,    77,    65,    79,    23,   -47,    50,
     -47,   -47,   -47,   -47,     9,   118,     5,    91,   -47,    75,
       9,    65,    65,    65,   124,    25,   -47,   -47,   -47,    48,
     110,   133,    72,    94,    94,   -47,    22,   125,    83,    23,
       9,   129,   -47,    65,    65,    65,    65,    65,    65,   150,
     131,   135,    92,    87,   116,   -47,   -47,    77,    77,   -47,
      65,   141,    44,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,    65,    30,   -47,   155,     5,     5,
      91,    91,    91,   -47,   134,   103,   156,   -47,   -47,    65,
     -47,    65,   110,   -47,    13,   -47,     9,    23,    94,    92,
     -47,   -47,   157,   138,   158,   -47,    92,    76,    65,    26,
     125,   -47,     9,   -47,   160,   -47,   140,   -47,     1,   -47,
     136,   -47,   162,   -47,    65,   -47,   165,   -47,   137,   130,
     -47,   -47,   -47,   132,    23,   168,   147,    40,   -47,   170,
     -47,     9,   -47,     9,   149,    26,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,    14,     1,     0,     3,     2,     0,    10,     0,
      64,    66,    63,     0,     0,     0,     0,     0,    31,    31,
      16,    17,    18,    19,     0,     0,    56,    60,    62,     0,
       0,     0,    73,     0,    66,     0,    49,    48,    53,     0,
      51,     0,     0,     0,     0,    29,     0,    26,     0,     0,
       0,    31,    21,     0,     0,     0,     0,     0,     0,     8,
      31,     0,    72,     0,     0,    65,    67,     0,     0,    22,
       0,     0,     0,    28,    31,    31,    31,    47,    41,    43,
      42,    44,    45,    46,     0,     0,    15,     0,    54,    55,
      57,    58,    59,    61,     0,     0,     0,    20,    70,     0,
      68,     0,    50,    52,     0,    24,     0,     0,     0,    23,
      31,    38,     0,    12,     0,     5,    71,     0,     0,    31,
      25,    27,     0,     7,     0,     9,     0,    69,     0,    31,
      31,    11,     0,    40,     0,    34,     0,     6,     0,    31,
      37,    39,    31,    36,     0,     0,     0,     0,    31,     0,
      31,     0,    32,     0,    31,    31,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -17,   126,   -34,   -46,    70,    24,   -18,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,   112,   -47,   111,   -11,   100,    95,
     123,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    95,     9,    29,   125,     6,     7,
      19,    20,    45,    46,    47,   129,    50,    21,   139,   146,
      22,    23,    24,    84,    38,    39,    40,    25,    26,    27,
      28,    63
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,     4,    35,    85,    41,   133,    48,    51,     3,    71,
      73,    53,    54,    60,    10,    11,    12,    55,    56,    57,
      61,    62,    64,    53,    54,    13,    74,    14,    10,    34,
      12,   134,    72,    48,   110,    53,    54,    15,    48,    43,
       8,    14,    65,   118,   150,    75,    16,    17,    44,    31,
     -13,    18,   -30,    75,    53,    54,   106,   107,   108,   104,
      30,    65,    32,    75,    33,   -30,   -30,    66,    67,    77,
      10,    34,    12,   109,   121,    78,    79,    80,    81,    82,
      83,    13,    36,    14,    37,    42,    53,    54,   116,   119,
     117,    59,   122,    53,    54,   127,    48,    48,   147,    10,
      34,    12,    53,    54,    98,   130,    58,   128,    77,    99,
      43,   135,    14,    70,    78,    79,    80,    81,    82,    83,
     113,   143,    52,   138,   144,   114,    53,    54,    53,    54,
     151,    68,   153,    48,   154,   100,   155,    69,   101,    97,
      32,   141,    33,    53,    54,    53,    54,    53,    54,    76,
      90,    91,    92,    88,    89,    87,    94,    96,   105,   111,
     115,   112,   136,   123,   126,   124,   131,   132,   137,   140,
     142,   145,   148,   149,   152,   -35,    86,   120,   102,   156,
     103,    93
};

static const yytype_uint8 yycheck[] =
{
      18,    29,    13,    49,    15,     4,    17,    24,     0,    43,
      44,    10,    11,    30,     5,     6,     7,    12,    13,    14,
      31,    32,    33,    10,    11,    16,     4,    18,     5,     6,
       7,    30,    43,    44,     4,    10,    11,    28,    49,    16,
       6,    18,    17,    30,     4,    23,    37,    38,    25,     3,
       0,    42,    26,    23,    10,    11,    74,    75,    76,    70,
       4,    17,    16,    23,    18,    39,    40,    19,    20,    25,
       5,     6,     7,    84,   108,    31,    32,    33,    34,    35,
      36,    16,     5,    18,     7,     6,    10,    11,    99,   106,
     101,    16,   110,    10,    11,    19,   107,   108,   144,     5,
       6,     7,    10,    11,    17,   122,    15,   118,    25,    22,
      16,   129,    18,    41,    31,    32,    33,    34,    35,    36,
      17,   139,     4,   134,   142,    22,    10,    11,    10,    11,
     148,    21,   150,   144,   151,    19,   153,     4,    22,     4,
      16,     4,    18,    10,    11,    10,    11,    10,    11,    24,
      55,    56,    57,    53,    54,    26,     6,    26,    17,     4,
       4,    27,    26,     6,     6,    27,     6,    27,     6,     4,
      40,    39,     4,    26,     4,    26,    50,   107,    67,   155,
      68,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    45,     0,    29,    46,    51,    52,     6,    48,
       5,     6,     7,    16,    18,    28,    37,    38,    42,    53,
      54,    60,    63,    64,    65,    70,    71,    72,    73,    49,
       4,     3,    16,    18,     6,    70,     5,     7,    67,    68,
      69,    70,     6,    16,    25,    55,    56,    57,    70,    59,
      59,    53,     4,    10,    11,    12,    13,    14,    15,    16,
      53,    70,    70,    74,    70,    17,    19,    20,    21,     4,
      41,    55,    70,    55,     4,    23,    24,    25,    31,    32,
      33,    34,    35,    36,    66,    56,    54,    26,    71,    71,
      72,    72,    72,    73,     6,    47,    26,     4,    17,    22,
      19,    22,    69,    67,    70,    17,    59,    59,    59,    70,
       4,     4,    27,    17,    22,     4,    70,    70,    30,    53,
      57,    55,    59,     6,    27,    50,     6,    19,    70,    58,
      53,     6,    27,     4,    30,    59,    26,     6,    70,    61,
       4,     4,    40,    59,    59,    39,    62,    56,     4,    26,
       4,    59,     4,    59,    53,    53,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    47,    47,    47,    48,
      49,    50,    50,    51,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      58,    59,    60,    61,    61,    62,    62,    63,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    70,    70,    71,    71,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     6,     5,     3,     0,     6,
       0,     2,     0,     2,     0,     3,     1,     1,     1,     1,
       4,     2,     3,     3,     3,     4,     1,     4,     2,     1,
       0,     0,    12,     8,     0,     4,     0,     8,     4,     9,
       7,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     1,     1,     1,     3,     1,     3,     4,     6,
       4,     3,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 88 "exemple.y"
                                     {
                                      emet(NULL,0,NULL,"HALT",NULL);
                                      emet(NULL,0,NULL,"END",NULL);

                                      for(int i=0; i<ln_inst-1; i++){
                                        fprintf(yyout,"%s\n",instructions_buffer[i]);
                                        free(instructions_buffer[i]);
                                      }
}
#line 1494 "exemple.tab.c"
    break;

  case 3:
#line 98 "exemple.y"
                                                     {
                                                      for(int i=0; i<ln_inst-1; i++){
                                                        fprintf(yyout,"%s\n",instructions_buffer[i]);
                                                        free(instructions_buffer[i]);
                                                      }
                                                      ln_inst = 1;
                                                      tmp_cnt = 0;                                                 
                                                     }
#line 1507 "exemple.tab.c"
    break;

  case 5:
#line 108 "exemple.y"
                                                               {
                                                                emet(NULL,0,NULL,"END\n",NULL);
                                                                pop_scope();
                                                                sym_enter((yyvsp[-4].cl.st).value_data.ident.lexema, &(yyvsp[-4].cl.st));
                                                               }
#line 1517 "exemple.tab.c"
    break;

  case 6:
#line 116 "exemple.y"
                                          { (yyval.cl.st).value_data.cont_params += 1; treat_parameter((yyvsp[-2].cl.st),(yyvsp[0].cl.st)); }
#line 1523 "exemple.tab.c"
    break;

  case 7:
#line 117 "exemple.y"
                                          { (yyval.cl.st).value_data.cont_params = 1; treat_parameter((yyvsp[-2].cl.st),(yyvsp[0].cl.st)); }
#line 1529 "exemple.tab.c"
    break;

  case 8:
#line 118 "exemple.y"
                                          { (yyval.cl.st).value_data.cont_params = 0; }
#line 1535 "exemple.tab.c"
    break;

  case 9:
#line 121 "exemple.y"
                                                   {
                                    
                                    if((yyvsp[0].cl.st).value_data.return_type != UNKNOWN_TYPE)
                                      treat_return(&(yyvsp[-5].cl.st), (yyvsp[0].cl.st));
                                    else 
                                      (yyvsp[-5].cl.st).value_data.return_type = UNKNOWN_TYPE;
                                    
                                    emet(NULL,0,NULL,"START",&(yyvsp[-5].cl.st));
                                    (yyvsp[-5].cl.st).value_type = FUNCTION; /* El valor tipo de ID es FUNCTION */
                                    (yyvsp[-5].cl.st).value_data.cont_params = (yyvsp[-2].cl.st).value_data.cont_params;
                                    (yyval.cl.st) = (yyvsp[-5].cl.st);
                                    
                                  }
#line 1553 "exemple.tab.c"
    break;

  case 10:
#line 134 "exemple.y"
       { push_scope(); }
#line 1559 "exemple.tab.c"
    break;

  case 11:
#line 136 "exemple.y"
                                  { (yyval.cl.st) = (yyvsp[0].cl.st);}
#line 1565 "exemple.tab.c"
    break;

  case 12:
#line 137 "exemple.y"
                                  { (yyval.cl.st).value_data.return_type = UNKNOWN_TYPE; }
#line 1571 "exemple.tab.c"
    break;

  case 13:
#line 139 "exemple.y"
                                    { complete((yyvsp[0].cl).lls, ln_inst); }
#line 1577 "exemple.tab.c"
    break;

  case 14:
#line 141 "exemple.y"
                { emet(NULL, 0, NULL, "START main", NULL); }
#line 1583 "exemple.tab.c"
    break;

  case 15:
#line 143 "exemple.y"
                                               {
                  complete((yyvsp[-2].cl).lls, (yyvsp[-1].cl.st.value_data.enter));
                  (yyval.cl).lls = (yyvsp[0].cl).lls;
                }
#line 1592 "exemple.tab.c"
    break;

  case 20:
#line 153 "exemple.y"
                                       {
                          (yyval.cl).lls = createEmptyList(); 
                          type type;
                          bool temp_type = false;

                          if((yyvsp[-1].cl.st).value_type == TMP_TYPE){
                            type = (yyvsp[-1].cl.st).value_data.tmp_type;
                            temp_type = true;
                          } else type = (yyvsp[-1].cl.st).value_type;

                          if(type == INT_TYPE){
                            if(temp_type)
                              emet((yyvsp[-3].cl.st).value_data.ident.lexema,(yyvsp[-1].cl.st).value_data.tmp_val,NULL,NULL,NULL);
                            else emet((yyvsp[-3].cl.st).value_data.ident.lexema,0,&(yyvsp[-1].cl.st),NULL,NULL);

                            (yyvsp[-1].cl.st).value_data.id_type = INT_TYPE;
                            
                          } else if(type == FLOAT_TYPE){
                            if(temp_type) emet((yyvsp[-3].cl.st).value_data.ident.lexema,(yyvsp[-1].cl.st).value_data.tmp_val,NULL,NULL,NULL);
                            else emet((yyvsp[-3].cl.st).value_data.ident.lexema,0,&(yyvsp[-1].cl.st),NULL,NULL);

                            (yyvsp[-1].cl.st).value_data.id_type = FLOAT_TYPE;

                          } else if(type == BOOL_TYPE){
                            emet((yyvsp[-3].cl.st).value_data.ident.lexema,0,&(yyvsp[-1].cl.st),NULL,NULL);

                            (yyvsp[-1].cl.st).value_data.id_type = BOOL_TYPE;

                          } else if (type == MATRIX_TYPE){
                              (yyvsp[-1].cl.st).value_data.id_type = MATRIX_TYPE;

                              if((yyvsp[-1].cl.st).value_data.matrix_type == INT_TYPE) {
                                long despl = 0;
                                for(int i= 0; i<(yyvsp[-1].cl.st).value_data.row; i++) 
                                  for(int j= 0; j<(yyvsp[-1].cl.st).value_data.column; j++){
                                    (yyvsp[-1].cl.st).value_data.pos = (yyvsp[-1].cl.st).value_data.column*i+j;
                                    (yyvsp[-1].cl.st).value_data.despl = despl;
                                    if(temp_type){
                                      char buffer_matrix[50];
                                      sprintf(buffer_matrix,"$t%ld",(yyvsp[-1].cl.st).value_data.tmp_val);
                                      emet(buffer_matrix,0,&(yyvsp[-1].cl.st),NULL,NULL);

                                    }else
                                      emet((yyvsp[-3].cl.st).value_data.ident.lexema,0,&(yyvsp[-1].cl.st),NULL,NULL);
                                    despl+=4;
                                  }
                            } else if((yyvsp[-1].cl.st).value_data.matrix_type == FLOAT_TYPE) {
                                long despl = 0;
                                for(int i= 0; i<(yyvsp[-1].cl.st).value_data.row; i++) 
                                  for(int j= 0; j<(yyvsp[-1].cl.st).value_data.column; j++){
                                    (yyvsp[-1].cl.st).value_data.pos = (yyvsp[-1].cl.st).value_data.column*i+j;
                                    (yyvsp[-1].cl.st).value_data.despl = despl;
                                    if(temp_type){
                                      char buffer_matrix[50];
                                      sprintf(buffer_matrix,"$t%ld",(yyvsp[-1].cl.st).value_data.tmp_val);
                                      emet(buffer_matrix,0,&(yyvsp[-1].cl.st),NULL,NULL);

                                    }else
                                      emet((yyvsp[-3].cl.st).value_data.ident.lexema,0,&(yyvsp[-1].cl.st),NULL,NULL);
                                    despl +=4;
                                  }
                                  
                            } else yyerror("Only accept Integer or Float matrix");

                          } else if (type == FUNCTION){
                            (yyvsp[-1].cl.st).value_data.id_type = FUNCTION;
                          } 

                          (yyvsp[-1].cl.st).value_data.ident.lexema = (yyvsp[-3].cl.st).value_data.ident.lexema;
                          (yyvsp[-1].cl.st).value_type = ID_TYPE;
                          sym_enter((yyvsp[-3].cl.st).value_data.ident.lexema, &(yyvsp[-1].cl.st));
                        }
#line 1669 "exemple.tab.c"
    break;

  case 21:
#line 225 "exemple.y"
                                         { 
                          (yyval.cl).lls = createEmptyList(); 
                          type valueType;                     
                        
                          if((yyvsp[-1].cl.st).value_type == TMP_TYPE){
                            valueType = (yyvsp[-1].cl.st).value_data.tmp_type;
                          } else valueType = (yyvsp[-1].cl.st).value_type;

                          sym_value_type add_param;
                          add_param.value_type = INT_TYPE;
                          add_param.value_data.enter = 1;
                          
                          if(valueType == INT_TYPE){
                            emet(NULL,0,NULL,"PARAM",&(yyvsp[-1].cl.st));
                            emet(NULL,0,NULL,"PUTI,",&add_param);

                          } else if(valueType == FLOAT_TYPE){
                            emet(NULL,0,NULL,"PARAM",&(yyvsp[-1].cl.st));
                            emet(NULL,0,NULL,"PUTF,",&add_param);
                            
                          } else if(valueType == FUNCTION){
                            (yyvsp[-1].cl.st).value_data.id_type = FUNCTION;
                            
                          } else if(valueType == ID_TYPE){
                            emet(NULL,0,NULL,"PARAM",&(yyvsp[-1].cl.st));
                            if((yyvsp[-1].cl.st).value_data.id_type == INT_TYPE)
                              emet(NULL,0,NULL,"PUTI,",&add_param);
                            else
                              emet(NULL,0,NULL,"PUTF,",&add_param);
                            
                          } else yyerror("AQUI HAY UN ERROR"); 
                        }
#line 1706 "exemple.tab.c"
    break;

  case 22:
#line 257 "exemple.y"
                                                 {   
                            (yyval.cl).lls = createEmptyList();                
                           emet(NULL,0,NULL,"RETURN",&(yyvsp[-1].cl.st));
                          }
#line 1715 "exemple.tab.c"
    break;

  case 23:
#line 264 "exemple.y"
                                    {
                                      (yyval.cl).llc = createList(ln_inst);
                                      (yyval.cl).llf = createList(ln_inst+1);
                                      if_emet(&(yyvsp[-2].cl.st),(yyvsp[-1].cl.st.value_data.ident.lexema),&(yyvsp[0].cl.st),0);
                                      goto_emet(0);
                                    }
#line 1726 "exemple.tab.c"
    break;

  case 24:
#line 270 "exemple.y"
                                    { (yyval.cl) = (yyvsp[-1].cl); }
#line 1732 "exemple.tab.c"
    break;

  case 25:
#line 272 "exemple.y"
                                  {
                                    (yyval.cl).llc = fusion((yyvsp[-3].cl).llc,(yyvsp[0].cl).llc);
                                    (yyval.cl).llf = (yyvsp[0].cl).llf;
                                    complete((yyvsp[-3].cl).llf,(yyvsp[-1].cl.st.value_data.enter)); 
                                  }
#line 1742 "exemple.tab.c"
    break;

  case 27:
#line 279 "exemple.y"
                                       {
                                        complete((yyvsp[-3].cl).llc, (yyvsp[-1].cl.st.value_data.enter));
                                        (yyval.cl).llc = (yyvsp[0].cl).llc;
                                        (yyval.cl).llf = fusion((yyvsp[-3].cl).llf,(yyvsp[0].cl).llf);
                                      }
#line 1752 "exemple.tab.c"
    break;

  case 28:
#line 284 "exemple.y"
                                      {
                                        (yyval.cl).llc = (yyvsp[0].cl).llf;
                                        (yyval.cl).llf = (yyvsp[0].cl).llc;
                                      }
#line 1761 "exemple.tab.c"
    break;

  case 30:
#line 290 "exemple.y"
                                    {
                                      (yyval.cl).lls = createList(ln_inst);
                                      goto_emet(0);
                                    }
#line 1770 "exemple.tab.c"
    break;

  case 31:
#line 295 "exemple.y"
                                    { (yyval.cl.st.value_data.enter) = ln_inst; }
#line 1776 "exemple.tab.c"
    break;

  case 32:
#line 298 "exemple.y"
                                                                              {
                                                                                  complete((yyvsp[-10].cl).llc, (yyvsp[-8].cl.st.value_data.enter));
                                                                                  complete((yyvsp[-10].cl).llf, (yyvsp[-5].cl.st.value_data.enter));
                                                                                  complete((yyvsp[-4].cl).llf, (yyvsp[-3].cl.st.value_data.enter));
                                                                                  list fusiona = fusion((yyvsp[-2].cl).lls,(yyvsp[-6].cl).lls);
                                                                                  (yyval.cl).lls = fusion((yyvsp[-4].cl).lls,fusiona);
                                                                              }
#line 1788 "exemple.tab.c"
    break;

  case 33:
#line 307 "exemple.y"
                                                                        {
                                                                          complete((yyvsp[-4].cl).llc, (yyvsp[-2].cl.st.value_data.enter));
                                                                          complete((yyvsp[-7].cl).llf, (yyvsp[-5].cl.st.value_data.enter));
                                                                          (yyval.cl).llf = (yyvsp[-4].cl).llf;
                                                                          list fusiona = fusion((yyvsp[-1].cl).lls, (yyvsp[0].cl).lls);
                                                                          (yyval.cl).lls = fusion(fusiona,(yyvsp[-7].cl).lls);
                                                                        }
#line 1800 "exemple.tab.c"
    break;

  case 34:
#line 314 "exemple.y"
                                                                        { (yyval.cl).lls = createEmptyList(); }
#line 1806 "exemple.tab.c"
    break;

  case 35:
#line 316 "exemple.y"
                                             { (yyval.cl).lls = (yyvsp[0].cl).lls; }
#line 1812 "exemple.tab.c"
    break;

  case 36:
#line 317 "exemple.y"
                                            { (yyval.cl).lls = createEmptyList(); }
#line 1818 "exemple.tab.c"
    break;

  case 37:
#line 320 "exemple.y"
                                                                          {
                                                                            complete((yyvsp[-5].cl).llc, (yyvsp[-3].cl.st.value_data.enter));
                                                                            complete((yyvsp[-2].cl).lls, (yyvsp[-6].cl.st.value_data.enter));
                                                                            goto_emet((yyvsp[-6].cl.st.value_data.enter));
                                                                            (yyval.cl).lls = (yyvsp[-5].cl).llf;
                                                                          }
#line 1829 "exemple.tab.c"
    break;

  case 38:
#line 327 "exemple.y"
                                                {
                                                  complete((yyvsp[-2].cl).lls,ln_inst);
                                                  sym_value_type aux;
                                                  sum_op(&aux,(yyvsp[-3].cl).st,(yyvsp[-3].cl).inc);
                                                  emet((yyvsp[-3].cl).st.value_data.ident.lexema,aux.value_data.tmp_val,NULL,NULL,NULL);
                                                  goto_emet((yyvsp[-3].cl).ln);
                                                  (yyval.cl).lls = (yyvsp[-3].cl).lls;
                                                }
#line 1842 "exemple.tab.c"
    break;

  case 39:
#line 336 "exemple.y"
                                                        {
                                                          error_treatment(&(yyvsp[-5].cl.st),&(yyvsp[-3].cl.st),&(yyvsp[-1].cl.st));
                                                          emet((yyvsp[-7].cl.st).value_data.ident.lexema, 0,&(yyvsp[-5].cl.st), NULL,NULL);
                                                          (yyvsp[-7].cl.st).value_data.id_type = INT_TYPE;
                                                          saveInto((yyvsp[-7].cl.st).value_data.ident.lexema,&(yyvsp[-7].cl.st));
                                                          (yyval.cl).inc = (yyvsp[-3].cl.st);
                                                          (yyval.cl).st = (yyvsp[-7].cl.st);
                                                          (yyval.cl).ln = ln_inst;
                                                          if_emet(&(yyvsp[-7].cl.st),"LS",&(yyvsp[-1].cl.st),ln_inst+2);
                                                          (yyval.cl).lls = createList(ln_inst);
                                                          goto_emet(0);
                                                        }
#line 1859 "exemple.tab.c"
    break;

  case 40:
#line 348 "exemple.y"
                                                        {
                                                          error_treatment(&(yyvsp[-3].cl.st),&(yyvsp[-1].cl.st),NULL);
                                                          emet((yyvsp[-5].cl.st).value_data.ident.lexema, 0,&(yyvsp[-3].cl.st), NULL,NULL);
                                                          (yyvsp[-5].cl.st).value_data.id_type = INT_TYPE;
                                                          saveInto((yyvsp[-5].cl.st).value_data.ident.lexema,&(yyvsp[-5].cl.st));
                                                          sym_value_type aux;
                                                          aux.value_data.enter = 1;
                                                          aux.value_type = INT_TYPE;
                                                          (yyval.cl).inc = aux;
                                                          (yyval.cl).st = (yyvsp[-5].cl.st);
                                                          (yyval.cl).ln = ln_inst;
                                                          if_emet(&(yyvsp[-5].cl.st),"LS",&(yyvsp[-1].cl.st),ln_inst+2);
                                                          (yyval.cl).lls = createList(ln_inst);
                                                          goto_emet(0);
                                                        }
#line 1879 "exemple.tab.c"
    break;

  case 41:
#line 364 "exemple.y"
                                { (yyval.cl.st.value_data.ident.lexema) = "GT";  }
#line 1885 "exemple.tab.c"
    break;

  case 42:
#line 365 "exemple.y"
                                { (yyval.cl.st.value_data.ident.lexema) = "GE";  }
#line 1891 "exemple.tab.c"
    break;

  case 43:
#line 366 "exemple.y"
                                { (yyval.cl.st.value_data.ident.lexema) = "LT";  }
#line 1897 "exemple.tab.c"
    break;

  case 44:
#line 367 "exemple.y"
                                { (yyval.cl.st.value_data.ident.lexema) = "LE";  }
#line 1903 "exemple.tab.c"
    break;

  case 45:
#line 368 "exemple.y"
                                { (yyval.cl.st.value_data.ident.lexema) = "EQ";  }
#line 1909 "exemple.tab.c"
    break;

  case 46:
#line 369 "exemple.y"
                                { (yyval.cl.st.value_data.ident.lexema) = "NEQ"; }
#line 1915 "exemple.tab.c"
    break;

  case 47:
#line 370 "exemple.y"
                                { (yyval.cl.st.value_data.ident.lexema) = "NOT"; }
#line 1921 "exemple.tab.c"
    break;

  case 48:
#line 372 "exemple.y"
                        { (yyval.cl.st).value_type = FLOAT_TYPE; (yyval.cl.st).value_data.real = (yyvsp[0].cl.st.value_data.real);  }
#line 1927 "exemple.tab.c"
    break;

  case 49:
#line 373 "exemple.y"
                        { (yyval.cl.st).value_type = INT_TYPE; (yyval.cl.st).value_data.enter = (yyvsp[0].cl.st.value_data.enter); }
#line 1933 "exemple.tab.c"
    break;

  case 50:
#line 376 "exemple.y"
                                { row_value(&(yyval.cl.st),(yyvsp[-2].cl.st),(yyvsp[0].cl.st)); }
#line 1939 "exemple.tab.c"
    break;

  case 51:
#line 377 "exemple.y"
                                { (yyval.cl.st).value_data.row = 1; }
#line 1945 "exemple.tab.c"
    break;

  case 52:
#line 379 "exemple.y"
                                { col_value(&(yyval.cl.st),(yyvsp[-2].cl.st),(yyvsp[0].cl.st)); }
#line 1951 "exemple.tab.c"
    break;

  case 53:
#line 380 "exemple.y"
                                { col_ini(&(yyval.cl.st), (yyvsp[0].cl.st));}
#line 1957 "exemple.tab.c"
    break;

  case 54:
#line 382 "exemple.y"
                                { sum_op(&(yyval.cl.st),(yyvsp[-2].cl.st),(yyvsp[0].cl.st)); }
#line 1963 "exemple.tab.c"
    break;

  case 55:
#line 383 "exemple.y"
                                { rest_op(&(yyval.cl.st),(yyvsp[-2].cl.st),(yyvsp[0].cl.st)); }
#line 1969 "exemple.tab.c"
    break;

  case 57:
#line 386 "exemple.y"
                              { mul_op(&(yyval.cl.st),(yyvsp[-2].cl.st),(yyvsp[0].cl.st)); }
#line 1975 "exemple.tab.c"
    break;

  case 58:
#line 387 "exemple.y"
                              { div_op(&(yyval.cl.st),(yyvsp[-2].cl.st),(yyvsp[0].cl.st)); }
#line 1981 "exemple.tab.c"
    break;

  case 59:
#line 388 "exemple.y"
                              { mod_op(&(yyval.cl.st),(yyvsp[-2].cl.st),(yyvsp[0].cl.st)); }
#line 1987 "exemple.tab.c"
    break;

  case 61:
#line 391 "exemple.y"
                            { pow_op(&(yyval.cl.st),(yyvsp[-2].cl.st),(yyvsp[0].cl.st)); }
#line 1993 "exemple.tab.c"
    break;

  case 63:
#line 394 "exemple.y"
                                             { (yyval.cl.st).value_type = FLOAT_TYPE; (yyval.cl.st).value_data.real = (yyvsp[0].cl.st.value_data.real); }
#line 1999 "exemple.tab.c"
    break;

  case 64:
#line 395 "exemple.y"
                                             { (yyval.cl.st).value_type = INT_TYPE; (yyval.cl.st).value_data.enter = (yyvsp[0].cl.st.value_data.enter); }
#line 2005 "exemple.tab.c"
    break;

  case 65:
#line 396 "exemple.y"
                                             { (yyval.cl.st) = (yyvsp[-1].cl.st); }
#line 2011 "exemple.tab.c"
    break;

  case 66:
#line 397 "exemple.y"
                                             { if(sym_lookup((yyvsp[0].cl.st).value_data.ident.lexema, &(yyval.cl.st)) == SYMTAB_NOT_FOUND) yyerror("Var doesn't exit"); }
#line 2017 "exemple.tab.c"
    break;

  case 67:
#line 398 "exemple.y"
                                             { (yyval.cl.st) = (yyvsp[-1].cl.st); }
#line 2023 "exemple.tab.c"
    break;

  case 68:
#line 399 "exemple.y"
                                             { acces_vector(&(yyval.cl.st), (yyvsp[-3].cl.st).value_data.ident.lexema, (yyvsp[-1].cl.st)); }
#line 2029 "exemple.tab.c"
    break;

  case 69:
#line 400 "exemple.y"
                                             { acces_matrix(&(yyval.cl.st), (yyvsp[-5].cl.st).value_data.ident.lexema, (yyvsp[-3].cl.st), (yyvsp[-1].cl.st)); }
#line 2035 "exemple.tab.c"
    break;

  case 70:
#line 401 "exemple.y"
                                             {
                                                if(sym_lookup((yyvsp[-3].cl.st).value_data.ident.lexema, &(yyval.cl.st)) == SYMTAB_NOT_FOUND) yyerror("Var doesn't exit");
                                                if((yyval.cl.st).value_type == FUNCTION){

                                                  if((yyval.cl.st).value_data.cont_params < (yyvsp[-1].cl.st).value_data.cont_params) yyerror("Too much parameters.");
                                                  if((yyval.cl.st).value_data.cont_params > (yyvsp[-1].cl.st).value_data.cont_params) yyerror("Not enough parameters.");

                                                  if((yyval.cl.st).value_data.return_type != UNKNOWN_TYPE){
                                                    (yyval.cl.st).value_data.tmp_type = (yyval.cl.st).value_data.return_type;
                                                    long tmp = getTmp();
                                                    emet(NULL,tmp,NULL,"CALL",&(yyval.cl.st));
                                                    (yyval.cl.st).value_data.tmp_val = tmp;
                                                    (yyval.cl.st).value_type = TMP_TYPE;
                                                  }else{
                                                    emet(NULL,0,NULL,"CALL",&(yyval.cl.st));
                                                  }
                                                }else yyerror("Only work with function type");
      }
#line 2058 "exemple.tab.c"
    break;

  case 71:
#line 420 "exemple.y"
                                            { (yyval.cl.st).value_data.cont_params+= 1; emet(NULL,0,NULL,"PARAM",&(yyvsp[0].cl.st)); }
#line 2064 "exemple.tab.c"
    break;

  case 72:
#line 421 "exemple.y"
                                            { (yyval.cl.st).value_data.cont_params = 1; emet(NULL,0,NULL,"PARAM",&(yyvsp[0].cl.st)); }
#line 2070 "exemple.tab.c"
    break;

  case 73:
#line 422 "exemple.y"
                                            { (yyval.cl.st).value_data.cont_params = 0; }
#line 2076 "exemple.tab.c"
    break;


#line 2080 "exemple.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 425 "exemple.y"

