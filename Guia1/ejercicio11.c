#include <stdio.h>

int main(void){

    int medicion1,medicion2,medicion3,promedio=0;
    char *tipo;
    printf("Intensidad de señal en dBm\n");
    printf("Ingrese el intensidad 1: ");
    scanf("%d",&medicion1);
    printf("Ingrese el intensidad 2: ");
    scanf("%d",&medicion2);
    printf("Ingrese el intensidad 3: ");
    scanf("%d",&medicion3);

    promedio= (medicion1+medicion2+medicion3)/3;

    if(promedio<=-85){
        tipo= "Debil";
    }
    else if(promedio >=-65){
        tipo= "Fuerte";
    }
    else{
        tipo="Aceptable";
    }

    printf("Promedio: %d dBm -> %s\n", promedio,tipo);

}