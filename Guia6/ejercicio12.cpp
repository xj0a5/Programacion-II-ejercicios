#include <iostream>
#include <string>
#include <ctime>
#include <vector>

class Router{
    public:
    
    double potencia;
    double canal;

    Router(double p,double c){
        potencia = p;
        canal = c;
    }
    Router(){
        potencia = 0;
        canal = 0;
    }
    void mostrar(){
        std::cout << "Potencia: " << potencia << "\t|Canal: " << canal << std::endl;
    }
};

class Gabinete{
    public:
    Router router1;
    Router router2;
        
};

class SalaDeEquipos{
    public:
    Gabinete gabineteA;
    Gabinete gabineteB;
    
    void mostrarEstadoTotal() {
        std::cout << "--- GABINETE A ---\n";
        std::cout << "Router 1 - "; 
        gabineteA.router1.mostrar(); 
        std::cout << "Router 2 - "; 
        gabineteA.router2.mostrar();
        
        std::cout << "\n--- GABINETE B ---\n";
        std::cout << "Router 1 - "; 
        gabineteB.router1.mostrar();
        std::cout << "Router 2 - "; 
        gabineteB.router2.mostrar();
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
    SalaDeEquipos posta;
    
    posta.gabineteA.router1.canal=100;
    posta.gabineteA.router1.potencia=1000;
    
    posta.gabineteA.router2.canal=200;
    posta.gabineteA.router2.potencia=2000;
    
    posta.gabineteB.router1.canal=50;
    posta.gabineteB.router1.potencia=500;
    
    posta.gabineteB.router2.canal=300;
    posta.gabineteB.router2.potencia=3000;

    posta.mostrarEstadoTotal();

    return 0;
}