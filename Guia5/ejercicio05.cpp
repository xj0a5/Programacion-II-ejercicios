#include <iostream>

double mbpsAKbps(double mbps){
    double kbps;
    kbps = (mbps/8)*1000;
    return kbps;
}

double tiempoDescargaSeg(double tamanioMB,double velocidadMbps){
    double tiempo;
    tiempo = tamanioMB / velocidadMbps;
    return tiempo;
}
int main(void){
    double tamanio,velocidad;
    
    std::cout << "Ingrese su velocidad de bajada Mbps: ";
    std::cin >> velocidad;
    std::cout << "Ingrese el tamaño de su archivo(Mb): ";
    std::cin >> tamanio; 
    tamanio = tamanio * 8;
    std::cout << "Su velocidad equivalente a Kbps es: " << mbpsAKbps(velocidad) << "\nTiempo de descarga: " << tiempoDescargaSeg(tamanio,velocidad) << " segundos\n";

    return 0;
}