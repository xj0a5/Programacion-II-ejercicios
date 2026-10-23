#include <stdio.h>
#include <string.h>

int main(void){

    int vector1[5],vector2[5];
    int resultante[5];
    int *puntero;
    int i;
    puntero = &vector1[0];
    for(i=0;i<5;i++){
        printf("Escriba el valor N° %d, del vector 1 \n",i);
        scanf("%d",puntero);
        puntero += 1 ;
    }
    puntero = &vector2[0];
    for(i=0;i<5;i++){
        printf("Escriba el valor N° %d, del vector 2 \n",i);
        scanf("%d",puntero);
        puntero += 1 ;
    }
    printf("---VECTOR RESULTANTE---\n");
    puntero = &resultante[0];
    for(i=0;i<5;i++){
        *puntero = vector1[i]+vector2[i] ;
        puntero += 1 ;
        printf("%d ",resultante[i]);
    }
    printf("\n");
}