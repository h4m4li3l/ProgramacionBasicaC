//Y aqui estan todas las funciones


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>
#include "llibreriapropia.h"
#include "llibreriaactividades.h"

// la tercer variable guarda el numero en el global de la funcion que la llama
int pedirNumEntreRango(int minimo, int maximo, int *num){                                   
  do{
    printf("+-----------------------------------------+\n");
    printf("|   Enter a number between %d - %d :        |\n", minimo, maximo);
    printf("+-----------------------------------------+\n");
    printf("\n: >> ");                                                             
    fflush(stdin);                                                                 
    scanf("%d", &*num );

        if(*num <  minimo ||  *num > maximo){
        printf("\nNumber Not valid.Try Again!\n");
        }
                                                                                 
  }while(*num < minimo || *num > maximo);
  return 0;  
                                                                                 
}  

// Devuleve un saludo basado en numero
int saludoEspecial(int num){
    switch(num){
        case 1:printf("\nBuenos Dias.\n");
               break;
        case 2:printf("\nBuenas Tardes.\n");
               break;
        case 3:printf("\nBuenas Noches.\n");
               break;
        case 0:printf("\nHasta Pronto.\n");
               return 0;
        default:
       printf("\nThat Shouldn't Happen. Ehat thw aeck hre dou yoing?.\n");
    }
    return 0;
}

// Pinta la tabla de multiplicar de un numero dado 
int pintaTablaMultiplicar(int num){
    int res = 0;
    for(int mult = 0; mult <= 10; mult++){
        res = mult * num; 
        printf("%d X %d = %d.\n", num, mult, res);
    }
    return 0;
}

// Inicializa un array de int con la cantidad de numeros solicitados numE 
void inicializaVector(int v[], int numE){

    //int arrLength=10;
    printf("\nEnter numbers in the array:\n");

    for(int i = 0; i < numE; i++){
      int iv_userInput=0;  
      
      printf("\n[%d]:> ", i+1);
      fflush(stdin);
      scanf("%d", &iv_userInput);
       
      v[i] = iv_userInput;
    }
}

// pinta una array de int 
void pintaVector (int v[], int numE){

    for(int i = 0; i < numE; i++){
        printf("\narr[%d] = %d.\n", i+1, v[i]); 
  }
    printf("\n");
}

// Calcula la media de la array
float mediaArray(int v[], int numE){
    int sum = 0;
    float media = 0.0;
    for(int i = 0;i < numE; i++){
        sum += v[i];
    }
    media = (float)sum /numE;
    printf("\n The Array media is: %.3f\n\n\n", media);

    return 0;
}

// pide un numero y lo introduce en  una variable 
int pedirNumero(int *num){
  
  printf("\nEnter a number.\n");
  printf(": >>  ");
  scanf("%d", &*num);
  return 0;

}

// print two variables
// interchanges the values of them 
// print the after
void intercambioVariables (int *num1, int *num2){

    printf("\nNumbers Before Interchange.\n");
    printf("Num 1: %d. \n", *num1);
    printf("Num 2: %d. \n", *num2);
    
    int holder = 0;
    holder = *num1;
    *num1 = *num2;
    *num2 = holder;
    
    printf("\nNumbers After Interchange.\n");
    printf("Num 1: %d. \n", *num1);
    printf("Num 2: %d. \n", *num2);
}
///////////////////////////////////////////////////////////////////////////////
// specific logic for activity 5. May not make so much sense out of that scope
void combinacionUsuario( int *usu1, int *usu2, int min, int max){
    
    pedirNumEntreRango(min, max, &*usu1);
    do{
    pedirNumEntreRango(min, max, &*usu2);
    if(*usu2 == *usu1){
        printf("\nNumbers can't be equal, my friend. Insert Another.\n");
    }
    }while(*usu2 == *usu1);
}

void combinacionGanadora(int *pc1, int *pc2){
    srand(time(NULL));

     *pc1 = rand() % 10 + 0;
    do{
     *pc2 = rand() % 10 + 0;
    }while(*pc2 == *pc1);

    //Uncomment the two lines bellow to test the fetures.
    printf("\n-----Results uncommented. For testing:----\n");
    printf("\n%d %d\n.", *pc1,*pc2);
}

int calculaAciertos(int pc1, int pc2, int usu1, int usu2, int vect[]){

    vect[0]= pc1;
    vect[1]= pc2;
    vect[2]= usu1;
    vect[3]= usu2;

    int count = 0;
    for(int i = 0; i < 2; i++){
        if((vect[i] == vect[2] || vect[i] == vect[3])){
        count ++;
        }
    }
    printf("\nYour Numbers:\n");
    printf("\n\t%d   and   %d.\n", usu1, usu2);
    printf("\nWinning Numbers:\n");
    printf("\n\t%d   and   %d.\n", pc1, pc2);
    if(count == 2){
        printf("\n\n\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!YoOoOu WoOoOoOn TheEeEeE PriIiIze!!!!!!!!!!!, Lul!\n");
        printf("!YoOoOu WoOoOoOn TheEeEeE PriIiIze!!!!!!!!!!!, Lul!\n");
        printf("!YoOoOu WoOoOoOn TheEeEeE PriIiIze!!!!!!!!!!!, Lul!\n");
        printf("!YoOoOu WoOoOoOn TheEeEeE PriIiIze!!!!!!!!!!!, Lul!\n");
        printf("!YoOoOu WoOoOoOn TheEeEeE PriIiIze!!!!!!!!!!!, Lul!\n");
        printf("!YoOoOu WoOoOoOn TheEeEeE PriIiIze!!!!!!!!!!!, Lul!\n");
        printf("!YoOoOu WoOoOoOn TheEeEeE PriIiIze!!!!!!!!!!!, Lul!\n");
        printf("!YoOoOu WoOoOoOn TheEeEeE PriIiIze!!!!!!!!!!!, Lul!\n");
        printf("!YoOoOu WoOoOoOn TheEeEeE PriIiIze!!!!!!!!!!!, Lul!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }else if(count == 1){
        printf("\n\nAlmost  =/  You've got ONE! number Correct...\n\n");
    }else if(count == 0){
        printf("\n\nNa, Honey. More Luck Next Time!\n\n");
    }
    else{
       printf("\nThat Shouldn't Happen. Ehat thw aeck hre dou yoing?.\n");
    }

    return 0;
}
///////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
