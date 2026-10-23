#include <iostream>


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
    virtual void diagnostico(){
        std::cout << "|Estado: " << activo <<"\n"<< std::endl;
    }
};
class Router:public DispositivoRed{
    public:
    
    double potencia;

    Router(std::string mote,std::string fabri, bool estado,double pot):DispositivoRed(mote,fabri,estado),potencia(pot){};

    void mostrarInfo()override{
        DispositivoRed::mostrarInfo();
        std::cout << "\t|Potencia: " << potencia << std::endl;
    }
};

int main(void){
    Router labredes("LabRedes","MKT",1,2.4);
    labredes.mostrarInfo();
}