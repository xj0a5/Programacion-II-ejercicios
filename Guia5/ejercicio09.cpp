#include <iostream>
#include <cmath>

double calcularPotenciadBm(double potencia){
    double potenciadbm;
    potenciadbm=10*log10(potencia/0.001);
    return potenciadbm;
}

double calcularPotenciadBm(double tension,double impedancia){
    double potencia;
    double potenciadbm;
    potencia = (tension*tension)/impedancia;
    potenciadbm = calcularPotenciadBm(potencia);
    return potenciadbm;
}

int main(void){
    double potencia,impedancia,tension;
    int opcion;
    std::cout << "\t\t=====INGRESE UNA OPCION=====\n1-Potencia en dBm con solo potencia\n2-Potencia en dBm con tension e impedancia\n";
    std::cin >> opcion;
    switch(opcion){
        case 1:{
            std::cout << "Ingrese valor de la potencia del audio: ";
            std::cin >> potencia;
            potencia = calcularPotenciadBm(potencia);
            std::cout << "Su potencia es: " << potencia << "dBm\n";
            break;
        }
        case 2:
            std::cout << "Ingrese valor de la tension: ";
            std::cin >> tension;
            std::cout << "Ingrese valor de la impedancia: ";
            std::cin >> impedancia;
            potencia = calcularPotenciadBm(tension,impedancia);
            std::cout << "Su potencia es: " << potencia << "dBm\n";
            break;
        default: break;
    }
    return 0;
}