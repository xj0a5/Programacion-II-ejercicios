#include <stdio.h>
#include "funciones.h"

int main(void){
    int resultado,n;

    printf("Número para calcular su factorial : ");
    scanf("%d",&n);
    resultado= factorial(n);
    printf("Su factorial es : %d\n",resultado);

}