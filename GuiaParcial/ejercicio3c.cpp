#include <iostream>
#include <string>
/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LA CLASE Transmisor ====== */

class Transmisor{
    private:
    std::string nombre;
    double potencia;
    bool activo;
    public:
    Transmisor(std::string mote,double pot){
        activo = 1 ;
        nombre = mote;
        potencia = 0;
        setPotencia(pot);
    }
    void setPotencia(double pot){
        if(pot>0 && pot <46){
            potencia = pot;
        }else{
            std::cout << "Valor de potencia no valido"<<std::endl;
        }
    }
    void apagar(void){activo = 0;}
    void mostrarEstado(void){

        std::cout << "Nombre: " << nombre << "\t|Potencia: " << potencia << "\t|Estado: " << (activo ? "Encendido":"Apagado")<<std::endl;
    }
    void encender(void){activo=1;}
    std::string getNombre(void){return nombre;}
    double getPotencia(void){return potencia;}

};
int main()
{
Transmisor tx("TX-Norte", 43.0);
tx.mostrarEstado();
tx.setPotencia(50.0); // debe rechazar
std::cout << "Potencia actual: " << tx.getPotencia() << " dBm\n";
tx.setPotencia(40.0); // debe aceptar
std::cout << "Potencia actual: " << tx.getPotencia() << " dBm\n";
tx.apagar();
tx.mostrarEstado();
tx.encender();
tx.mostrarEstado();
Transmisor txPrueba("TX-Prueba", 80.0); // potencia inicial invalida
std::cout << txPrueba.getNombre() << ": " << txPrueba.getPotencia() << "dBm\n";

return 0;
}