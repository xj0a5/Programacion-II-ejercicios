#include <stdio.h>

int operacion(int a,int b,char x){
    int resultado;
    switch(x){
        case '*':resultado= a * b ;printf("La operación fue: %d * %d \n",a,b);break;
        case '+':resultado= a + b ;printf("La operación fue: %d + %d \n",a,b);break;
        case '-':resultado= a - b ;printf("La operación fue: %d - %d \n",a,b);break;
        case '%':resultado= a % b ;printf("La operación fue: %d %% %d \n",a,b);break;
        case '/':resultado= a / b ;printf("La operación fue: %d/ %d \n",a,b);break;
        default:resultado=0;printf("==EL CARACTER NO ES UN OPERADOR==\n");

    }
    return resultado;
}