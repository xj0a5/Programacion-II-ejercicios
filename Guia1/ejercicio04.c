#include <stdio.h>

int main(void){

    int numeroa,numerob;
    float resultado;
    char caracter;
    printf("Ingrese un caracter de operador : ");
    scanf("%c", &caracter);
    printf("Ingrese un numero a: ");
    scanf("%d", &numeroa);
    printf("Ingrese el numero b: ");
    scanf("%d", &numerob);
    
    switch(caracter){
        case '+': resultado = numeroa + numerob; printf("El resultado es: %.0f \n",resultado);break;
        case '-': resultado = numeroa - numerob; printf("El resultado es: %.0f \n",resultado);break;
        case '/': resultado = numeroa / numerob; printf("El resultado es: %.2f \n",resultado);break;
        case '*': resultado = numeroa * numerob; printf("El resultado es: %.2f \n",resultado);break;
        case '%': resultado = numeroa % numerob; printf("El resultado es: %.2f \n",resultado);break;
        default:printf("Error: No se reconoce operador aritmetico\n"); return 1;
    }
    return 0;
}