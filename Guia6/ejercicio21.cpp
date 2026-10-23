#include <iostream>
#include <string>

class Plan{
    public:
    
    std::string nombre;
    double velocidadMbps;
    double precioMensual;

};

class Cliente{
    protected:
    std::string nombre;
    Plan servicio;

    public:

    Cliente(std::string mote,std::string mote_rut, double velo,double precio){
        nombre = mote;
        servicio.nombre = mote_rut;
        servicio.precioMensual = precio;
        servicio.velocidadMbps = velo;
    }
    void estado(){
        std::cout << "\t\t===DATOS DEL USUARIO===\nNombre: " << nombre << "\tPlan: " << servicio.nombre << 
        "\tVelocidadMbps: " << servicio.velocidadMbps << "\tPrecio: " << servicio.precioMensual << std::endl;
    }

};

int main(void){

    Cliente Pepe("Doc.Nefario","5G+300MB+NOCHE",300,16000);
    Pepe.estado();

    return 0;
}