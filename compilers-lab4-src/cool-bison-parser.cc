/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         cool_yyparse
#define yylex           cool_yylex
#define yyerror         cool_yyerror
#define yydebug         cool_yydebug
#define yynerrs         cool_yynerrs
#define yylval          cool_yylval
#define yychar          cool_yychar
#define yylloc          cool_yylloc

/* First part of user prologue.  */
#line 2 "cool.bison"

#include <iostream>
#include "cool-tree.h"
#include "stringtab.h"
#include "utilities.h"

extern char *curr_filename;

/*
 * Default locations represent a range in the source file, but this is not a requirement.
 * It could be a single point or just a line number, or even more complex structures.
 */
#define YYLTYPE int

/*
 * The function yyparse expects to find the textual location of a token just parsed in the global variable yylloc.
 * So yylex must store the proper data in that variable.
 */
#define cool_yylloc curr_lineno

/*
 * YYLLOC_DEFAULT macro is invoked each time a rule is matched, before the associated action is run.
 */
extern int node_lineno;
#define YYLLOC_DEFAULT(Current, Rhs, N)  { Current = Rhs[1]; node_lineno = Current; }
#define SET_NODELOC(Current)  { node_lineno = Current; }

/* Root of AST */
Program ast_root;

/* List of classes */
Classes parse_results;

/* Number of parsing errors */
int parse_errors = 0;

void yyerror(char *s);
extern int yylex();


#line 120 "cool-bison-parser.cc"

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

