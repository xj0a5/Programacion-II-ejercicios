#include <stdio.h>
#include <string.h>

char minus[50],mayus[50];
int n,longitud,i;

int main(void){
    printf("Ingrese una palabra para convertirla en mayuscula\n");
    scanf("%s",minus);

    longitud = strlen(minus);
    for(n;n<longitud;n++){
        i= minus[n]-32;
        mayus[n]=(char)i;
    }
    printf("%s\n",mayus);
}
