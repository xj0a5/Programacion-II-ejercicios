#include <iostream>
#include <vector>
#include <string>
#include <ctime>

struct ConfiguracionRouter
{
int canal;
double potencia;
std::string ssid;
};

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

void mensajeerror(std::vector<ConfiguracionRouter> &nodos,std::vector<std::string> &mensaje){
    
    for(size_t i=0;i<nodos.size();i++){
        std::string prefijo = "Nodo [" + std::to_string(i+1) + "] ";
        if(nodos[i].canal>13 || nodos[i].canal<1){
            mensaje.push_back(prefijo + "[Canal-Rango-OUT]");
        }
        if(nodos[i].potencia>30 || nodos[i].potencia<0){
            mensaje.push_back(prefijo + "[Potencia-Rango-OUT]");
        }
        if(nodos[i].ssid.empty()){
            mensaje.push_back(prefijo + "[SSID-ANY%]");
        }
    }   
}

int main(void){
    srand(time(NULL));

    std::vector<ConfiguracionRouter> Nodos;
    std::vector<std::string> mensaje;

    for(int i=0;i<10;i++){
        ConfiguracionRouter celda;
        celda.canal = rand() %25;
        celda.potencia = rand() %70;
        if(rand()%2){
            celda.ssid =  origendestinorandom();
        }
        Nodos.push_back(celda);
    }

    mensajeerror(Nodos,mensaje);

    for(size_t i=0;i<mensaje.size();i++){
        std::cout << mensaje[i] << std::endl;
    }
    return 0;
}