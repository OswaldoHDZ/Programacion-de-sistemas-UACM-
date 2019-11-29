# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
#include <string.h>


extern int yylineno;

/*
Nodos en el arbol de sintaxis abstracto
*/
struct ast{
	int nodetype;
	struct ast *l;
	struct ast *r;
};


struct numval{
	int nodetype;	/*tipo K para constante */
	double number;
};


struct idval{
	int nodetype;  /*tipo I para identificador*/
	char *nombreID;
};



/*Construcción del arbol*/
struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newnum(double d);
struct ast *newID(char *nombre_simbolo);

/*Evaluar el ast*/
double eval(struct ast *);

/*borrar y liberar un ast*/
void treefree(struct ast *);

/*Esta agrega un nodo que contiene
un operador, por ejemplo
					+
				/   \
		  izq   der
*/
struct ast *newast(int nodetype, struct ast *l, struct ast *r){
	struct ast *a = malloc(sizeof(struct ast));
	if(!a) {
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = nodetype;
	a->l = l;
	a->r = r;
	return a;
}



/*
Agrega un nodo que contiene un número
de tipo double
*/
struct ast *newnum(double d){
	struct numval *a = malloc(sizeof(struct numval));
	if(!a) {
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = 'K';
	a->number = d;
	return (struct ast *)a;
}


/*
Agrega un nodo que contiene un identificador
de tipo cadena
*/
struct ast *newID(char *nombre_simbolo){
	struct idval *a = malloc(sizeof(struct idval));
	if(!a) {
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = 'I';
	a->nombreID = (char *)malloc(strlen(nombre_simbolo)+1);
	strcpy(a->nombreID,nombre_simbolo);
	return (struct ast *)a;
}




/*
 Evalua (numericamente) una expresión aritmetica
 e imprime en  notación polaca inversa dicha
 expresión
*/
double eval(struct ast *a){
	// printf("\nEntrando %s \n",a->nodetype);
	double v; // calculated value of this subtree
	switch(a->nodetype) {
		case 'I': v = 0.0; printf(" %s ",((struct idval *)a)->nombreID); break;
		case 'K': v = ((struct numval *)a)->number; printf(" %.2f ",((struct numval *)a)->number); break;
		case '+': v = eval(a->l) + eval(a->r);  printf(" + "); break;
		case '-': v = eval(a->l) - eval(a->r);	printf(" - ");break;
		case '*': v = eval(a->l) * eval(a->r);   printf(" * "); break;
		case '/': v = eval(a->l) / eval(a->r);   printf(" / ");break;
		case '|': v = eval(a->l); if(v < 0) v = -v; break;
		case 'M': v = -eval(a->l); break;
		default: printf("internal error: bad node %c\n", a->nodetype);
	}
	return v;
}




void imprime_arbol(struct ast *arbol){
	printf("\n%c",(char)arbol->nodetype);

	if(arbol->l==NULL){
	  imprime_arbol(arbol->l);
	  return;
	}
	if(arbol->r==NULL){
	  imprime_arbol(arbol->r);
	  return;
	}
}



inorden(struct ast *arbol){
	printf(" %c ",(char)arbol->nodetype);


}

/*
Libera el espacio para crear el siguiente
árbol.
*/
void treefree(struct ast *a){
	switch(a->nodetype) {
		/* two subtrees */
		case '+':
		case '-':
		case '*':
		case '/':
				treefree(a->r);
				/* one subtree */
		case '|':
		case 'M':
			treefree(a->l);
			/* no subtree */
		case 'I':
		case 'K':
		free(a);
		break;
		default: printf("internal error: free bad node %c\n", a->nodetype);
	}
}
