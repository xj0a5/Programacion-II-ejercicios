#include <stdio.h>
#include <string.h>

char cadena1[50];
char cadena2[50];
char concatenada[100];
int longitud,c1,c2,n;
int iguales=1; //las cadenas seran iguales si esta variable no se modifica
int main(void){
    printf("Ingrese cadena1\n");
    scanf("%s",cadena1);
    printf("Ingrese cadena2\n");
    scanf("%s",cadena2);
    c1= strlen(cadena1)+1;
    c2= strlen(cadena2)+1;
    printf("La longitud de la cadena(incluyendo el null) es: %d \n",c1);
    printf("La longitud de la cadena(incluyendo el null) es: %d \n",c2);
    if(c1!=c2){
        iguales=0;
    }
     else{
        for(n=0;n<c1;n++){
            if(cadena1[n]!=cadena2[n]){
                iguales=0;
                break;
            }
            }
        }
    if(iguales==1){
        printf("Son iguales las cadenas\n");
    }
    else{
        printf("No son iguales las cadenas\n");
    }
    c1-=1;
    c2-=1;
    for(n=0;c1>0 && c2>0; n++){
        concatenada[n]= cadena1[n];
        concatenada[strlen(cadena1)+n]=cadena2[n];
        c1-= 1;
    }
    printf("%s\n",concatenada);
    strcpy(cadena2,cadena1);
}