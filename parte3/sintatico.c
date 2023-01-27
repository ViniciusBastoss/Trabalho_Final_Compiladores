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




/* First part of user prologue.  */
#line 1 "sintatico.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lexico.c"
#include "utils.c"
int contaVar, contaVarLocal = 0;  //conta numero de variaveis
int marcaPar = 0;
int rotulo = 0; //marca lugares no codigo
int tipo, escopo = GLOBAL;
char charAux[10],identificadores[30];

#line 84 "sintatico.c"

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

#include "sintatico.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_PROGRAMA = 3,                 /* T_PROGRAMA  */
  YYSYMBOL_T_INICIO = 4,                   /* T_INICIO  */
  YYSYMBOL_T_FIM = 5,                      /* T_FIM  */
  YYSYMBOL_T_LEIA = 6,                     /* T_LEIA  */
  YYSYMBOL_T_ESCREVA = 7,                  /* T_ESCREVA  */
  YYSYMBOL_T_SE = 8,                       /* T_SE  */
  YYSYMBOL_T_ENTAO = 9,                    /* T_ENTAO  */
  YYSYMBOL_T_SENAO = 10,                   /* T_SENAO  */
  YYSYMBOL_T_FIMSE = 11,                   /* T_FIMSE  */
  YYSYMBOL_T_ENQTO = 12,                   /* T_ENQTO  */
  YYSYMBOL_T_FACA = 13,                    /* T_FACA  */
  YYSYMBOL_T_FIMENQTO = 14,                /* T_FIMENQTO  */
  YYSYMBOL_T_INTEIRO = 15,                 /* T_INTEIRO  */
  YYSYMBOL_T_LOGICO = 16,                  /* T_LOGICO  */
  YYSYMBOL_T_MAIS = 17,                    /* T_MAIS  */
  YYSYMBOL_T_MENOS = 18,                   /* T_MENOS  */
  YYSYMBOL_T_VEZES = 19,                   /* T_VEZES  */
  YYSYMBOL_T_DIV = 20,                     /* T_DIV  */
  YYSYMBOL_T_ATRIBUI = 21,                 /* T_ATRIBUI  */
  YYSYMBOL_T_MAIOR = 22,                   /* T_MAIOR  */
  YYSYMBOL_T_MENOR = 23,                   /* T_MENOR  */
  YYSYMBOL_T_IGUAL = 24,                   /* T_IGUAL  */
  YYSYMBOL_T_E = 25,                       /* T_E  */
  YYSYMBOL_T_OU = 26,                      /* T_OU  */
  YYSYMBOL_T_NAO = 27,                     /* T_NAO  */
  YYSYMBOL_T_ABRE = 28,                    /* T_ABRE  */
  YYSYMBOL_T_FECHA = 29,                   /* T_FECHA  */
  YYSYMBOL_T_V = 30,                       /* T_V  */
  YYSYMBOL_T_F = 31,                       /* T_F  */
  YYSYMBOL_T_IDENTIF = 32,                 /* T_IDENTIF  */
  YYSYMBOL_T_NUMERO = 33,                  /* T_NUMERO  */
  YYSYMBOL_T_FUNC = 34,                    /* T_FUNC  */
  YYSYMBOL_T_FIMFUNC = 35,                 /* T_FIMFUNC  */
  YYSYMBOL_T_RETORNE = 36,                 /* T_RETORNE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_40_2 = 40,                      /* $@2  */
  YYSYMBOL_rotinas = 41,                   /* rotinas  */
  YYSYMBOL_42_3 = 42,                      /* $@3  */
  YYSYMBOL_lista_rotinas = 43,             /* lista_rotinas  */
  YYSYMBOL_rotina = 44,                    /* rotina  */
  YYSYMBOL_45_4 = 45,                      /* $@4  */
  YYSYMBOL_funcao = 46,                    /* funcao  */
  YYSYMBOL_47_5 = 47,                      /* $@5  */
  YYSYMBOL_48_6 = 48,                      /* $@6  */
  YYSYMBOL_lista_parametros = 49,          /* lista_parametros  */
  YYSYMBOL_parametro = 50,                 /* parametro  */
  YYSYMBOL_cabecalho = 51,                 /* cabecalho  */
  YYSYMBOL_variaveis = 52,                 /* variaveis  */
  YYSYMBOL_declaracao_variaveis = 53,      /* declaracao_variaveis  */
  YYSYMBOL_tipo = 54,                      /* tipo  */
  YYSYMBOL_lista_variaveis = 55,           /* lista_variaveis  */
  YYSYMBOL_lista_comandos = 56,            /* lista_comandos  */
  YYSYMBOL_comando = 57,                   /* comando  */
  YYSYMBOL_entrada_saida = 58,             /* entrada_saida  */
  YYSYMBOL_escrita = 59,                   /* escrita  */
  YYSYMBOL_leitura = 60,                   /* leitura  */
  YYSYMBOL_repeticao = 61,                 /* repeticao  */
  YYSYMBOL_62_7 = 62,                      /* $@7  */
  YYSYMBOL_63_8 = 63,                      /* $@8  */
  YYSYMBOL_selecao = 64,                   /* selecao  */
  YYSYMBOL_65_9 = 65,                      /* $@9  */
  YYSYMBOL_66_10 = 66,                     /* $@10  */
  YYSYMBOL_atribuicao = 67,                /* atribuicao  */
  YYSYMBOL_68_11 = 68,                     /* $@11  */
  YYSYMBOL_expressao = 69,                 /* expressao  */
  YYSYMBOL_chamada_func = 70,              /* chamada_func  */
  YYSYMBOL_71_12 = 71,                     /* $@12  */
  YYSYMBOL_72_13 = 72,                     /* $@13  */
  YYSYMBOL_lista_argumentos = 73,          /* lista_argumentos  */
  YYSYMBOL_argumento = 74,                 /* argumento  */
  YYSYMBOL_termo = 75                      /* termo  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    65,    62,    83,    85,    85,   101,   102,
     107,   107,   119,   131,   118,   148,   149,   153,   164,   169,
     170,   174,   175,   179,   181,   186,   202,   221,   222,   226,
     227,   228,   229,   230,   231,   246,   264,   265,   269,   274,
     281,   294,   299,   293,   318,   326,   317,   342,   341,   361,
     366,   371,   376,   381,   386,   391,   396,   401,   406,   412,
     414,   412,   425,   426,   428,   433,   442,   447,   452,   457,
     464
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
  "\"end of file\"", "error", "\"invalid token\"", "T_PROGRAMA",
  "T_INICIO", "T_FIM", "T_LEIA", "T_ESCREVA", "T_SE", "T_ENTAO", "T_SENAO",
  "T_FIMSE", "T_ENQTO", "T_FACA", "T_FIMENQTO", "T_INTEIRO", "T_LOGICO",
  "T_MAIS", "T_MENOS", "T_VEZES", "T_DIV", "T_ATRIBUI", "T_MAIOR",
  "T_MENOR", "T_IGUAL", "T_E", "T_OU", "T_NAO", "T_ABRE", "T_FECHA", "T_V",
  "T_F", "T_IDENTIF", "T_NUMERO", "T_FUNC", "T_FIMFUNC", "T_RETORNE",
  "$accept", "programa", "$@1", "$@2", "rotinas", "$@3", "lista_rotinas",
  "rotina", "$@4", "funcao", "$@5", "$@6", "lista_parametros", "parametro",
  "cabecalho", "variaveis", "declaracao_variaveis", "tipo",
  "lista_variaveis", "lista_comandos", "comando", "entrada_saida",
  "escrita", "leitura", "repeticao", "$@7", "$@8", "selecao", "$@9",
  "$@10", "atribuicao", "$@11", "expressao", "chamada_func", "$@12",
  "$@13", "lista_argumentos", "argumento", "termo", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       0,    -6,    28,   -38,   -38,   -38,    -3,   -38,   -38,   -38,
     -38,     2,    -4,   -38,    -7,    32,   -38,   -38,   -38,    -1,
       3,   -38,     4,    23,    21,    45,   -38,    36,    21,    51,
      -1,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,    -3,
     -38,   -38,    45,    45,   -38,   -38,    36,   -38,    86,   -38,
     -38,   -38,    62,    45,    46,    38,    86,   -38,   -38,   -38,
      37,   -38,    -2,    45,    45,    45,    45,    45,    45,    45,
      45,    45,   -38,    76,    45,   -38,   -38,   -38,    13,    13,
     -38,   -38,    42,    42,   111,    96,    96,    -1,   -38,    86,
     -38,    40,    80,    -1,    94,    -3,   -38,    77,   -38,    86,
     -38,    63,    -3,    65,    -1,   -38,    -3,   -38,   -38,   106,
     -38,   -38,   103,    -1,    97,   -38
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,    18,     1,    19,    24,    23,     3,
      20,     0,     5,    26,    22,     0,    10,    25,    21,    27,
       7,     9,     0,     0,     0,     0,    41,    47,     0,     0,
      27,    29,    37,    36,    30,    31,    32,    33,     8,     0,
      11,    40,     0,     0,    67,    68,    65,    66,    38,    39,
      58,    65,     0,     0,     0,     0,    34,    35,     4,    28,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,     0,    60,    12,    70,    51,    52,
      49,    50,    53,    54,    55,    56,    57,    27,    42,    48,
      63,     0,     0,    27,     0,    15,    45,     0,    61,    64,
      62,     0,    15,     0,    27,    43,    19,    16,    17,     0,
      13,    46,     0,    27,     0,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   115,   -38,   -38,
     -38,   -38,    34,   -38,   -38,    31,   124,   -37,   -38,   -30,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -24,   -14,   -38,   -38,   -38,   -38,    98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,    12,    15,    16,    20,    21,    22,    40,
      91,   112,   101,   102,     3,     9,    10,    11,    14,    29,
      30,    31,    32,    33,    34,    53,    93,    35,    87,   104,
      36,    54,    48,    37,    55,    90,    94,   100,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      59,    52,    60,     1,    56,    23,    24,    25,     7,     8,
      49,    26,     7,     8,    57,    63,    64,    65,    66,    62,
      67,    68,    69,    70,    71,    17,     4,    77,     5,    73,
      -6,    27,    65,    66,    13,    28,    19,   -10,    39,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    42,    43,
      89,    44,    45,    46,    47,    41,    58,    92,   103,    63,
      64,    65,    66,    97,   -59,   103,    75,    74,    95,    76,
      99,    72,    42,    43,   109,    44,    45,    51,    47,    63,
      64,    65,    66,   114,    67,    68,    69,    70,    71,    88,
      96,   105,   106,    63,    64,    65,    66,   108,    67,    68,
      69,    70,    71,    63,    64,    65,    66,   113,    67,    68,
      69,    70,    71,    63,    64,    65,    66,   111,    67,    68,
      69,    42,    43,    98,    44,    45,    51,    47,    63,    64,
      65,    66,   115,    67,    68,    38,   107,   110,    18,     0,
      61
};

static const yytype_int8 yycheck[] =
{
      30,    25,    39,     3,    28,     6,     7,     8,    15,    16,
      24,    12,    15,    16,    28,    17,    18,    19,    20,    43,
      22,    23,    24,    25,    26,    32,    32,    29,     0,    53,
      34,    32,    19,    20,    32,    36,     4,    34,    34,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    27,    28,
      74,    30,    31,    32,    33,    32,     5,    87,    95,    17,
      18,    19,    20,    93,    28,   102,    28,    21,    28,    32,
      94,     9,    27,    28,   104,    30,    31,    32,    33,    17,
      18,    19,    20,   113,    22,    23,    24,    25,    26,    13,
      10,    14,    29,    17,    18,    19,    20,    32,    22,    23,
      24,    25,    26,    17,    18,    19,    20,     4,    22,    23,
      24,    25,    26,    17,    18,    19,    20,    11,    22,    23,
      24,    27,    28,    29,    30,    31,    32,    33,    17,    18,
      19,    20,    35,    22,    23,    20,   102,   106,    14,    -1,
      42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    38,    51,    32,     0,    39,    15,    16,    52,
      53,    54,    40,    32,    55,    41,    42,    32,    53,     4,
      43,    44,    45,     6,     7,     8,    12,    32,    36,    56,
      57,    58,    59,    60,    61,    64,    67,    70,    44,    34,
      46,    32,    27,    28,    30,    31,    32,    33,    69,    70,
      75,    32,    69,    62,    68,    71,    69,    70,     5,    56,
      54,    75,    69,    17,    18,    19,    20,    22,    23,    24,
      25,    26,     9,    69,    21,    28,    32,    29,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    65,    13,    69,
      72,    47,    56,    63,    73,    28,    10,    56,    29,    69,
      74,    49,    50,    54,    66,    14,    29,    49,    32,    56,
      52,    11,    48,     4,    56,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    40,    38,    41,    42,    41,    43,    43,
      45,    44,    47,    48,    46,    49,    49,    50,    51,    52,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    58,    58,    59,    59,
      60,    62,    63,    61,    65,    66,    64,    68,    67,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    71,
      72,    70,    73,    73,    74,    75,    75,    75,    75,    75,
      75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     8,     0,     0,     2,     2,     1,
       0,     2,     0,     0,    12,     0,     2,     2,     2,     0,
       1,     3,     2,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     2,     2,
       2,     0,     0,     7,     0,     0,     9,     0,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     0,
       0,     6,     2,     0,     1,     1,     1,     1,     1,     2,
       3
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
#  undef YYSTACK_RELOCATE
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
  case 2: /* $@1: %empty  */
