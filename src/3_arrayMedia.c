/*
 -Realiza un programa en C que declare un array de máximo 10 elementos junto
 a la variable de control del elementos (numE)
 -Para ello el main principal pedirá al usuario 
 cuantos elementos quiere introducir
 (entre 1 y 10) que se debe controlar con una funcion 
 "pideNumEntreRango" 
 Se debe hacer un procedimiento que 
 inicialice el vector con la cantidad de números introducidos por el usuario
 "inicializaVector"
 Posteriormente muestra el array a traves del procedimiento 
 "pintaVector"
 Una vez hecho hacer una funcion en C llamada 
 "mediaArray"
 que reciba como parametros el array con numeros junto su numE y devuelva la media
 de los numeros que tienes el array.   
  */


#include <stdio.h>
#include <stdlib.h>
#include "llibreriapropia.h"
#include "llibreriaactividades.h"

#define MAX_ARRAY_EX3 10
int actividad_3_arrayMedia() {
   int maxArray3 = MAX_ARRAY_EX3;
   int minArray3 = 1;
   int numE = 0;
   int arrayEx3[MAX_ARRAY_EX3];
      
printf("\n+---------------------------------------------------------------------+\n");
printf("|  Array Media     :                                                  |\n");
printf("|                                                                     |\n");
printf("|  Give a number to initialize an Array (MAX 10).                     |\n");
printf("|  Then insert that amount of numbers on the array and the program    |\n");
printf("|  will calculate the array media.                                    |\n");
printf("+---------------------------------------------------------------------+\n");   
    
   pedirNumEntreRango(minArray3, maxArray3, &numE);
   
   inicializaVector(arrayEx3, numE);

   pintaVector(arrayEx3, numE);

   mediaArray(arrayEx3,numE); 
return 0;
}
