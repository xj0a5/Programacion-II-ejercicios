#include <iostream>
#include <cmath>
#include <vector>

double areaCobertura(double radio){
    double area;
    area = M_PI*pow(radio,2);
    return area;
}

double areaCobertura(double potencia, double sensibilidad){
    double margen_dB;
    margen_dB = potencia -sensibilidad;
    double radio;
    radio=margen_dB / 20.0;
    return areaCobertura(radio);
}
struct antenas{
    double potencia;
    double sensibilidad;
};
int main(void){
    std::cout << "Area con radio 5km: " << areaCobertura(5.0) << "\n";
    std::cout << "Area con pot 120 y sens 20: " << areaCobertura(120.0, 20.0) << "\n";
    std::vector<antenas> Nodos;
    std::vector<double> radios;

    for(int i=0;i<10;i++){
        antenas celda;
        celda.potencia = (double(rand()%200));
        celda.sensibilidad = (double(rand()%35));
        Nodos.push_back(celda);
    }

    for(size_t i=0;i<Nodos.size();i++){
        radios.push_back(areaCobertura(Nodos[i].potencia,Nodos[i].sensibilidad));
        std::cout << "Potencia: " << Nodos[i].potencia << "W\t|Sensibilidad: " << Nodos[i].sensibilidad << "dBi\t|Tiene un area de: " << radios[i] << "Km"<<std::endl;
    }
    
    return 0;
}
