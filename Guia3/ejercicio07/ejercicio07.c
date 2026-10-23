#include <stdio.h>
#include "funciones.h"

int main(void){
    char x;
    int a,b;
    int resultado;
    printf("Escribir el operador:");
    scanf("%c",&x);
    printf("Escribir el primer numero:");
    scanf("%d",&a);
    printf("Escribir el segundo numero:");
    scanf("%d",&b);
    
    resultado = operacion(a,b,x);

    printf("EL RESULTADO ES: %d \n",resultado);
    
}