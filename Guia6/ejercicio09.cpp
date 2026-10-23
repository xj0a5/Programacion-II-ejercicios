#include <iostream>

class Router{
    public:
    
    double potencia;
    double canal;

    Router(double p,double c){
        potencia = p;
        canal = c;
    }
    void mostrar(){
        std::cout << "Potencia: " << potencia << "\t|Canal: " << canal << std::endl;
    }
};

class Rack{
    private:
    
    Router r1;
    Router r2;
    Router r3;

    public:

    Rack(double potencia, double canal)
    :   r1(potencia,canal),
        r2(potencia,canal),
        r3(potencia,canal){}

    void mostrarEstado(){
        r1.mostrar();r2.mostrar();r3.mostrar();
    }
};

int main(void){
    double potencia, canal;
    
    std::cout << "Ingrese canal: "<< std::endl;
    std::cin >> canal;
    std::cout << "Ingrese potencia: "<< std::endl;
    std::cin >> potencia;

    Rack Alpha(potencia,canal);

    Alpha.mostrarEstado();
}