#include <stdio.h>

void mostrar_clasificacion(float dbm){
    if(dbm>-60){
        printf("Excelente\n");
    }
    else if(dbm>-75 && dbm<=-60){
        printf("Buena\n");
    }
    else if(dbm > -90 && dbm<=-75){
        printf("Debil\n");
    }
    else{
        printf("Sin senal\n");
    }
}