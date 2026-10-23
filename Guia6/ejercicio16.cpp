#include <iostream>
#include <string>
#include <ctime>
#include <vector>

class Sensor{
    private:
    int valorActual;
    std::string id;
    
    public:
    Sensor(int grados,std::string mote){
        valorActual = grados;
        id = mote;
    }
    int getSensor() const{                  //preguntar porque const
        return valorActual;
    }
    std::string getMote() const{
        return id;
    }
    bool rango(int grados){
        bool beta=true;
        if(grados < -45 || grados >85){
            beta=false;
        }
        return beta;
    }
    ~Sensor(){
       std::cout << "Valores del Sensor: " << id <<"\t==Direccion de memoria: "<< this <<"\t===Eliminando===" << std::endl;
    }
};

std::string stringrandom(void){
    switch(rand() % 3){
        case 0:return "MKT";
        case 1:return "Cisco"; 
        case 2:return "Netgear";
       default: return "dios";
    }
}

int main(void){
    srand(time(NULL));
    std::vector<Sensor> Nodos;
    for(int i=0;i<3;i++){
        Sensor celda((rand() % 206) - 80,stringrandom());
        Nodos.push_back(celda);
        //std::cout << Nodos[i].getSensor() << "°C" << std::endl;
        std::cout << "Ciclo: " <<i+1 << std::endl;
    }
    
}