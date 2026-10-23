#include <iostream>
#include <vector>

struct EstacionCercana
{
std::string nombre;
double rssi;
};

void menordistancia(std::vector<EstacionCercana> &estacion,std::vector<EstacionCercana> &cercana){
    int i=0;
    int deteccion=0;
    double mayor=estacion[i].rssi;
    for(size_t i=1;i<estacion.size();i++){
        if(mayor < estacion[i].rssi){
            mayor=estacion[i].rssi;
            deteccion=i;
        }
    }
    cercana.push_back(estacion[deteccion]);   
}

std::string origendestinorandom(void){
    switch(rand() % 4){
        case 0:return "Argentina";
        case 1:return "Brasil"; 
        case 2:return "Chile";
        case 3:return "Uruguay";
        case 4:return "Paraguay";
       default: return "Bolivia";
    }
}

int main(void){

    srand(time(NULL));
    std::vector<EstacionCercana> Nodos;
    std::vector<EstacionCercana> MasCercana;
    for(int i=0;i<4;i++){
        EstacionCercana celda;
        celda.nombre = origendestinorandom();
        celda.rssi = (double(rand()%100 -100));
        Nodos.push_back(celda);
    }   
    
    menordistancia(Nodos,MasCercana);

    std::cout << "La menor distancia la tiene el NODO #" << MasCercana[0].nombre << " \t Su potencia es: "<< MasCercana[0].rssi << "dBm" << std::endl; 
    return 0;
}