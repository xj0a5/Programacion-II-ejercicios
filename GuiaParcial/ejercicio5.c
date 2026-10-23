#include <stdio.h>

/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LAS FUNCIONES QUE FALTAN ====== */
void calcularEstadisticas(double muestras[],int cant, double *promedio, double *peor,double *mejor){
    double menor=muestras[0],mayor=muestras[0],suma=0;
    for(int i = 0;i<cant;i++){
        if(menor > muestras[i]){
            menor=muestras[i];
        }
        suma += muestras[i];
    }
    for(int i=0;i<cant;i++){
        if(mayor < muestras[i]){
            mayor=muestras[i];
        }
    }
    *promedio = suma / cant ;
    *peor = menor;
    *mejor = mayor;
}

int main()
{
    double muestras[] = {-65.0, -70.2, -68.5, -80.1, -72.3};
    int cantidad = 5;
    double promedio, peor, mejor;
    calcularEstadisticas(muestras, cantidad, &promedio, &peor, &mejor);

    printf("Promedio: %.2f dBm\n", promedio);
    printf("Peor caso: %.2f dBm\n", peor);
    printf("Mejor caso: %.2f dBm\n", mejor);
    return 0;
}