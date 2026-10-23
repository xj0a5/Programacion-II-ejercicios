#include <iostream>
#include <vector>
#include <string>

struct NodoRed
{
std::string ip;
int puerto;
bool activo;
};

int main(void){
    std::vector<NodoRed> nodos;
    int i;
    for(i=0;i<5;i++){
        NodoRed celda;
        celda.puerto =rand() % 65535;
        celda.activo = rand() % 2;
        std::cout << "Ingrese su IP: ";
        std::cin >> celda.ip;
        nodos.push_back(celda);
    }
    int aux=0;
    for(i=0;i<5;i++){
        if(nodos[i].activo ==1){
            aux++;
        }
    }

    std::cout << "Los nodos activos son: " << aux << std::endl;

    return 0;
}