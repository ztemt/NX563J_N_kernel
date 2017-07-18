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
#line 31 "external/selinux/checkpolicy/policy_parse.y"

#include <sys/types.h>
#include <assert.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

#include <sepol/policydb/expand.h>
#include <sepol/policydb/policydb.h>
#include <sepol/policydb/services.h>
#include <sepol/policydb/conditional.h>
#include <sepol/policydb/flask.h>
#include <sepol/policydb/hierarchy.h>
#include <sepol/policydb/polcaps.h>
#include "queue.h"
#include "checkpolicy.h"
#include "module_compiler.h"
#include "policy_define.h"

extern policydb_t *policydbp;
extern unsigned int pass;

extern char yytext[];
extern int yylex(void);
extern int yywarn(const char *msg);
extern int yyerror(const char *msg);

typedef int (* require_func_t)(int pass);


/* Line 371 of yacc.c  */
#line 105 "out/host/linux-x86/obj/EXECUTABLES/checkpolicy_intermediates/policy_parse.c"

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
   by #include "policy_parse.h".  */
#ifndef YY_YY_OUT_HOST_LINUX_X86_OBJ_EXECUTABLES_CHECKPOLICY_INTERMEDIATES_POLICY_PARSE_H_INCLUDED
# define YY_YY_OUT_HOST_LINUX_X86_OBJ_EXECUTABLES_CHECKPOLICY_INTERMEDIATES_POLICY_PARSE_H_INCLUDED
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
     PATH = 258,
     QPATH = 259,
     FILENAME = 260,
     CLONE = 261,
     COMMON = 262,
     CLASS = 263,
     CONSTRAIN = 264,
     VALIDATETRANS = 265,
     INHERITS = 266,
     SID = 267,
     ROLE = 268,
     ROLEATTRIBUTE = 269,
     ATTRIBUTE_ROLE = 270,
     ROLES = 271,
     TYPEALIAS = 272,
     TYPEATTRIBUTE = 273,
     TYPEBOUNDS = 274,
     TYPE = 275,
     TYPES = 276,
     ALIAS = 277,
     ATTRIBUTE = 278,
     BOOL = 279,
     TUNABLE = 280,
     IF = 281,
     ELSE = 282,
     TYPE_TRANSITION = 283,
     TYPE_MEMBER = 284,
     TYPE_CHANGE = 285,
     ROLE_TRANSITION = 286,
     RANGE_TRANSITION = 287,
     SENSITIVITY = 288,
     DOMINANCE = 289,
     DOM = 290,
     DOMBY = 291,
     INCOMP = 292,
     CATEGORY = 293,
     LEVEL = 294,
     RANGE = 295,
     MLSCONSTRAIN = 296,
     MLSVALIDATETRANS = 297,
     USER = 298,
     NEVERALLOW = 299,
     ALLOW = 300,
     AUDITALLOW = 301,
     AUDITDENY = 302,
     DONTAUDIT = 303,
     ALLOWXPERM = 304,
     AUDITALLOWXPERM = 305,
     DONTAUDITXPERM = 306,
     NEVERALLOWXPERM = 307,
     SOURCE = 308,
     TARGET = 309,
     SAMEUSER = 310,
     FSCON = 311,
     PORTCON = 312,
     NETIFCON = 313,
     NODECON = 314,
     PIRQCON = 315,
     IOMEMCON = 316,
     IOPORTCON = 317,
     PCIDEVICECON = 318,
     DEVICETREECON = 319,
     FSUSEXATTR = 320,
     FSUSETASK = 321,
     FSUSETRANS = 322,
     GENFSCON = 323,
     U1 = 324,
     U2 = 325,
     U3 = 326,
     R1 = 327,
     R2 = 328,
     R3 = 329,
     T1 = 330,
     T2 = 331,
     T3 = 332,
     L1 = 333,
     L2 = 334,
     H1 = 335,
     H2 = 336,
     NOT = 337,
     AND = 338,
     OR = 339,
     XOR = 340,
     CTRUE = 341,
     CFALSE = 342,
     IDENTIFIER = 343,
     NUMBER = 344,
     EQUALS = 345,
     NOTEQUAL = 346,
     IPV4_ADDR = 347,
     IPV6_ADDR = 348,
     MODULE = 349,
     VERSION_IDENTIFIER = 350,
     REQUIRE = 351,
     OPTIONAL = 352,
     POLICYCAP = 353,
     PERMISSIVE = 354,
     FILESYSTEM = 355,
     DEFAULT_USER = 356,
     DEFAULT_ROLE = 357,
     DEFAULT_TYPE = 358,
     DEFAULT_RANGE = 359,
     LOW_HIGH = 360,
     LOW = 361,
     HIGH = 362
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 68 "external/selinux/checkpolicy/policy_parse.y"

	unsigned int val;
	uint64_t val64;
	uintptr_t valptr;
	void *ptr;
        require_func_t require_func;


/* Line 387 of yacc.c  */
#line 264 "out/host/linux-x86/obj/EXECUTABLES/checkpolicy_intermediates/policy_parse.c"
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