#line 63 "sintatico.y"
        {contaVar = 0;}
#line 1235 "sintatico.c"
    break;

  case 3: /* $@2: %empty  */
#line 65 "sintatico.y"
        { 
            mostraTabela();
            empilha(contaVar);
            if(contaVar){
               fprintf(yyout,"\tAMEM\t%d\n", contaVar); 
            }
        }
#line 1247 "sintatico.c"
    break;

  case 4: /* programa: cabecalho $@1 variaveis $@2 rotinas T_INICIO lista_comandos T_FIM  */
#line 74 "sintatico.y"
        { 
            int conta = desempilha();
            if (conta)
               fprintf(yyout,"\tDMEM\t%d\n", conta); 
            fprintf(yyout, "\tFIMP\n");    
        }
#line 1258 "sintatico.c"
    break;

  case 6: /* $@3: %empty  */
#line 85 "sintatico.y"
    {
        //desvio sempre para inicio programa
        fprintf(yyout,"\tDSVS\tL%d\n", rotulo);
        empilha(rotulo);
    }
#line 1268 "sintatico.c"
    break;

  case 7: /* rotinas: $@3 lista_rotinas  */
#line 93 "sintatico.y"
    {
        //marca inicio do programa (main)
        int rot = desempilha();
        fprintf(yyout,"L%d\tNADA\n", rot); 
    }
