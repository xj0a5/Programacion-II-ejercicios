#include <stdio.h>
#include "funciones.h"

int main(void){
    int a,b;

    printf("Ingrese valor A: \n");
    scanf("%d",&a);
    printf("Ingrese valor B: \n");
    scanf("%d",&b);

    printf("Valores originales: \nA= %d \t B= %d \n",a,b);
    printf("Valores intercambiados por valor(localmente en la función):\n");
    intercambio_valor(a,b);

    printf("Valores intercambiados por puntero(valor global):\n");
    intercambio_puntero(&a,&b);

    printf("Valores despues de las respuestas: \nA= %d \t B= %d \n",a,b);

}