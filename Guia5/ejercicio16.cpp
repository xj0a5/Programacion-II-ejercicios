#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

struct Ruta{
    std::string destino;
    std::string gateway;
    int metrica;
};
std::string crearIpgw(){
    int octeto4 = 2+(rand() % 253);

    std::string ip = "192.168." + std::to_string(octeto4);
    ip += ".1";
    return ip;
}
std::string crearIp(){
    int octeto4 = 2+(rand() % 253);

    std::string ip = "192.168.1." + std::to_string(octeto4);
    return ip;
}


int main(void){
    int i;
    srand(time(NULL)); //mas random

    std::vector<Ruta> mapeo;

    for(i=0;i<4;i++){
        Ruta celda;
        celda.destino = crearIp();
        celda.gateway = crearIpgw();
        celda.metrica = rand() %4;
        mapeo.push_back(celda);       
    }

    std::ofstream archivo_s("Ruteo.txt");
    if (!archivo_s.is_open()) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return 1; 
    }
    int limite = mapeo.size();

    for(i=0;i<limite;i++){
        archivo_s << "Destino: " << mapeo[i].destino << " \t|GW: " << mapeo[i].gateway << "\t|Metrica: " << mapeo[i].metrica << "\n";
    }

    archivo_s.close();

    std::ifstream archivo_e("Ruteo.txt");
    if (!archivo_e.is_open()) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return 1; 
    }

    std::string lector;

    while(std::getline(archivo_e,lector)){
        std::cout << lector << "\n";
    }
    archivo_e.close();
    return 0;
}