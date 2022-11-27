/*
  Hacer un program en C para poder jugar al DOBLEACIERTO.
  Este juego se trata de elegir 2 números del 0 al 9 
  a taves de un procedimiento
  "combinacionUsuario"
  Que seran pedidos a traves de la funcion
  "pideNumEntreRango"
  Es decir, dentro de combinacionUsuario hay dos llamadas a pideNumEntreRango

  Posteriormente el sistema genera aleatoriamente (rand) la combinación ganadora
  de 2 numeros (tambien entre 0 y 9) atraves de un procedimiento llamado 
  "combinacionGanadora"

  Finalmente, hay que crear una funcion que datos los valores del usuario y los
  aleatorios, devuelva al main cuantos aciertos ha tenido el usuario 
  "calculaAciertos"

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "llibreriapropia.h"
#include "llibreriaactividades.h"
#define MAX 4
int actividad_5_loteriaDobleAcierto(){
   
    
printf("\n+---------------------------------------------------------------------+\n");
printf("|  Loteria Doble Acierto:                                             |\n");
printf("|                                                                     |\n");
printf("|  The program will generate two random numbers. [MIN 0 - MAX 9]      |\n");
printf("|                                                                     |\n");
printf("|  The Rest of the History You prob know... Good Luck!!!!             |\n");
printf("+---------------------------------------------------------------------+\n");   
    int max = 9;
    int min = 0;
    
    static int userNum1 = 0;
    static int userNum2 = 0;
    
    static int pcNum1 = 0;
    static int pcNum2 = 0;

    int v[MAX];

    combinacionGanadora(&pcNum1, &pcNum2);
    
    combinacionUsuario(&userNum1, &userNum2, min, max);
  

    calculaAciertos(pcNum1, pcNum2, userNum1, userNum2, v);
    return 0;
}

