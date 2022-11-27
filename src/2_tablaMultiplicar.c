/*
Hacer un programa en C que pida al usuario un numero controlado
entre 1 y 10 a traves de la funcion:
"pideNumEntreRango".
Posteriormente nos debe mostrar por pantalla la tabla de multiplicacion
de ese numero a traves de la llamada al procedimento:
"pintaTablaMultiplicar"

 */
#include <stdio.h>
#include <stdlib.h>
#include "llibreriapropia.h"
#include "llibreriaactividades.h"

int actividad_2_tablaMultiplicar() {
printf("\n+---------------------------------------------------------------------+\n");
printf("|                                                                     |\n");   
printf("|  Tabla de Multiplicar:                                              |\n");
printf("|                                                                     |\n");
printf("|  Given a number the program will print it's multiplication table.   |\n");
printf("|  From 1 to 10.                                                      |\n");
printf("+---------------------------------------------------------------------+\n");   
     
    int a = 1;
    int b = 10;
    int numInput = 0;

        pedirNumEntreRango(a, b, &numInput);
        pintaTablaMultiplicar(numInput);
        

return 0;
}
