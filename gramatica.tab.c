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
	#include "arbol.h"

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
			s = inserta_simbolo(nombre_simbolo,tipo_dato);
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
	Esta funcion recibe dos nombres de simbolos, los busca en la tabla
	de símbolos y luego compara sus tipos de datos. Si son diferentes
	marca error e incrementa el número de errores. Si son iguales
	no hace nada.
	*/
	void compara_variables(char *nombre_simbolo1, char *nombre_simbolo2){
		simbolo *s1, *s2;
		s1 = obtener_simbolo(nombre_simbolo1);
		s2 = obtener_simbolo(nombre_simbolo2);
		if(  strcmp(s1->tipo_dato,s2->tipo_dato) != 0 ){
		printf("\nNo se puede asignar  %s a un %s\n",s2->tipo_dato,s1->tipo_dato);
		return;
		}
	}




	void imprime_instruccion_leer(char *nombre_simbolo){
			simbolo *s;
			s = obtener_simbolo(nombre_simbolo);
			printf("scanf(\"%%d\",&%s);\n",s->nombre);
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
		if( get_inicializado(nombre_simbolo)){
			printf("\nLa variable %s no esta inicializada\n",nombre_simbolo);
			errores++;
		}
	}

	void imprime_indentacion(){
		int i=0;
		for(i=0; i<=num_espacios; i++)
		{
			printf(" ");
		};
	}



#line 197 "gramatica.tab.c" /* yacc.c:339  */

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
    CADENA = 260,
    DATO_CARACTER = 261,
    CARACTER = 262,
    IDENTIFICADOR = 263,
    NUMERO = 264,
    NUMFLOTANTE = 265,
    LETRA = 266,
    ABRIR_BLOQUE = 267,
    CERRAR_BLOQUE = 268,
    COMILLA_SIMPLE = 269,
    PRINCIPAL = 270,
    LEER = 271,
    IMPRIMIR = 272,
    MIENTRAS = 273,
    PARA = 274,
    OR = 275,
    ASIGNACION = 276,
    DOBLE_MAS = 277,
    DOBLE_MENOS = 278,
    MAS = 279,
    MENOS = 280,
    POR = 281,
    ENTRE = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 132 "gramatica.y" /* yacc.c:355  */

	struct ast *arbol;
	char *cadena;
	char *caracter;
	double 	flotante;
	int entero;

#line 273 "gramatica.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMATICA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 290 "gramatica.tab.c" /* yacc.c:358  */

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


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif


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
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

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
      28,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
static const yytype_uint16 yyrline[] =
{
       0,   167,   167,   167,   176,   177,   182,   183,   184,   185,
     189,   190,   191,   192,   193,   197,   198,   199,   200,   201,
     205,   206,   207,   208,   209,   212,   213,   214,   215,   216,
     218,   219,   220,   221,   222,   225,   226,   227,   228,   229,
     232,   233,   236,   237,   238,   239,   240,   241,   241,   250,
     251,   252,   256,   257,   258,   261,   262,   263,   264
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENTERO", "FLOTANTE", "CADENA",
  "DATO_CARACTER", "CARACTER", "IDENTIFICADOR", "NUMERO", "NUMFLOTANTE",
  "LETRA", "ABRIR_BLOQUE", "CERRAR_BLOQUE", "COMILLA_SIMPLE", "PRINCIPAL",
  "LEER", "IMPRIMIR", "MIENTRAS", "PARA", "OR", "ASIGNACION", "DOBLE_MAS",
  "DOBLE_MENOS", "MAS", "MENOS", "POR", "ENTRE", "'<'", "'('", "')'",
  "';'", "','", "$accept", "programa", "$@1", "declaraciones",
  "declaracion", "identificadores_entero", "identificadores_caracter",
  "identificadores_flotante", "declaracionMultiple",
  "declaracionMultipleCaracter", "declaracionMultipleFotante",
  "instrucciones", "instruccion", "$@2", "exp_arit", "factor", "termino", YY_NULLPTR
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
      41,    59,    44
};
# endif

