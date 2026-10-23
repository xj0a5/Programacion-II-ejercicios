#include <iostream>
#include <vector>
#include <string>
#include <ctime>

struct Red{
    std::string ssid;
    std::string ip;
};

std::string crearIp(){
    int octeto4 = 2+(rand() % 253);

    std::string ip = "192.168.1." + std::to_string(octeto4);
    return ip;
}

std::vector<std::string> listaIp(int cantidad){
    std::vector<std::string> lista;
    int i;
    for(i=0;i<cantidad;i++){
        lista.push_back(crearIp());
    }
    return lista;
}




int main(void){
    int i;

    srand(time(NULL));      //random mas random

    std::vector<Red> redes;

    for(i=0;i<10;i++){                              //funcion para crear datos random
        Red celda;
        celda.ip = crearIp();
        celda.ssid = "Red #" + std::to_string(i+1); 
        if(rand()%2 == 1){
            celda.ssid += " invitado";
        }
        redes.push_back(celda);
    }

    int contador=0;
    int limite = redes.size();
    for(i=0;i<limite;i++){
        if(redes[i].ssid.find("invitado")!= std::string::npos){
            std::cout << "SSID: " << redes[i].ssid << " | IP: " << redes[i].ip << "\n";
            contador++;
        }
    }

    std::cout << "\nTotal de redes de invitados: " << contador << "\n";

    return 0;
}
