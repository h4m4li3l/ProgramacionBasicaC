/*
  Crea un program en C que pueda almacenar nombre completo de 10 alumnos.
  Definiremos:
  MAXALUMNOS 10
  MAXCADENA 20
  
  El array de cadenas se llamará 
  vNombreCompleto[MAXALUMNOS][MAXCADENA]
  
  El Programa tendra dos opciones que se ven a continuacion, mostrando el menu
  a traves de un procedimiento llamado
  "pintaMenu"
  
  El valor que escoja el usuario debe estar controlado entre 0 y 3 con
  "pideNumEntreRango"
  
  0 - Salir
  
  1 - Insertar Alumno: Esta opcion va a añadir al final de la array el nombre
  completo del Alumno. Entendemos que un alumno esta en un array si coinciden
  la cadena completa.No hace falta controlar si hay dos nombres iguales.
  El Nombre del procedimiento sera.
  "nuevoAlumno"
  
  2 - Listar Alumnos: Esta opcion mostrara un listado con todos los nombres del
  array de cadenas. En ese caso de que no haya ninguno debe indicar que no hay
  alumnos en el array de cadenas. El nombre del procedimiento se debe llamar:
  "listarAlumnos"
  
  3 - Modificar nombre de un alumno (*opcional): Se mostraran todos los alumnos
  que hay introducidos en el array y se pedira el nombre completo de un alumno
  que se quiera modificar. En caso de que exista, se sobrescrbira al mencionado
  En caso contrario, se debe mostar el mensaje: El alumno no está dentro de la 
  base de datos. Si hay alumnos con el mismo nombre, se modificara el primero
  que se encuentre. El nombre del procedimiento sera:
  "modificarAlumno"
  
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "llibreriapropia.h"
#include "llibreriaactividades.h"
#include <ctype.h>

#define MAXALUMNOS 10
#define MAXCADENA 40
#define MAXSUPPLY 1

void pintaMenu();
int askConfirmation1(short int *conf);
int getActivityNumber(int min, int max, short int *actChoice);
void nuevoAlumno(char v[MAXALUMNOS][MAXCADENA], short int *numE);
void listarAlumno(char v[MAXALUMNOS][MAXCADENA], short int numE);
void modificarAlumno(char v[MAXALUMNOS][MAXCADENA],char vSupp[MAXSUPPLY][MAXCADENA], short int numE);
int compareStrings(char str1[], char str2[], short int *flag);

int actividad_7_alumnos(){
  
    char vSuppArr[MAXSUPPLY][MAXCADENA];
    char vNombreCompleto[MAXALUMNOS][MAXCADENA];
    static short int option = 1;
    static short int numE = 0;
    static short int confirmation=0;
do{
    do{
        system("cls");
        pintaMenu();
        getActivityNumber(0, 3, &option);
        
        switch(option){
        case 0:
              printf("Adios.");
              return 0;
        
        case 1:
              do{            
                system("cls"); 
                nuevoAlumno(vNombreCompleto, &numE);         
                askConfirmation1(&confirmation);
              }while(confirmation == 1 && numE < MAXALUMNOS);
            break; 
        
        case 2:
              do{
                system("cls");
                listarAlumno(vNombreCompleto, numE);
                askConfirmation1(&confirmation);
              }while(confirmation == 1);
            break; 
        
        case 3:
              do{
                  system("cls");
                modificarAlumno(vNombreCompleto, vSuppArr, numE);
                askConfirmation1(&confirmation);
              }while(confirmation == 1);
            break;
        
        default:
              printf("bye");
        }
      
    }while(confirmation == 2);

}while(confirmation !=0);
         
  return 0;

}

void pintaMenu(){
printf("\n+---------------------------------------------------------------------+\n");
printf("|  Alumnos:                                                           |\n");
printf("|                                                                     |\n");
printf("|  1. Insert Student                                                  |\n");
printf("|  2. List Students                                                   |\n");
printf("|  3. Modify Students                                                 |\n");
printf("|                                                                     |\n");
printf("|  0. Exit                                                            |\n");
printf("|                                                                     |\n");
printf("+---------------------------------------------------------------------+\n");   
}
int askConfirmation1(short int *conf){
  do{
  
      printf("\nWould you like to Continue:???? \n");
      printf("\n:>> [1] Continue.");
      printf("\n:>> [2] Go back to Menu.");
      printf("\n:>>  ");
      
      fflush(stdin);
      scanf("%hd",&*conf);
  }while(*conf < 1 || *conf > 2);
 
return 0;
}

void nuevoAlumno(char v[MAXALUMNOS][MAXCADENA], short int *numE){
    
    printf("\nEnter new student name: [%d].\n", (*numE)+1);
    printf(": >>  ");
    fflush(stdin);
    //getchar();
    fgets(v[(*numE)],MAXCADENA,stdin);
    fputs(v[(*numE)],stdout);
    (*numE)++;

}

void listarAlumno(char v[MAXALUMNOS][MAXCADENA], short int numE){
    
    short int holder = 2;
    if(numE == 0){
    printf("Theres no students yet.");
    }else{
        do{
            printf("\n 1. List all students.\n");
            printf("\n 2. Exit this Menu.\n");
            fflush(stdin);
            printf(":: >> ");
            scanf("%hd", &holder);
        }while(holder < 1 || holder > 2 ); 
   
        if(holder == 1){   
            for(int i = 0; i < numE; i++){
                printf("Student [%d] : ", i+1);
                fflush(stdout);
                fputs(v[i], stdout); 
            }
        }else if(holder == 2){
            printf("\n");
        }else{
            printf("Not supose to happen");
        }
    }

}


void modificarAlumno(char v[MAXALUMNOS][MAXCADENA],char vSupp[MAXSUPPLY][MAXCADENA], short int numE){
    
    int flagIgualeslength = (-1);

    for(int i = 0; i < numE; i++){
        printf("Student [%d] : ", i+1);
        fflush(stdout);
        fputs(v[i],stdout);
    }
    
    printf("\nIntroduce a name to modify .\n");
    printf("::: >> ");
    fflush(stdin);
    //getchar();
    fgets(vSupp[0],MAXCADENA,stdin);
    //fputs(vSupp[0],stdout);

    for(int i = 0; i < numE; i++){        
      if(strcmpi(vSupp[0],v[i]) == 0){
          flagIgualeslength=i;
      }
    }
    //printf("flag %d", flagIgualeslength);
    if(flagIgualeslength >=0){
      printf("Introduce The New Name: ");
      fflush(stdin);
      fgets(vSupp[0],MAXCADENA,stdin);
      strcpy(v[flagIgualeslength],vSupp[0]);
      printf("Done Copying.");
    }else{
      printf("No Name match. Done1");  
    }
}
    