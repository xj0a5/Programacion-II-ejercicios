#include <iostream>
#include <cmath>

int main(void){
    float potencia;
    float equivalente;

    std::cout << "Ingrese la potencia en vatios: \n";
    std::cin >> potencia;
    equivalente = (10 * log10(potencia/0.001 ));
    std::cout << "La potencia equivalente de " << potencia << "W en dBm es: " << equivalente << "dBm\n";

}