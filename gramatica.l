%{
/* Reconocedor de tokens para una calculadora */
#include "gramatica.tab.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
%}


DIGITO [0-9]
LETRA [a-zA-Z]


%%
"<-"                        { return ASIGNACION;  }
"haz"                       { return HAZ; }
"si"                        { return SI; }
"otro"                      { return OTRO; }
"+"                         { return MAS; }
"--"                        { return DOBLE_MENOS; }
"++"                        { return DOBLE_MAS; }
"para"                      { return PARA; }
"||"                        { return OR; }
"mientras"                  { return MIENTRAS; }
"leer"                      { return LEER;  }
"imprimir"                  { return IMPRIMIR; }
"{"                         { return ABRIR_BLOQUE;            }
"}"                         { return CERRAR_BLOQUE;         }
"entero"                    { return ENTERO; }
"caracter"                  { return CARACTER; }
"flotante"                  { return FLOTANTE; }
"principal"                 { return PRINCIPAL; }
"\""[a-zA-Z0-9_,\- ]*"\""   { return CADENA; }
"0"|[1-9][0-9]*             { yylval.entero = atoi(yytext);   return NUMERO; }
[a-z][a-zA-Z0-9_]*          { yylval.cadena = (char*) strdup(yytext); return IDENTIFICADOR; }
[a-zA-Z]                    { yylval.caracter = yytext[0]; return LETRA; }
[0-9]+([.][0-9]+)           { yylval.flotante = strtod(yytext, NULL); return NUMFLOTANTE; }
[ \t\r\n]+     		        { /* Ignora los espacios en blanco */ }
. 					        {  return(yytext[0]);  }

%%