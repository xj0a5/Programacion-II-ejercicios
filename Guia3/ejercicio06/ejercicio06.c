#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(void){
    int dimenmatriz[2];
    int proceso=1;
    int dimenvector;

    tamaniomatriz(dimenmatriz);
    tamaniovector(&dimenvector);

    proceso = verificarmultiplicacion(dimenmatriz[1],dimenvector);
    if(proceso == 1){

        int contenidomatriz[dimenmatriz[0]][dimenmatriz[1]];
        int contenidovector[dimenvector];

        rellenomatriz(dimenmatriz[0],dimenmatriz[1],contenidomatriz);
        imprimirmatriz(dimenmatriz[0],dimenmatriz[1],contenidomatriz);
        rellenovector(dimenvector, contenidovector);
        imprimirvector(dimenvector, contenidovector);
        
        int dimensionresultado;
        
        dimensionresultado= dimenmatriz[0];
        
        int resultado[dimensionresultado];
        
        multiplicacion(dimenmatriz[0],dimenmatriz[1],contenidomatriz,contenidovector,resultado);
        
        printf("===VECTOR RESULTANTE===\n");
        imprimirvector(dimensionresultado, resultado);
    }
    else{
        printf("Error:NO COINCIDEN LAS COLUMNAS CON LA CANTIDAD DE VALORES DEL VECTOR\n");
    }
}