#include <stdio.h>

int verificar_argc(int argc, int limite){
    if(argc != limite){
        printf("Error:Cantidad de argumentos incorrecta\n");
        return 1;
    }
    return 0;
    }