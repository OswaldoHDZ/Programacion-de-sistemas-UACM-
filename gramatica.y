%{
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


void imprime_indentacion(){
	int i=0;
	for(i=0; i<=num_espacios; i++)
	{
		printf(" ");
	};
}


%}
/* Valores semánticos de los tokens */
%union{
	struct ast *arbol;
	char *cadena;
	char caracter;
	int entero;
}



%define parse.lac full

%start programa
%token ENTERO
%token CADENA
%token <caracter> DATO_CARACTER
%token CARACTER
%token <cadena> IDENTIFICADOR
%token <entero> NUMERO
%token ABRIR_BLOQUE CERRAR_BLOQUE
%token PRINCIPAL
%token LEER IMPRIMIR MIENTRAS PARA
%token OR ASIGNACION DOBLE_MAS DOBLE_MENOS MAS MENOS POR ENTRE

%type <arbol> exp_arit factor termino

%left '<' OR MAS MENOS POR ENTRE
%right DOBLE_MAS  DOBLE_MENOS


%%

programa : PRINCIPAL '(' ')' ABRIR_BLOQUE							{ num_espacios = 0; printf("int main(){\n");  num_espacios += 2;	  }
		  declaraciones
		  instrucciones
		  CERRAR_BLOQUE																{ printf("}\n\n");  num_espacios -= 2;		}
          ;



declaraciones : /*declaraciones*/
		| declaraciones declaracion ';'
		;



declaracion :  /*empty*/
						|	ENTERO identificadores_entero
						|	CARACTER identificadores_caracter
						;

identificadores_entero :  IDENTIFICADOR      					 	{instalar($1,"entero"); imprime_indentacion(); printf("int %s;\n",$1);  }
		| IDENTIFICADOR ',' identificadores_entero				{instalar($1,"entero"); imprime_indentacion(); printf("int %s;\n",$1);  }
		;

identificadores_caracter : IDENTIFICADOR      					{ instalar($1,"caracter"); int i=0;  imprime_indentacion();  printf("int %s;\n",$1);  }
		| IDENTIFICADOR ',' identificadores_caracter				{ instalar($1,"caracter"); int i=0;  imprime_indentacion();   printf("int %s;\n",$1);  }
		;


instrucciones : /*empty*/
		| instrucciones instruccion ';'
		;

instruccion : LEER '(' IDENTIFICADOR ')'    {  verifica_contexto($3);	imprime_indentacion();  	imprime_instruccion_leer($3);}
		| IDENTIFICADOR ASIGNACION IDENTIFICADOR     { compara_variables($1,$3); }
		| IDENTIFICADOR ASIGNACION NUMERO     { }
		| IMPRIMIR '(' CADENA ')'
		| MIENTRAS '(' exp_arit ')' ABRIR_BLOQUE	 { imprime_indentacion(); printf("while(");   eval($3);   treefree($3);  printf("){\n");  num_espacios += 2; }
			instrucciones
		  CERRAR_BLOQUE																	{ num_espacios -= 2;  imprime_indentacion();  printf("}\n");			}
		;







exp_arit : factor
			  | exp_arit MAS factor			{ $$ = newast('+', $1,$3);  		       }
			  | exp_arit MENOS factor   { $$ = newast('-', $1,$3);  		       }
			;


factor	: termino
			| factor POR termino         { $$ = newast('*', $1,$3);  		     }
			| factor ENTRE termino			 { $$ = newast('/', $1,$3);   		     }
			;


termino : NUMERO					{ $$ = newnum($1);   }
			 | IDENTIFICADOR	  { $$ = newID($1);  }
		   | '(' exp_arit ')'	{ $$ = $2;  }
		   ;

%%

#include "lex.yy.c"

int main(){
    yyparse();
}

int yyerror(const char *s){
  fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,s);
}
