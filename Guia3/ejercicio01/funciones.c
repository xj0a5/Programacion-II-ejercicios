#include <stdio.h>

void intercambio_valor(int a,int b){
    int auxiliar;
    auxiliar = a;
    a = b;
    b= auxiliar;
    printf("A= %d\t B= %d\n",a,b);

}
void intercambio_puntero(int *a, int *b){
    int auxiliar;
    auxiliar = *a;
    *a = *b;
    *b = auxiliar;
    printf("A= %d\t B= %d\n",*a,*b);
}