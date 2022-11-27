/*
Hacer un programa en C que pasandole un numero controlado entre 0 y 3
a traves de una funcion nos muestre por pantalla
 
 "Buenos dias"    - caso inserte 1
 "Buenas tardes"  - caso inserte 2
 "Buenas noches"  - caso inserte 3
 "Hasta pronto"   - caso inserte 0
 
-Para obtner el numero entre 0 y 3, el main debe llamar a una funcion.
Que vaya preguntando al usuario numeros hasta que introduzca uno valido.
("pideNumEntreRango(int min, int max);")

-Posteriormente llamara al procedimento saludar
("void saludoEspecial (int num);")

-Una ves saludado 
el programa espera con un getch() 
borra la pantalla 
y vuelve a empezar.

-Prototipos:
int pideNumEntreRango (int min, int max);
void saludoEspecial (int num); */

#include <stdio.h>
#include <stdlib.h>
#include "llibreriapropia.h"
#include "llibreriaactividades.h"

int actividad_1_saludoEspecial() {
printf("\n+---------------------------------------------------------------------+\n");
printf("|  Saludo Especial:                                                   |\n");
printf("|                                                                     |\n");
printf("|  Given a number the program will give a special greeting back.      |\n");
printf("|  From 0 to 3.                                                       |\n");
printf("+---------------------------------------------------------------------+\n");   

    static int numInput = 0;
    int a = 0;
    int b = 3;

    
        pedirNumEntreRango(a, b, &numInput);
        
        saludoEspecial(numInput);
    

return 0;
}
