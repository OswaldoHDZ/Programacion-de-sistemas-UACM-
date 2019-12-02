%{
/* Reconocedor de tokens para una calculadora */
#include "gramatica.tab.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
%}


%option yylineno

DIGITO [0-9]
LETRA [a-zA-Z]


%%
'\''[a-zA-Z0-9,.\-|\$#]'\'' { return DATO_CARACTER; }
"caracter"		            { return CARACTER; }
"+"                         { return MAS; }
"-"						    { return MENOS;  }
"*"                         { return POR;  }
"/"                         { return ENTRE;  }
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
"'"                         { return COMILLA_SIMPLE; }
"entero"                    { return ENTERO;                        }
"flotante"                  { return FLOTANTE; }
"principal"                 { return PRINCIPAL;                     }
"\""[a-zA-Z0-9_,\- ]*"\""   { return CADENA; }
[0-9]+([.][0-9]+)           { yylval.flotante = strtod(yytext, NULL);   return NUMFLOTANTE; }
"0"|[1-9][0-9]*             { yylval.entero = atoi(yytext);   return NUMERO; }
[a-z][a-zA-Z0-9_]*          { yylval.cadena = (char*) strdup(yytext); return IDENTIFICADOR;      }
[a-zA-Z0-9]                 { yylval.caracter = (char*) strdup(yytext); return LETRA; }
[ \t\r\n]+     		        { /* Ignora los espacios en blanco */ }
. 					        {  return(yytext[0]);  }

%%
