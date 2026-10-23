#include <iostream>

class Router{
    public:
    
    double potencia;
    double canal;

    Router(double p,double c){
        potencia = p;
        canal = c;
    }
    double getPotencia(){
        return potencia;
    }
    double getCanal(){
        return canal;
    }
};

bool operator==(const Router& a, const Router& b){
    bool beta = false;
    if(a.canal==b.canal){
        if(a.potencia==b.potencia){
            beta = true;
        }
    }
    return beta;
}

int main(void){
    double canal,potencia,canal2,potencia2;
    std::cout << "Ingresar canal: ";
    std::cin >> canal;
    std::cout << "Ingresar potencia: ";
    std::cin >> potencia;
    Router origen(canal,potencia);
    std::cout << "Ingresar canal: ";
    std::cin >> canal2;
    std::cout << "Ingresar potencia: ";
    std::cin >> potencia2;
    Router destino(canal2,potencia2);
    
    if( origen == destino){
        std::cout << "Iguales" << std::endl;
    }
    else{
        std::cout << "Distintos" << std::endl;
    }
    return 0;
}