#include <math.h>
#include <stdio.h>

float watts_a_dbm(float a){
    float dbm;
    dbm = 10 * log10(a*1000);
    return dbm;
}
float dbm_a_watts(float a){
    float watts;
    watts= pow(10, a/10.0) / 1000 ;
    return watts;
}

void mostrar_clasificacion(float dbm){
    printf("Señal ");
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