#endif /* !YY_YY_OUT_HOST_LINUX_X86_OBJ_EXECUTABLES_CHECKPOLICY_INTERMEDIATES_POLICY_PARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 292 "out/host/linux-x86/obj/EXECUTABLES/checkpolicy_intermediates/policy_parse.c"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  118
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  191
/* YYNRULES -- Number of rules.  */
#define YYNRULES  393
/* YYNRULES -- Number of states.  */
#define YYNSTATES  791

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   362

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     113,   114,   117,     2,   112,   115,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   111,   110,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   108,     2,   109,   116,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,     9,    10,    28,    30,
      33,    36,    38,    41,    44,    47,    49,    50,    52,    55,
      61,    63,    66,    72,    77,    85,    87,    88,    90,    92,
      94,    96,    99,   102,   105,   108,   113,   118,   123,   128,
     133,   138,   144,   150,   156,   162,   168,   174,   176,   177,
     183,   185,   188,   193,   197,   200,   203,   208,   210,   211,
     213,   216,   221,   225,   227,   230,   236,   240,   242,   245,
     247,   249,   255,   260,   262,   265,   267,   269,   271,   273,
     275,   277,   279,   281,   283,   285,   287,   289,   291,   293,
     295,   297,   299,   301,   303,   305,   307,   309,   311,   313,
     317,   323,   328,   333,   338,   343,   346,   347,   352,   357,
     359,   361,   368,   373,   374,   378,   381,   385,   389,   393,
     397,   401,   403,   405,   408,   409,   411,   413,   415,   424,
     432,   440,   448,   450,   452,   454,   456,   464,   472,   480,
     488,   497,   505,   513,   521,   527,   535,   537,   539,   541,
     543,   545,   547,   549,   551,   553,   561,   569,   577,   585,
     593,   602,   611,   620,   629,   633,   639,   644,   649,   655,
     663,   668,   670,   673,   677,   683,   688,   690,   691,   693,
     696,   698,   700,   706,   711,   715,   718,   722,   726,   728,
     732,   736,   740,   741,   746,   747,   752,   753,   758,   759,
     764,   765,   770,   771,   776,   777,   782,   783,   788,   789,
     794,   796,   797,   802,   803,   808,   811,   812,   817,   818,
     823,   827,   831,   835,   839,   843,   847,   849,   851,   853,
     855,   857,   859,   861,   864,   871,   876,   877,   879,   882,
     886,   888,   889,   891,   894,   896,   898,   900,   902,   904,
     908,   912,   918,   922,   928,   932,   936,   938,   939,   941,
     944,   950,   954,   956,   957,   959,   962,   967,   974,   976,
     977,   979,   982,   987,   989,   990,   992,   995,  1000,  1005,
    1007,  1008,  1010,  1013,  1018,  1023,  1028,  1030,  1031,  1033,
    1036,  1043,  1044,  1052,  1057,  1059,  1061,  1063,  1066,  1069,
    1073,  1075,  1078,  1079,  1084,  1086,  1088,  1090,  1097,  1100,
    1101,  1105,  1107,  1111,  1113,  1115,  1119,  1121,  1123,  1125,
    1127,  1129,  1132,  1135,  1136,  1141,  1143,  1145,  1147,  1151,
    1153,  1156,  1161,  1163,  1166,  1168,  1170,  1173,  1177,  1179,
    1182,  1184,  1185,  1189,  1191,  1193,  1195,  1197,  1199,  1201,
    1203,  1205,  1207,  1209,  1213,  1217,  1220,  1225,  1227,  1229,
    1231,  1234,  1237,  1239,  1241,  1243,  1245,  1247,  1249,  1251,
    1256,  1259,  1261,  1264,  1268,  1272,  1274,  1276,  1278,  1280,
    1282,  1284,  1286,  1288,  1290,  1292,  1296,  1297,  1304,  1309,
    1310,  1312,  1314,  1317
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     119,     0,    -1,   120,    -1,   291,    -1,    -1,    -1,    -1,
     121,   124,   126,   128,   122,   134,   140,   155,   223,   201,
     123,   226,   236,   249,   252,   239,   228,    -1,   125,    -1,
     124,   125,    -1,     8,   282,    -1,   127,    -1,   126,   127,
      -1,    12,   282,    -1,   129,   132,    -1,   130,    -1,    -1,
     131,    -1,   130,   131,    -1,     7,   282,   108,   277,   109,
      -1,   133,    -1,   132,   133,    -1,     8,   282,   108,   277,
     109,    -1,     8,   282,    11,   282,    -1,     8,   282,    11,
     282,   108,   277,   109,    -1,   135,    -1,    -1,   136,    -1,
     137,    -1,   138,    -1,   139,    -1,   135,   136,    -1,   135,
     137,    -1,   135,   138,    -1,   135,   139,    -1,   101,   270,
      53,   110,    -1,   101,   270,    54,   110,    -1,   102,   270,
      53,   110,    -1,   102,   270,    54,   110,    -1,   103,   270,
      53,   110,    -1,   103,   270,    54,   110,    -1,   104,   270,
      53,   106,   110,    -1,   104,   270,    53,   107,   110,    -1,
     104,   270,    53,   105,   110,    -1,   104,   270,    54,   106,
     110,    -1,   104,   270,    54,   107,   110,    -1,   104,   270,
      54,   105,   110,    -1,   141,    -1,    -1,   142,   145,   146,
     149,   151,    -1,   143,    -1,   142,   143,    -1,    33,   282,
     144,   110,    -1,    33,   282,   110,    -1,    22,   270,    -1,
      34,   282,    -1,    34,   108,   277,   109,    -1,   147,    -1,
      -1,   148,    -1,   147,   148,    -1,    38,   282,   144,   110,
      -1,    38,   282,   110,    -1,   150,    -1,   149,   150,    -1,
      39,   282,   111,   267,   110,    -1,    39,   282,   110,    -1,
     152,    -1,   151,   152,    -1,   153,    -1,   154,    -1,    41,
     270,   270,   206,   110,    -1,    42,   270,   206,   110,    -1,
     156,    -1,   155,   156,    -1,   158,    -1,   157,    -1,   168,
      -1,   303,    -1,   289,    -1,   110,    -1,   192,    -1,   193,
      -1,   195,    -1,   196,    -1,   197,    -1,   200,    -1,   194,
      -1,   159,    -1,   160,    -1,   161,    -1,   162,    -1,   163,
      -1,   165,    -1,   166,    -1,   180,    -1,   181,    -1,   182,
      -1,   290,    -1,    23,   282,   110,    -1,    20,   282,   144,
     164,   110,    -1,    20,   282,   164,   110,    -1,    17,   282,
     144,   110,    -1,    18,   282,   267,   110,    -1,    19,   282,
     267,   110,    -1,   112,   267,    -1,    -1,    24,   282,   167,
     110,    -1,    25,   282,   167,   110,    -1,    86,    -1,    87,
      -1,    26,   170,   108,   172,   109,   169,    -1,    27,   108,
     172,   109,    -1,    -1,   113,   170,   114,    -1,    82,   170,
      -1,   170,    83,   170,    -1,   170,    84,   170,    -1,   170,
      85,   170,    -1,   170,    90,   170,    -1,   170,    91,   170,
      -1,   171,    -1,   282,    -1,   172,   173,    -1,    -1,   174,
      -1,   175,    -1,   297,    -1,    28,   270,   270,   111,   270,
     282,   285,   110,    -1,    28,   270,   270,   111,   270,   282,
     110,    -1,    29,   270,   270,   111,   270,   282,   110,    -1,
      30,   270,   270,   111,   270,   282,   110,    -1,   176,    -1,
     177,    -1,   178,    -1,   179,    -1,    45,   270,   270,   111,
     270,   270,   110,    -1,    46,   270,   270,   111,   270,   270,
     110,    -1,    47,   270,   270,   111,   270,   270,   110,    -1,
      48,   270,   270,   111,   270,   270,   110,    -1,    28,   270,
     270,   111,   270,   282,   285,   110,    -1,    28,   270,   270,
     111,   270,   282,   110,    -1,    29,   270,   270,   111,   270,
     282,   110,    -1,    30,   270,   270,   111,   270,   282,   110,
      -1,    32,   270,   270,   265,   110,    -1,    32,   270,   270,
     111,   270,   265,   110,    -1,   183,    -1,   184,    -1,   185,
      -1,   186,    -1,   187,    -1,   188,    -1,   189,    -1,   190,
      -1,   191,    -1,    45,   270,   270,   111,   270,   270,   110,
      -1,    46,   270,   270,   111,   270,   270,   110,    -1,    47,
     270,   270,   111,   270,   270,   110,    -1,    48,   270,   270,
     111,   270,   270,   110,    -1,    44,   270,   270,   111,   270,
     270,   110,    -1,    49,   270,   270,   111,   270,   282,   257,
     110,    -1,    50,   270,   270,   111,   270,   282,   257,   110,
      -1,    51,   270,   270,   111,   270,   282,   257,   110,    -1,
      52,   270,   270,   111,   270,   282,   257,   110,    -1,    15,
     282,   110,    -1,    13,   282,    21,   270,   110,    -1,    13,
     282,   164,   110,    -1,    34,   108,   198,   109,    -1,    31,
     270,   270,   282,   110,    -1,    31,   270,   270,   111,   270,
     282,   110,    -1,    45,   270,   270,   110,    -1,   199,    -1,
     198,   199,    -1,    13,   276,   110,    -1,    13,   276,   108,
     198,   109,    -1,    14,   282,   267,   110,    -1,   202,    -1,
      -1,   203,    -1,   202,   203,    -1,   204,    -1,   205,    -1,
       9,   270,   270,   206,   110,    -1,    10,   270,   206,   110,
      -1,   113,   206,   114,    -1,    82,   206,    -1,   206,    83,
     206,    -1,   206,    84,   206,    -1,   207,    -1,    69,   221,
      70,    -1,    72,   222,    73,    -1,    75,   221,    76,    -1,
      -1,    69,   221,   208,   274,    -1,    -1,    70,   221,   209,
     274,    -1,    -1,    71,   221,   210,   274,    -1,    -1,    72,
     221,   211,   274,    -1,    -1,    73,   221,   212,   274,    -1,
      -1,    74,   221,   213,   274,    -1,    -1,    75,   221,   214,
     274,    -1,    -1,    76,   221,   215,   274,    -1,    -1,    77,
     221,   216,   274,    -1,    55,    -1,    -1,    53,    13,   217,
     274,    -1,    -1,    54,    13,   218,   274,    -1,    13,   222,
      -1,    -1,    53,    20,   219,   274,    -1,    -1,    54,    20,
     220,   274,    -1,    78,   222,    79,    -1,    78,   222,    81,
      -1,    80,   222,    79,    -1,    80,   222,    81,    -1,    78,
     222,    80,    -1,    79,   222,    81,    -1,    90,    -1,    91,
      -1,   221,    -1,    35,    -1,    36,    -1,    37,    -1,   224,
      -1,   223,   224,    -1,    43,   282,    16,   270,   225,   110,
      -1,    39,   266,    40,   265,    -1,    -1,   227,    -1,   226,
     227,    -1,    12,   282,   263,    -1,   229,    -1,    -1,   230,
      -1,   229,   230,    -1,   231,    -1,   232,    -1,   233,    -1,
     234,    -1,   235,    -1,    60,   286,   263,    -1,    61,   287,
     263,    -1,    61,   287,   115,   287,   263,    -1,    62,   286,
     263,    -1,    62,   286,   115,   286,   263,    -1,    63,   286,
     263,    -1,    64,   284,   263,    -1,   237,    -1,    -1,   238,
      -1,   237,   238,    -1,    56,   286,   286,   263,   263,    -1,
     240,   243,   246,    -1,   241,    -1,    -1,   242,    -1,   241,
     242,    -1,    57,   282,   286,   263,    -1,    57,   282,   286,
     115,   286,   263,    -1,   244,    -1,    -1,   245,    -1,   244,
     245,    -1,    58,   282,   263,   263,    -1,   247,    -1,    -1,
     248,    -1,   247,   248,    -1,    59,   256,   256,   263,    -1,
      59,   288,   288,   263,    -1,   250,    -1,    -1,   251,    -1,
     250,   251,    -1,    65,   283,   263,   110,    -1,    66,   282,
     263,   110,    -1,    67,   282,   263,   110,    -1,   253,    -1,
      -1,   254,    -1,   253,   254,    -1,    68,   283,   284,   115,
     282,   263,    -1,    -1,    68,   283,   284,   115,   115,   255,
     263,    -1,    68,   283,   284,   263,    -1,    92,    -1,   262,
      -1,   258,    -1,   268,   262,    -1,   268,   258,    -1,   108,
     259,   109,    -1,   260,    -1,   259,   260,    -1,    -1,   262,
     115,   261,   262,    -1,   262,    -1,   258,    -1,   286,    -1,
     282,   111,   282,   111,   282,   264,    -1,   111,   265,    -1,
      -1,   266,   115,   266,    -1,   266,    -1,   282,   111,   267,
      -1,   282,    -1,   282,    -1,   267,   112,   282,    -1,   116,
      -1,   117,    -1,   282,    -1,   278,    -1,   269,    -1,   268,
     282,    -1,   268,   278,    -1,    -1,   282,   115,   271,   282,
      -1,   268,    -1,   269,    -1,   276,    -1,   108,   275,   109,
      -1,   273,    -1,   272,   276,    -1,   272,   108,   275,   109,
      -1,   276,    -1,   275,   276,    -1,    88,    -1,   282,    -1,
     277,   282,    -1,   108,   279,   109,    -1,   280,    -1,   279,
     280,    -1,   282,    -1,    -1,   115,   281,   282,    -1,   278,
      -1,    88,    -1,   100,    -1,    88,    -1,     3,    -1,     4,
      -1,     5,    -1,    89,    -1,    89,    -1,    93,    -1,    98,
     282,   110,    -1,    99,   282,   110,    -1,   292,   294,    -1,
      94,   282,   293,   110,    -1,    95,    -1,   286,    -1,   256,
      -1,   295,   308,    -1,   295,   296,    -1,   296,    -1,   157,
      -1,   158,    -1,   168,    -1,   297,    -1,   303,    -1,   110,
      -1,    96,   108,   298,   109,    -1,   298,   299,    -1,   299,
      -1,   300,   110,    -1,   301,   302,   110,    -1,     8,   282,
     270,    -1,    13,    -1,    20,    -1,    23,    -1,    15,    -1,
      43,    -1,    24,    -1,    25,    -1,    33,    -1,    38,    -1,
     282,    -1,   302,   112,   282,    -1,    -1,   306,   108,   294,
     109,   304,   305,    -1,   307,   108,   294,   109,    -1,    -1,
      97,    -1,    27,    -1,   224,   308,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   162,   162,   163,   165,   167,   170,   165,   174,   175,
     177,   180,   181,   183,   186,   188,   189,   191,   192,   194,
     197,   198,   200,   202,   204,   207,   208,   210,   211,   212,
     213,   214,   215,   216,   217,   219,   221,   224,   226,   229,
     231,   234,   236,   238,   240,   242,   244,   247,   248,   250,
     252,   253,   255,   257,   260,   262,   264,   267,   268,   270,
     271,   273,   275,   278,   279,   281,   283,   286,   287,   289,
     290,   292,   295,   298,   299,   301,   302,   303,   304,   305,
     306,   308,   309,   310,   311,   312,   313,   314,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   328,
     331,   333,   336,   339,   342,   345,   346,   348,   351,   354,
     356,   359,   362,   365,   367,   369,   372,   375,   378,   381,
     384,   387,   390,   394,   397,   399,   401,   403,   406,   409,
     412,   415,   419,   421,   423,   425,   428,   432,   436,   440,
     445,   447,   449,   451,   454,   456,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   469,   472,   475,   478,   481,
     484,   487,   490,   493,   496,   499,   502,   505,   507,   509,
     512,   515,   517,   520,   522,   525,   528,   529,   531,   532,
     534,   535,   537,   540,   543,   545,   548,   551,   554,   557,
     560,   563,   566,   566,   569,   569,   572,   572,   575,   575,
     578,   578,   581,   581,   584,   584,   587,   587,   590,   590,
     593,   596,   596,   599,   599,   602,   605,   605,   608,   608,
     611,   614,   617,   620,   623,   626,   630,   632,   635,   637,
     639,   641,   644,   645,   647,   650,   651,   653,   654,   656,
     659,   659,   661,   662,   664,   665,   666,   667,   668,   670,
     673,   675,   678,   680,   683,   686,   689,   690,   692,   693,
     695,   698,   700,   701,   703,   704,   706,   708,   711,   712,
     714,   715,   717,   720,   721,   723,   724,   726,   728,   731,
     732,   734,   735,   737,   739,   741,   744,   745,   747,   748,
     750,   752,   752,   754,   757,   760,   762,   764,   766,   770,
     772,   773,   775,   775,   776,   777,   779,   782,   784,   785,
     787,   789,   792,   794,   797,   798,   800,   802,   804,   806,
     808,   811,   814,   817,   817,   820,   823,   826,   827,   828,
     829,   830,   832,   833,   835,   838,   839,   841,   843,   843,
     845,   845,   845,   845,   847,   850,   852,   855,   857,   860,
     863,   866,   869,   872,   875,   880,   885,   888,   890,   892,
     894,   896,   897,   899,   900,   901,   902,   903,   904,   906,
     908,   909,   911,   912,   914,   917,   918,   919,   920,   921,
     922,   923,   924,   925,   927,   929,   933,   932,   937,   939,
     941,   944,   947,   948
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PATH", "QPATH", "FILENAME", "CLONE",
  "COMMON", "CLASS", "CONSTRAIN", "VALIDATETRANS", "INHERITS", "SID",
  "ROLE", "ROLEATTRIBUTE", "ATTRIBUTE_ROLE", "ROLES", "TYPEALIAS",
  "TYPEATTRIBUTE", "TYPEBOUNDS", "TYPE", "TYPES", "ALIAS", "ATTRIBUTE",
  "BOOL", "TUNABLE", "IF", "ELSE", "TYPE_TRANSITION", "TYPE_MEMBER",
  "TYPE_CHANGE", "ROLE_TRANSITION", "RANGE_TRANSITION", "SENSITIVITY",
  "DOMINANCE", "DOM", "DOMBY", "INCOMP", "CATEGORY", "LEVEL", "RANGE",
  "MLSCONSTRAIN", "MLSVALIDATETRANS", "USER", "NEVERALLOW", "ALLOW",
  "AUDITALLOW", "AUDITDENY", "DONTAUDIT", "ALLOWXPERM", "AUDITALLOWXPERM",
  "DONTAUDITXPERM", "NEVERALLOWXPERM", "SOURCE", "TARGET", "SAMEUSER",
  "FSCON", "PORTCON", "NETIFCON", "NODECON", "PIRQCON", "IOMEMCON",
  "IOPORTCON", "PCIDEVICECON", "DEVICETREECON", "FSUSEXATTR", "FSUSETASK",
  "FSUSETRANS", "GENFSCON", "U1", "U2", "U3", "R1", "R2", "R3", "T1", "T2",
  "T3", "L1", "L2", "H1", "H2", "NOT", "AND", "OR", "XOR", "CTRUE",
  "CFALSE", "IDENTIFIER", "NUMBER", "EQUALS", "NOTEQUAL", "IPV4_ADDR",
  "IPV6_ADDR", "MODULE", "VERSION_IDENTIFIER", "REQUIRE", "OPTIONAL",
  "POLICYCAP", "PERMISSIVE", "FILESYSTEM", "DEFAULT_USER", "DEFAULT_ROLE",
  "DEFAULT_TYPE", "DEFAULT_RANGE", "LOW_HIGH", "LOW", "HIGH", "'{'", "'}'",
  "';'", "':'", "','", "'('", "')'", "'-'", "'~'", "'*'", "$accept",
  "policy", "base_policy", "$@1", "$@2", "$@3", "classes", "class_def",
  "initial_sids", "initial_sid_def", "access_vectors", "opt_common_perms",
  "common_perms", "common_perms_def", "av_perms", "av_perms_def",
  "opt_default_rules", "default_rules", "default_user_def",
  "default_role_def", "default_type_def", "default_range_def", "opt_mls",
  "mls", "sensitivities", "sensitivity_def", "alias_def", "dominance",
  "opt_categories", "categories", "category_def", "levels", "level_def",
  "mlspolicy", "mlspolicy_decl", "mlsconstraint_def",
  "mlsvalidatetrans_def", "te_rbac", "te_rbac_decl", "rbac_decl",
  "te_decl", "attribute_def", "type_def", "typealias_def",
  "typeattribute_def", "typebounds_def", "opt_attr_list", "bool_def",
  "tunable_def", "bool_val", "cond_stmt_def", "cond_else", "cond_expr",
  "cond_expr_prim", "cond_pol_list", "cond_rule_def",
  "cond_transition_def", "cond_te_avtab_def", "cond_allow_def",
  "cond_auditallow_def", "cond_auditdeny_def", "cond_dontaudit_def",
  "transition_def", "range_trans_def", "te_avtab_def", "allow_def",
  "auditallow_def", "auditdeny_def", "dontaudit_def", "neverallow_def",
  "xperm_allow_def", "xperm_auditallow_def", "xperm_dontaudit_def",
  "xperm_neverallow_def", "attribute_role_def", "role_type_def",
  "role_attr_def", "role_dominance", "role_trans_def", "role_allow_def",
  "roles", "role_def", "roleattribute_def", "opt_constraints",
  "constraints", "constraint_decl", "constraint_def", "validatetrans_def",
  "cexpr", "cexpr_prim", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "op", "role_mls_op",
  "users", "user_def", "opt_mls_user", "initial_sid_contexts",
  "initial_sid_context_def", "opt_dev_contexts", "dev_contexts",
  "dev_context_def", "pirq_context_def", "iomem_context_def",
  "ioport_context_def", "pci_context_def", "dtree_context_def",
  "opt_fs_contexts", "fs_contexts", "fs_context_def", "net_contexts",
  "opt_port_contexts", "port_contexts", "port_context_def",
  "opt_netif_contexts", "netif_contexts", "netif_context_def",
  "opt_node_contexts", "node_contexts", "node_context_def", "opt_fs_uses",
  "fs_uses", "fs_use_def", "opt_genfs_contexts", "genfs_contexts",
  "genfs_context_def", "$@17", "ipv4_addr_def", "xperms",
  "nested_xperm_set", "nested_xperm_list", "nested_xperm_element", "$@18",
  "xperm", "security_context_def", "opt_mls_range_def", "mls_range_def",
  "mls_level_def", "id_comma_list", "tilde", "asterisk", "names", "$@19",
  "tilde_push", "asterisk_push", "names_push", "identifier_list_push",
  "identifier_push", "identifier_list", "nested_id_set", "nested_id_list",
  "nested_id_element", "$@20", "identifier", "filesystem", "path",
  "filename", "number", "number64", "ipv6_addr", "policycap_def",
  "permissive_def", "module_policy", "module_def", "version_identifier",
  "avrules_block", "avrule_decls", "avrule_decl", "require_block",
  "require_list", "require_decl", "require_class", "require_decl_def",
  "require_id_list", "optional_block", "$@21", "optional_else",
  "optional_decl", "else_decl", "avrule_user_defs", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   123,   125,
      59,    58,    44,    40,    41,    45,   126,    42
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   118,   119,   119,   121,   122,   123,   120,   124,   124,
     125,   126,   126,   127,   128,   129,   129,   130,   130,   131,
     132,   132,   133,   133,   133,   134,   134,   135,   135,   135,
     135,   135,   135,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   139,   139,   139,   139,   139,   140,   140,   141,
     142,   142,   143,   143,   144,   145,   145,   146,   146,   147,
     147,   148,   148,   149,   149,   150,   150,   151,   151,   152,
     152,   153,   154,   155,   155,   156,   156,   156,   156,   156,
     156,   157,   157,   157,   157,   157,   157,   157,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   159,
     160,   160,   161,   162,   163,   164,   164,   165,   166,   167,
     167,   168,   169,   169,   170,   170,   170,   170,   170,   170,
     170,   170,   171,   172,   172,   173,   173,   173,   174,   174,
     174,   174,   175,   175,   175,   175,   176,   177,   178,   179,
     180,   180,   180,   180,   181,   181,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   196,
     197,   198,   198,   199,   199,   200,   201,   201,   202,   202,
     203,   203,   204,   205,   206,   206,   206,   206,   206,   207,
     207,   207,   208,   207,   209,   207,   210,   207,   211,   207,
     212,   207,   213,   207,   214,   207,   215,   207,   216,   207,
     207,   217,   207,   218,   207,   207,   219,   207,   220,   207,
     207,   207,   207,   207,   207,   207,   221,   221,   222,   222,
     222,   222,   223,   223,   224,   225,   225,   226,   226,   227,
     228,   228,   229,   229,   230,   230,   230,   230,   230,   231,
     232,   232,   233,   233,   234,   235,   236,   236,   237,   237,
     238,   239,   240,   240,   241,   241,   242,   242,   243,   243,
     244,   244,   245,   246,   246,   247,   247,   248,   248,   249,
     249,   250,   250,   251,   251,   251,   252,   252,   253,   253,
     254,   255,   254,   254,   256,   257,   257,   257,   257,   258,
     259,   259,   261,   260,   260,   260,   262,   263,   264,   264,
     265,   265,   266,   266,   267,   267,   268,   269,   270,   270,
     270,   270,   270,   271,   270,   272,   273,   274,   274,   274,
     274,   274,   275,   275,   276,   277,   277,   278,   279,   279,
     280,   281,   280,   280,   282,   283,   283,   284,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   293,   293,
     294,   295,   295,   296,   296,   296,   296,   296,   296,   297,
     298,   298,   299,   299,   300,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   302,   302,   304,   303,   305,   305,
     306,   307,   308,   308
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     0,     0,    17,     1,     2,
       2,     1,     2,     2,     2,     1,     0,     1,     2,     5,
       1,     2,     5,     4,     7,     1,     0,     1,     1,     1,
       1,     2,     2,     2,     2,     4,     4,     4,     4,     4,
       4,     5,     5,     5,     5,     5,     5,     1,     0,     5,
       1,     2,     4,     3,     2,     2,     4,     1,     0,     1,
       2,     4,     3,     1,     2,     5,     3,     1,     2,     1,
       1,     5,     4,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     4,     4,     4,     4,     2,     0,     4,     4,     1,
       1,     6,     4,     0,     3,     2,     3,     3,     3,     3,
       3,     1,     1,     2,     0,     1,     1,     1,     8,     7,
       7,     7,     1,     1,     1,     1,     7,     7,     7,     7,
       8,     7,     7,     7,     5,     7,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     7,     7,     7,     7,     7,
       8,     8,     8,     8,     3,     5,     4,     4,     5,     7,
       4,     1,     2,     3,     5,     4,     1,     0,     1,     2,
       1,     1,     5,     4,     3,     2,     3,     3,     1,     3,
       3,     3,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       1,     0,     4,     0,     4,     2,     0,     4,     0,     4,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     6,     4,     0,     1,     2,     3,
       1,     0,     1,     2,     1,     1,     1,     1,     1,     3,
       3,     5,     3,     5,     3,     3,     1,     0,     1,     2,
       5,     3,     1,     0,     1,     2,     4,     6,     1,     0,
       1,     2,     4,     1,     0,     1,     2,     4,     4,     1,
       0,     1,     2,     4,     4,     4,     1,     0,     1,     2,
       6,     0,     7,     4,     1,     1,     1,     2,     2,     3,
       1,     2,     0,     4,     1,     1,     1,     6,     2,     0,
       3,     1,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     2,     2,     0,     4,     1,     1,     1,     3,     1,
       2,     4,     1,     2,     1,     1,     2,     3,     1,     2,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     2,     4,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     4,
       2,     1,     2,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     6,     4,     0,
       1,     1,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,     2,     0,     3,     0,   344,     0,     1,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     390,     0,   368,   363,   364,    88,    89,    90,    91,    92,
      93,    94,   365,    95,    96,    97,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    81,    82,    87,    83,    84,
      85,    86,    98,   355,   393,   362,   366,   367,     0,   350,
     294,   357,   359,   358,     0,    10,     0,     9,    16,    11,
     106,     0,     0,     0,     0,     0,   106,     0,     0,     0,
       0,     0,     0,   121,   122,     0,   316,   317,     0,   320,
       0,   319,   318,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     393,   361,   360,     0,   356,    13,     0,    12,     5,     0,
      15,    17,     0,     0,     0,     0,   314,   164,     0,     0,
       0,     0,   106,     0,    99,   109,   110,     0,     0,   115,
       0,     0,     0,     0,     0,     0,   124,   341,   343,     0,
     338,   340,   322,   321,     0,   323,     0,     0,     0,     0,
       0,     0,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   375,   378,   376,   377,   380,   381,   382,
     383,   379,     0,   371,     0,     0,   354,     0,   392,     0,
       0,    26,     0,    14,    20,    18,     0,   105,   166,   175,
       0,    54,   102,   103,   104,     0,   101,   107,   108,   114,
     116,   117,   118,   119,   120,     0,     0,   337,   339,     0,
       0,     0,     0,     0,     0,     0,     0,   311,   313,   334,
       0,   167,   172,     0,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   369,   370,   372,   384,     0,     0,
     386,     0,     0,     0,     0,     0,    48,    25,    27,    28,
      29,    30,     0,    21,   165,   315,   100,     0,     0,     0,
       0,     0,     0,     0,   113,   123,   125,   126,   132,   133,
     134,   135,   127,   342,     0,   324,     0,     0,     0,   168,
       0,   144,     0,     0,     0,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   374,   373,     0,   236,   389,
       0,   335,     0,     0,     0,     0,     0,     0,    47,     0,
      50,    31,    32,    33,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     0,     0,     0,     0,
       0,   310,   312,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   385,     0,     0,   391,   387,     0,    19,
     336,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    73,    76,    75,    77,    79,    78,     0,
      51,    58,    23,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   349,   141,     0,   142,   143,   169,   145,   174,
     159,   155,   156,   157,   158,     0,     0,   296,   295,     0,
     306,     0,     0,     0,     0,   234,     0,    35,    36,    37,
      38,    39,    40,     0,     0,     0,     0,     0,     0,    53,
       0,     0,    74,   177,   232,     0,    55,     0,     0,    57,
      59,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   305,     0,   300,   304,   160,   298,   297,   161,
     162,   163,     0,     0,    43,    41,    42,    46,    44,    45,
      52,   353,     0,     0,     6,   176,   178,   180,   181,   233,
       0,     0,     0,     0,    63,    60,     0,     0,     0,     0,
       0,     0,     0,     0,   112,   299,   301,   302,   235,   388,
       0,     0,     0,   179,    56,    62,     0,     0,     0,     0,
      64,    49,    67,    69,    70,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   188,     0,   257,   237,    61,    66,
       0,     0,     0,    68,   129,     0,   130,   131,   136,   137,
     138,   139,   303,     0,   229,   230,   231,   226,   227,   228,
     215,   211,   216,   213,   218,   192,   194,   196,   198,     0,
     200,   202,   204,   206,   208,     0,     0,     0,   185,     0,
       0,     0,   183,     0,     0,   238,   280,   256,   258,     0,
       0,     0,   128,   182,     0,     0,     0,     0,   189,     0,
       0,     0,     0,   190,     0,     0,   191,     0,     0,     0,
     220,   224,   221,   225,   222,   223,   184,   186,   187,   239,
       0,     0,     0,     0,     0,   287,   279,   281,   259,    65,
       0,    72,     0,   325,   326,     0,   329,   212,   327,   217,
     214,   219,   193,   195,   197,   199,   201,   203,   205,   207,
     209,     0,     0,   346,   345,     0,     0,     0,     0,   263,
     286,   288,   282,    71,     0,   332,     0,   330,     0,     0,
       0,     0,     0,     0,     0,   241,   269,   262,   264,   289,
     328,   333,     0,     0,   260,   283,   284,   285,   347,   348,
       0,     0,     0,     0,     0,     0,     0,     7,   240,   242,
     244,   245,   246,   247,   248,     0,   274,   268,   270,   265,
     331,   309,     0,   293,     0,     0,   351,     0,     0,     0,
       0,   243,     0,     0,   261,   273,   275,   271,     0,   307,
     291,     0,     0,   266,   249,     0,   250,     0,   252,   254,
     255,     0,   352,     0,     0,   276,   308,     0,   290,     0,
       0,     0,   272,     0,     0,   292,   267,   251,   253,   277,
     278
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,   211,   522,    11,    12,    88,    89,
     138,   139,   140,   141,   213,   214,   276,   277,   278,   279,
     280,   281,   337,   338,   339,   340,   149,   401,   458,   459,
     460,   503,   504,   531,   532,   533,   534,   392,   393,    43,
      44,    45,    46,    47,    48,    49,   144,    50,    51,   157,
      52,   355,   102,   103,   235,   295,   296,   297,   298,   299,
     300,   301,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
     181,   182,    71,   494,   495,   496,   497,   498,   563,   564,
     629,   630,   631,   632,   634,   635,   637,   638,   639,   624,
     626,   625,   627,   589,   590,   453,   130,   375,   566,   567,
     727,   728,   729,   730,   731,   732,   733,   734,   616,   617,
     618,   705,   706,   707,   708,   736,   737,   738,   754,   755,
     756,   655,   656,   657,   689,   690,   691,   777,    82,   426,
     427,   473,   474,   543,   428,   649,   759,   246,   247,   145,
     108,   109,   110,   240,   665,   666,   667,   694,   668,   330,
     111,   169,   170,   236,   112,   685,   720,   414,   430,   747,
     774,   397,    72,     5,     6,    84,    73,    74,    75,    76,
     202,   203,   204,   205,   268,    77,   329,   377,    78,   378,
     132
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -496
static const yytype_int16 yypact[] =
{
     -35,   -19,   166,  -496,   194,  -496,   417,  -496,   305,  -496,
     -19,   128,  -496,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,    70,    77,    77,    77,    77,    77,    98,
      77,    77,    77,    77,    77,    77,    77,    77,    77,   104,
    -496,   -19,  -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,
    -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,
    -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,
    -496,  -496,  -496,  -496,   506,  -496,  -496,  -496,   148,  -496,
    -496,  -496,  -496,  -496,   151,  -496,   -19,  -496,   246,  -496,
      12,   -19,   226,   338,   -19,   -19,    26,   268,    68,    68,
      70,    70,   249,  -496,  -496,     4,  -496,  -496,   163,  -496,
      77,  -496,   153,    77,    77,    77,    77,   379,    77,    77,
      77,    77,    77,    77,    77,    77,    77,   239,   304,   -19,
     390,  -496,  -496,   417,  -496,  -496,   -19,  -496,  -496,   414,
     437,  -496,    77,   -19,   343,   187,  -496,  -496,    77,   370,
     215,   289,   386,   372,  -496,  -496,  -496,   387,   393,    18,
      91,    70,    70,    70,    70,    70,  -496,  -496,  -496,   107,
    -496,  -496,  -496,  -496,   389,  -496,   391,   398,   -50,    10,
     416,    28,  -496,   399,    87,   400,   407,   411,   428,   430,
     431,   432,   -19,  -496,  -496,  -496,  -496,  -496,  -496,  -496,
    -496,  -496,    22,  -496,   402,   -19,  -496,   512,  -496,   435,
     438,   316,   -19,   414,  -496,  -496,   449,   433,  -496,  -496,
     -19,  -496,  -496,  -496,  -496,   450,  -496,  -496,  -496,  -496,
      18,   300,   247,  -496,  -496,    34,   -19,  -496,  -496,    77,
     -19,    77,    77,    77,   451,    77,   452,   453,   436,  -496,
     342,  -496,  -496,    77,  -496,    77,    77,    77,    77,    77,
      77,    77,    77,    77,  -496,  -496,  -496,  -496,   363,    77,
    -496,   -19,    77,    77,    77,    77,   515,   316,  -496,  -496,
    -496,  -496,    21,  -496,  -496,  -496,  -496,    77,    77,    77,
      77,    77,    77,    77,   536,  -496,  -496,  -496,  -496,  -496,
    -496,  -496,  -496,  -496,   -19,  -496,   -19,   -19,   -19,  -496,
     -19,  -496,   -19,   -19,   379,  -496,    77,    77,    77,    77,
      77,   -19,   -19,   -19,   -19,  -496,  -496,   -19,   526,   539,
     -36,  -496,   293,   321,   375,   385,   -19,   920,  -496,   362,
    -496,  -496,  -496,  -496,  -496,   -19,   -19,    77,    77,    77,
      77,    77,    77,    77,   459,  -496,    23,   464,   477,   482,
     485,  -496,   433,    30,   489,   491,   494,   496,   497,   149,
     149,   149,   149,  -496,   -19,   498,  -496,  -496,   492,  -496,
    -496,   499,   501,   503,   504,   505,   507,   236,   281,    17,
     -19,  -496,   826,  -496,  -496,  -496,  -496,  -496,  -496,   202,
    -496,   580,   511,   -18,   509,   510,   513,   514,   516,   517,
     518,  -496,  -496,  -496,   520,  -496,  -496,  -496,  -496,  -496,
    -496,  -496,  -496,  -496,  -496,   -13,   521,  -496,  -496,   -13,
    -496,   522,   523,   524,   582,  -496,   417,  -496,  -496,  -496,
    -496,  -496,  -496,   525,   527,   528,   529,   530,   531,  -496,
     532,   533,  -496,    62,  -496,   -19,  -496,   -19,   584,   580,
    -496,   -19,  -496,    77,    77,    77,    77,    77,    77,    77,
     141,  -496,  -496,   207,  -496,   534,  -496,  -496,  -496,  -496,
    -496,  -496,   -19,   535,  -496,  -496,  -496,  -496,  -496,  -496,
    -496,  -496,    77,    77,  -496,   475,  -496,  -496,  -496,  -496,
     111,    31,   -19,   382,  -496,  -496,   157,   -19,   -19,   -19,
      77,    77,    77,    77,  -496,  -496,  -496,  -496,  -496,  -496,
      77,   154,   614,  -496,  -496,  -496,   538,   377,    77,    77,
    -496,   448,  -496,  -496,  -496,  -496,    24,   540,   541,   544,
     546,   547,   552,   556,   154,    66,    97,   190,  -496,   401,
     401,   401,    66,   401,   401,   401,   401,   401,    66,    66,
      66,   154,   154,   130,  -496,   -19,    32,  -496,  -496,  -496,
     -19,    77,   154,  -496,  -496,   562,  -496,  -496,  -496,  -496,
    -496,  -496,  -496,   134,  -496,  -496,  -496,  -496,  -496,  -496,
    -496,  -496,  -496,  -496,  -496,   566,  -496,  -496,   573,   600,
    -496,  -496,   598,  -496,  -496,   346,   594,   395,  -496,     0,
     154,   154,  -496,   -19,   556,  -496,   392,   620,  -496,   367,
     154,   159,  -496,  -496,    84,    84,    84,    84,  -496,    84,
      84,    84,    84,  -496,    84,    84,  -496,    84,    84,    84,
    -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,   595,  -496,
     568,   556,    96,   -19,   -19,   609,   392,  -496,  -496,  -496,
     165,  -496,   416,  -496,  -496,   216,  -496,  -496,  -496,  -496,
    -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,
    -496,   -19,   -19,  -496,  -496,   -19,   -19,   -19,    96,   625,
     609,  -496,  -496,  -496,   167,  -496,   416,  -496,   572,   -19,
     578,   579,   581,   490,   -19,   344,   632,   625,  -496,  -496,
    -496,  -496,   186,   -19,  -496,  -496,  -496,  -496,  -496,  -496,
      44,   556,   556,   603,   556,   556,   490,  -496,   344,  -496,
    -496,  -496,  -496,  -496,  -496,   -19,   635,   632,  -496,  -496,
    -496,   585,    58,  -496,    65,   -19,  -496,   158,   172,   -19,
     -19,  -496,   -19,   403,  -496,   635,  -496,  -496,   -19,  -496,
    -496,   -19,   556,  -496,  -496,   603,  -496,   556,  -496,  -496,
    -496,   -19,  -496,   605,   602,  -496,  -496,   -19,  -496,   -19,
     -19,   -19,  -496,   -19,   -19,  -496,  -496,  -496,  -496,  -496,
    -496
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -496,  -496,  -496,  -496,  -496,  -496,  -496,   688,  -496,   612,
    -496,  -496,  -496,   561,  -496,   493,  -496,  -496,   425,   427,
     434,   439,  -496,  -496,  -496,   366,   -91,  -496,  -496,  -496,
     248,  -496,   205,  -496,   178,  -496,  -496,  -496,   318,  -281,
    -279,  -496,  -496,  -496,  -496,  -496,   -46,  -496,  -496,   615,
    -269,  -496,   -14,  -496,   302,  -496,  -496,  -496,  -496,  -496,
    -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,
    -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,
     408,  -173,  -496,  -496,  -496,   220,  -496,  -496,  -495,  -496,
    -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,  -496,
    -496,  -496,  -496,  -185,  -258,  -496,  -356,  -496,  -496,   160,
    -496,  -496,    -5,  -496,  -496,  -496,  -496,  -496,  -496,  -496,
     108,  -496,  -496,  -496,    20,  -496,  -496,    -9,  -496,  -496,
     -31,  -496,  -496,    73,  -496,  -496,    40,  -496,  -445,   100,
    -351,  -496,   258,  -496,  -398,  -368,  -496,  -303,  -278,   -92,
    -346,  -276,   545,  -496,  -496,  -496,   -41,    36,  -179,  -335,
     -51,  -496,   564,  -496,    -1,    47,    11,   200,    -4,   -27,
     -34,  -496,  -496,  -496,  -496,  -496,  -123,  -496,   665,  -229,
    -496,   543,  -496,  -496,  -496,  -248,  -496,  -496,  -496,  -496,
     622
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -229
static const yytype_int16 yytable[] =
{
       8,   250,   150,   151,    83,   152,   302,   360,   252,    85,
     209,   403,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   104,   429,   429,   429,   429,   475,   412,   412,
     192,   478,   345,   142,   361,   193,   454,   194,     7,   148,
     128,   180,   195,   180,   565,   196,   197,   198,   148,   583,
     153,   217,     7,   148,   168,   199,   394,   172,   395,     1,
     200,   243,   287,   288,   289,   201,   608,   609,   396,     7,
       7,   492,   493,   379,   472,   475,    79,   621,   477,   290,
     291,   292,   293,   610,   611,   135,   159,   160,   614,   398,
     146,   462,     7,   146,   146,   425,   434,   499,     7,   104,
     104,   584,   585,   586,   171,   129,   225,   173,   164,   165,
     591,   394,   105,   395,   646,   647,   648,   592,   168,   167,
     500,   245,   472,   396,   143,   660,   506,   449,   207,   346,
      39,   264,     7,   413,   574,   210,    10,   251,   143,   419,
      86,   525,   146,   294,   398,   582,     7,   230,   231,   232,
     233,   234,   100,     7,   155,   156,   587,   588,     7,   742,
     104,   104,   104,   104,   104,     7,     9,   545,   171,   287,
     288,   289,   249,   760,   161,   162,   163,   244,   248,   518,
     762,   164,   165,   101,   683,   105,   290,   291,   292,   293,
     252,   263,   662,   106,   107,     7,   684,   254,   255,     7,
     106,   107,    10,   593,   267,   229,   117,   546,   547,   548,
     594,   282,   127,   610,   611,   105,   237,   610,   611,   285,
     524,   362,   167,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   303,   561,    39,    79,   305,
     612,   302,   610,   611,   623,     7,     7,   192,   610,   611,
     514,     7,   193,   136,   194,   249,   133,   425,    86,   195,
       7,   134,   196,   197,   198,   106,   535,   562,   175,   661,
     331,   105,   199,   765,   249,   693,   710,   200,   663,   663,
     663,   663,   201,   663,   663,   663,   663,   767,   663,   663,
       7,   663,   663,   663,   599,   740,    79,   219,   450,   220,
     605,   606,   607,   356,   249,   357,   358,   359,   773,   248,
     455,   248,   146,   483,   699,   425,   515,   700,   701,   702,
     369,   370,   371,   372,   696,   223,   373,   220,   783,   380,
     161,   714,   161,   162,   163,   389,   147,   164,   165,   164,
     165,   443,   444,   445,   402,   331,   381,   382,   664,   664,
     664,   664,   743,   664,   664,   664,   664,   166,   664,   664,
     148,   664,   664,   664,   595,   596,   597,   598,   600,   601,
     602,   603,   604,   248,   383,   384,   763,   764,   154,   766,
     768,   769,   770,   161,   771,   163,   446,   447,   448,   451,
     164,   165,   180,   778,    79,   336,   399,    80,   456,   224,
      81,   220,   380,   782,   722,   723,   724,   725,   726,   785,
     526,   786,   787,   788,   206,   789,   790,   272,   273,   274,
     275,   502,   212,   528,   529,   640,   641,   642,   385,   386,
      13,    14,    15,   129,    16,    17,    18,    19,   387,   388,
      20,    21,    22,    23,   136,    24,    25,    26,    27,    28,
     314,    29,   315,   218,   331,   776,   501,   652,   653,   654,
     331,    30,    31,    32,    33,    34,    35,    36,    37,    38,
     431,   432,   433,   326,   644,   327,   645,   659,   619,   220,
     222,   248,   226,   695,   492,   493,   697,   569,   570,   528,
     529,   587,   588,   718,   719,    80,   772,   227,   143,   380,
     239,   527,   241,   228,   249,   380,   536,   537,   538,   242,
     253,   256,   266,    39,    40,   711,    41,   695,   257,    13,
      14,    15,   258,    16,    17,    18,    19,    42,   269,    20,
      21,    22,    23,   711,    24,    25,    26,    27,    28,   259,
      29,   260,   261,   262,   270,   220,   271,   313,   336,   129,
      30,    31,    32,    33,    34,    35,    36,    37,    38,   284,
     286,   309,   311,   354,   613,   374,   376,   411,   312,   146,
     113,   114,   115,   116,   415,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   669,   670,   671,   416,   672,   673,
     674,   675,   417,   676,   677,   418,   678,   679,   680,   420,
     436,   421,    39,    40,   422,    41,   423,   424,   435,   437,
     651,   438,   650,   439,   440,   441,    42,   442,   457,   461,
     463,   464,   482,   502,   465,   466,   565,   467,   468,   469,
     471,   476,   479,   480,   481,   484,   628,   485,   486,   487,
     488,   489,   490,   491,   519,    79,  -228,   682,   568,   517,
     576,   577,   686,   687,   578,   174,   579,   580,   176,   177,
     178,   179,   581,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   622,   633,   636,   643,   614,   688,   610,   681,
     698,   650,   704,   713,   650,   650,   650,   216,   715,   716,
     735,   717,   746,   221,   753,   772,   758,    80,   650,    87,
     137,   215,   341,   721,   342,   400,   283,   505,   530,   573,
     452,   343,   741,   470,   158,   523,   344,   744,   745,   650,
     748,   749,   363,   751,   775,   658,   615,   739,   757,   692,
     709,   516,   712,   238,   752,   703,   575,   750,   780,   131,
     784,   761,     0,   650,   650,   265,   650,   650,   650,   650,
       0,   650,   208,     0,     0,     0,     0,   248,   779,     0,
     650,     0,     0,   781,     0,     0,     0,     0,     0,     0,
     650,     0,     0,     0,     0,     0,   650,     0,   650,   650,
     650,     0,   650,   650,   304,     0,   306,   307,   308,     0,
     310,     0,     0,     0,     0,     0,     0,     0,   316,     0,
     317,   318,   319,   320,   321,   322,   323,   324,   325,     0,
       0,     0,     0,     0,   328,     0,     0,   332,   333,   334,
     335,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   347,   348,   349,   350,   351,   352,   353,    13,
      14,    15,     0,    16,    17,    18,    19,     0,     0,    20,
      21,    22,    23,     0,    24,    25,    26,    27,    28,     0,
      29,   364,   365,   366,   367,   368,     0,     0,     0,   129,
      30,    31,    32,    33,    34,    35,    36,    37,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   404,   405,   406,   407,   408,   409,   410,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,   390,    41,     0,     0,     0,     0,
       0,     0,     0,    13,    14,    15,   391,    16,    17,    18,
      19,     0,     0,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   507,   508,
     509,   510,   511,   512,   513,     0,     0,    40,   390,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     391,     0,     0,     0,     0,     0,     0,   520,   521,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   539,   540,   541,   542,     0,
       0,     0,     0,     0,     0,   544,     0,     0,     0,     0,
       0,     0,     0,   571,   572,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   620
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-496)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,   180,    94,    95,     8,    96,   235,   310,   181,    10,
     133,   346,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   369,   370,   371,   372,   425,     5,     5,
       8,   429,    11,    21,   312,    13,   392,    15,    88,    22,
      41,    13,    20,    13,    12,    23,    24,    25,    22,   544,
      96,   143,    88,    22,   105,    33,   337,   108,   337,    94,
      38,   111,    28,    29,    30,    43,   561,   562,   337,    88,
      88,     9,    10,   109,   425,   473,    89,   572,   429,    45,
      46,    47,    48,    83,    84,    86,   100,   101,    56,   337,
      91,   109,    88,    94,    95,   108,   374,   453,    88,   100,
     101,    35,    36,    37,   105,    43,   152,   108,    90,    91,
      13,   392,   108,   392,   114,   610,   611,    20,   169,   115,
     455,   111,   473,   392,   112,   620,   461,   110,   129,   108,
      96,   109,    88,   110,   110,   136,     8,   109,   112,   109,
      12,   110,   143,   109,   392,   543,    88,   161,   162,   163,
     164,   165,    82,    88,    86,    87,    90,    91,    88,   115,
     161,   162,   163,   164,   165,    88,     0,    13,   169,    28,
      29,    30,    88,   115,    83,    84,    85,   178,   179,   482,
     115,    90,    91,   113,    88,   108,    45,    46,    47,    48,
     363,   192,   108,   116,   117,    88,   100,   110,   111,    88,
     116,   117,     8,    13,   205,   114,   108,    53,    54,    55,
      20,   212,   108,    83,    84,   108,   109,    83,    84,   220,
     109,   313,   115,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,   236,    82,    96,    89,   240,
     110,   470,    83,    84,   110,    88,    88,     8,    83,    84,
     109,    88,    13,     7,    15,    88,   108,   108,    12,    20,
      88,   110,    23,    24,    25,   116,   109,   113,   115,   110,
     271,   108,    33,   115,    88,   110,   109,    38,   624,   625,
     626,   627,    43,   629,   630,   631,   632,   115,   634,   635,
      88,   637,   638,   639,   552,   109,    89,   110,   389,   112,
     558,   559,   560,   304,    88,   306,   307,   308,   753,   310,
     108,   312,   313,   436,   682,   108,   109,   685,   686,   687,
     321,   322,   323,   324,   108,   110,   327,   112,   773,   330,
      83,   699,    83,    84,    85,   336,   110,    90,    91,    90,
      91,   105,   106,   107,   345,   346,    53,    54,   624,   625,
     626,   627,   720,   629,   630,   631,   632,   108,   634,   635,
      22,   637,   638,   639,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   374,    53,    54,   744,   745,   110,   747,
     748,   749,   750,    83,   752,    85,   105,   106,   107,   390,
      90,    91,    13,   761,    89,    33,    34,    92,   399,   110,
      95,   112,   403,   771,    60,    61,    62,    63,    64,   777,
     501,   779,   780,   781,   110,   783,   784,   101,   102,   103,
     104,    39,     8,    41,    42,    79,    80,    81,    53,    54,
      13,    14,    15,    43,    17,    18,    19,    20,    53,    54,
      23,    24,    25,    26,     7,    28,    29,    30,    31,    32,
     108,    34,   110,   110,   455,   758,   457,    65,    66,    67,
     461,    44,    45,    46,    47,    48,    49,    50,    51,    52,
     370,   371,   372,   110,    79,   112,    81,   110,   570,   112,
     110,   482,   110,   662,     9,    10,   665,   110,   111,    41,
      42,    90,    91,     3,     4,    92,    93,   110,   112,   500,
     111,   502,   111,   110,    88,   506,   507,   508,   509,   111,
     111,   111,   110,    96,    97,   694,    99,   696,   111,    13,
      14,    15,   111,    17,    18,    19,    20,   110,    16,    23,
      24,    25,    26,   712,    28,    29,    30,    31,    32,   111,
      34,   111,   111,   111,   109,   112,   108,   111,    33,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,   110,
     110,   110,   110,    27,   565,    39,    27,   108,   115,   570,
      25,    26,    27,    28,   110,    30,    31,    32,    33,    34,
      35,    36,    37,    38,   625,   626,   627,   110,   629,   630,
     631,   632,   110,   634,   635,   110,   637,   638,   639,   110,
     108,   110,    96,    97,   110,    99,   110,   110,   110,   110,
     614,   110,   613,   110,   110,   110,   110,   110,    38,   108,
     111,   111,    40,    39,   111,   111,    12,   111,   111,   111,
     110,   110,   110,   110,   110,   110,    70,   110,   110,   110,
     110,   110,   110,   110,   109,    89,    73,   651,   110,   115,
     110,   110,   653,   654,   110,   110,   110,   110,   113,   114,
     115,   116,   110,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   110,    73,    76,    81,    56,    68,    83,   111,
     681,   682,    57,   111,   685,   686,   687,   142,   110,   110,
      58,   110,    89,   148,    59,    93,   111,    92,   699,    11,
      88,   140,   277,   704,   277,   339,   213,   459,   503,   531,
     392,   277,   713,   411,    99,   495,   277,   721,   722,   720,
     724,   725,   314,   728,   755,   617,   566,   707,   737,   656,
     690,   473,   696,   169,   735,   688,   536,   726,   765,    74,
     774,   742,    -1,   744,   745,   202,   747,   748,   749,   750,
      -1,   752,   130,    -1,    -1,    -1,    -1,   758,   762,    -1,
     761,    -1,    -1,   767,    -1,    -1,    -1,    -1,    -1,    -1,
     771,    -1,    -1,    -1,    -1,    -1,   777,    -1,   779,   780,
     781,    -1,   783,   784,   239,    -1,   241,   242,   243,    -1,
     245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
      -1,    -1,    -1,    -1,   269,    -1,    -1,   272,   273,   274,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   287,   288,   289,   290,   291,   292,   293,    13,
      14,    15,    -1,    17,    18,    19,    20,    -1,    -1,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    -1,
      34,   316,   317,   318,   319,   320,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   347,   348,   349,   350,   351,   352,   353,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,   110,    17,    18,    19,
      20,    -1,    -1,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   463,   464,
     465,   466,   467,   468,   469,    -1,    -1,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,   492,   493,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   510,   511,   512,   513,    -1,
      -1,    -1,    -1,    -1,    -1,   520,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   528,   529,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   571
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    94,   119,   120,   121,   291,   292,    88,   282,     0,
       8,   124,   125,    13,    14,    15,    17,    18,    19,    20,
      23,    24,    25,    26,    28,    29,    30,    31,    32,    34,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    96,
      97,    99,   110,   157,   158,   159,   160,   161,   162,   163,
     165,   166,   168,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   200,   290,   294,   295,   296,   297,   303,   306,    89,
      92,    95,   256,   286,   293,   282,    12,   125,   126,   127,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
      82,   113,   170,   171,   282,   108,   116,   117,   268,   269,
     270,   278,   282,   270,   270,   270,   270,   108,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   108,   282,    43,
     224,   296,   308,   108,   110,   282,     7,   127,   128,   129,
     130,   131,    21,   112,   164,   267,   282,   110,    22,   144,
     267,   267,   144,   164,   110,    86,    87,   167,   167,   170,
     170,    83,    84,    85,    90,    91,   108,   115,   278,   279,
     280,   282,   278,   282,   270,   115,   270,   270,   270,   270,
      13,   198,   199,   270,   270,   270,   270,   270,   270,   270,
     270,   270,     8,    13,    15,    20,    23,    24,    25,    33,
      38,    43,   298,   299,   300,   301,   110,   282,   308,   294,
     282,   122,     8,   132,   133,   131,   270,   267,   110,   110,
     112,   270,   110,   110,   110,   164,   110,   110,   110,   114,
     170,   170,   170,   170,   170,   172,   281,   109,   280,   111,
     271,   111,   111,   111,   282,   111,   265,   266,   282,    88,
     276,   109,   199,   111,   110,   111,   111,   111,   111,   111,
     111,   111,   111,   282,   109,   299,   110,   282,   302,    16,
     109,   108,   101,   102,   103,   104,   134,   135,   136,   137,
     138,   139,   282,   133,   110,   282,   110,    28,    29,    30,
      45,    46,    47,    48,   109,   173,   174,   175,   176,   177,
     178,   179,   297,   282,   270,   282,   270,   270,   270,   110,
     270,   110,   115,   111,   108,   110,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   110,   112,   270,   304,
     277,   282,   270,   270,   270,   270,    33,   140,   141,   142,
     143,   136,   137,   138,   139,    11,   108,   270,   270,   270,
     270,   270,   270,   270,    27,   169,   282,   282,   282,   282,
     265,   266,   267,   198,   270,   270,   270,   270,   270,   282,
     282,   282,   282,   282,    39,   225,    27,   305,   307,   109,
     282,    53,    54,    53,    54,    53,    54,    53,    54,   282,
      98,   110,   155,   156,   157,   158,   168,   289,   303,    34,
     143,   145,   282,   277,   270,   270,   270,   270,   270,   270,
     270,   108,     5,   110,   285,   110,   110,   110,   110,   109,
     110,   110,   110,   110,   110,   108,   257,   258,   262,   268,
     286,   257,   257,   257,   266,   110,   108,   110,   110,   110,
     110,   110,   110,   105,   106,   107,   105,   106,   107,   110,
     144,   282,   156,   223,   224,   108,   282,    38,   146,   147,
     148,   108,   109,   111,   111,   111,   111,   111,   111,   111,
     172,   110,   258,   259,   260,   262,   110,   258,   262,   110,
     110,   110,    40,   294,   110,   110,   110,   110,   110,   110,
     110,   110,     9,    10,   201,   202,   203,   204,   205,   224,
     277,   282,    39,   149,   150,   148,   277,   270,   270,   270,
     270,   270,   270,   270,   109,   109,   260,   115,   265,   109,
     270,   270,   123,   203,   109,   110,   144,   282,    41,    42,
     150,   151,   152,   153,   154,   109,   282,   282,   282,   270,
     270,   270,   270,   261,   270,    13,    53,    54,    55,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    82,   113,   206,   207,    12,   226,   227,   110,   110,
     111,   270,   270,   152,   110,   285,   110,   110,   110,   110,
     110,   110,   262,   206,    35,    36,    37,    90,    91,   221,
     222,    13,    20,    13,    20,   221,   221,   221,   221,   222,
     221,   221,   221,   221,   221,   222,   222,   222,   206,   206,
      83,    84,   110,   282,    56,   227,   236,   237,   238,   267,
     270,   206,   110,   110,   217,   219,   218,   220,    70,   208,
     209,   210,   211,    73,   212,   213,    76,   214,   215,   216,
      79,    80,    81,    81,    79,    81,   114,   206,   206,   263,
     282,   286,    65,    66,    67,   249,   250,   251,   238,   110,
     206,   110,   108,   268,   269,   272,   273,   274,   276,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   111,   286,    88,   100,   283,   282,   282,    68,   252,
     253,   254,   251,   110,   275,   276,   108,   276,   282,   263,
     263,   263,   263,   283,    57,   239,   240,   241,   242,   254,
     109,   276,   275,   111,   263,   110,   110,   110,     3,     4,
     284,   282,    60,    61,    62,    63,    64,   228,   229,   230,
     231,   232,   233,   234,   235,    58,   243,   244,   245,   242,
     109,   282,   115,   263,   286,   286,    89,   287,   286,   286,
     284,   230,   282,    59,   246,   247,   248,   245,   111,   264,
     115,   282,   115,   263,   263,   115,   263,   115,   263,   263,
     263,   263,    93,   256,   288,   248,   265,   255,   263,   286,
     287,   286,   263,   256,   288,   263,   263,   263,   263,   263,
     263
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
        case 4:
/* Line 1792 of yacc.c  */
#line 165 "external/selinux/checkpolicy/policy_parse.y"
    { if (define_policy(pass, 0) == -1) return -1; }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 167 "external/selinux/checkpolicy/policy_parse.y"
    { if (pass == 1) { if (policydb_index_classes(policydbp)) return -1; }
                            else if (pass == 2) { if (policydb_index_others(NULL, policydbp, 0)) return -1; }}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 170 "external/selinux/checkpolicy/policy_parse.y"
    { if (pass == 1) { if (policydb_index_bools(policydbp)) return -1;}
			   else if (pass == 2) { if (policydb_index_others(NULL, policydbp, 0)) return -1;}}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 178 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_class()) return -1;}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 184 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_initial_sid()) return -1;}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 195 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_common_perms()) return -1;}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 201 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_av_perms(FALSE)) return -1;}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 203 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_av_perms(TRUE)) return -1;}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 205 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_av_perms(TRUE)) return -1;}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 220 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_default_user(DEFAULT_SOURCE)) return -1; }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 222 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_default_user(DEFAULT_TARGET)) return -1; }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 225 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_default_role(DEFAULT_SOURCE)) return -1; }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 227 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_default_role(DEFAULT_TARGET)) return -1; }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 230 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_default_type(DEFAULT_SOURCE)) return -1; }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 232 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_default_type(DEFAULT_TARGET)) return -1; }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 235 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_default_range(DEFAULT_SOURCE_LOW)) return -1; }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 237 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_default_range(DEFAULT_SOURCE_HIGH)) return -1; }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 239 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_default_range(DEFAULT_SOURCE_LOW_HIGH)) return -1; }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 241 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_default_range(DEFAULT_TARGET_LOW)) return -1; }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 243 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_default_range(DEFAULT_TARGET_HIGH)) return -1; }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 245 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_default_range(DEFAULT_TARGET_LOW_HIGH)) return -1; }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 256 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_sens()) return -1;}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 258 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_sens()) return -1;}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 263 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_dominance()) return -1;}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 265 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_dominance()) return -1;}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 274 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_category()) return -1;}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 276 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_category()) return -1;}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 282 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_level()) return -1;}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 284 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_level()) return -1;}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 293 "external/selinux/checkpolicy/policy_parse.y"
    { if (define_constraint((constraint_expr_t*)(yyvsp[(4) - (5)].valptr))) return -1; }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 296 "external/selinux/checkpolicy/policy_parse.y"
    { if (define_validatetrans((constraint_expr_t*)(yyvsp[(3) - (4)].valptr))) return -1; }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 329 "external/selinux/checkpolicy/policy_parse.y"
    { if (define_attrib()) return -1;}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 332 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_type(1)) return -1;}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 334 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_type(0)) return -1;}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 337 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_typealias()) return -1;}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 340 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_typeattribute()) return -1;}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 343 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_typebounds()) return -1;}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 349 "external/selinux/checkpolicy/policy_parse.y"
    { if (define_bool_tunable(0)) return -1; }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 352 "external/selinux/checkpolicy/policy_parse.y"
    { if (define_bool_tunable(1)) return -1; }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 355 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id("T",0)) return -1; }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 357 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id("F",0)) return -1; }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 360 "external/selinux/checkpolicy/policy_parse.y"
    { if (pass == 2) { if (define_conditional((cond_expr_t*)(yyvsp[(2) - (6)].ptr), (avrule_t*)(yyvsp[(4) - (6)].ptr), (avrule_t*)(yyvsp[(6) - (6)].ptr)) < 0) return -1;  }}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 363 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 365 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = NULL; }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 368 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = (yyvsp[(2) - (3)].ptr);}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 370 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_expr(COND_NOT, (yyvsp[(2) - (2)].ptr), 0);
			  if ((yyval.ptr) == 0) return -1; }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 373 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_expr(COND_AND, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr));
			  if ((yyval.ptr) == 0) return  -1; }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 376 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_expr(COND_OR, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr));
			  if ((yyval.ptr) == 0) return   -1; }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 379 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_expr(COND_XOR, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr));
			  if ((yyval.ptr) == 0) return  -1; }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 382 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_expr(COND_EQ, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr));
			  if ((yyval.ptr) == 0) return  -1; }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 385 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_expr(COND_NEQ, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr));
			  if ((yyval.ptr) == 0) return  -1; }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 388 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 391 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_expr(COND_BOOL,0, 0);
			  if ((yyval.ptr) == COND_ERR) return   -1; }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 395 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_pol_list((avrule_t *)(yyvsp[(1) - (2)].ptr), (avrule_t *)(yyvsp[(2) - (2)].ptr)); }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 397 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = NULL; }
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 400 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 402 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 404 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = NULL; }
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 407 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_filename_trans() ;
                          if ((yyval.ptr) == COND_ERR) return -1;}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 410 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_compute_type(AVRULE_TRANSITION) ;
                          if ((yyval.ptr) == COND_ERR) return -1;}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 413 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_compute_type(AVRULE_MEMBER) ;
                          if ((yyval.ptr) ==  COND_ERR) return -1;}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 416 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_compute_type(AVRULE_CHANGE) ;
                          if ((yyval.ptr) == COND_ERR) return -1;}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 420 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 422 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 424 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 426 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 429 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_te_avtab(AVRULE_ALLOWED) ;
                          if ((yyval.ptr) == COND_ERR) return -1; }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 433 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_te_avtab(AVRULE_AUDITALLOW) ;
                          if ((yyval.ptr) == COND_ERR) return -1; }
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 437 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_te_avtab(AVRULE_AUDITDENY) ;
                          if ((yyval.ptr) == COND_ERR) return -1; }
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 441 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = define_cond_te_avtab(AVRULE_DONTAUDIT);
                          if ((yyval.ptr) == COND_ERR) return -1; }
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 446 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_filename_trans()) return -1; }
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 448 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_compute_type(AVRULE_TRANSITION)) return -1;}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 450 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_compute_type(AVRULE_MEMBER)) return -1;}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 452 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_compute_type(AVRULE_CHANGE)) return -1;}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 455 "external/selinux/checkpolicy/policy_parse.y"
    { if (define_range_trans(0)) return -1; }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 457 "external/selinux/checkpolicy/policy_parse.y"
    { if (define_range_trans(1)) return -1; }
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 470 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_te_avtab(AVRULE_ALLOWED)) return -1; }
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 473 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_te_avtab(AVRULE_AUDITALLOW)) return -1; }
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 476 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_te_avtab(AVRULE_AUDITDENY)) return -1; }
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 479 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_te_avtab(AVRULE_DONTAUDIT)) return -1; }
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 482 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_te_avtab(AVRULE_NEVERALLOW)) return -1; }
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 485 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_te_avtab_extended_perms(AVRULE_XPERMS_ALLOWED)) return -1; }
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 488 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_te_avtab_extended_perms(AVRULE_XPERMS_AUDITALLOW)) return -1; }
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 491 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_te_avtab_extended_perms(AVRULE_XPERMS_DONTAUDIT)) return -1; }
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 494 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_te_avtab_extended_perms(AVRULE_XPERMS_NEVERALLOW)) return -1; }
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 497 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_attrib_role()) return -1; }
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 500 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_role_types()) return -1;}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 503 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_role_attr()) return -1;}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 508 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_role_trans(0)) return -1; }
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 510 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_role_trans(1)) return -1;}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 513 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_role_allow()) return -1; }
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 516 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 518 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.ptr) = merge_roles_dom((role_datum_t*)(yyvsp[(1) - (2)].ptr), (role_datum_t*)(yyvsp[(2) - (2)].ptr)); if ((yyval.ptr) == 0) return -1;}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 521 "external/selinux/checkpolicy/policy_parse.y"
    {(yyval.ptr) = define_role_dom(NULL); if ((yyval.ptr) == 0) return -1;}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 523 "external/selinux/checkpolicy/policy_parse.y"
    {(yyval.ptr) = define_role_dom((role_datum_t*)(yyvsp[(4) - (5)].ptr)); if ((yyval.ptr) == 0) return -1;}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 526 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_roleattribute()) return -1;}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 538 "external/selinux/checkpolicy/policy_parse.y"
    { if (define_constraint((constraint_expr_t*)(yyvsp[(4) - (5)].valptr))) return -1; }
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 541 "external/selinux/checkpolicy/policy_parse.y"
    { if (define_validatetrans((constraint_expr_t*)(yyvsp[(3) - (4)].valptr))) return -1; }
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 544 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = (yyvsp[(2) - (3)].valptr); }
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 546 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NOT, (yyvsp[(2) - (2)].valptr), 0);
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 549 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_AND, (yyvsp[(1) - (3)].valptr), (yyvsp[(3) - (3)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 552 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_OR, (yyvsp[(1) - (3)].valptr), (yyvsp[(3) - (3)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 555 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = (yyvsp[(1) - (1)].valptr); }
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 558 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_USER, (yyvsp[(2) - (3)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 561 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_ROLE, (yyvsp[(2) - (3)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 564 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_TYPE, (yyvsp[(2) - (3)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 566 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(1)) return -1; }
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 567 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NAMES, CEXPR_USER, (yyvsp[(2) - (4)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 569 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(1)) return -1; }
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 570 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_USER | CEXPR_TARGET), (yyvsp[(2) - (4)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 572 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(1)) return -1; }
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 573 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_USER | CEXPR_XTARGET), (yyvsp[(2) - (4)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 575 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(1)) return -1; }
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 576 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NAMES, CEXPR_ROLE, (yyvsp[(2) - (4)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 578 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(1)) return -1; }
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 579 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_ROLE | CEXPR_TARGET), (yyvsp[(2) - (4)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 581 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(1)) return -1; }
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 582 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_ROLE | CEXPR_XTARGET), (yyvsp[(2) - (4)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 584 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(1)) return -1; }
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 585 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NAMES, CEXPR_TYPE, (yyvsp[(2) - (4)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 587 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(1)) return -1; }
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 588 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_TYPE | CEXPR_TARGET), (yyvsp[(2) - (4)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 208:
/* Line 1792 of yacc.c  */
#line 590 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(1)) return -1; }
    break;

  case 209:
/* Line 1792 of yacc.c  */
#line 591 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_TYPE | CEXPR_XTARGET), (yyvsp[(2) - (4)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 210:
/* Line 1792 of yacc.c  */
#line 594 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_USER, CEXPR_EQ);
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 211:
/* Line 1792 of yacc.c  */
#line 596 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(1)) return -1; }
    break;

  case 212:
/* Line 1792 of yacc.c  */
#line 597 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NAMES, CEXPR_ROLE, CEXPR_EQ);
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 213:
/* Line 1792 of yacc.c  */
#line 599 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(1)) return -1; }
    break;

  case 214:
/* Line 1792 of yacc.c  */
#line 600 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_ROLE | CEXPR_TARGET), CEXPR_EQ);
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 215:
/* Line 1792 of yacc.c  */
#line 603 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_ROLE, (yyvsp[(2) - (2)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 216:
/* Line 1792 of yacc.c  */
#line 605 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(1)) return -1; }
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 606 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NAMES, CEXPR_TYPE, CEXPR_EQ);
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 608 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(1)) return -1; }
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 609 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_TYPE | CEXPR_TARGET), CEXPR_EQ);
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 612 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_L1L2, (yyvsp[(2) - (3)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 615 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_L1H2, (yyvsp[(2) - (3)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 618 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_H1L2, (yyvsp[(2) - (3)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 621 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_H1H2, (yyvsp[(2) - (3)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 624 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_L1H1, (yyvsp[(2) - (3)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 627 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_L2H2, (yyvsp[(2) - (3)].valptr));
			  if ((yyval.valptr) == 0) return -1; }
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 631 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = CEXPR_EQ; }
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 633 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = CEXPR_NEQ; }
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 636 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = (yyvsp[(1) - (1)].valptr); }
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 638 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = CEXPR_DOM; }
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 640 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = CEXPR_DOMBY; }
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 642 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.valptr) = CEXPR_INCOMP; }
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 648 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_user()) return -1;}
    break;

  case 239:
/* Line 1792 of yacc.c  */
#line 657 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_initial_sid_context()) return -1;}
    break;

  case 249:
/* Line 1792 of yacc.c  */
#line 671 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_pirq_context((yyvsp[(2) - (3)].val))) return -1;}
    break;

  case 250:
/* Line 1792 of yacc.c  */
#line 674 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_iomem_context((yyvsp[(2) - (3)].val64),(yyvsp[(2) - (3)].val64))) return -1;}
    break;

  case 251:
/* Line 1792 of yacc.c  */
#line 676 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_iomem_context((yyvsp[(2) - (5)].val64),(yyvsp[(4) - (5)].val64))) return -1;}
    break;

  case 252:
/* Line 1792 of yacc.c  */
#line 679 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_ioport_context((yyvsp[(2) - (3)].val),(yyvsp[(2) - (3)].val))) return -1;}
    break;

  case 253:
/* Line 1792 of yacc.c  */
#line 681 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_ioport_context((yyvsp[(2) - (5)].val),(yyvsp[(4) - (5)].val))) return -1;}
    break;

  case 254:
/* Line 1792 of yacc.c  */
#line 684 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_pcidevice_context((yyvsp[(2) - (3)].val))) return -1;}
    break;

  case 255:
/* Line 1792 of yacc.c  */
#line 687 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_devicetree_context()) return -1;}
    break;

  case 260:
/* Line 1792 of yacc.c  */
#line 696 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_fs_context((yyvsp[(2) - (5)].val),(yyvsp[(3) - (5)].val))) return -1;}
    break;

  case 266:
/* Line 1792 of yacc.c  */
#line 707 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_port_context((yyvsp[(3) - (4)].val),(yyvsp[(3) - (4)].val))) return -1;}
    break;

  case 267:
/* Line 1792 of yacc.c  */
#line 709 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_port_context((yyvsp[(3) - (6)].val),(yyvsp[(5) - (6)].val))) return -1;}
    break;

  case 272:
/* Line 1792 of yacc.c  */
#line 718 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_netif_context()) return -1;}
    break;

  case 277:
/* Line 1792 of yacc.c  */
#line 727 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_ipv4_node_context()) return -1;}
    break;

  case 278:
/* Line 1792 of yacc.c  */
#line 729 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_ipv6_node_context()) return -1;}
    break;

  case 283:
/* Line 1792 of yacc.c  */
#line 738 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_fs_use(SECURITY_FS_USE_XATTR)) return -1;}
    break;

  case 284:
/* Line 1792 of yacc.c  */
#line 740 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_fs_use(SECURITY_FS_USE_TASK)) return -1;}
    break;

  case 285:
/* Line 1792 of yacc.c  */
#line 742 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_fs_use(SECURITY_FS_USE_TRANS)) return -1;}
    break;

  case 290:
/* Line 1792 of yacc.c  */
#line 751 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_genfs_context(1)) return -1;}
    break;

  case 291:
/* Line 1792 of yacc.c  */
#line 752 "external/selinux/checkpolicy/policy_parse.y"
    {insert_id("-", 0);}
    break;

  case 292:
/* Line 1792 of yacc.c  */
#line 753 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_genfs_context(1)) return -1;}
    break;

  case 293:
/* Line 1792 of yacc.c  */
#line 755 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_genfs_context(0)) return -1;}
    break;

  case 294:
/* Line 1792 of yacc.c  */
#line 758 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id(yytext,0)) return -1; }
    break;

  case 295:
/* Line 1792 of yacc.c  */
#line 761 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(0)) return -1; }
    break;

  case 296:
/* Line 1792 of yacc.c  */
#line 763 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(0)) return -1; }
    break;

  case 297:
/* Line 1792 of yacc.c  */
#line 765 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id("~", 0)) return -1; }
    break;

  case 298:
/* Line 1792 of yacc.c  */
#line 767 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id("~", 0)) return -1;
			  if (insert_separator(0)) return -1; }
    break;

  case 302:
/* Line 1792 of yacc.c  */
#line 775 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id("-", 0)) return -1; }
    break;

  case 306:
/* Line 1792 of yacc.c  */
#line 780 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id(yytext,0)) return -1; }
    break;

  case 310:
/* Line 1792 of yacc.c  */
#line 788 "external/selinux/checkpolicy/policy_parse.y"
    {if (insert_separator(0)) return -1;}
    break;

  case 311:
/* Line 1792 of yacc.c  */
#line 790 "external/selinux/checkpolicy/policy_parse.y"
    {if (insert_separator(0)) return -1;}
    break;

  case 312:
/* Line 1792 of yacc.c  */
#line 793 "external/selinux/checkpolicy/policy_parse.y"
    {if (insert_separator(0)) return -1;}
    break;

  case 313:
/* Line 1792 of yacc.c  */
#line 795 "external/selinux/checkpolicy/policy_parse.y"
    {if (insert_separator(0)) return -1;}
    break;

  case 318:
/* Line 1792 of yacc.c  */
#line 805 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(0)) return -1; }
    break;

  case 319:
/* Line 1792 of yacc.c  */
#line 807 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(0)) return -1; }
    break;

  case 320:
/* Line 1792 of yacc.c  */
#line 809 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id("*", 0)) return -1; 
			  if (insert_separator(0)) return -1; }
    break;

  case 321:
/* Line 1792 of yacc.c  */
#line 812 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id("~", 0)) return -1;
			  if (insert_separator(0)) return -1; }
    break;

  case 322:
/* Line 1792 of yacc.c  */
#line 815 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id("~", 0)) return -1; 
			  if (insert_separator(0)) return -1; }
    break;

  case 323:
/* Line 1792 of yacc.c  */
#line 817 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id("-", 0)) return -1; }
    break;

  case 324:
/* Line 1792 of yacc.c  */
#line 818 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_separator(0)) return -1; }
    break;

  case 325:
/* Line 1792 of yacc.c  */
#line 821 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id("~", 1)) return -1; }
    break;

  case 326:
/* Line 1792 of yacc.c  */
#line 824 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id("*", 1)) return -1; }
    break;

  case 334:
/* Line 1792 of yacc.c  */
#line 836 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id(yytext, 1)) return -1; }
    break;

  case 341:
/* Line 1792 of yacc.c  */
#line 845 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id("-", 0)) return -1; }
    break;

  case 344:
/* Line 1792 of yacc.c  */
#line 848 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id(yytext,0)) return -1; }
    break;

  case 345:
/* Line 1792 of yacc.c  */
#line 851 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id(yytext,0)) return -1; }
    break;

  case 346:
/* Line 1792 of yacc.c  */
#line 853 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id(yytext,0)) return -1; }
    break;

  case 347:
/* Line 1792 of yacc.c  */
#line 856 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id(yytext,0)) return -1; }
    break;

  case 348:
/* Line 1792 of yacc.c  */
#line 858 "external/selinux/checkpolicy/policy_parse.y"
    { yytext[strlen(yytext) - 1] = '\0'; if (insert_id(yytext + 1,0)) return -1; }
    break;

  case 349:
/* Line 1792 of yacc.c  */
#line 861 "external/selinux/checkpolicy/policy_parse.y"
    { yytext[strlen(yytext) - 1] = '\0'; if (insert_id(yytext + 1,0)) return -1; }
    break;

  case 350:
/* Line 1792 of yacc.c  */
#line 864 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.val) = strtoul(yytext,NULL,0); }
    break;

  case 351:
/* Line 1792 of yacc.c  */
#line 867 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.val64) = strtoull(yytext,NULL,0); }
    break;

  case 352:
/* Line 1792 of yacc.c  */
#line 870 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id(yytext,0)) return -1; }
    break;

  case 353:
/* Line 1792 of yacc.c  */
#line 873 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_polcap()) return -1;}
    break;

  case 354:
/* Line 1792 of yacc.c  */
#line 876 "external/selinux/checkpolicy/policy_parse.y"
    {if (define_permissive()) return -1;}
    break;

  case 355:
/* Line 1792 of yacc.c  */
#line 881 "external/selinux/checkpolicy/policy_parse.y"
    { if (end_avrule_block(pass) == -1) return -1;
                          if (policydb_index_others(NULL, policydbp, 0)) return -1;
                        }
    break;

  case 356:
/* Line 1792 of yacc.c  */
#line 886 "external/selinux/checkpolicy/policy_parse.y"
    { if (define_policy(pass, 1) == -1) return -1; }
    break;

  case 357:
/* Line 1792 of yacc.c  */
#line 889 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id(yytext,0)) return -1; }
    break;

  case 358:
/* Line 1792 of yacc.c  */
#line 891 "external/selinux/checkpolicy/policy_parse.y"
    { if (insert_id(yytext,0)) return -1; }
    break;

  case 374:
/* Line 1792 of yacc.c  */
#line 915 "external/selinux/checkpolicy/policy_parse.y"
    { if (require_class(pass)) return -1; }
    break;

  case 375:
/* Line 1792 of yacc.c  */
#line 917 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.require_func) = require_role; }
    break;

  case 376:
/* Line 1792 of yacc.c  */
#line 918 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.require_func) = require_type; }
    break;

  case 377:
/* Line 1792 of yacc.c  */
#line 919 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.require_func) = require_attribute; }
    break;

  case 378:
/* Line 1792 of yacc.c  */
#line 920 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.require_func) = require_attribute_role; }
    break;

  case 379:
/* Line 1792 of yacc.c  */
#line 921 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.require_func) = require_user; }
    break;

  case 380:
/* Line 1792 of yacc.c  */
#line 922 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.require_func) = require_bool; }
    break;

  case 381:
/* Line 1792 of yacc.c  */
#line 923 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.require_func) = require_tunable; }
    break;

  case 382:
/* Line 1792 of yacc.c  */
#line 924 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.require_func) = require_sens; }
    break;

  case 383:
/* Line 1792 of yacc.c  */
#line 925 "external/selinux/checkpolicy/policy_parse.y"
    { (yyval.require_func) = require_cat; }
    break;

  case 384:
/* Line 1792 of yacc.c  */
#line 928 "external/selinux/checkpolicy/policy_parse.y"
    { if ((yyvsp[(0) - (1)].require_func) (pass)) return -1; }
    break;

  case 385:
/* Line 1792 of yacc.c  */
#line 930 "external/selinux/checkpolicy/policy_parse.y"
    { if ((yyvsp[(0) - (3)].require_func) (pass)) return -1; }
    break;

  case 386:
/* Line 1792 of yacc.c  */
#line 933 "external/selinux/checkpolicy/policy_parse.y"
    { if (end_avrule_block(pass) == -1) return -1; }
    break;

  case 387:
/* Line 1792 of yacc.c  */
#line 935 "external/selinux/checkpolicy/policy_parse.y"
    { if (end_optional(pass) == -1) return -1; }
    break;

  case 388:
/* Line 1792 of yacc.c  */
#line 938 "external/selinux/checkpolicy/policy_parse.y"
    { if (end_avrule_block(pass) == -1) return -1; }
    break;

  case 390:
/* Line 1792 of yacc.c  */
#line 942 "external/selinux/checkpolicy/policy_parse.y"
    { if (begin_optional(pass) == -1) return -1; }
    break;

  case 391:
/* Line 1792 of yacc.c  */
#line 945 "external/selinux/checkpolicy/policy_parse.y"
    { if (begin_optional_else(pass) == -1) return -1; }
    break;


/* Line 1792 of yacc.c  */
#line 3718 "out/host/linux-x86/obj/EXECUTABLES/checkpolicy_intermediates/policy_parse.c"
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