#include "cool-bison-parser.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CLASS = 3,                      /* CLASS  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FI = 5,                         /* FI  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_IN = 7,                         /* IN  */
  YYSYMBOL_INHERITS = 8,                   /* INHERITS  */
  YYSYMBOL_LET = 9,                        /* LET  */
  YYSYMBOL_LOOP = 10,                      /* LOOP  */
  YYSYMBOL_POOL = 11,                      /* POOL  */
  YYSYMBOL_THEN = 12,                      /* THEN  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_CASE = 14,                      /* CASE  */
  YYSYMBOL_ESAC = 15,                      /* ESAC  */
  YYSYMBOL_OF = 16,                        /* OF  */
  YYSYMBOL_DARROW = 17,                    /* DARROW  */
  YYSYMBOL_NEW = 18,                       /* NEW  */
  YYSYMBOL_ISVOID = 19,                    /* ISVOID  */
  YYSYMBOL_STR_CONST = 20,                 /* STR_CONST  */
  YYSYMBOL_INT_CONST = 21,                 /* INT_CONST  */
  YYSYMBOL_BOOL_CONST = 22,                /* BOOL_CONST  */
  YYSYMBOL_TYPEID = 23,                    /* TYPEID  */
  YYSYMBOL_OBJECTID = 24,                  /* OBJECTID  */
  YYSYMBOL_ASSIGN = 25,                    /* ASSIGN  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_LE = 27,                        /* LE  */
  YYSYMBOL_ERROR = 28,                     /* ERROR  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '-'  */
  YYSYMBOL_33_ = 33,                       /* '*'  */
  YYSYMBOL_34_ = 34,                       /* '~'  */
  YYSYMBOL_35_ = 35,                       /* '@'  */
  YYSYMBOL_36_ = 36,                       /* '.'  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* ':'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_class_list = 47,                /* class_list  */
  YYSYMBOL_class = 48,                     /* class  */
  YYSYMBOL_feature_list = 49,              /* feature_list  */
  YYSYMBOL_feature = 50,                   /* feature  */
  YYSYMBOL_formal_list = 51,               /* formal_list  */
  YYSYMBOL_formal = 52,                    /* formal  */
  YYSYMBOL_expr_list_comma = 53,           /* expr_list_comma  */
  YYSYMBOL_expr_list_simicolon = 54,       /* expr_list_simicolon  */
  YYSYMBOL_expr = 55,                      /* expr  */
  YYSYMBOL_case_list = 56,                 /* case_list  */
  YYSYMBOL_case = 57,                      /* case  */
  YYSYMBOL_let_expr = 58,                  /* let_expr  */
  YYSYMBOL_let_binding_list = 59,          /* let_binding_list  */
  YYSYMBOL_let_binding = 60,               /* let_binding  */
  YYSYMBOL_optional_assign = 61            /* optional_assign  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,    33,    31,    43,    32,    36,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    37,
      29,    30,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,    34,     2,     2,     2,
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
      25,    26,    27,    28,     2
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   111,   111,   116,   118,   120,   127,   129,   136,   137,
     142,   144,   146,   151,   152,   154,   159,   165,   166,   168,
     173,   175,   177,   181,   183,   185,   187,   189,   192,   194,
     196,   199,   202,   205,   208,   210,   213,   216,   219,   221,
     223,   225,   227,   229,   231,   233,   235,   238,   244,   245,
     250,   255,   267,   269,   271,   275,   281,   282
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CLASS", "ELSE", "FI",
  "IF", "IN", "INHERITS", "LET", "LOOP", "POOL", "THEN", "WHILE", "CASE",
  "ESAC", "OF", "DARROW", "NEW", "ISVOID", "STR_CONST", "INT_CONST",
  "BOOL_CONST", "TYPEID", "OBJECTID", "ASSIGN", "NOT", "LE", "ERROR",
  "'<'", "'='", "'+'", "'-'", "'*'", "'~'", "'@'", "'.'", "';'", "'{'",
  "'}'", "':'", "'('", "')'", "','", "'/'", "$accept", "program",
  "class_list", "class", "feature_list", "feature", "formal_list",
  "formal", "expr_list_comma", "expr_list_simicolon", "expr", "case_list",
  "case", "let_expr", "let_binding_list", "let_binding", "optional_assign", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      62,   -26,    -2,    35,    61,  -111,    61,    11,  -111,  -111,
    -111,    15,  -111,    18,     1,  -111,    16,    42,    41,  -111,
      12,  -111,    63,    60,  -111,    65,    70,    66,    50,  -111,
    -111,   142,    67,    80,    69,    60,   142,    13,   142,   142,
      82,   142,  -111,  -111,  -111,   -21,   142,   142,    53,   142,
     299,  -111,  -111,  -111,    84,  -111,   188,    68,    81,     5,
    -111,   155,   209,  -111,    45,   142,   142,   299,    45,    85,
     111,   219,   235,   142,   142,   142,   142,   142,   142,   100,
     102,   142,    90,   142,   110,   113,   142,   110,   142,  -111,
     299,    54,   299,  -111,  -111,   251,  -111,  -111,   309,   309,
     309,    25,    25,    45,   103,    97,   299,   142,    -3,  -111,
      70,   299,  -111,   178,     7,  -111,   142,  -111,   116,   142,
     267,   142,  -111,  -111,  -111,   101,  -111,   299,   105,    56,
     106,    83,   119,   142,  -111,  -111,  -111,   127,    58,   142,
    -111,   283,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     0,     0,     1,     4,
       5,     0,     8,     0,     0,     8,     0,     0,     0,     9,
       0,    12,     0,    13,     6,     0,    56,     0,     0,    14,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,     0,     0,     0,     0,
      57,    34,    10,    16,     0,    15,     0,     0,     0,     0,
      52,     0,     0,    36,    37,     0,    17,    46,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      27,     0,    18,    22,    33,     0,    20,    47,    45,    43,
      44,    38,    39,    40,     0,     0,    41,     0,     0,    54,
      56,    51,    53,     0,     0,    29,     0,    21,     0,    17,
       0,     0,    55,    32,    35,     0,    49,    19,     0,     0,
       0,     0,     0,    17,    28,    11,    31,     0,     0,     0,
      30,     0,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,    64,   132,  -111,  -111,   118,  -110,  -111,
     -31,  -111,  -111,  -111,  -111,   -81,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    14,    19,    28,    29,    91,    70,
      92,   114,   126,    51,    59,    60,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,   121,    16,   109,    65,    56,   112,    61,    62,   129,
      64,     6,    86,    16,    57,    67,    68,    71,    72,    11,
      66,     7,   124,   138,    73,    17,    74,    75,    76,    77,
      78,   125,    79,    80,    90,     8,    17,    58,    13,    95,
      18,    81,    98,    99,   100,   101,   102,   103,    87,    12,
     106,    25,   108,    21,    69,   111,    15,   113,    78,    36,
      79,    80,    37,     1,     2,     2,    38,    39,     9,    81,
      10,    40,    41,    42,    43,    44,   120,    45,    24,    46,
      79,    80,    22,    23,    27,   127,    26,    47,   136,    81,
     131,    48,    34,    35,    49,    31,   115,   116,   134,   116,
     140,   116,    30,    53,    52,    63,    33,    82,   141,    54,
      73,    84,    74,    75,    76,    77,    78,    36,    79,    80,
      37,    85,    93,   104,    38,    39,   105,    81,   107,    40,
      41,    42,    43,    44,    58,    45,   110,    46,   119,   118,
     128,   132,   137,   135,   139,    47,   133,    20,    36,    48,
      94,    37,    49,    55,   122,    38,    39,     0,     0,     0,
      40,    41,    42,    43,    44,    88,    45,     0,    46,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,     0,
      48,     0,    73,    49,    74,    75,    76,    77,    78,   123,
      79,    80,     0,     0,     0,     0,     0,     0,     0,    81,
      83,     0,     0,     0,     0,    73,     0,    74,    75,    76,
      77,    78,     0,    79,    80,    73,     0,    74,    75,    76,
      77,    78,    81,    79,    80,    89,     0,     0,     0,     0,
       0,     0,    81,     0,     0,     0,    73,     0,    74,    75,
      76,    77,    78,     0,    79,    80,    73,     0,    74,    75,
      76,    77,    78,    81,    79,    80,    96,     0,     0,     0,
       0,     0,    73,    81,    74,    75,    76,    77,    78,     0,
      79,    80,     0,     0,     0,     0,     0,    97,    73,    81,
      74,    75,    76,    77,    78,     0,    79,    80,   117,     0,
       0,     0,     0,     0,    73,    81,    74,    75,    76,    77,
      78,     0,    79,    80,     0,     0,   130,     0,     0,     0,
      73,    81,    74,    75,    76,    77,    78,     0,    79,    80,
     142,     0,     0,     0,     0,     0,    73,    81,    74,    75,
      76,    77,    78,     0,    79,    80,    -1,     0,    -1,    -1,
      76,    77,    78,    81,    79,    80,     0,     0,     0,     0,
       0,     0,     0,    81
};

static const yytype_int16 yycheck[] =
{
      31,     4,     1,    84,    25,    36,    87,    38,    39,   119,
      41,    37,     7,     1,     1,    46,    47,    48,    49,     8,
      41,    23,    15,   133,    27,    24,    29,    30,    31,    32,
      33,    24,    35,    36,    65,     0,    24,    24,    23,    70,
      39,    44,    73,    74,    75,    76,    77,    78,    43,    38,
      81,    39,    83,    37,     1,    86,    38,    88,    33,     6,
      35,    36,     9,     1,     3,     3,    13,    14,     4,    44,
       6,    18,    19,    20,    21,    22,   107,    24,    37,    26,
      35,    36,    40,    41,    24,   116,    23,    34,     5,    44,
     121,    38,    42,    43,    41,    25,    42,    43,    42,    43,
      42,    43,    37,    23,    37,    23,    40,    23,   139,    40,
      27,    43,    29,    30,    31,    32,    33,     6,    35,    36,
       9,    40,    37,    23,    13,    14,    24,    44,    38,    18,
      19,    20,    21,    22,    24,    24,    23,    26,    41,    36,
      24,    40,    23,    37,    17,    34,    41,    15,     6,    38,
      39,     9,    41,    35,   110,    13,    14,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    10,    24,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      38,    -1,    27,    41,    29,    30,    31,    32,    33,    11,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      12,    -1,    -1,    -1,    -1,    27,    -1,    29,    30,    31,
      32,    33,    -1,    35,    36,    27,    -1,    29,    30,    31,
      32,    33,    44,    35,    36,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    27,    -1,    29,    30,
      31,    32,    33,    -1,    35,    36,    27,    -1,    29,    30,
      31,    32,    33,    44,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    27,    44,    29,    30,    31,    32,    33,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    42,    27,    44,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    27,    44,    29,    30,    31,    32,
      33,    -1,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      27,    44,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    27,    44,    29,    30,
      31,    32,    33,    -1,    35,    36,    27,    -1,    29,    30,
      31,    32,    33,    44,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    46,    47,    48,    37,    23,     0,    48,
      48,     8,    38,    23,    49,    38,     1,    24,    39,    50,
      49,    37,    40,    41,    37,    39,    23,    24,    51,    52,
      37,    25,    61,    40,    42,    43,     6,     9,    13,    14,
      18,    19,    20,    21,    22,    24,    26,    34,    38,    41,
      55,    58,    37,    23,    40,    52,    55,     1,    24,    59,
      60,    55,    55,    23,    55,    25,    41,    55,    55,     1,
      54,    55,    55,    27,    29,    30,    31,    32,    33,    35,
      36,    44,    23,    12,    43,    40,     7,    43,    10,    16,
      55,    53,    55,    37,    39,    55,    37,    42,    55,    55,
      55,    55,    55,    55,    23,    24,    55,    38,    55,    60,
      23,    55,    60,    55,    56,    42,    43,    37,    36,    41,
      55,     4,    61,    11,    15,    24,    57,    55,    24,    53,
      39,    55,    40,    41,    42,    37,     5,    23,    53,    17,
      42,    55,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    47,    48,    48,    49,    49,
      50,    50,    50,    51,    51,    51,    52,    53,    53,    53,
      54,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    56,
      57,    58,    59,    59,    59,    60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     6,     8,     0,     2,
       5,    10,     2,     0,     1,     3,     3,     0,     1,     3,
       2,     3,     2,     1,     1,     1,     1,     3,     6,     4,
       8,     7,     5,     3,     1,     5,     2,     2,     3,     3,
       3,     3,     2,     3,     3,     3,     2,     3,     0,     2,
       6,     4,     1,     3,     3,     4,     0,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: class_list  */
