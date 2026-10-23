#include <stdio.h>

int main(void){

    float latencia1,latencia2,latencia3,promedio;
        printf("Ingrese latencia 1 (ms): ");
        scanf("%f",&latencia1);
        printf("Ingrese latencia 1 (ms): ");
        scanf("%f",&latencia2);
        printf("Ingrese latencia 2 (ms): ");
        scanf("%f",&latencia3);
        
        promedio = (latencia1+latencia2+latencia3)/3;

        printf("Latencia promedio: %.2f ms\n",promedio);
        if(promedio>=150){
            printf("Conexion inestable\n");
        }
        else{
            printf("Conexion estable\n");
        }
}