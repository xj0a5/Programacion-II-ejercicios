#include <iostream>
#include <vector>
#include <cmath>

double perdidaTrayecto(double distancia_km,double frecuencia_Mhz){
    double perdida_dB;
    perdida_dB = 32.44+20*log10(distancia_km)+20*log10(frecuencia_Mhz);
    return perdida_dB;
}

double perdidaTrayecto(double distancia_km,double frecuencia_Mhz,int n){
    double perdida_dB;
    perdida_dB= perdidaTrayecto(distancia_km, frecuencia_Mhz) +10*n*log10(distancia_km);
    return perdida_dB;
}

int main(void){
    double distancia,frecuencia,n,resultado;

    std::cout << "Ingrese la distancia(Km): " ;
    std::cin >> distancia;
    std::cout << "Ingrese la frecuencia(MHz): " ;
    std::cin >> frecuencia;
    resultado = perdidaTrayecto(distancia,frecuencia);
    std::cout << "La perdida de potencia es : " << resultado << "dB\n";
    std::cout << "Ingrese valor de n: " ;
    std::cin >> n;
    resultado = perdidaTrayecto(distancia,frecuencia,n);
    std::cout << "La perdida de potencia es : " << resultado << "dB\n";
}