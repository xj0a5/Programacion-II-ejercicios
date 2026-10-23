#include <stdio.h>
#include <math.h>
/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LAS FUNCIONES QUE FALTAN ====== */
const int anchodebanda= 20;

int validarCanal(int canal){
    int beta = 1;
    if(canal<1 ||canal>13){
        beta= 0;
    }
    return beta;
}

double calcularFrecuenciaCentral(int canal){
    double r;
    r = 2412 + (canal-1)*5;
    return r;
}

int canalesSolapados(int canalA,int canalB){
    int beta=0;
    double distancia = calcularFrecuenciaCentral(canalA) - calcularFrecuenciaCentral(canalB);
    if(distancia<0){distancia = distancia*(-1);}
    if(distancia < anchodebanda){
        beta=1;
    }
    return beta;
}
int main(){

    int canal = 6;
    int valido = validarCanal(canal);
    double frecCentral = calcularFrecuenciaCentral(canal);

    printf("Canal %d: %s\n", canal, valido ? "valido" : "invalido");
    printf("Frecuencia central: %.2f MHz\n", frecCentral);
    printf("Canal 14: %s\n", validarCanal(14) ? "valido" : "invalido");
    printf("Canales 1 y 6: %s\n", canalesSolapados(1, 6) ? "se solapan" : "no se solapan");
    printf("Canales 1 y 4: %s\n", canalesSolapados(1, 4) ? "se solapan" : "no se solapan");
    return 0;
}