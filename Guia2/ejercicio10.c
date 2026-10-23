#include <stdio.h>
#include <string.h>
//DATOS : DESDE EL 97 AL 122 SON MINUSCULAS -32 LA CONVIERTE EN MAYUS

int main(void){
    char minus[50],mayus[50];
    int n,longitud,i;

    printf("Ingrese nombre de la estación: \n");
    fgets(minus, sizeof(minus), stdin);

    longitud = strlen(minus);

    for(i=0;i<longitud;i++){
            if(minus[i]>96 && minus[i]<123){
                n=minus[i]-32;
                mayus[i]=(char)n;
            }
            else{
                mayus[i] = minus[i];
            }
        }
    printf("%s\n",mayus);
}