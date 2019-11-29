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
#line 1 "gramatica.y" /* yacc.c:339  */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "TS.h"

#define YYDEBUG 1
int errores;
int num_espacios;

int yylex();
int yyerror(const char *s);


/*
Verifica si el identificador que se pasa como
parametro ya esta en la tabla de simbols.
Si ya existe, manda error e incrementa el número de errores
si no existe entonces lo inserta en la tabla de simbolos.
Se usa en las reglas de declaraciones
entero a; <-  tendría que insertarla en la tabla de simbolos
entero a; <-- tendría que marcar que ya está
*/
void instalar(char *nombre_simbolo, char *tipo_dato){
	simbolo *s;
	s = obtener_simbolo(nombre_simbolo);
	if( s == 0 )
		s = inserta_simbolo(nombre_simbolo, tipo_dato);
	else{
		errores++;
		printf("(Variable duplicada): %s ya está declarada \n",nombre_simbolo);
	}
}

/*
Si la variable no está declarada anteriormente
entonces no se puede usar y manda un mensaje
Se utiliza en cualquier expresion o funcion
que utilice una variable
leer(edad); <- Si no existe en la tabla manda error
								porque se debe declarar antes
						<- Si ya existe no hace nada porque ya
								está declarada
*/
void verifica_contexto(char *nombre_simbolo){
	if(obtener_simbolo(nombre_simbolo) == 0){
		printf("%s es un identificador no declarado \n",nombre_simbolo);
		errores++;
	}
}


/*
Verifica si dos simbolos tienen el mismo tipo
*/
void verifica_tipos(char *nombre_simbolo1, char *nombre_simbolo2){
	simbolo *s1, *s2;
	s1 = obtener_simbolo(nombre_simbolo1);
	s2 = obtener_simbolo(nombre_simbolo2);
	printf("\nComparando %s y %s \n",s1->tipo_dato,s2->tipo_dato);
	if( strcmp(s1->tipo_dato,s2->tipo_dato) != 0){
		printf("Las dos variables deben tener el mismo tipo de dato ");
		errores++;
	}
}


void asignar_inicializado(char *nombre_simbolo, int valor){
		set_inicializado(nombre_simbolo, valor);
}

void asignar_inicializadoCaracter (char *nombre_simbolo, char *valor){
	set_inicializadoCaracter(nombre_simbolo,valor);
}

void asignar_inicializadoFlotante (char *nombre_simbolo, float valor){
	set_inicializadoFlotante(nombre_simbolo,valor);
}

void verifica_inicializacion(char *nombre_simbolo){
	simbolo *s;
	s = obtener_simbolo(nombre_simbolo);
	if( s->inicializado == 0 || s->inicializadoValorCaracter == " " || s->inicializadoValorFlotante == 0.0){
		printf("\nLa variable %s no esta inicializada\n",nombre_simbolo);
		errores++;
	}
}


void imprime_indentacion(){
	int i = 0;
	printf("\n");
	for(i=0; i<num_espacios; i++)
		printf(" ");
}


void imprime_instruccion_leer(char *nombre_simbolo){
	simbolo *s;
	char *tipo_dato;
	s = obtener_simbolo(nombre_simbolo);

	if( strcmp(s->tipo_dato,"entero") == 0 )
		printf("scanf(\"%%d\",&%s);",nombre_simbolo);
	if( strcmp(s->tipo_dato,"flotante") == 0 )
		printf("scanf(\"%%f\",&%s);",nombre_simbolo);
	if( strcmp(s->tipo_dato,"caracter") == 0 )
		printf("scanf(\"%%c\",&%s);",nombre_simbolo);
}





#line 183 "gramatica.tab.c" /* yacc.c:339  */

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
   by #include "gramatica.tab.h".  */
