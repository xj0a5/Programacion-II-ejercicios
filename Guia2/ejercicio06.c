#include <stdio.h>
#include <string.h>

int main(void){

    int matriz[3][3];
    int i,j,fila,columna;
    int vector[3];
    int resultante[3];
    int transpuesta[3][3];

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("MATRIZ: Ingrese el valor de la fila %d en la columna %d \n",i,j);
            scanf("%d",&fila);
            matriz[i][j] = fila;
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<3;i++){
        printf("Ingrese valor el valor %d del VECTOR de longitud 3\n",i);
        scanf("%d",&vector[i]);
    }
    printf("---MATRIZ---\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("---VECTOR---\n");
    for(i=0;i<3;i++){
        printf("%d ",vector[i]);
    }
    printf("\n ---RESULTADO--- \n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            resultante[i] += matriz[i][j]*vector[j];
            
        }
        printf("%d \n",resultante[i]);
    }
}