#include <iostream>
#include <fstream>
#include <string>


class Router{
    public:
    
    double potencia;
    double canal;

    Router(double p,double c){
        potencia = p;
        canal = c;
    }
    std::string mostrar(){
        return "Potencia: "+std::to_string(potencia)+ "\t|Canal: "+std::to_string(canal) +"\n";
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

    std::string mostrarEstado(){
        return "Router 1 - " + r1.mostrar() + 
               "Router 2 - " + r2.mostrar() + 
               "Router 3 - " + r3.mostrar();
    }

    void guardarEstado(std::string archivo){

    std::ofstream archivo_e(archivo,std::ios::app);

    if(archivo_e.is_open()){
        archivo_e << "===Nuevo Registro===\tPack Router\n" << mostrarEstado() << std::endl;

    }else{
            std::cout << "Error: No se pudo abrir el archivo" << std::endl;
        }
    }

};

int main(void){
    Rack elpato(50, 1300);
    elpato.guardarEstado("historial-rack.txt");
    return 0;
}