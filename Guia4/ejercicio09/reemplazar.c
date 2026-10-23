#include <stdio.h>
#include "funciones.h"

FILE *lectura;
FILE *proceso;

int main(void){
    int limite;

    limite=contadorstr("EST");

    lectura=fopen("estacion.txt","r");
    if(lectura == NULL){
                printf("Error: NO SE ENCUENTRA EL ARCHIVO.\n");
                return -1;
            }
    proceso=fopen("estacion-actualizada.txt","w");
            if(proceso == NULL){
               printf("Error: NO SE ENCUENTRA EL ARCHIVO.\n");
               fclose(lectura);
               return -2;
            }
    

    reemplazopalabra("NODE",lectura,"EST",proceso,limite);
    fclose(lectura);
    fclose(proceso);
    return 0;

}