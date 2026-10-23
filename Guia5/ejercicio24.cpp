#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

double perdidaTrayecto(double distancia_km,double frecuencia_Mhz){
    double perdida_dB;
    perdida_dB = 32.44+20*log10(distancia_km)+20*log10(frecuencia_Mhz);
    return perdida_dB;
}

void ultimainstancia(std::vector<double> &distancias,std::vector<double> &ultimainstancia,std::vector<double> &perdidas){
    double mayordistancia=-1;
    int deteccion=-1;
    for(size_t i=0;i<distancias.size();i++){
        if(mayordistancia<distancias[i] && perdidas[i]<120){
            mayordistancia=distancias[i];
            deteccion = i;
        }
    }
    if(deteccion != -1){
        ultimainstancia.push_back(distancias[deteccion]);
        ultimainstancia.push_back(perdidas[deteccion]);
    }
}

int main(void){
    srand(time(NULL));

    std::vector<double> distancias;
    std::vector<double> perdidas;
    std::vector<double> maximadistancia;
    double frecuencia=2400;

    for(int i=0;i<10;i++){
        distancias.push_back(rand() %126);
        perdidas.push_back(perdidaTrayecto(distancias[i],frecuencia));
    }

    ultimainstancia(distancias,maximadistancia,perdidas);
    if(maximadistancia.empty()){
        std::cout << "Ninguna de las conexiones probadas tuvo una perdida menor a 120 dB." << std::endl;
    }else{
        std::cout << "La distancia maxima es: " << maximadistancia[0] << "Km\t Su perdida es de: " << maximadistancia[1] << std::endl;
    }
    return 0;
}