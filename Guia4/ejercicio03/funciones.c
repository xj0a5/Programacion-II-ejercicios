#include <stdio.h>

int contadorstr(char str[]){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}
int verificar_argc(int argc, int limite){
    if(argc != limite){
        printf("Error:Cantidad de argumentos incorrecta\n");
        return 1;
    }
    return 0;
    }