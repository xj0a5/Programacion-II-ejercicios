#include <stdio.h>

int main(void){

    int numero,resto;
    printf("Ingrese un número: ");
    scanf("%d", &numero);
    resto = numero % 2;
    if(resto==0){
        printf("El número es par\n");
    }
    else{
        printf("El número es impar\n");
    }
    return 0;
}