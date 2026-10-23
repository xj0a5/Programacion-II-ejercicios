#include <iostream>

class Bateria{
    public:
    double voltaje;
    double capacidadAh;
    Bateria(){
        voltaje= 0;
        capacidadAh= 0;
    }
    Bateria(double tension,double amperhora){
        voltaje = tension;
        capacidadAh = amperhora;
    }
    void mostrar(){
        std::cout << "Voltaje: " << voltaje << "\nCapacidad: " << capacidadAh << std::endl;
    }
};


int main(void){

    srand(time(NULL));

    Bateria duracell;
    Bateria moura((double(rand()%20)),(double(rand()%1000 + 1000)));
    duracell.mostrar();
    moura.mostrar();
    return 0;
}