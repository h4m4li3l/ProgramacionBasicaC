/*
  Crea un programa en C que pida al usuario valores a dos variables
  mediante una funcion llamada
  "pedirNumero"
  Hay que hacer una llamada a la funcion por cada inicializacion
  de la variable. No deben estar controlados
  Posteriormente, crea un procedimiento en C llamado
  "intercambioVariables"
  que intercambie el valor de las dos variables que pasaremos como
  parametros y que previamente hemos introducido por teclado
  Se deben intercambiar los valores entre las variables y no mostrar las
  variables al reves.
  Se deben mostrar el valor de las variables antes del cambio y posterior
  al cambio directamente con printf en el main.

*/

#include <stdio.h>
#include <stdlib.h>
#include "llibreriapropia.h"
#include "llibreriaactividades.h"

int actividad_4_intercambioVariables(){
printf("\n+---------------------------------------------------------------------+\n");
printf("|  Intercambio de Variables:                                          |\n");
printf("|                                                                     |\n");
printf("|  After Introducing two numbers the program will swap them internally|\n");
printf("|  var a = x var b = y -> var a = y var b = x                         |\n");
printf("+---------------------------------------------------------------------+\n");   
    int a = 0;
    int b = 0;
    
   printf("Introduce two number. ");
  
    pedirNumero(&a);
    pedirNumero(&b);

    intercambioVariables(&a, &b);

    
    
    return 0;
}
