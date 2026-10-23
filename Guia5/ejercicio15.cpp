#include <iostream>
#include <vector>
#include <string>
#include <ctime>

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

struct Paquete{
    std::string origen;
    std::string destino;
    int bytes;
    bool exitoso;
};

int main(void){
    int i,aux=0;

    srand(time(NULL));      //random mas random

    std::vector<Paquete> Datos;

    for(i=0;i<8;i++){
        Paquete celda;
        celda.origen = origendestinorandom();
        celda.destino = origendestinorandom();
        celda.bytes = rand() %256;
        celda.exitoso = rand() %2;
        Datos.push_back(celda);
    }

    for(i=0;i<8;i++){
        if(Datos[i].exitoso==true){
            aux++;
        }
    }

    int total=Datos.size();
    int porcentaje= (aux*100)/total;
    std::cout << "El " << porcentaje << "% del total de paquetes a llegado con éxito \n";
    return 0;
}