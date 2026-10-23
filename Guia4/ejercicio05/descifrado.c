#include <stdio.h>
#include "funciones.h"
#include <stdlib.h>

FILE *lectura;
FILE *descifrado;

int main(int argc, char *argv[]){

    if(verificar_argc(argc, 3)!=0){
        return 1;
    }

    lectura = fopen(argv[2], "r");
    if(lectura == NULL){
        printf("Error: NO SE ENCUENTRA EL ARCHIVO.\n");
        return -1;
    }

    descifrado=fopen("archivo_descifrado.txt","w");
    int iteracion=atoi(argv[1]);
    char lector[100];

    while(fgets(lector, 100, lectura) != NULL){
    int i=0;

    while(lector[i] != '\0'){
            char letra_actual=lector[i];

            if(letra_actual >= 65 && letra_actual <=90){
                int nueva_letra = letra_actual - iteracion;
                if(nueva_letra < 65){
                    nueva_letra= nueva_letra +25;
                }
                fprintf(descifrado,"%c", nueva_letra);

            }
            else if(letra_actual >=97 && letra_actual <= 122){
                int nueva_letra = letra_actual - iteracion;
                if(nueva_letra < 97){
                    nueva_letra=nueva_letra + 26;
                }
                fprintf(descifrado,"%c", nueva_letra);
            }
            else{
                fprintf(descifrado,"%c",letra_actual);
            }
            i++;
        }
    }

    fprintf(descifrado,"\n");
    fclose(lectura);
    fclose(descifrado);
    return 0;    
}