#line 1278 "sintatico.c"
    break;

  case 10: /* $@4: %empty  */
#line 107 "sintatico.y"
      {
        //marca a funcao e guarda seu rotulo
        fprintf(yyout,"L%d\tENSP\n", ++rotulo);
        strcpy(elemTab.rot,"L");
        sprintf(charAux, "%d", rotulo);
        strcat(elemTab.rot, charAux); 
      }
#line 1290 "sintatico.c"
    break;

  case 12: /* $@5: %empty  */
#line 119 "sintatico.y"
     {
           strcpy(elemTab.id, atomo);
           marcaPar++;
           elemTab.tip = tipo;
           elemTab.esc = escopo;
           elemTab.cat = FUN;
           insereSimbolo(elemTab);
           escopo = LOCAL;
           strcpy(elemTab.rot,"");
     }
#line 1305 "sintatico.c"
    break;

  case 13: /* $@6: %empty  */
#line 131 "sintatico.y"
        {
            //printf("\n%d %d\n", marcaPar, contaVar);
           indicesLocais(marcaPar, contaVar);
           mostraTabela(); 
           //empilha(contaVarLocal);
           if(contaVarLocal){
               fprintf(yyout,"\tAMEM\t%d\n", contaVarLocal); 
            }
        }
#line 1319 "sintatico.c"
    break;

  case 14: /* funcao: T_FUNC tipo T_IDENTIF $@5 T_ABRE lista_parametros T_FECHA variaveis $@6 T_INICIO lista_comandos T_FIMFUNC  */
