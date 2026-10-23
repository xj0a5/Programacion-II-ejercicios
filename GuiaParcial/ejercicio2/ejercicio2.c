#include <stdio.h>
#include <math.h>

double calcularFSPL(double dis, double frec){
    double resultado;
    resultado = 32.44+20*log10(dis)+20*log10(frec);
    return resultado;
}

double calcularPotenciaRecibida(double p, double g1,double g2, double perdida){
    double resultado;
    resultado = p+g1+g2-perdida;
    return resultado;
}

int main(){
    double distanciaKm = 5.0;
    double frecuenciaMHz = 2400.0;
    double perdida = calcularFSPL(distanciaKm, frecuenciaMHz);
    printf("Perdida por espacio libre: %.2f dB\n", perdida);
    double potenciaRx = calcularPotenciaRecibida(43.0, 15.0, 12.0, perdida);
    printf("Potencia recibida estimada: %.2f dBm\n", potenciaRx);
    return 0;
}