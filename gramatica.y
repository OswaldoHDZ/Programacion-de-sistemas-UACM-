%{
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


void verifica_inicializacion(char *nombre_simbolo){
	simbolo *s;
	s = obtener_simbolo(nombre_simbolo);
	if( s->inicializado == 0 ){
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




%}
/* Valores semánticos de los tokens */
%union{
	char *cadena;
	double flotante;
	int entero;
}


%start programa
%token ENTERO FLOTANTE
%token <flotante> NUMFLOTANTE
%token CADENA
%token <cadena> IDENTIFICADOR
%token <entero> NUMERO
%token ABRIR_BLOQUE CERRAR_BLOQUE
%token PRINCIPAL
%token LEER IMPRIMIR MIENTRAS PARA
%token OR ASIGNACION DOBLE_MAS DOBLE_MENOS MAS

%left '<' OR MAS
%right DOBLE_MAS  DOBLE_MENOS


%%

programa : PRINCIPAL '(' ')' ABRIR_BLOQUE { num_espacios = 0; printf("int main(){");  num_espacios += 2;  }
					  declaraciones
					  instrucciones
          CERRAR_BLOQUE   { num_espacios -= 2; printf("\n}\n"); }
          ;



declaraciones : /*declaraciones*/
		| declaraciones declaracion ';'
		;

declaracion : /*empty*/
		|  ENTERO IDENTIFICADOR 		{
																	instalar($2,"entero");
																	asignar_inicializado($2,0);
																	imprime_indentacion();
																	printf("int %s;",$2);
																}
		|  FLOTANTE IDENTIFICADOR 	{
																	instalar($2,"flotante");
																	asignar_inicializado($2,0);
																	imprime_indentacion();
																	printf("float %s;",$2);
																}
		;


instrucciones : /*empty*/
		| instrucciones instruccion ';'
		;

instruccion : LEER '(' IDENTIFICADOR ')'    { verifica_contexto($3);  verifica_inicializacion($3); imprime_indentacion(); imprime_instruccion_leer($3);}
		| IDENTIFICADOR ASIGNACION expresion_aritmetica    { asignar_inicializado($1,1); }
		| IDENTIFICADOR ASIGNACION IDENTIFICADOR  { verifica_tipos($1,$3); asignar_inicializado($1,1); }
		| IMPRIMIR '(' CADENA ')'
		| MIENTRAS '(' expresion ')' ABRIR_BLOQUE   { imprime_indentacion(); printf("while(){"); num_espacios += 2;  }
			instrucciones
		  CERRAR_BLOQUE  { num_espacios -= 2; imprime_indentacion(); printf("}");   }
		| PARA '(' IDENTIFICADOR ASIGNACION NUMERO ';' expresion ';' expresion_incremento  ')' ABRIR_BLOQUE
			instrucciones
			CERRAR_BLOQUE
		;


expresion : expresion '<' expresion
		|   expresion OR expresion
		| NUMERO
		| IDENTIFICADOR            { verifica_contexto($1);  }
		| expresion_incremento
		| expresion_aritmetica
		;


expresion_incremento : IDENTIFICADOR DOBLE_MAS
										 | IDENTIFICADOR DOBLE_MENOS
										 ;

expresion_aritmetica : expresion_aritmetica MAS expresion_aritmetica
										 | NUMERO
										 | IDENTIFICADOR
										 | '(' expresion_aritmetica ')'
										 ;

%%

#include "lex.yy.c"

int main(){
    yyparse();
}

int yyerror(const char *s){
  fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,s);
}