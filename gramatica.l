%{
/* Reconocedor de tokens para una calculadora */
#include "gramatica.tab.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
%}


DIGITO [0-9]


%%
"+"                         { return MAS; }
"--"                        { return DOBLE_MENOS; }
"++"                        { return DOBLE_MAS; }
"para"                      { return PARA; }
"<-"                        { return ASIGNACION;  }
"||"                        { return OR; }
"mientras"                  { return MIENTRAS; }
"leer"                      { return LEER;  }
"imprimir"                  { return IMPRIMIR; }
"{"                         { return ABRIR_BLOQUE;            }
"}"                         { return CERRAR_BLOQUE;         }
"entero"                    { return ENTERO;                        }
"caracter"                  { return CARACTER; }
"flotante"                  { return FLOTANTE; }
"caracter"                  { return CARACTER; }
"principal"                 { return PRINCIPAL;                     }
"'"                         { return COMILLA_SIMPLE;}
"\""[a-zA-Z0-9_,\- ]*"\""   { return CADENA; }
"0"|[1-9][0-9]*             { yylval.entero = atoi(yytext);   return NUMERO; }
[a-zA-Z]                    { yylval.caracter =  yytext[0];        return LETRA; }
[0-9]*[\.][0-9]*             { yylval.flotante = atof(yytext); return NUMFLOTANTE; }
[a-z][a-zA-Z0-9_]*          { yylval.cadena = (char*) strdup(yytext); return IDENTIFICADOR;      }
[ \t\r\n]+     		        { /* Ignora los espacios en blanco */ }
. 					        {  return(yytext[0]);  }

%%