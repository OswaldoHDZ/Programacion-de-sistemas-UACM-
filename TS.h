#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct simbolo{
	char 			*nombre; 						// Nombre del identificador
	char 			*tipo_dato;   					// tipo de dato: caracter flotante entero
	int 			inicializado; 					// Solo datos enteros	   3	
	char 			*inicializadoValorCaracter; 		// Solo datos caracteres  's'
	float			inicializadoValorFlotante; 		// Solo datos flotantes   4.5
	struct simbolo *siguiente_nodo;
};

typedef struct simbolo simbolo;
simbolo *tabla_simbolos = (simbolo *)0;

simbolo *inserta_simbolo(char *nombre_simbolo, char *tipo_dato){
	simbolo *ptr;

	ptr = (simbolo *)malloc(sizeof(simbolo));

	// Insertando nombre|
	ptr -> nombre = (char *)malloc(strlen(nombre_simbolo)+1);
	strcpy(ptr->nombre, nombre_simbolo);

	// Insertando tipo de tipo_dato
	ptr -> tipo_dato = (char *)malloc(strlen(tipo_dato)+1);
	strcpy(ptr->tipo_dato, tipo_dato);

	// Actualizando referencia o apuntadores
	ptr -> siguiente_nodo = (struct simbolo *)tabla_simbolos;
	tabla_simbolos = ptr;
	return ptr;
}

simbolo *obtener_simbolo(char *nombre_simbolo){
	simbolo *ptr;
	for(ptr = tabla_simbolos; ptr != (simbolo *)0; ptr = (simbolo *)ptr->siguiente_nodo)
		if(strcmp(ptr -> nombre, nombre_simbolo) == 0)
			return ptr;
	return 0;
}



void set_inicializado(char *nombre_simbolo, int valor){
	simbolo *s = tabla_simbolos;
	while( strcmp(s->nombre, nombre_simbolo) != 0){  /*ptr != (simbolo *)0*/
		s = s -> siguiente_nodo;
	}
	s->inicializado = valor;
}

void set_inicializadoCaracter(char *nombre_simbolo, char *valor){
	simbolo *s = tabla_simbolos;
	while( strcmp(s->nombre, nombre_simbolo) != 0){  /*ptr != (simbolo *)0*/
		s = s -> siguiente_nodo;
	}
	s->inicializadoValorCaracter = valor;
}

void set_inicializadoFlotante(char *nombre_simbolo, float valor){
	simbolo *s = tabla_simbolos;
	while( strcmp(s->nombre, nombre_simbolo) != 0){  /*ptr != (simbolo *)0*/
		s = s -> siguiente_nodo;
	}
	s->inicializadoValorFlotante = valor;
}


int get_inicializado(char *nombre_simbolo){
	simbolo *s = tabla_simbolos;
	while( strcmp(s->nombre, nombre_simbolo) != 0){  /*ptr != (simbolo *)0*/
		s = s -> siguiente_nodo;
	}
	return s->inicializado;
}

void imprime_tabla(simbolo *primer_simbolo){
	simbolo *simbolo_actual = primer_simbolo;
	while(simbolo_actual != NULL){  /*ptr != (simbolo *)0*/
		printf("%s \n",simbolo_actual -> nombre);
		simbolo_actual = simbolo_actual -> siguiente_nodo;
	}
}