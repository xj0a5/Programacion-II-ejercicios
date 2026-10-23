#include <iostream>
#include <string>
/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LAS CLASES NodoRed, Transmisor y Receptor
====== */
class NodoRed{
    protected:
    std::string nombre;
    bool activo;
    public:
    std::string getNombre(void){return nombre;}
    NodoRed(std::string mote){
        nombre = mote;
        activo = 1 ;
    }
    void apagar(void){activo=0;}
    void prender(void){activo=1;}
    bool getActivo(void){return activo;}
};
class Transmisor:public NodoRed{
    private:
    double potencia;
    public:
    Transmisor(std::string mote,double pot):NodoRed(mote),potencia(pot) {}
    void mostrarEstado(void){
        std::cout << "Nombre: " << nombre << "\t|Potencia: " << potencia << "Estado: " <<(this->getActivo() ? "ON":"OFF") << std::endl;
    }
};
class Receptor:public NodoRed{
    private:
    double sensibilidad;
    public:
    Receptor(std::string mote, double sensi):NodoRed(mote),sensibilidad(sensi){}
    void mostrarEstado(void){
        std::cout << "Nombre: " << nombre << "\t|Sensibilidad(dB): " << sensibilidad << "\t Estado: " << (this->getActivo() ? "ON":"OFF")<< std::endl;
    }
};
int main()
{
Transmisor tx("TX-Norte", 43.0);
Receptor rx("RX-Sur", -95.0);
tx.mostrarEstado();
rx.mostrarEstado();
rx.apagar(); // método heredado de NodoRed
rx.mostrarEstado();
std::cout << "Nombre del TX: " << tx.getNombre() << "\n";
std::cout << "Activo: " << (tx.getActivo() ? "si" : "no") << "\n";

return 0;
}