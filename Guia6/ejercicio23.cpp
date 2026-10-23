#include <iostream>
#include <vector>
#include <ctime>
#include <string>

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
};

class DispositivoRed: public Dispositivo{

    protected:

    bool activo;

    public:

    DispositivoRed(std::string mote,std::string fabri, bool estado):Dispositivo(mote,fabri),activo(estado){};
    void virtual mostrarInfo(){
        std::cout << "Nombre: " << Nombre << "\t|Fabricante: " << Fabricante << "\t|Estado: " << activo;
    }
    double virtual costoMantenimientoAnual(){return 0.0;}
};
class Router:public DispositivoRed{
    public:
    
    double potencia;

    Router(std::string mote,std::string fabri, bool estado,double pot):DispositivoRed(mote,fabri,estado),potencia(pot){};

    void mostrarInfo()override{
        DispositivoRed::mostrarInfo();
        std::cout << "\t|Potencia: " << potencia << "Ghz"<< "\t|Resultado: "<< costoMantenimientoAnual()<< std::endl;
    }
    double costoMantenimientoAnual() override{
        double resultado;
        resultado= potencia * 2.5;
        return resultado;
    }
};

class Switch:public DispositivoRed{
    
    private:
    double puertos;
    
    public:

    Switch(std::string mote,std::string fabri,bool estado,double puerto):DispositivoRed(mote,fabri,estado),puertos(puerto){}

    void mostrarInfo()override{
        DispositivoRed::mostrarInfo();
        std::cout << "\t|Puertos: " << puertos << "\t|Resultado: "<< costoMantenimientoAnual() << std::endl;
    }
    double costoMantenimientoAnual() override{
        double resultado;
        resultado= puertos * 3;
        return resultado;
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

    std::vector<DispositivoRed*> Nodos;

    Nodos.push_back(new Router("LabRedes",stringrandom(),rand()%2,2.4));
    Nodos.push_back(new Switch("Alfa",stringrandom(),rand()%2,3));

    for(size_t i=0;i<Nodos.size();i++){
        Nodos[i]->mostrarInfo();
    }

}