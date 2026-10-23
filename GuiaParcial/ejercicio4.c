#include <stdio.h>
#include <math.h>

double calcularEIRP(double pot, double g){
    double resultado;
    resultado = pot + g;
    return resultado;
}

double calcularFSPL(double dis, double frec){
    double r;
    r= 32.44+20*log10(dis)+20*log10(frec);
    return r;
}

double calcularPotenciaRx(double eirp, double g, double perd){
    double r;
    r = eirp + g - perd;
    return r;
}

double calcularMargen(double pot, double sensi){
    double r;
    r= pot - sensi;
    return r;
}

int main() {
    double eirp = calcularEIRP(43.0, 15.0);
    double perdida = calcularFSPL(5.0, 2400.0);
    double potenciaRx = calcularPotenciaRx(eirp, 12.0, perdida);
    double margen = calcularMargen(potenciaRx, -95.0);
    printf("EIRP: %.2f dBm\n", eirp);
    printf("Perdida FSPL: %.2f dB\n", perdida);
    printf("Potencia Rx: %.2f dBm\n", potenciaRx);
    printf("Margen de enlace: %.2f dB\n", margen);

return 0;
}