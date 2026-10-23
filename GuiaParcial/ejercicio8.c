#include <stdio.h>
#include <math.h>

/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LAS FUNCIONES QUE FALTAN ====== */

double dBmaW(double dBm){
    double r;
    r= pow(10,dBm/10)/1000;
    return r;
}
double wattsADbm(double w){
    double r;
    r = 10*log10(w*1000);
    return r;
}
double sumarPotencias(double potencias[],int cant){
    double suma=0;
    for(int i=0;i<cant;i++){
        suma += potencias[i];
    }
    double pot_w=dBmaW(suma);
    return pot_w;
}
int main(){
    
    double potenciasDbm[] = {10.0, 13.0, 16.0};
    int cantidad = 3;
    double potenciaTotalWatts = sumarPotencias(potenciasDbm, cantidad);
    double potenciaTotalDbm = wattsADbm(potenciaTotalWatts);

    printf("Potencia total: %.4f W\n", potenciaTotalWatts);
    printf("Potencia total: %.2f dBm\n", potenciaTotalDbm);

    return 0;
}