#line 141 "sintatico.y"
        { 
            escopo = GLOBAL;
            removeLocais();
            mostraTabela();
        }
#line 1329 "sintatico.c"
    break;

  case 17: /* parametro: tipo T_IDENTIF  */
#line 154 "sintatico.y"
         { 
           strcpy(elemTab.id, atomo);
           marcaPar++;
           elemTab.tip = tipo;
           elemTab.esc = escopo;
           elemTab.cat = PAR;
           insereSimbolo(elemTab);
         }
#line 1342 "sintatico.c"
    break;

  case 18: /* cabecalho: T_PROGRAMA T_IDENTIF  */
#line 165 "sintatico.y"
        {fprintf(yyout,"\tINPP\n"); }
#line 1348 "sintatico.c"
    break;

  case 23: /* tipo: T_LOGICO  */
#line 180 "sintatico.y"
     { tipo = LOG; }
#line 1354 "sintatico.c"
    break;

  case 24: /* tipo: T_INTEIRO  */
#line 182 "sintatico.y"
    { tipo = INT;}
#line 1360 "sintatico.c"
    break;

  case 25: /* lista_variaveis: lista_variaveis T_IDENTIF  */
#line 187 "sintatico.y"
         { 
           strcpy(elemTab.id, atomo);
           elemTab.tip = tipo;
           elemTab.esc = escopo;
           elemTab.cat = VAR;
           if(escopo == LOCAL){
               elemTab.end = contaVarLocal;
               contaVarLocal++;
           }
           else{
               elemTab.end = contaVar;
               contaVar++;         
           }
           insereSimbolo(elemTab);  
         }
