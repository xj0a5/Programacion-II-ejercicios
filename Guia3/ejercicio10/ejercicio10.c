#include <stdio.h>
#include "funciones.h"

int main(void){
    int a;
    double resultado,auxiliar;
    printf("\t===MENU===\n1_Conversion de dBm a Watts\n2_Clasificacion de señal\n3_Convertir Watts a dBm y clasificar la señal obtenida\n4_Salir\nSeleccione una opcion:");
    scanf("%d",&a);
    switch(a){
        case 1:printf("Ingrese valor: ");scanf("%lf",&auxiliar);resultado = dbm_a_watts(auxiliar);printf("El resultado es: %f W\n",resultado);break;
        case 2:printf("Ingrese valor: ");scanf("%lf",&auxiliar);mostrar_clasificacion(auxiliar);break;
        case 3:printf("Ingrese valor: ");scanf("%lf",&auxiliar);resultado = watts_a_dbm(auxiliar);printf("El resultado es: %f dBm\n",resultado);mostrar_clasificacion(resultado);break;
        case 4:break;
        default:printf("Elija una opcion válida\nEjecute otra vez el programa\n");
    }
}