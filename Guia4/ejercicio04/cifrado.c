#include <stdio.h>
#include "funciones.h"
#include <stdlib.h>

FILE *lectura;
//FILE *cifrado;

int main(int argc, char *argv[]){

    if(verificar_argc(argc, 3)!=0){
       return 1;
    }

    lectura = fopen(argv[2], "r");
    if(lectura == NULL){
        printf("Error: NO SE ENCUENTRA EL ARCHIVO.\n");
        return -1;
    }

    int iteracion=atoi(argv[1]);
    char lector[100];

    while(fgets(lector, 100, lectura) != NULL){
        int i=0;

        while(lector[i] != '\0'){
            char letra_actual=lector[i];

            if(letra_actual >= 65 && letra_actual <=90){
                int nueva_letra = letra_actual + iteracion;
                if(nueva_letra > 90){
                    nueva_letra= nueva_letra -26;
                }
                printf("%c", nueva_letra);

            }
            else if(letra_actual >=97 && letra_actual <= 122){
                int nueva_letra = letra_actual + iteracion;
                if(nueva_letra > 122){
                    nueva_letra=nueva_letra - 26;
                }
                printf("%c", nueva_letra);
            }
            else{
                printf("%c",letra_actual);
            }
            i++;
        }
    }

    printf("\n");
    fclose(lectura);
    return 0;

}
