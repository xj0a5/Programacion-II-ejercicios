#include <string.h>
#include <stdio.h>

char espaciarstr(char str[],int pos, char caracter){
    char guardado;

    guardado = str[pos];
    str[pos] = caracter;
    printf("%s",str);
    return guardado;
}