#ifndef YY_YY_GRAMATICA_TAB_H_INCLUDED
# define YY_YY_GRAMATICA_TAB_H_INCLUDED
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
    ENTERO = 258,
    FLOTANTE = 259,
    NUMFLOTANTE = 260,
    CADENA = 261,
    CARACTER = 262,
    IDENTIFICADOR = 263,
    NUMERO = 264,
    LETRA = 265,
    ABRIR_BLOQUE = 266,
    CERRAR_BLOQUE = 267,
    COMILLA_SIMPLE = 268,
    PRINCIPAL = 269,
    LEER = 270,
    IMPRIMIR = 271,
    MIENTRAS = 272,
    PARA = 273,
    HAZ = 274,
    SI = 275,
    ENTONCES = 276,
    OTRO = 277,
    OR = 278,
    ASIGNACION = 279,
    DOBLE_MAS = 280,
    DOBLE_MENOS = 281,
    MAS = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 118 "gramatica.y" /* yacc.c:355  */

	char 	*cadena;
	double 	flotante;
	char 	*caracter;
	int 	entero;

#line 258 "gramatica.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMATICA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 275 "gramatica.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

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
      29,    30,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      28,     2,    33,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   145,   145,   145,   153,   154,   157,   158,   159,   160,
     161,   163,   164,   165,   166,   168,   169,   170,   171,   174,
     175,   176,   177,   178,   181,   182,   183,   184,   185,   188,
     189,   190,   191,   192,   196,   197,   200,   201,   202,   203,
     204,   204,   207,   213,   214,   215,   216,   217,   218,   219,
     223,   224,   227,   228,   229,   230,   231
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENTERO", "FLOTANTE", "NUMFLOTANTE",
  "CADENA", "CARACTER", "IDENTIFICADOR", "NUMERO", "LETRA", "ABRIR_BLOQUE",
  "CERRAR_BLOQUE", "COMILLA_SIMPLE", "PRINCIPAL", "LEER", "IMPRIMIR",
  "MIENTRAS", "PARA", "HAZ", "SI", "ENTONCES", "OTRO", "OR", "ASIGNACION",
  "DOBLE_MAS", "DOBLE_MENOS", "MAS", "'<'", "'('", "')'", "';'", "','",
  "'>'", "$accept", "programa", "$@1", "declaraciones", "declaracion",
  "declaracionMultiple", "declaracionMultipleCaracter",
  "declaracionMultipleFotante", "instrucciones", "instruccion", "$@2",
  "expresion", "expresion_incremento", "expresion_aritmetica", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    60,    40,
      41,    59,    44,    62
};
# endif

#define YYPACT_NINF -86

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-86)))

