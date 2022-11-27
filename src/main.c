#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

//Aqui estan las funciones hasta el 5. El 6 y el 7 estan en su actividad_.c
//porque sino se iba quedar muy extenso.
#include "llibreriapropia.h"

//Aqui estan los headers que llaman cada ().c de cada actividad {1-7}
#include "llibreriaactividades.h"


/*******************************************************************************
*        Welcome to the Unidad Formativa 2 Activities Compilation.             *
*******************************************************************************/


// Define el rango para el menu de Actividades
#define MIN_getactnum 0
#define MAX_getactnum 7


int askConfirmation(short int *conf);
void mainActivityBanner();
int getActivityNumber(int min, int max, short int *actChoice);
int callActivityNumber(short int *num);

int main (){
    
    short int actNum = 0;
    short int confirmation =  1;
    do{
        do{
            system("cls");
            mainActivityBanner();
            getActivityNumber(MIN_getactnum, MAX_getactnum, &actNum);
            if(actNum == 0){system("cls");printf("\nAdios. =)\n");return 0;}
            
            do{
                system("cls");
                callActivityNumber(&actNum);
                askConfirmation(&confirmation);
                
            }while(confirmation == 1);
            
        }while(confirmation == 2);
        
        if(confirmation == 0){
        system("cls");
        printf("Adios =).");
        return 0;
        }
    }while(confirmation !=0);

    return 0;
}


int askConfirmation(short int *conf){
  static short int c = 0;
  do{
  printf("\nWould you like to Continue:???? \n");
  printf("\n:>> [1] Play Again.");
  printf("\n:>> [2] Go back to Main Menu.");
  printf("\n:>> [0] Exit.");
  printf("\n:>>  ");
  fflush(stdin);
  scanf("%hd",&c);
  }while(c < 0 || c > 2);
  *conf = c;
return 0;
}

void mainActivityBanner(){
system("cls");
printf("\n####################################################\n");
printf("#     Welcome to: Activities Unidad Formativa 2.   #\n");
printf("#                                                  #\n");
printf("#  Choose an Activity:                             #\n");
printf("#                                                  #\n");
printf("#  1. Saludo Especial                              #\n");
printf("#  2. Tabla de Multiplicar                         #\n");
printf("#  3. Array Media                                  #\n");
printf("#  4. Intercambio de Variables                     #\n");
printf("#  5. Loteria Doble Acierto                        #\n");
printf("#  6. Calculadora                                  #\n");
printf("#  7. Alumnos                                      #\n");
printf("#                                                  #\n");
printf("#  0. Salir                                        #\n");
printf("####################################################\n");

printf("\n");
printf("\n");
printf("     Choose an Activity: \n");
printf("\n");
}


int getActivityNumber(int min, int max, short int *actChoice){
  
  int a = 0;
  do{
  printf(": >> ");
  fflush(stdin);
  scanf("%d", &a);
  }while(a < min || a > max);

  *actChoice = a;
  
  return 0;
}

int callActivityNumber(short int *num){
  switch(*num){
     case 0:
      printf("\nGood Bye Thanks For Playing.\n");
      return 0;
     case 1: 
      printf("\nYou Have Choosen Activity: %d.\n", *num);
      actividad_1_saludoEspecial();
      break;
     case 2:
      printf("\nYou Have Choosen Activity: %d.\n", *num);
      actividad_2_tablaMultiplicar();
      break;
     case 3:
      printf("\nYou Have Choosen Activity: %d.\n", *num);
      actividad_3_arrayMedia();
      break;
     case 4:
      printf("\nYou Have Choosen Activity: %d.\n", *num);
      actividad_4_intercambioVariables();
      break;
     case 5: 
      printf("\nYou Have Choosen Activity: %d.\n", *num);
      actividad_5_loteriaDobleAcierto();
      break;
     case 6: 
      printf("\nYou Have Choosen Activity: %d.\n", *num);
      actividad_6_calculadora();
      break;
     case 7: 
      printf("\nYou Have Choosen Activity: %d.\n", *num);
      actividad_7_alumnos();
      break;
     default:
       printf("\nThat Shouldn't Happen. Ehat thw aeck hre dou yoing?.\n");
       return 0;
    }
  return 0;
}

