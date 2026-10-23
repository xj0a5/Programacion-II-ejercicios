#include <iostream>
#include <ctime>

struct WIFI{
    std::string nombre;
    int canal;
    double frecuencia;
};

int main(void){
    int i=0;
    WIFI nuevared;
    std::cout << "Ingrese el nombre de su red: ";
    std::cin >> nuevared.nombre;
    std::cout << "Ingrese el canal de su red: ";
    std::cin >> nuevared.canal;
    std::cout << "Ingrese la frecuencia de su red(MHz): ";
    while(i==0){
        std::cin >> nuevared.frecuencia;
        if(nuevared.frecuencia < 2400.0 || nuevared.frecuencia > 2485.0){
            std::cout << "Ingrese una frecuencia aceptable: ";
        }else{
            i=1;
        }
    }
    std::cout << "\n\t\t======DATOS DE RED=====\n" << "SSID: " << nuevared.nombre << "\nCanal: " << nuevared.canal << "\nFrecuencia: " << nuevared.frecuencia << "MHz\n";
}
