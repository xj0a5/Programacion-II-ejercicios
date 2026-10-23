#include <stdio.h>
#include <string.h>
int main(void){
    char letra;
    printf("Ingrese una letra para ver su codigo en ASCII\n");
    scanf("%c",&letra);
    printf("La letra %c tiene un codigo ASCII=%d\n",letra,letra);
}