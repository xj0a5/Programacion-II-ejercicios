#include <stdio.h>

int factorial(int n){
    int resultado=1,i;
    if(n!=0){
        for(i=n; i>0 ; i--){

            resultado *= i;

        }

    }
    else if (n<0){

        printf("No existe el factorial de un número negativo!!! \n");
        resultado=0;
    }
    else{
        resultado=1;
    }
    return resultado;
}