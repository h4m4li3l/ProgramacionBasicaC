#ifndef __LLIBRERIAPROPIA_H__
#define __LLIBRERIAPROPIA_H__
    
    int pedirNumEntreRango(int minimo, int maximo, int *num);
    int saludoEspecial(int num);
    int pintaTablaMultiplicar(int num);
    void inicializaVector(int v[], int numE);
    void pintaVector(int v[], int numE);
    float mediaArray(int v[], int numE);
    int pedirNumero(int *num);
    void intercambioVariables (int *num1, int *num2);
    void combinacionUsuario( int *usu1, int *usu2, int min, int max);
    void combinacionGanadora(int *pc1, int *pc2);
    int calculaAciertos(int pc1, int pc2, int usu1, int usu2, int vect[]);
#endif
