#include <iostream>
#include <string>
/* ====== DECLARÁ E IMPLEMENTÁ ACÁ TODAS LAS CLASES NECESARIAS ====== */
class NodoRed{
    private:
    std::string nombre;
    bool activo;
    public:
    NodoRed(std::string mote){
        nombre = mote;
        activo = 1;
    }
    std::string getNombre(void){return nombre;}
    bool getActivo(void){return activo;}
    void apagar(void){activo=0;}
    void mostrarEstado(void){
        std::cout << getNombre() << ": " << (getActivo() ? "ON":"OFF")<<std::endl;
    }
};
class Transmisor:public NodoRed{
    private:
    double potencia;
    public:
    Transmisor(std::string mote, double pot):NodoRed(mote){
        potencia = pot;
    }
    double getPotencia(){return potencia;}
    void mostrarEstado(void){
        NodoRed::mostrarEstado();
        std::cout << "Potencia de salida: " << potencia << "dBm" << std::endl;
    }
};
class Antena{
    private:
    double frecuencia, ganancia;
    public:
    Antena(double frec, double gain){
        frecuencia = frec;
        ganancia = gain ;
    }
    double getFrecuencia(void){return frecuencia;}
    double getGanancia(void){return ganancia;}
    void mostrar(void){
        std::cout << "Antena: " << frecuencia << "Mhz, " << ganancia << "dB" << std::endl;
    }
};
class EstacionBase{
    private:
    std::string nombre;
    Antena antena;
    Transmisor tx;
    public:
    EstacionBase(std::string mote,Antena alfa, Transmisor beta):antena(alfa.getFrecuencia(),alfa.getGanancia()),tx(beta.getNombre(),beta.getPotencia()){
        nombre=mote;
    }
    void mostrarResumen(void){
        std::cout << "\t\t---" << nombre << "---" << std::endl;
        antena.mostrar();
        tx.mostrarEstado();
    }
    double calcularEIRP(void){
        double eirp;
        eirp = tx.getPotencia() + antena.getGanancia();
        return eirp;
    }
    void apagarTransmisor(void){
        tx.apagar();
    }
};
int main()
{
Antena antena(2400, 15.0);
Transmisor tx("TX-Norte", 43.0);
EstacionBase estacion("Estacion-Norte", antena, tx);
estacion.mostrarResumen();
std::cout << "EIRP: " << estacion.calcularEIRP() << " dBm\n";

estacion.apagarTransmisor();
estacion.mostrarResumen();
std::cout << "TX original activo: " << (tx.getActivo() ? "si" : "no") <<
"\n";
return 0;
}