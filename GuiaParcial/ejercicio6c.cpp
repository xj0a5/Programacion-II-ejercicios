#include <iostream>
#include <string>
/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LAS CLASES Antena y EstacionBase ====== */
class Antena{
    private:
    double frecuencia,ganancia;
    public:
    Antena(double frec, double gain){frecuencia=frec;ganancia=gain;}
    double getFrecuencia(void){return frecuencia;}
    double getGanancia(void){return ganancia;}
    void mostrar(void){
        std::cout << "Frecuencia: " << frecuencia << "\t|Ganancia: " << ganancia << std::endl;
    }
};

class EstacionBase{
    private:
    std::string nombre;
    Antena antena;
    public:
    EstacionBase(std::string mote, Antena alfa):antena(alfa.getFrecuencia(),alfa.getGanancia()){
        nombre = mote;
        
    }
    void mostrarResumen(void){
        std::cout << "\t\tNombre de base: " << nombre << std::endl;
        antena.mostrar();
    }
    std::string getNombre(void){return nombre;}
};
int main(){
Antena antena(2400, 15.0);
EstacionBase estacion("Estacion-Norte", antena);
estacion.mostrarResumen();

std::cout << "Nombre: " << estacion.getNombre() << "\n";
return 0;
}