#include <iostream>
#include <ctime>
#include <vector>

class Sensor{
    private:
    int valorActual;
    
    public:
    Sensor(int grados){
        valorActual = grados;
    }
    int getSensor() const{                  //preguntar porque const
        return valorActual;
    }
    bool rango(int grados){
        bool beta=true;
        if(grados < -45 || grados >85){
            beta=false;
        }
        return beta;
    }
};
bool operator>(const Sensor& a, const Sensor& b){
    bool beta=false;
    if(a.getSensor() > b.getSensor()){
        beta=true;
    }
    return beta;
    }

int main(void){
    srand(time(NULL));
    std::vector<Sensor> Nodos;
    for(int i=0;i<3;i++){
        Sensor celda((rand() % 206) - 80);
        Nodos.push_back(celda);
        std::cout << Nodos[i].getSensor() << "°C" << std::endl;
    }
    if(Nodos[0] > Nodos[1] && Nodos[0] > Nodos[2]){
        std::cout << "La mayor temperatura es: " << Nodos[0].getSensor() << std::endl;
    }else if(Nodos[1]>Nodos[2]){
        std::cout << "La mayor temperatura es: " << Nodos[1].getSensor() << std::endl;
    }else{
        std::cout << "La mayor temperatura es: " << Nodos[2].getSensor() << std::endl;
    }
}