#define YYTABLE_NINF -55

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,     4,    45,     6,   -86,    44,   -86,   -86,     3,    38,
      49,    51,    39,    35,   -16,   -15,    24,   -86,    42,   -86,
      61,    63,    64,    69,    68,    58,    72,    83,    92,    88,
      94,    13,    95,    98,    15,    97,   -86,    74,    36,   -86,
      75,    59,   -86,    99,    62,   -86,   -86,    81,   -86,    20,
      84,    80,    82,    70,    86,    48,   -86,    84,    90,    72,
     106,    72,    92,   111,    92,   104,   105,    94,   -86,     5,
      20,   -86,   -86,   -86,   -86,    15,    15,   108,    15,   112,
     -86,    91,   -86,   -86,    93,   -86,    96,   110,   -86,   -86,
     -86,    89,    89,   -86,    56,   100,    72,    92,    94,   113,
     -86,    15,   -86,   -86,   -86,   101,    46,    54,    94,   -86,
     116,   -86,     1,   102,   118,   -86,    57,   -86
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     2,     4,    34,     0,
       0,     0,     0,     0,     7,    15,    11,     5,     0,     3,
       0,     0,     0,     0,     0,     0,    19,     0,    29,     0,
      24,     0,     0,     0,     0,     0,    35,     8,    20,     9,
      16,    30,    17,     0,    25,    13,    55,    38,    53,     0,
      37,     0,     0,    47,    46,     0,    48,    49,     0,    19,
       0,    19,    29,     0,    29,     0,     0,    24,    54,     0,
       0,    36,    39,    50,    51,     0,     0,     0,     0,     0,
      10,    21,    22,    18,    31,    32,    12,     0,    27,    56,
      52,    45,    43,    40,    44,     0,    19,    29,    24,     0,
      34,     0,    23,    33,    14,    26,     0,     0,    24,    41,
       0,    28,     0,     0,     0,    34,     0,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -86,   -86,   -86,   -86,   -86,   -57,   -67,   -59,   -85,   -86,
     -86,   -64,    17,   -30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     8,    12,    39,    45,    42,    13,    24,
     100,    55,    56,    57
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      88,    50,    80,    83,    82,    85,     9,    10,    25,    27,
      11,    91,    92,     1,    94,   106,    26,    28,    46,    69,
      46,    47,    48,    53,    54,    46,    73,    74,    68,    48,
     116,   104,    70,     3,    -6,    89,     5,   107,   103,   102,
      90,   111,    49,    18,    49,     4,    14,    19,    29,    49,
      20,    21,    22,    23,    18,     6,    30,    15,   109,    16,
      60,    20,    21,    22,    23,    18,    31,    37,    61,   117,
      17,    75,    20,    21,    22,    23,    76,    75,    77,    75,
      38,    78,    76,    63,    76,   110,    66,    78,    40,    78,
      32,    64,    33,    34,    67,    73,    74,   -54,    35,    36,
      41,    43,    44,    51,    52,    58,    59,    62,   -54,    65,
      71,    70,    72,   -53,    79,    81,    84,    86,    87,    93,
      99,    95,    78,    96,   112,    97,   105,   113,    98,   115,
       0,   101,   114,   108
};