#line 111 "cool.bison"
                     {  (yyloc) = (yylsp[0]); ast_root = program((yyvsp[0].classes)); }
#line 1409 "cool-bison-parser.cc"
    break;

  case 3: /* class_list: class  */
#line 117 "cool.bison"
  { (yyval.classes) = single_Classes((yyvsp[0].class_)); parse_results = (yyval.classes); }
#line 1415 "cool-bison-parser.cc"
    break;

  case 4: /* class_list: class_list class  */
#line 119 "cool.bison"
  { (yyval.classes) = append_Classes((yyvsp[-1].classes), single_Classes((yyvsp[0].class_))); parse_results = (yyval.classes); }
#line 1421 "cool-bison-parser.cc"
    break;

  case 5: /* class_list: error ';' class  */
#line 121 "cool.bison"
  { (yyval.classes) = single_Classes((yyvsp[0].class_)); yyerrok; }
#line 1427 "cool-bison-parser.cc"
    break;

  case 6: /* class: CLASS TYPEID '{' feature_list '}' ';'  */
#line 128 "cool.bison"
  { (yyval.class_) = class_((yyvsp[-4].symbol), idtable.add_string("Object"), (yyvsp[-2].features), stringtable.add_string(curr_filename)); }
#line 1433 "cool-bison-parser.cc"
    break;

  case 7: /* class: CLASS TYPEID INHERITS TYPEID '{' feature_list '}' ';'  */
