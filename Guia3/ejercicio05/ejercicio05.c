#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char *argv[]){
    //int orden[5];
    //int resultado[1];
    int numeros[10],i;

    for(i=0;i<argc-1;i++){
        numeros[i]=convertidor(argv[i+1]);
        printf("%d ",numeros[i]);
    }
    ordenar_burbuja(numeros, argc-1);
    printf("Numeros ordenados: ");
    for(i = 0; i < argc-1; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    


}