#line 1380 "sintatico.c"
    break;

  case 26: /* lista_variaveis: T_IDENTIF  */
#line 203 "sintatico.y"
        { 
           strcpy(elemTab.id, atomo);
           elemTab.tip = tipo;
           elemTab.esc = escopo;
           elemTab.cat = VAR;
           if(escopo == LOCAL){
               elemTab.end = contaVarLocal;
               contaVarLocal++;
           }
           else{
               elemTab.end = contaVar;
               contaVar++;         
           }
           insereSimbolo(elemTab);   
        }
#line 1400 "sintatico.c"
    break;

  case 34: /* comando: T_RETORNE expressao  */
#line 232 "sintatico.y"
    {
       if(escopo == LOCAL){
           fprintf(yyout,"\tARZL\t%d\n", indFunc);
       }
          
       else
           yyerror("Erro lexico!");
        desempilha();

        if (contaVarLocal)
           fprintf(yyout,"\tDMEM\t%d\n", contaVarLocal);
        if(marcaPar - 1)    
           fprintf(yyout,"\tRTSP\t%d\n", marcaPar - 1);
    }
#line 1419 "sintatico.c"
    break;

  case 35: /* comando: T_RETORNE chamada_func  */
#line 247 "sintatico.y"
    {
       if(escopo == LOCAL){
           fprintf(yyout,"\tARZL\t%d\n", indFunc);
       }
          
       else
           yyerror("Erro lexico!");

        if (contaVarLocal)
           fprintf(yyout,"\tDMEM\t%d\n", contaVarLocal);
        if(marcaPar - 1)    
           fprintf(yyout,"\tRTSP\t%d\n", marcaPar - 1);
    }
#line 1437 "sintatico.c"
    break;

  case 38: /* escrita: T_ESCREVA expressao  */
#line 270 "sintatico.y"
       {
        desempilha();
        fprintf(yyout, "\tESCR\n");
       }
#line 1446 "sintatico.c"
    break;

  case 39: /* escrita: T_ESCREVA chamada_func  */
#line 275 "sintatico.y"
         {
            fprintf(yyout, "\tESCR\n");
         }
#line 1454 "sintatico.c"
    break;

  case 40: /* leitura: T_LEIA T_IDENTIF  */
#line 282 "sintatico.y"
        { 
            int pos = buscaSimbolo(atomo);
            if(tabSimb[pos].esc == GLOBAL)
              fprintf(yyout,"\tLEIA\n\tARZG\t%d\n", tabSimb[pos].end); 
            else
              fprintf(yyout,"\tLEIA\n\tARZL\t%d\n", tabSimb[pos].end); 
        }
#line 1466 "sintatico.c"
    break;

  case 41: /* $@7: %empty  */
