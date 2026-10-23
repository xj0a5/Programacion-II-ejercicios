#include <stdio.h>
#include "funciones.h"

int main(void){
    printf("La cadena es \n'Esto es una cadena 1234567' \n");
    char str[27]="Esto es una cadena 1234567";
    int pos;
    char caracter,guardado;
    printf("Ingrese caracter de insercion: ");
    scanf("%c",&caracter);
    printf("Ingrese posicion de insercion: ");
    scanf("%d",&pos);
    guardado= espaciarstr(str,pos,caracter);
    printf("\nSe reemplazo el caracter: %c\n",guardado);

}