# ProyectoFinalProgSistemas

Actividades para análisis semántico

  1.- Verificación de duplicidad. Usar la función instalar(char *nombre_simbolo) para evitar duplicidad en la 
      declaración de las variables. En los siguientes casos debe enviar un mensaje de error.

        entero edad, edad;
        ------------------------------------
        entero a,b,c;
        flotante a;

        ------------------------------------
        entero a;
        flotante a;
        caracter a;
        
   2.- Verificación de declaración. Usar la función verifica_contexto(char *nombre_simbolo) para asegurar 
       que una variable haya sido declarada antes de ser usada en cualquier instrucción o expresión. Si la variable 
       no aparece en la sección de declaraciones entonces se debe desplegar un mensaje de error cuando se intente usar.
       
       
   3.- Agregar un segundo parámetro en la función verifica_contexto(char *nombre_simbolo, char *mensaje_error). 
       En este caso mensaje de error será introducido dependiendo del contexto en el que surgió el error. Por ejemplo, 
       si el error fue en la instrucción imprimir entonces debería desplegar un mensaje de acuerdo a ese error: 
       “No se puede imprimir la variable -----”.
       
       
   4.- Verificación de inicialización. En esta actividad se debe checar si una variable a la que se quiera acceder, 
       ya está inicializada. Para esto necesitamos de un campo “inicializado” en la tabla de símbolos que nos indique 
       si la variable ya fue inicializada (valor true o 1), o no (valor false o 0).  Los pasos a seguir son los siguientes:
       
        a) Añadir el campo “inicializado” en la tabla de símbolos, este tendrá el tipo unsigned short int. Archivo TS.h.
        
        
        b) Añadir la función get_inicializado(char *nombre_simbolo) en TS.h. Esta función recibirá el nombre de un símbolo 
           y devolverá 1 si la respectiva variable ya fue inicializada, o 0 en caso de que no haya sido inicializada.
       
        c) Implementar la función verificar_inicialización(char *nombre_simbolo) en el archivo de Bison. Esta devolverá 1 
           si el símbolo ya fue inicializado y 0 en caso contrario.
       
        d) Añadir esta función las acciones correspondientes (donde se use alguna variable).
        
        e) Realizar pruebas con muchos códigos distintos para que marque error cuando deba hacerlo.
       
