#include <stdio.h>

int main(void){
    float celsius;

    printf("Ingrese cantidad de grados[CELSIUS] \n");
    scanf("%f", &celsius);

    if(celsius<=0){

        printf("El agua esta en estado SOLIDO(Hielo)\n");

        return 1;                                               //por lo general se usa return 0 si el programa se ejecuto correctamente
    }
    else if(celsius >= 100){

        printf("El agua esta en estado GASEOSO(Vapor)\n");

        return 2;
    }
    else{

        printf("El agua esta en estado LIQUIDO\n");

        return 0;
    }
}