static const yytype_int8 yycheck[] =
{
      67,    31,    59,    62,    61,    64,     3,     4,    24,    24,
       7,    75,    76,    14,    78,   100,    32,    32,     5,    49,
       5,     8,     9,     8,     9,     5,    25,    26,     8,     9,
     115,    98,    27,    29,    31,    30,    30,   101,    97,    96,
      70,   108,    29,     8,    29,     0,     8,    12,    24,    29,
      15,    16,    17,    18,     8,    11,    32,     8,    12,     8,
      24,    15,    16,    17,    18,     8,    24,     9,    32,    12,
      31,    23,    15,    16,    17,    18,    28,    23,    30,    23,
       8,    33,    28,    24,    28,    31,    24,    33,     5,    33,
      29,    32,    29,    29,    32,    25,    26,    27,    29,    31,
       8,    13,     8,     8,     6,     8,    32,    32,    27,    10,
      30,    27,    30,    27,    24,     9,     5,    13,    13,    11,
      10,     9,    33,    32,     8,    32,    13,   110,    32,    11,
      -1,    31,    30,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    35,    29,     0,    30,    11,    36,    37,     3,
       4,     7,    38,    42,     8,     8,     8,    31,     8,    12,
      15,    16,    17,    18,    43,    24,    32,    24,    32,    24,
      32,    24,    29,    29,    29,    29,    31,     9,     8,    39,
       5,     8,    41,    13,     8,    40,     5,     8,     9,    29,
      47,     8,     6,     8,     9,    45,    46,    47,     8,    32,
      24,    32,    32,    24,    32,    10,    24,    32,     8,    47,
      27,    30,    30,    25,    26,    23,    28,    30,    33,    24,
      39,     9,    39,    41,     5,    41,    13,    13,    40,    30,
      47,    45,    45,    11,    45,     9,    32,    32,    32,    10,
      44,    31,    39,    41,    40,    13,    42,    45,    32,    12,
      31,    40,     8,    46,    30,    11,    42,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    36,    35,    37,    37,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    39,
      39,    39,    39,    39,    40,    40,    40,    40,    40,    41,
      41,    41,    41,    41,    42,    42,    43,    43,    43,    43,
      44,    43,    43,    45,    45,    45,    45,    45,    45,    45,
      46,    46,    47,    47,    47,    47,    47
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     8,     0,     3,     0,     2,     4,     4,
       6,     2,     6,     4,     8,     2,     4,     4,     6,     0,
       1,     3,     3,     5,     0,     1,     5,     3,     7,     0,
       1,     3,     3,     5,     0,     3,     4,     3,     3,     4,
       0,     8,    13,     3,     3,     3,     1,     1,     1,     1,
       2,     2,     3,     1,     1,     1,     3
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
#line 145 "gramatica.y" /* yacc.c:1646  */
    { num_espacios = 0; printf("int main(){");  num_espacios += 2;  }
#line 1429 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 148 "gramatica.y" /* yacc.c:1646  */
    { num_espacios -= 2; printf("\n}\n"); }
#line 1435 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 158 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[0].cadena),"entero");    asignar_inicializado((yyvsp[0].cadena),0);   imprime_indentacion(); printf("int %s;",(yyvsp[0].cadena));   }
#line 1441 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 159 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"entero");    asignar_inicializado((yyvsp[-2].cadena),(yyvsp[0].entero));  imprime_indentacion(); printf("int %s = %d;",(yyvsp[-2].cadena),(yyvsp[0].entero));   }
#line 1447 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 160 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"entero");    asignar_inicializado((yyvsp[-2].cadena),0);   printf("%s;",(yyvsp[-2].cadena));   }
#line 1453 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 161 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-4].cadena),"entero");    asignar_inicializado((yyvsp[-4].cadena),(yyvsp[-2].entero));  printf("%s = %d;",(yyvsp[-4].cadena),(yyvsp[-2].entero));   }
#line 1459 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 163 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[0].cadena),"caracter");  asignar_inicializadoCaracter((yyvsp[0].cadena)," ");  imprime_indentacion(); printf("char %s ;",(yyvsp[0].cadena));      }
#line 1465 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 164 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-4].cadena),"caracter");      }
#line 1471 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 165 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"caracter");  asignar_inicializadoCaracter((yyvsp[-2].cadena)," ");  printf("%s;",(yyvsp[-2].cadena));   }
#line 1477 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 166 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-6].cadena),"caracter");  asignar_inicializadoCaracter((yyvsp[-6].cadena),(yyvsp[-3].caracter));   imprime_indentacion(); printf("char %s = ;",(yyvsp[-6].cadena));   }
#line 1483 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 168 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[0].cadena),"flotante");    asignar_inicializadoFlotante((yyvsp[0].cadena),0.0); imprime_indentacion(); printf("float %s;",(yyvsp[0].cadena));   }
#line 1489 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 169 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"flotante");    asignar_inicializadoFlotante((yyvsp[-2].cadena),(yyvsp[0].flotante));  imprime_indentacion(); printf("float %s = %f;",(yyvsp[-2].cadena),(yyvsp[0].flotante));   }
#line 1495 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 170 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"flotante");    asignar_inicializadoFlotante((yyvsp[-2].cadena),0.0); 					   printf("%s;",(yyvsp[-2].cadena));   }
#line 1501 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 171 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-4].cadena),"flotante");    asignar_inicializadoFlotante((yyvsp[-4].cadena),(yyvsp[-2].flotante));  					   printf("%s = %f;",(yyvsp[-4].cadena),(yyvsp[-2].flotante));   }
#line 1507 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 175 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[0].cadena),"entero");    asignar_inicializado((yyvsp[0].cadena),0); imprime_indentacion(); printf("%s,",(yyvsp[0].cadena));   }
#line 1513 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 176 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"entero");    asignar_inicializado((yyvsp[-2].cadena),(yyvsp[0].entero)); imprime_indentacion(); printf("int %s = %d,",(yyvsp[-2].cadena),(yyvsp[0].entero));   }
#line 1519 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 177 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"entero");    asignar_inicializado((yyvsp[-2].cadena),0); printf("%s,",(yyvsp[-2].cadena));   }
#line 1525 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 178 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-4].cadena),"entero");    asignar_inicializado((yyvsp[-4].cadena),(yyvsp[-2].entero)); imprime_indentacion(); printf("int %s = %d,",(yyvsp[-4].cadena),(yyvsp[-2].entero));   }
#line 1531 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 182 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[0].cadena),"caracter");    asignar_inicializadoCaracter((yyvsp[0].cadena)," "); imprime_indentacion(); printf("%s,",(yyvsp[0].cadena));   }
#line 1537 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 183 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-4].cadena),"caracter");    asignar_inicializadoCaracter((yyvsp[-4].cadena),(yyvsp[-1].caracter)); imprime_indentacion(); printf("char %s = %s,",(yyvsp[-4].cadena),(yyvsp[-1].caracter));   }
#line 1543 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 184 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"caracter");    asignar_inicializadoCaracter((yyvsp[-2].cadena)," "); printf("%s,",(yyvsp[-2].cadena));   }
#line 1549 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 185 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-6].cadena),"caracter");    asignar_inicializadoCaracter((yyvsp[-6].cadena),(yyvsp[-3].caracter)); imprime_indentacion(); printf("char %s = %s,",(yyvsp[-6].cadena),(yyvsp[-3].caracter));   }
#line 1555 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 189 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[0].cadena),"entero");    asignar_inicializadoFlotante((yyvsp[0].cadena),0.0); 	imprime_indentacion(); printf("%s,",(yyvsp[0].cadena));   }
#line 1561 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 190 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"entero");    asignar_inicializadoFlotante((yyvsp[-2].cadena),(yyvsp[0].flotante)); 	imprime_indentacion(); printf("int %s = %f,",(yyvsp[-2].cadena),(yyvsp[0].flotante));   }
#line 1567 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 191 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"entero");    asignar_inicializadoFlotante((yyvsp[-2].cadena),0.0); 						   printf("%s,",(yyvsp[-2].cadena));   }
#line 1573 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 192 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-4].cadena),"entero");    asignar_inicializadoFlotante((yyvsp[-4].cadena),(yyvsp[-2].flotante));	imprime_indentacion(); printf("int %s = %f,",(yyvsp[-4].cadena),(yyvsp[-2].flotante));   }
#line 1579 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 200 "gramatica.y" /* yacc.c:1646  */
    { verifica_contexto((yyvsp[-1].cadena));  verifica_inicializacion((yyvsp[-1].cadena)); imprime_indentacion(); imprime_instruccion_leer((yyvsp[-1].cadena));}
#line 1585 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 201 "gramatica.y" /* yacc.c:1646  */
    { asignar_inicializado((yyvsp[-2].cadena),1); }
#line 1591 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 202 "gramatica.y" /* yacc.c:1646  */
    { verifica_tipos((yyvsp[-2].cadena),(yyvsp[0].cadena)); asignar_inicializado((yyvsp[-2].cadena),1); }
#line 1597 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 204 "gramatica.y" /* yacc.c:1646  */
    { imprime_indentacion(); printf("while(){"); num_espacios += 2;  }
#line 1603 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 206 "gramatica.y" /* yacc.c:1646  */
    { num_espacios -= 2; imprime_indentacion(); printf("}");   }
#line 1609 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 217 "gramatica.y" /* yacc.c:1646  */
    { verifica_contexto((yyvsp[0].cadena));  }
#line 1615 "gramatica.tab.c" /* yacc.c:1646  */
    break;


#line 1619 "gramatica.tab.c" /* yacc.c:1646  */
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
#line 234 "gramatica.y" /* yacc.c:1906  */


#include "lex.yy.c"

int main(){
    yyparse();
}

int yyerror(const char *s){
  fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,s);
}
