#include <stdio.h>
#include "funciones.h"
#include <stdlib.h>

FILE *lectura;
FILE *proceso;

int main(void){
    int limite;
    lectura=fopen("trafico.txt","r");
    if(lectura == NULL){
                printf("Error: NO SE ENCUENTRA EL ARCHIVO.\n");
                return -1;
            }
    proceso=fopen("errores.log","w");
            if(proceso == NULL){
               printf("Error: NO SE ENCUENTRA EL ARCHIVO.\n");
               fclose(lectura);
               return -2;
            }
    limite = contadorstr("[ERROR]");

    extraerlineas("[ERROR]",lectura,proceso,limite);

    fclose(lectura);
    fclose(proceso);
    return 0;
}