#line 130 "cool.bison"
  { (yyval.class_) = class_((yyvsp[-6].symbol), (yyvsp[-4].symbol), (yyvsp[-2].features), stringtable.add_string(curr_filename)); }
#line 1439 "cool-bison-parser.cc"
    break;

  case 8: /* feature_list: %empty  */
#line 136 "cool.bison"
  { (yyval.features) = nil_Features(); }
#line 1445 "cool-bison-parser.cc"
    break;

  case 9: /* feature_list: feature_list feature  */
#line 138 "cool.bison"
  { (yyval.features) = append_Features((yyvsp[-1].features), single_Features((yyvsp[0].feature))); }
#line 1451 "cool-bison-parser.cc"
    break;

  case 10: /* feature: OBJECTID ':' TYPEID optional_assign ';'  */
#line 143 "cool.bison"
  { (yyval.feature) = attr((yyvsp[-4].symbol), (yyvsp[-2].symbol), (yyvsp[-1].expression)); }
#line 1457 "cool-bison-parser.cc"
    break;

  case 11: /* feature: OBJECTID '(' formal_list ')' ':' TYPEID '{' expr '}' ';'  */
#line 145 "cool.bison"
  { (yyval.feature) = method((yyvsp[-9].symbol), (yyvsp[-7].formals), (yyvsp[-4].symbol), (yyvsp[-2].expression)); }