#line 294 "sintatico.y"
        { 
            fprintf(yyout,"L%d\tNADA\n", ++rotulo); 
            empilha(rotulo);
        }
#line 1475 "sintatico.c"
    break;

  case 42: /* $@8: %empty  */
#line 299 "sintatico.y"
        {
             int tip = desempilha();
             if(tip != LOG)
                 yyerror("Incompatilidade de tipo");
             fprintf(yyout,"\tDSVF\tL%d\n", ++rotulo);
             empilha(rotulo);
        }
#line 1487 "sintatico.c"
    break;

  case 43: /* repeticao: T_ENQTO $@7 expressao T_FACA $@8 lista_comandos T_FIMENQTO  */
#line 308 "sintatico.y"
         { 
            int rot1 = desempilha();
            int rot2 = desempilha();
            fprintf(yyout,"\tDSVS\tL%d\n",rot2);
            fprintf(yyout,"L%d\tNADA\n",rot1);
         }
#line 1498 "sintatico.c"
    break;

  case 44: /* $@9: %empty  */
#line 318 "sintatico.y"
        {
             int tip = desempilha();
             if(tip != LOG)
                 yyerror("Imcompatilidade de tipo");
             fprintf(yyout,"\tDSVF\tL%d\n", ++rotulo);
             empilha(rotulo);
        }
#line 1510 "sintatico.c"
    break;

  case 45: /* $@10: %empty  */
#line 326 "sintatico.y"
        { 
            int rot = desempilha();
            fprintf(yyout,"\tDSVS\tL%d\n", ++rotulo);
            fprintf(yyout,"L%d\tNADA\n", rot);
            empilha(rotulo);
        }
#line 1521 "sintatico.c"
    break;

  case 46: /* selecao: T_SE expressao T_ENTAO $@9 lista_comandos T_SENAO $@10 lista_comandos T_FIMSE  */
#line 333 "sintatico.y"
        { 
            int rot = desempilha();
            fprintf(yyout,"L%d\tNADA\n", rot); 
        }
#line 1530 "sintatico.c"
    break;

  case 47: /* $@11: %empty  */
#line 342 "sintatico.y"
        {
            int pos = buscaSimbolo(atomo);
            empilha(pos);
        }
#line 1539 "sintatico.c"
    break;

  case 48: /* atribuicao: T_IDENTIF $@11 T_ATRIBUI expressao  */
#line 347 "sintatico.y"
        {
            int tip = desempilha();
            int pos = desempilha();
            if (tabSimb[pos].tip != tip)
               yyerror("Incompatibilidade de tipo!");
            if(tabSimb[pos].esc == GLOBAL)
              fprintf(yyout,"\tARZG\t%d\n", tabSimb[pos].end); 
            else
              fprintf(yyout,"\tARZL\t%d\n", tabSimb[pos].end); 

        }
#line 1555 "sintatico.c"
    break;

  case 49: /* expressao: expressao T_VEZES expressao  */
#line 362 "sintatico.y"
        {
            testaTipo(INT,INT, INT);
            fprintf(yyout,"\tMULT\n"); 
        }
#line 1564 "sintatico.c"
    break;

  case 50: /* expressao: expressao T_DIV expressao  */
#line 367 "sintatico.y"
        {
            testaTipo(INT,INT, INT);
            fprintf(yyout,"\tDIVI\n"); 
        }
#line 1573 "sintatico.c"
    break;

  case 51: /* expressao: expressao T_MAIS expressao  */
#line 372 "sintatico.y"
        {
            testaTipo(INT,INT, INT);
            fprintf(yyout,"\tSOMA\n"); 
        }
#line 1582 "sintatico.c"
    break;

  case 52: /* expressao: expressao T_MENOS expressao  */
#line 377 "sintatico.y"
        {
            testaTipo(INT,INT, INT);
            fprintf(yyout,"\tSUBT\n");
        }
#line 1591 "sintatico.c"
    break;

  case 53: /* expressao: expressao T_MAIOR expressao  */
#line 382 "sintatico.y"
        {
            testaTipo(INT,INT, LOG);
            fprintf(yyout,"\tCMMA\n"); 
        }
