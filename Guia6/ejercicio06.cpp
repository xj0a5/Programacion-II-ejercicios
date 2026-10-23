#include <iostream>

class Suscriptor{
    private:
    double datosDisponiblesGB;
    public:
    Suscriptor(double d){
        datosDisponiblesGB = d;
    }
    double getdatosDisponiblesGB(void){
        return datosDisponiblesGB;
    }
    void consumirGB(double gb){
        if(gb > datosDisponiblesGB){
            std::cout << "No hay mas datos disponibles" << std::endl;
        }
        else{
            std::cout << "Se consumio: "<< gb << "Gb" << std::endl;
            datosDisponiblesGB -= gb;
            std::cout << "Datos disponibles: "<< datosDisponiblesGB << "Gb" << std::endl;
        }
    }


};

int main(void){
    Suscriptor uno(10.0);
    double datos;
    while(uno.getdatosDisponiblesGB() !=0){
        std::cin >> datos;
        uno.consumirGB(datos);
    }


}