#line 1463 "cool-bison-parser.cc"
    break;

  case 12: /* feature: error ';'  */
#line 146 "cool.bison"
            {}
#line 1469 "cool-bison-parser.cc"
    break;

  case 13: /* formal_list: %empty  */
#line 151 "cool.bison"
  { (yyval.formals) = nil_Formals(); }
#line 1475 "cool-bison-parser.cc"
    break;

  case 14: /* formal_list: formal  */
#line 153 "cool.bison"
  { (yyval.formals) = single_Formals((yyvsp[0].formal)); }
#line 1481 "cool-bison-parser.cc"
    break;

  case 15: /* formal_list: formal_list ',' formal  */
#line 155 "cool.bison"
  { (yyval.formals) = append_Formals((yyvsp[-2].formals), single_Formals((yyvsp[0].formal))); }
#line 1487 "cool-bison-parser.cc"
    break;

  case 16: /* formal: OBJECTID ':' TYPEID  */
#line 160 "cool.bison"
  { (yyval.formal) = formal((yyvsp[-2].symbol), (yyvsp[0].symbol)); }
#line 1493 "cool-bison-parser.cc"
    break;

  case 17: /* expr_list_comma: %empty  */
#line 165 "cool.bison"
  { (yyval.expressions) = nil_Expressions(); }
#line 1499 "cool-bison-parser.cc"
    break;

  case 18: /* expr_list_comma: expr  */
#line 167 "cool.bison"
  { (yyval.expressions) = single_Expressions((yyvsp[0].expression)); }
#line 1505 "cool-bison-parser.cc"
    break;

  case 19: /* expr_list_comma: expr_list_comma ',' expr  */
#line 169 "cool.bison"
  { (yyval.expressions) = append_Expressions((yyvsp[-2].expressions), single_Expressions((yyvsp[0].expression))); }
#line 1511 "cool-bison-parser.cc"
    break;

  case 20: /* expr_list_simicolon: expr ';'  */
#line 174 "cool.bison"
  { (yyval.expressions) = single_Expressions((yyvsp[-1].expression)); }
#line 1517 "cool-bison-parser.cc"
    break;

  case 21: /* expr_list_simicolon: expr_list_simicolon expr ';'  */
#line 176 "cool.bison"
  { (yyval.expressions) = append_Expressions((yyvsp[-2].expressions), single_Expressions((yyvsp[-1].expression))); }
#line 1523 "cool-bison-parser.cc"
    break;

  case 22: /* expr_list_simicolon: error ';'  */
#line 177 "cool.bison"
            { yyerrok; }
#line 1529 "cool-bison-parser.cc"
    break;

  case 23: /* expr: STR_CONST  */
#line 182 "cool.bison"
  { (yyval.expression) = string_const((yyvsp[0].symbol)); }
#line 1535 "cool-bison-parser.cc"
    break;

  case 24: /* expr: INT_CONST  */
#line 184 "cool.bison"
  { (yyval.expression) = int_const((yyvsp[0].symbol)); }
#line 1541 "cool-bison-parser.cc"
    break;

  case 25: /* expr: BOOL_CONST  */
