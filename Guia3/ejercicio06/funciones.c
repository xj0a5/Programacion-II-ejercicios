#include <stdio.h>

int verificarmultiplicacion(int a,int b){
    if(a!=b){
        printf("===ERROR:LAS COLUMNAS DE LA MATRIZ DEBEN COINCIDIR CON EL VECTOR===\n");
        return 0;
    }
    else{
        return 1;
    }
}
void tamaniomatriz(int *m){
    int i,j;
    printf("Ingrese tamaño de filas: ");
    scanf("%d",&i);
    printf("Ingrese tamaño de columnas: ");
    scanf("%d",&j);
    m[0] = i;
    m[1] = j;
}
void rellenomatriz(int filas, int columnas, int matriz[filas][columnas]){
    int i,j;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            printf("Ingrese valor de la fila %d en la columna %d :",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }

}
void tamaniovector(int *v){
    int i;
    printf("Ingrese cantidad de valores del vector: ");
    scanf("%d",&i);
    *v=i;

}
void rellenovector(int dimension, int *v){
    int i;
    for(i=0;i<dimension;i++){
        printf("Ingrese el valor %d del vector:",i);
        scanf("%d",&v[i]);

    }
}
void imprimirmatriz(int filas, int columnas, int matriz[filas][columnas]) {
    printf("\n=====Matriz======\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            
            printf("%d\t", matriz[i][j]); 
        }
        printf("\n");
    }
    printf("\n");
}
void imprimirvector(int dimension, int *v) {
    printf("\n=====Vector=====\n");
    
    for (int i = 0; i < dimension; i++) {
        printf("%d\n", v[i]); 
    }
    printf("\n");
}
void multiplicacion(int filas, int columnas, int matriz[filas][columnas],int vector[],int *resultado){
    int i,j;
    for(i=0;i<filas;i++){
        resultado[i]=0;
        for(j=0;j<columnas;j++){

            resultado[i] += matriz[i][j]*vector[j];

        }
    }
}