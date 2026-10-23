#include <iostream>
#include <string>
#include <vector>
#include <ctime>

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

void delay_segundos(int segundos) {                                 //funcion de timer
    clock_t inicio = clock();
    while ((clock() - inicio) / CLOCKS_PER_SEC < segundos) {
        
    }
}