#line 1600 "sintatico.c"
    break;

  case 54: /* expressao: expressao T_MENOR expressao  */
#line 387 "sintatico.y"
        {
            testaTipo(INT,INT, LOG);
            fprintf(yyout,"\tCMME\n");
        }
#line 1609 "sintatico.c"
    break;

  case 55: /* expressao: expressao T_IGUAL expressao  */
#line 392 "sintatico.y"
        {
            testaTipo(INT,INT, LOG);
            fprintf(yyout,"\tCMIG\n"); 
        }
#line 1618 "sintatico.c"
    break;

  case 56: /* expressao: expressao T_E expressao  */
#line 397 "sintatico.y"
        {
            testaTipo(LOG, LOG, LOG);
            fprintf(yyout,"\tCONJ\n"); 
        }
#line 1627 "sintatico.c"
    break;

  case 57: /* expressao: expressao T_OU expressao  */
#line 402 "sintatico.y"
        {
            testaTipo(LOG, LOG, LOG);
            fprintf(yyout,"\tDISJ\n"); 
        }
#line 1636 "sintatico.c"
    break;

  case 59: /* $@12: %empty  */
#line 412 "sintatico.y"
                 {aux = buscaSimbolo(atomo);}
#line 1642 "sintatico.c"
    break;

  case 60: /* $@13: %empty  */
#line 414 "sintatico.y"
     {
        empilha(LIXO);
     }
#line 1650 "sintatico.c"
    break;

  case 61: /* chamada_func: T_IDENTIF $@12 T_ABRE $@13 lista_argumentos T_FECHA  */
#line 418 "sintatico.y"
     {
        confereParametros(aux);
        fprintf(yyout,"\tSVCP\n");
        fprintf(yyout,"\tDSVS\t%s\n",tabSimb[aux].rot);
     }
#line 1660 "sintatico.c"
    break;

  case 65: /* termo: T_IDENTIF  */
#line 434 "sintatico.y"
        {
            int pos = buscaSimbolo(atomo);
            if(tabSimb[pos].esc == GLOBAL)
              fprintf(yyout,"\tCRVG\t%d\n", tabSimb[pos].end); 
            else
               fprintf(yyout,"\tCRVL\t%d\n", tabSimb[pos].end);
            empilha(tabSimb[pos].tip);
        }
#line 1673 "sintatico.c"
    break;

  case 66: /* termo: T_NUMERO  */
#line 443 "sintatico.y"
        {
        fprintf(yyout,"\tCRCT\t%s\n", atomo);
        empilha(INT);
        }
#line 1682 "sintatico.c"
    break;

  case 67: /* termo: T_V  */
#line 448 "sintatico.y"
        {
        fprintf(yyout,"\tCRCT\t1\n"); 
        empilha(LOG);
        }
#line 1691 "sintatico.c"
    break;

  case 68: /* termo: T_F  */
#line 453 "sintatico.y"
        {
        fprintf(yyout,"\tCRCT\t0\n"); 
        empilha(LOG);
        }
#line 1700 "sintatico.c"
    break;

  case 69: /* termo: T_NAO termo  */
#line 458 "sintatico.y"
        {
        int t = desempilha();
        if (t != LOG) yyerror ("Incompatibilidade de tipo!");
        fprintf(yyout,"\tNEGA\n"); 
        empilha(LOG);
        }
#line 1711 "sintatico.c"
    break;


#line 1715 "sintatico.c"

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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 466 "sintatico.y"




int main(int argc, char *argv[]){
    char *p, nameIn[100], nameOut[100];
    argv++;
    if(argc < 2){
        puts("\nCompilador Simples\n");
        puts("\n\tUso: ./simples <NOME>[.simples]/n/n");
        exit(10);
    }
    p = strstr(argv[0], ".simples");
    if(p) *p = 0;
    strcpy(nameIn, argv[0]);
    strcat(nameIn, ".simples");
    strcpy(nameOut, argv[0]);
    strcat(nameOut, ".mvs");
    yyin = fopen(nameIn, "rt");
    if(!yyin){
        puts("Programa fonte não encontrado!");
        exit(20);
    }
    yyout = fopen(nameOut,"wt");
    yyparse(); /*LR melhorado*/
    puts("Programa ok!");
}
