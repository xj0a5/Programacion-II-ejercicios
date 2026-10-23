#include <stdio.h>

FILE *lectura;

int main(void){
    char archivo[100],lector[100];
    printf("Ingrese el nombre del archivo(INCLUYA LA EXTENSION): ");
    scanf("%s",archivo);

    lectura = fopen(archivo, "r");
    if(lectura == NULL){
        printf("Error: NO SE ENCUENTRA EL ARCHIVO.\n");
        return -1;
    }
    while(fgets(lector, 100, lectura) != NULL){
        printf("%s", lector);
    }
    fclose(lectura);
    printf("\n");
    return 0;
}