#line 186 "cool.bison"
  { (yyval.expression) = bool_const((yyvsp[0].boolean)); }
#line 1547 "cool-bison-parser.cc"
    break;

  case 26: /* expr: OBJECTID  */
#line 188 "cool.bison"
  { (yyval.expression) = object((yyvsp[0].symbol)); }
#line 1553 "cool-bison-parser.cc"
    break;

  case 27: /* expr: OBJECTID ASSIGN expr  */
#line 190 "cool.bison"
  { (yyval.expression) = assign((yyvsp[-2].symbol), (yyvsp[0].expression)); }
#line 1559 "cool-bison-parser.cc"
    break;

  case 28: /* expr: expr '.' OBJECTID '(' expr_list_comma ')'  */
#line 193 "cool.bison"
  { (yyval.expression) = dispatch((yyvsp[-5].expression), (yyvsp[-3].symbol), (yyvsp[-1].expressions)); }
#line 1565 "cool-bison-parser.cc"
    break;

  case 29: /* expr: OBJECTID '(' expr_list_comma ')'  */
#line 195 "cool.bison"
  { (yyval.expression) = dispatch(object(idtable.add_string("self")), (yyvsp[-3].symbol), (yyvsp[-1].expressions)); }
#line 1571 "cool-bison-parser.cc"
    break;

  case 30: /* expr: expr '@' TYPEID '.' OBJECTID '(' expr_list_comma ')'  */
#line 197 "cool.bison"
  { (yyval.expression) = static_dispatch((yyvsp[-7].expression), (yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expressions)); }
#line 1577 "cool-bison-parser.cc"
    break;

  case 31: /* expr: IF expr THEN expr ELSE expr FI  */
