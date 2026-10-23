#include <iostream>
#include <string>
#include <vector>
#include <ctime>

struct Sensor
{
int id;
std::string tipo;
double valor;
};

std::string origendestinorandom(void){
    switch(rand() % 3){
        case 0:return "temperatura";
        case 1:return "humedad"; 
        case 2:return "voltaje";
       default: return "voltaje";
    }
}


int main(void){

    srand(time(NULL));
    std::vector<Sensor> Nodos;

    for(int i=0;i<9;i++){
        Sensor celda;
        celda.id = i;
        celda.tipo = origendestinorandom();
        celda.valor = (double(rand()%256));
        Nodos.push_back(celda);
    }
    double valor_t=0,valor_h=0,valor_v=0,suma_t=0,suma_h=0,suma_v=0;
    for(size_t i=0;i<Nodos.size();i++){
        if(Nodos[i].tipo=="temperatura"){
            suma_t++;
            valor_t += Nodos[i].valor;
        }
        if(Nodos[i].tipo=="humedad"){
            suma_h++;
            valor_h += Nodos[i].valor;
        }
        if(Nodos[i].tipo=="voltaje"){
            suma_v++;
            valor_v += Nodos[i].valor;
        }
    }
        double promedio;
        promedio = valor_t / suma_t ;
        std::cout << "El promedio de temperatura es: " << promedio << "C°" << std::endl;
        promedio = valor_h / suma_h ; 
        std::cout << "El promedio de temperatura es: " << promedio << "%" << std::endl;
        promedio = valor_v / suma_v ;
        std::cout << "El promedio de temperatura es: " << promedio << "V" << std::endl;
        return 0;
    }