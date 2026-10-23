#include <stdio.h>

int main(void){

    int num,sumatoria=0,cantidad=0;
    while(num!=0){

        printf("Ingrese un número: ");
        scanf("%d",&num);
        sumatoria += num;
        if(num>0){
            cantidad +=1;
        }

    }
    printf("El Resultado de la sumatoria es : %d\nLa cantidad de números mayores que 0 ingresó es: %d\n",sumatoria,cantidad);
}