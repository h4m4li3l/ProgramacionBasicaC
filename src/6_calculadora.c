/*
  Crea una caculadora con las opciones sumar restar multiplicar y dividir
  utilizando procedimientos y funciones
  Mediante un menu debes pedir al usuario que operaciones desea utilizar.
  "pintaMenu"
  El Valor que escoja el usuario en el menu, debe estar controlado entre 0 y 3
  "pideNumEntreRango"
  Posteriormente hay que solicitar los dos operandos para realizar el calculo
  mediante un procedimiento llamado
  "pideOperadores"
  Hay que verificar que el programa no divida por 0 en este caso debe mostrar
  un mensaje de error
  Para salir del programa hay que poner un 0.
  El main debe mostar el resultado cada vez que se hace una operacion
  En cada opcion usando un switch se hará una llamada a las funciones
  suma resta multiplicacion o division segun la opcion escogida
  El programa finaliza cuando se introduce un 0.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "llibreriapropia.h"
#include "llibreriaactividades.h"

void pintaMenuCalculadora();
void pideOperadores(int *a, int *b);
int operaciones(int a, int b, int operat, int *resultado);

int actividad_6_calculadora() {


printf("\n+----------------------------------------------------------------------+\n");
printf("|   Calculadora:                                                       |\n");
printf("+----------------------------------------------------------------------+\n");

  static int operacion = 0;
  static int min = 0;
  static int max = 4;
  static int resultado = 0;
  static int operadorA = 0;
  static int operadorB = 0;
  
  pintaMenuCalculadora();
  do{
        pedirNumEntreRango(min, max, &operacion);
  }while(operacion < 0 || operacion >4);
 
  if(operacion == 0){
      printf("\nQuitting to main menu\n.");
      return 0;
  }else{
    pideOperadores(&operadorA, &operadorB);
    //Si operacion es division
    if(operacion == 4){
        if(operadorB == 0){
          printf("\nThe second number is 0. The Matrix doesn't allow it.\n");
          //pide solo el segundo numero hasta que sea diferente de 0
            do{
              printf("\nInsert Another Number:\n");
              printf(": >>  ");
              fflush(stdin);
              scanf("%d", &operadorB);
            }while(operadorB == 0);
        }
    }  
    operaciones(operadorA, operadorB, operacion, &resultado);
  }
  return 0;
  }


void pintaMenuCalculadora(){
  
    printf("\n+------------------------------------------------------------------+\n");
    printf("|   Select an operation to perform:                                |\n");
    printf("|                                                                  |\n");
    printf("| 1.Sumar                                                          |\n");
    printf("| 2.Restar                                                         |\n");
    printf("| 3.Multiplicar                                                    |\n");
    printf("| 4.Dividir                                                        |\n");
    printf("| 0.Salir                                                          |\n");
    printf("+------------------------------------------------------------------+\n");
 
}

void pideOperadores(int *a, int *b){
    printf("\nEnter two numbers to perform the operations with:\n");
    int count = 0;
    do{
    printf("[%d]\n: >>  ",count+1);
    fflush(stdin);
    
    if(count == 0){scanf("%d",&*a);}
    if(count == 1){scanf("%d",&*b);}
    count ++;
    }while(count < 2);
    
}

int operaciones(int a, int b, int operat, int *resultado){
  
    switch(operat){
      case 1://suma
        *resultado = a + b;
        printf("\n\nThe Sum is equal to: %d\n", *resultado);
        break;
      case 2://rest
        *resultado = a - b;
        printf("\n\nThe Subtraction is equal to: %d\n", *resultado);
        break;
      case 3://multiplicar
        *resultado = a * b;
        printf("\n\nThe Multiplication is equal to: %d\n", *resultado);
        break;
      case 4://division
          *resultado =  a / b;
          printf("\nThe division is equal to: %d.\n", *resultado);
          int rest = a % b;
          printf("\nThe remainder is equal to: %d.\n", rest);
          float floatt = (float)a/b;
          printf("\nFloat Division is equal to: %.3f.\n", floatt);
        break;
      case 0:
        printf("\nLuck and Good Bye...\n"); 
        break;

      default:
        printf("\nwhat the heck are you trying to do.\n");
        break;
      }
    return 0;
}
