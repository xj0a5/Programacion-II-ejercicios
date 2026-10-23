#include <stdio.h>

FILE *lectura;
FILE *escritura;

int main(int argc,char *argv[]){

    char lector[100];

    lectura = fopen(argv[1], "r");
    escritura = fopen(argv[2], "w");

    if(lectura == NULL){
       printf("Error: NO SE ENCUENTRA EL ARCHIVO DE ORIGEN.\n");
       return -1;
    }

    if(escritura == NULL){
       printf("Error: NO SE ENCUENTRA EL ARCHIVO DE DESTINO.\n");
       return -2;
    }
    while(fgets(lector, 100, lectura) != NULL){
        fprintf(escritura, "%s", lector);
    }

    fclose(lectura);
    fclose(escritura);

    printf("si se copio \n");
    return 0;
}