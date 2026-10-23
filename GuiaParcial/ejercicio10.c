#include <stdio.h>
#include <math.h>

/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LAS FUNCIONES QUE FALTAN ====== */
void analizarEnlace(double Tx,double Gtx,double Grx,double dis,double frec,double sensi,double *eirp,double *perdida,double *pot_rx, double *margen){
    *eirp = Tx + Gtx;
    *perdida = 32.44 + 20*log10(dis)+20* log10(frec);
    *pot_rx = *eirp + Grx-*perdida;
    *margen = *pot_rx - sensi;
}
const char *evaluarEnlace(double margen){
    if(margen <= 0){return "No viable";}
    else if(margen >0 && margen <= 10){
        return "Marginal";
    }
    else if(margen>10 && margen <= 20){
        return "Bueno";
    }else{
        return "Excelente";
    }
}

double dbmAWatts(double pot_e){
    double result;
    result = pow(10,pot_e / 10) / 1000;
    return result;
}
int main() {
    double eirp, perdida, potenciaRx, margen;
    analizarEnlace(43.0, 15.0, 12.0, 5.0, 2400.0, -95.0,
    &eirp, &perdida, &potenciaRx, &margen);

    printf("=== ANALISIS DE ENLACE ===\n");
    printf("EIRP: %.2f dBm\n", eirp);
    printf("Perdida FSPL: %.2f dB\n", perdida);
    printf("Potencia Rx: %.2f dBm\n", potenciaRx);
    printf("Margen: %.2f dB\n", margen);
    const char *evaluacion = evaluarEnlace(margen);
    printf("Evaluacion: %s\n", evaluacion);

    double potenciaRxWatts = dbmAWatts(potenciaRx);
    printf("Potencia Rx en Watts: %.3e W\n", potenciaRxWatts);

    return 0;
}