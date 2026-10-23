#include <stdio.h>

/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LAS FUNCIONES QUE FALTAN ====== */
int clasificarRSSI(double rssi){
    int cat;
    if(rssi > -60){
        cat=4;
    }else if(rssi>-75 && rssi <=-60){
        cat = 3;
    }else if (rssi > -90 && rssi <=-75){
        cat = 2;
    }else if(rssi <= -90){
        cat=1;
    }else{
        cat=0;
    }
    return cat;
}

const char *descripcionCalidad(int cali){
    switch (cali)
    {
    case 4:return "Excelente";
    case 3:return "Buena";
    case 2:return "Debil";
    case 1:return "Sin senal util";
    default:return "desconocido";
    }
}

int main() {
    double rssi = -68.5;

    int calidad = clasificarRSSI(rssi);
    printf("RSSI: %.1f dBm -> Calidad: %d\n", rssi, calidad);
    const char *descripcion = descripcionCalidad(calidad);
    printf("Descripcion: %s\n", descripcion);
    return 0;
}