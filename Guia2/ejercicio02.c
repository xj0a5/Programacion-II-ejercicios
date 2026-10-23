#include <stdio.h>
#include <string.h>

char palabra[50];
char invertida[50];
int longitud,n,i;

int main(void){
    printf("Ingrese una palabra sin espacios\n");
    scanf("%s",palabra);

    longitud = strlen(palabra);
    i = 0;
    
    for(n;longitud>0;n++){
        invertida[i] = palabra[longitud-1];
        longitud -= 1;
        i += 1;
    }

    printf("%s\n",invertida);

}