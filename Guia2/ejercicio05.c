#include <stdio.h>
#include <string.h>

int tamaño,i,j;

int main(void){
    
    int matriz[3][3];
    int transpuesta[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            matriz[i][j] = (i+2*j)*(i+2*j);
            transpuesta[j][i] = matriz[i][j];
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

printf("---Transpuesta---\n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",transpuesta[i][j]);
        }
        printf("\n");
    }

}