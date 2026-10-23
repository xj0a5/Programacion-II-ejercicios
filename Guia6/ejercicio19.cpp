#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

class Router{
    private:
    double potencia;

    public:
    Router(double p){
        setPotencia(p);
    }
    void setPotencia(double p){
        if(p>-1 && p<31){
            potencia = p;
        }
        else{
            potencia = -1.0;
            std::cout << "Valor no permitido" << std::endl;
        }
    }
    double getPotencia(){
        return potencia;
    }

    void guardarEstado(std::string archivo){

        std::ofstream archivo_e(archivo,std::ios::app);

        if(archivo_e.is_open()){
            archivo_e << "===Nuevo Registro===\tGanancia: " << getPotencia() << std::endl;
        }else{
            std::cout << "Error: No se pudo abrir el archivo" << std::endl;
        }
    }
};

int main(void){
    
    srand(time(NULL));

    Router mkt(rand()%50);

    mkt.guardarEstado("historial-router.txt");

    return 0;
}