#define YYPACT_NINF -71

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-71)))

#define YYTABLE_NINF -7

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       6,     2,    46,    17,   -71,    38,   -71,   -71,     7,    43,
      47,    55,    39,    44,   -19,   -71,   -17,   -71,   -15,   -71,
     -71,    53,   -71,    50,    52,    54,    45,    66,    69,    70,
      74,    71,    76,    20,    78,    82,    10,   -71,    56,    -9,
     -71,   -71,    57,    -5,   -71,   -71,    79,     1,   -71,   -71,
     -71,   -71,   -71,    61,    62,   -71,   -71,   -71,    10,    41,
     -18,   -71,    85,    86,    69,    88,    84,    74,    83,    87,
      76,   -71,   -71,    48,    10,    10,    90,    10,    10,     3,
     -71,    67,   -71,    13,   -71,    68,   -71,    72,    92,   -71,
     -71,   -18,   -18,   -71,   -71,   -71,    89,    85,    85,    95,
      88,    88,    98,    93,   -71,    77,   -71,   -71,    80,   -71,
     -71,    21,   -71,    81,    51,    85,    88,    94,    98,    98,
     -71,   -71,   -71,    99,   -71,   -71,    97,    91,    98,   -71
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     2,     4,    40,     0,
       0,     0,     0,     0,    10,     7,    20,     9,    15,     8,
       5,     0,     3,     0,     0,     0,     0,     0,    25,     0,
      35,     0,    30,     0,     0,     0,     0,    41,    12,    10,
      11,    13,    22,    20,    21,    23,     0,    15,    16,    18,
      43,    44,    45,     0,     0,    57,    55,    56,     0,     0,
      49,    52,    25,     0,    25,    35,     0,    35,     0,     0,
      30,    42,    46,     0,     0,     0,     0,     0,     0,    26,
      14,    12,    13,    36,    24,    22,    23,    17,     0,    18,
      58,    50,    51,    47,    53,    54,     0,    25,    25,     0,
      35,    35,    30,     0,    40,    27,    28,    14,    37,    38,
      24,    31,    19,    17,     0,    25,    35,     0,    30,    30,
      48,    29,    39,     0,    33,    19,     0,    32,    30,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   -71,   -71,   -71,   105,   104,   106,   -61,   -70,
     -60,    14,   -71,   -71,    59,   -49,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     8,    12,    40,    48,    44,    41,    49,
      45,    13,    26,   104,    59,    60,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,    80,    27,    82,    29,    84,    31,    86,    77,    78,
       9,    10,    63,    28,    11,    30,    66,    32,    55,    56,
      57,     1,    69,    64,    96,    91,    92,    67,    50,    51,
      52,     3,   112,    70,    99,    97,   106,   107,    -6,    58,
     109,   110,   117,    94,    95,   100,     4,     5,   124,   125,
       6,    14,    21,   118,   121,    16,   122,    22,   129,    21,
      23,    24,    25,    18,   120,    74,    75,    23,    24,    25,
      20,    76,    74,    75,    33,    38,    37,    39,    90,    34,
      42,    35,    43,    36,    47,    46,    53,    54,    62,    65,
      68,    71,    72,    79,    85,    81,    83,    87,   105,    98,
     101,    88,    93,   103,   102,   108,   111,   113,   123,   115,
     126,   127,   116,   119,    15,    19,    17,    73,   114,     0,
       0,     0,     0,   128
};