#line 200 "cool.bison"
  { (yyval.expression) = cond((yyvsp[-5].expression), (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1583 "cool-bison-parser.cc"
    break;

  case 32: /* expr: WHILE expr LOOP expr POOL  */
#line 203 "cool.bison"
  { (yyval.expression) = loop((yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1589 "cool-bison-parser.cc"
    break;

  case 33: /* expr: '{' expr_list_simicolon '}'  */
#line 206 "cool.bison"
  { (yyval.expression) = block((yyvsp[-1].expressions)); }
#line 1595 "cool-bison-parser.cc"
    break;

  case 34: /* expr: let_expr  */
#line 209 "cool.bison"
  { (yyval.expression) = (yyvsp[0].expression); }
#line 1601 "cool-bison-parser.cc"
    break;

  case 35: /* expr: CASE expr OF case_list ESAC  */
#line 211 "cool.bison"
  { (yyval.expression) = typcase((yyvsp[-3].expression), (yyvsp[-1].cases)); }
#line 1607 "cool-bison-parser.cc"
    break;

  case 36: /* expr: NEW TYPEID  */
#line 214 "cool.bison"
  { (yyval.expression) = new_((yyvsp[0].symbol)); }
#line 1613 "cool-bison-parser.cc"
    break;

  case 37: /* expr: ISVOID expr  */
#line 217 "cool.bison"
  { (yyval.expression) = isvoid((yyvsp[0].expression)); }
#line 1619 "cool-bison-parser.cc"
    break;

  case 38: /* expr: expr '+' expr  */
#line 220 "cool.bison"
  { (yyval.expression) = plus((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1625 "cool-bison-parser.cc"
    break;

  case 39: /* expr: expr '-' expr  */
#line 222 "cool.bison"
  { (yyval.expression) = sub((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1631 "cool-bison-parser.cc"
    break;

  case 40: /* expr: expr '*' expr  */
#line 224 "cool.bison"
  { (yyval.expression) = mul((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1637 "cool-bison-parser.cc"
    break;

  case 41: /* expr: expr '/' expr  */
#line 226 "cool.bison"
  { (yyval.expression) = divide((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1643 "cool-bison-parser.cc"
    break;

  case 42: /* expr: '~' expr  */
#line 228 "cool.bison"
  { (yyval.expression) = neg((yyvsp[0].expression)); }
#line 1649 "cool-bison-parser.cc"
    break;

  case 43: /* expr: expr '<' expr  */
#line 230 "cool.bison"
  { (yyval.expression) = lt((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1655 "cool-bison-parser.cc"
    break;

  case 44: /* expr: expr '=' expr  */
#line 232 "cool.bison"
  { (yyval.expression) = eq((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1661 "cool-bison-parser.cc"
    break;

  case 45: /* expr: expr LE expr  */
#line 234 "cool.bison"
  { (yyval.expression) = leq((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1667 "cool-bison-parser.cc"
    break;

  case 46: /* expr: NOT expr  */
#line 236 "cool.bison"
  { (yyval.expression) = comp((yyvsp[0].expression)); }
#line 1673 "cool-bison-parser.cc"
    break;

  case 47: /* expr: '(' expr ')'  */
#line 239 "cool.bison"
  { (yyval.expression) = (yyvsp[-1].expression); }
#line 1679 "cool-bison-parser.cc"
    break;

  case 48: /* case_list: %empty  */
#line 244 "cool.bison"
  { (yyval.cases) = nil_Cases(); }
#line 1685 "cool-bison-parser.cc"
    break;

  case 49: /* case_list: case_list case  */
#line 246 "cool.bison"
  { (yyval.cases) = append_Cases((yyvsp[-1].cases), single_Cases((yyvsp[0].case_))); }
#line 1691 "cool-bison-parser.cc"
    break;

  case 50: /* case: OBJECTID ':' TYPEID DARROW expr ';'  */
#line 251 "cool.bison"
  { (yyval.case_) = branch((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression)); }
#line 1697 "cool-bison-parser.cc"
    break;

  case 51: /* let_expr: LET let_binding_list IN expr  */
#line 256 "cool.bison"
  {
    auto bind = (yyvsp[-2].expression);
    bind->set_body((yyvsp[0].expression));
    while (bind->parent) {
        bind = bind->parent;
    }
    (yyval.expression) = bind;
  }
#line 1710 "cool-bison-parser.cc"
    break;

  case 52: /* let_binding_list: let_binding  */
#line 268 "cool.bison"
  { (yyval.expression) = (yyvsp[0].expression); }
#line 1716 "cool-bison-parser.cc"
    break;

  case 53: /* let_binding_list: let_binding_list ',' let_binding  */
#line 270 "cool.bison"
  { auto bind = (yyvsp[-2].expression); bind->set_body((yyvsp[0].expression)); (yyval.expression) = (yyvsp[0].expression); }
#line 1722 "cool-bison-parser.cc"
    break;

  case 54: /* let_binding_list: error ',' let_binding  */
#line 271 "cool.bison"
                        { yyerrok; (yyval.expression) = (yyvsp[0].expression); }
#line 1728 "cool-bison-parser.cc"
    break;

  case 55: /* let_binding: OBJECTID ':' TYPEID optional_assign  */
#line 276 "cool.bison"
  { auto res = let((yyvsp[-3].symbol), (yyvsp[-1].symbol), (yyvsp[0].expression), no_expr()); (yyval.expression) = res; }
#line 1734 "cool-bison-parser.cc"
    break;

  case 56: /* optional_assign: %empty  */
#line 281 "cool.bison"
  { (yyval.expression) = no_expr(); }
#line 1740 "cool-bison-parser.cc"
    break;

  case 57: /* optional_assign: ASSIGN expr  */
#line 283 "cool.bison"
  { (yyval.expression) = (yyvsp[0].expression); }
#line 1746 "cool-bison-parser.cc"
    break;


#line 1750 "cool-bison-parser.cc"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 286 "cool.bison"


void yyerror(char *s)
{
    std::cerr << "Error: \"" << curr_filename << "\", line " << curr_lineno << ": " \
         << s << " at or near ";
    print_cool_token(yychar);
    std::cerr << std::endl;
    parse_errors++;

    if (parse_errors > 50) {
        std::fprintf(stdout, "More than 50 parse errors\n");
        std::exit(1);
    }
}
