#include <stdio.h>
#include "funciones.h"

FILE *lectura;


int main(int argc,char *argv[]){

    if(verificar_argc(argc, 3)!=0){
        return 1;
    }

    char lector[100];
    int limite;

    lectura = fopen(argv[2], "r");

    if(lectura == NULL){
       printf("Error: NO SE ENCUENTRA EL ARCHIVO.\n");
       return -1;
    }

    limite = contadorstr(argv[1]);

    while(fgets(lector, 100, lectura) != NULL){
        int i=0,deteccion=0;
        
        while(lector[i] != '\0' && deteccion==0){
            int j=0,coincidencia=1;

            while(j<limite){
                if(lector[i+j] != argv[1][j]){
                    coincidencia=0;
                    break;
                }
                j++;
            }
            if(coincidencia==1){
                deteccion=1;
            }
            i++;
            }
        if(deteccion == 1){
            printf("%s",lector);
        }

    }
    fclose(lectura);
    printf("\n");
    return 0;
}