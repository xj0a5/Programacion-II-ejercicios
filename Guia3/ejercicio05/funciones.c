#include <string.h>
#include <stdlib.h>

int convertidor(char x[]){
    int numero;
    numero = atoi(x);
    return numero;
}
void ordenar_burbuja(int *numeros, int posiciones){
    int i,j,auxiliar;

    for(i=0;i<posiciones-1;i++){
        for (j=0;j<posiciones-i-1;j++){
            if(numeros[j] > numeros[j+1]){
                auxiliar = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = auxiliar;
            }
        }
    }
}