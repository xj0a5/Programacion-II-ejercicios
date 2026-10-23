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
    
    if(caracter == '+'){
        
        resultado = numeroa + numerob;
        printf("El resultado es %2.f \n",resultado);

    }
    else if(caracter == '-'){
    
        resultado = numeroa - numerob;
        printf("El resultado es %2.f \n",resultado);

    }
    else if(caracter == '*'){
    
        resultado = numeroa * numerob;
        printf("El resultado es %2.f \n",resultado);

    }
    else if(caracter == '/'){
    
        resultado = numeroa / numerob;
        printf("El resultado es %2.f \n",resultado);

    }
    else if(caracter == '%'){
        resultado = numeroa % numerob;
        printf("El resultado es %2.f \n",resultado);
    }
    else{
        printf("Error: No se reconoce operador aritmetico\n");
        return 1;
    }
    return 0;
}