static const yytype_int16 yycheck[] =
{
      70,    62,    21,    64,    21,    65,    21,    67,    26,    27,
       3,     4,    21,    32,     7,    32,    21,    32,     8,     9,
      10,    15,    21,    32,    21,    74,    75,    32,     8,     9,
      10,    29,   102,    32,    21,    32,    97,    98,    31,    29,
     100,   101,    21,    77,    78,    32,     0,    30,   118,   119,
      12,     8,     8,    32,   115,     8,   116,    13,   128,     8,
      16,    17,    18,     8,    13,    24,    25,    16,    17,    18,
      31,    30,    24,    25,    21,     9,    31,     8,    30,    29,
      10,    29,     8,    29,     8,    14,     8,     5,    32,    32,
      11,    30,    30,     8,    10,     9,     8,    14,     9,    32,
      32,    14,    12,    11,    32,    10,     8,    14,    14,    32,
      11,    14,    32,    32,     9,    11,    10,    58,   104,    -1,
      -1,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    34,    29,     0,    30,    12,    35,    36,     3,
       4,     7,    37,    44,     8,    38,     8,    40,     8,    39,
      31,     8,    13,    16,    17,    18,    45,    21,    32,    21,
      32,    21,    32,    21,    29,    29,    29,    31,     9,     8,
      38,    41,    10,     8,    40,    43,    14,     8,    39,    42,
       8,     9,    10,     8,     5,     8,     9,    10,    29,    47,
      48,    49,    32,    21,    32,    32,    21,    32,    11,    21,
      32,    30,    30,    47,    24,    25,    30,    26,    27,     8,
      41,     9,    41,     8,    43,    10,    43,    14,    14,    42,
      30,    48,    48,    12,    49,    49,    21,    32,    32,    21,
      32,    32,    32,    11,    46,     9,    41,    41,    10,    43,
      43,     8,    42,    14,    44,    32,    32,    21,    32,    32,
      13,    41,    43,    14,    42,    42,    11,    14,    32,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    35,    34,    36,    36,    37,    37,    37,    37,
      38,    38,    38,    38,    38,    39,    39,    39,    39,    39,
      40,    40,    40,    40,    40,    41,    41,    41,    41,    41,
      42,    42,    42,    42,    42,    43,    43,    43,    43,    43,
      44,    44,    45,    45,    45,    45,    45,    46,    45,    47,
      47,    47,    48,    48,    48,    49,    49,    49,    49
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     8,     0,     3,     0,     2,     2,     2,
       1,     3,     3,     3,     5,     1,     3,     5,     3,     7,
       1,     3,     3,     3,     5,     0,     1,     3,     3,     5,
       0,     1,     5,     3,     7,     0,     1,     3,     3,     5,
       0,     3,     4,     3,     3,     3,     4,     0,     8,     1,
       3,     3,     1,     3,     3,     1,     1,     1,     3
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
      YY_LAC_DISCARD ("YYBACKUP");                              \
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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


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
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
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
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
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

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
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

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");

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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 2:
#line 167 "gramatica.y" /* yacc.c:1646  */
    { num_espacios = 0; printf("int main(){\n");  num_espacios += 2;	  }
#line 1679 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 170 "gramatica.y" /* yacc.c:1646  */
    { printf("}\n\n");  num_espacios -= 2;		}
#line 1685 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 189 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[0].cadena),"entero"); 	asignar_inicializado((yyvsp[0].cadena),0);		imprime_indentacion();	printf("int %s;\n",(yyvsp[0].cadena));  }
#line 1691 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 190 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"entero"); 	asignar_inicializado((yyvsp[-2].cadena),0);		imprime_indentacion(); 	printf("int %s;\n",(yyvsp[-2].cadena));  }
#line 1697 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 191 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"entero");   	asignar_inicializado((yyvsp[-2].cadena),(yyvsp[0].entero));	imprime_indentacion(); 	printf("int %s = %d;\n",(yyvsp[-2].cadena),(yyvsp[0].entero));   }
#line 1703 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 192 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"entero");    asignar_inicializado((yyvsp[-2].cadena),0);   							printf("%s;",(yyvsp[-2].cadena));   }
#line 1709 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 193 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-4].cadena),"entero");    asignar_inicializado((yyvsp[-4].cadena),(yyvsp[-2].entero));  							printf("%s = %d;",(yyvsp[-4].cadena),(yyvsp[-2].entero));   }
#line 1715 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 197 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[0].cadena),"caracter"); asignar_inicializadoCaracter((yyvsp[0].cadena)," ");	int i=0;  	imprime_indentacion();  printf("int %s;\n",(yyvsp[0].cadena));  }
#line 1721 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 198 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"caracter"); asignar_inicializadoCaracter((yyvsp[-2].cadena)," ");	int i=0;  	imprime_indentacion();  printf("int %s;\n",(yyvsp[-2].cadena));  }
#line 1727 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 199 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-4].cadena),"caracter"); asignar_inicializadoCaracter((yyvsp[-4].cadena),(yyvsp[-1].caracter));					imprime_indentacion(); 	printf("char %s = %s;",(yyvsp[-4].cadena),(yyvsp[-1].caracter)); }
#line 1733 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 200 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"caracter"); asignar_inicializadoCaracter((yyvsp[-2].cadena)," ");  										printf("%s;",(yyvsp[-2].cadena));   }
#line 1739 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 201 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-6].cadena),"caracter"); asignar_inicializadoCaracter((yyvsp[-6].cadena),(yyvsp[-3].caracter));   				imprime_indentacion();	printf("char %s = ;",(yyvsp[-6].cadena));   }
#line 1745 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 205 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[0].cadena),"flotante"); int i=0; asignar_inicializadoFlotante((yyvsp[0].cadena),0.0); imprime_indentacion();  	printf("float %s;\n",(yyvsp[0].cadena));  }
#line 1751 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 206 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"flotante"); int i=0; asignar_inicializadoFlotante((yyvsp[-2].cadena),0.0); imprime_indentacion();  	printf("float %s;\n",(yyvsp[-2].cadena));  }
#line 1757 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 207 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"flotante");			asignar_inicializadoFlotante((yyvsp[-2].cadena),(yyvsp[0].flotante));  imprime_indentacion(); 	printf("float %s = %f;",(yyvsp[-2].cadena),(yyvsp[0].flotante));   }
#line 1763 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 208 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"flotante");    		asignar_inicializadoFlotante((yyvsp[-2].cadena),0.0); 					   		printf("%s;",(yyvsp[-2].cadena));   }
#line 1769 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 209 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-4].cadena),"flotante");    		asignar_inicializadoFlotante((yyvsp[-4].cadena),(yyvsp[-2].flotante));  					   		printf("%s = %f;",(yyvsp[-4].cadena),(yyvsp[-2].flotante));   }
#line 1775 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 213 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[0].cadena),"entero");    asignar_inicializado((yyvsp[0].cadena),0); imprime_indentacion(); printf("%s,",(yyvsp[0].cadena));   }
#line 1781 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 214 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"entero");    asignar_inicializado((yyvsp[-2].cadena),(yyvsp[0].entero)); imprime_indentacion(); printf("int %s = %d,",(yyvsp[-2].cadena),(yyvsp[0].entero));   }
#line 1787 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 215 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"entero");    asignar_inicializado((yyvsp[-2].cadena),0); printf("%s,",(yyvsp[-2].cadena));   }
#line 1793 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 216 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-4].cadena),"entero");    asignar_inicializado((yyvsp[-4].cadena),(yyvsp[-2].entero)); imprime_indentacion(); printf("int %s = %d,",(yyvsp[-4].cadena),(yyvsp[-2].entero));   }
#line 1799 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 219 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[0].cadena),"caracter");    asignar_inicializadoCaracter((yyvsp[0].cadena)," "); imprime_indentacion(); printf("%s,",(yyvsp[0].cadena));   }
#line 1805 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 220 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-4].cadena),"caracter");    asignar_inicializadoCaracter((yyvsp[-4].cadena),(yyvsp[-1].caracter)); imprime_indentacion(); printf("char %s = %s,",(yyvsp[-4].cadena),(yyvsp[-1].caracter));   }
#line 1811 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 221 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"caracter");    asignar_inicializadoCaracter((yyvsp[-2].cadena)," "); printf("%s,",(yyvsp[-2].cadena));   }
#line 1817 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 222 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-6].cadena),"caracter");    asignar_inicializadoCaracter((yyvsp[-6].cadena),(yyvsp[-3].caracter)); imprime_indentacion(); printf("char %s = %s,",(yyvsp[-6].cadena),(yyvsp[-3].caracter));   }
#line 1823 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 226 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[0].cadena),"flotante");    asignar_inicializadoFlotante((yyvsp[0].cadena),0.0); 	imprime_indentacion(); printf("%s,",(yyvsp[0].cadena));   }
#line 1829 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 227 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"flotante");    asignar_inicializadoFlotante((yyvsp[-2].cadena),(yyvsp[0].flotante)); 		imprime_indentacion(); printf("int %s = %f,",(yyvsp[-2].cadena),(yyvsp[0].flotante));   }
#line 1835 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 228 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-2].cadena),"flotante");    asignar_inicializadoFlotante((yyvsp[-2].cadena),0.0); 						   printf("%s,",(yyvsp[-2].cadena));   }
#line 1841 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 229 "gramatica.y" /* yacc.c:1646  */
    { instalar((yyvsp[-4].cadena),"flotante");    asignar_inicializadoFlotante((yyvsp[-4].cadena),(yyvsp[-2].flotante));		imprime_indentacion(); printf("int %s = %f,",(yyvsp[-4].cadena),(yyvsp[-2].flotante));   }
#line 1847 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 236 "gramatica.y" /* yacc.c:1646  */
    {  verifica_contexto((yyvsp[-1].cadena));	verifica_inicializacion((yyvsp[-1].cadena)); imprime_indentacion();  	imprime_instruccion_leer((yyvsp[-1].cadena));}
#line 1853 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 237 "gramatica.y" /* yacc.c:1646  */
    { compara_variables((yyvsp[-2].cadena),(yyvsp[0].cadena)); }
#line 1859 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 238 "gramatica.y" /* yacc.c:1646  */
    { }
#line 1865 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 239 "gramatica.y" /* yacc.c:1646  */
    { }
#line 1871 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 241 "gramatica.y" /* yacc.c:1646  */
    { imprime_indentacion(); printf("while(");   eval((yyvsp[-2].arbol));   treefree((yyvsp[-2].arbol));  printf("){\n");  num_espacios += 2; }
#line 1877 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 243 "gramatica.y" /* yacc.c:1646  */
    { num_espacios -= 2;  imprime_indentacion();  printf("}\n");			}
#line 1883 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 251 "gramatica.y" /* yacc.c:1646  */
    { (yyval.arbol) = newast('+', (yyvsp[-2].arbol),(yyvsp[0].arbol));  }
#line 1889 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 252 "gramatica.y" /* yacc.c:1646  */
    { (yyval.arbol) = newast('-', (yyvsp[-2].arbol),(yyvsp[0].arbol));  }
#line 1895 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 257 "gramatica.y" /* yacc.c:1646  */
    { (yyval.arbol) = newast('*', (yyvsp[-2].arbol),(yyvsp[0].arbol)); }
#line 1901 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 258 "gramatica.y" /* yacc.c:1646  */
    { (yyval.arbol) = newast('/', (yyvsp[-2].arbol),(yyvsp[0].arbol)); }
#line 1907 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 261 "gramatica.y" /* yacc.c:1646  */
    { (yyval.arbol) = newnum((yyvsp[0].entero));   }
#line 1913 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 262 "gramatica.y" /* yacc.c:1646  */
    { (yyval.arbol) = newnum((yyvsp[0].flotante));   }
#line 1919 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 263 "gramatica.y" /* yacc.c:1646  */
    { (yyval.arbol) = newID((yyvsp[0].cadena));   verifica_inicializacion((yyvsp[0].cadena));  }
#line 1925 "gramatica.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 264 "gramatica.y" /* yacc.c:1646  */
    { (yyval.arbol) = (yyvsp[-1].arbol);  }
#line 1931 "gramatica.tab.c" /* yacc.c:1646  */
    break;


#line 1935 "gramatica.tab.c" /* yacc.c:1646  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
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

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

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

#if 1
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
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 267 "gramatica.y" /* yacc.c:1906  */


#include "lex.yy.c"

int main(){
    yyparse();
}

int yyerror(const char *s){
  fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,s);
}
