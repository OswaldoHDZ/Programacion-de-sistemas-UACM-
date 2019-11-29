/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 118 "gramatica.y" /* yacc.c:1909  */

	char *cadena;
	double flotante;
	char caracter;
	int entero;

#line 89 "gramatica.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMATICA_TAB_H_INCLUDED  */
