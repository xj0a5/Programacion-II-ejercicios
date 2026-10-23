#include <iostream>
#include <string>
#include <ctime>

class Dispositivo{
    public:
    std::string Nombre;
    std::string Fabricante;

    Dispositivo(){
        Nombre = "Vacio";
        Fabricante = "Vacio";
    }
    Dispositivo(std::string mote, std::string fabri){
        Nombre = mote;
        Fabricante = fabri;
    }
    void virtual mostrarDatos(){
        std::cout << "Nombre: " << Nombre << "\t|Fabricante: " << Fabricante << std::endl;
    }
};

class Modem:public Dispositivo{
    public:
    double VelocidadMbps;

    Modem(std::string mote, std::string fabri,double velocidad): Dispositivo(mote, fabri){
        VelocidadMbps= velocidad;
    }

    void mostrarDatos() override{
    std::cout << "Nombre: " << Nombre << "\t|Fabricante: " << Fabricante << "\t|Velocidad en Mbps: "<<VelocidadMbps <<std::endl;
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
    Modem LabRedes("Labredes",stringrandom(),rand()%200 +100);
    LabRedes.mostrarDatos();
}