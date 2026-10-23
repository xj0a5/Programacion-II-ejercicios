#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
/* ====== DECLARÁ E IMPLEMENTÁ ACÁ TODAS LAS CLASES NECESARIAS ====== */
class NodoRed{
    protected:
    std::string nombre;
    bool activo;
    public:
    NodoRed(std::string mote){nombre = mote; activo=1;}
    void apagar(void){activo=0;}
    void encender(void){activo=1;}
    std::string getNombre(void){return nombre;}
    bool getActivo(void){return activo;}
    void mostrar(void){
        std::cout << "Nombre: " << nombre << "\t|Estado: " <<(this->getActivo() ? "ON":"OFF")<<std::endl;
    }
};
class Transmisor: public NodoRed{
    private:
    double potencia;
    public:
    Transmisor(std::string mote, double pot):NodoRed(mote){potencia = pot;}
    double getPotencia(void){return potencia;}
    void mostrar(void){
        NodoRed::mostrar();
        std::cout << "Potencia(dBa): " << potencia << std::endl;
    }
};
class RedMonitoreo{
    private:
    std::string nombre;
    std::vector<Transmisor> transmisores;
    public:
    RedMonitoreo(std::string mote){nombre = mote;}
    void agregar(Transmisor Alfa){transmisores.push_back(Alfa);}
    void agregar(std::string mote,double pot){
        Transmisor Alfa(mote, pot);
        transmisores.push_back(Alfa);
    }
    void mostrar(void){
        std::cout << "\t\t===" << nombre << "===" << std::endl;
        for(size_t i=0;i<transmisores.size();i++){
            transmisores[i].mostrar();
        }
    }
    double potenciaTotalDbm(void){
        double total=0;
        for(size_t i=0;i<transmisores.size();i++){
            total += transmisores[i].getPotencia();
        }
        double pot = 10*log10(total/10);
        return pot;
    }
    void guardarLog(std::string archivo){
        std::ofstream archivo_s;
        archivo_s.open(archivo);
        if(archivo_s.is_open()){
            archivo_s << "Red: "<<nombre << "\t|Nodos: " << transmisores.size()<<std::endl;
            for(size_t i = 0;i<transmisores.size();i++){
                archivo_s <<"Nombre: " <<transmisores[i].getNombre() << "\t|Estado: " << 
                (transmisores[i].getActivo() ? "ON":"OFF") << "\t|Potencia(dBA): " << transmisores[i].getPotencia() <<
                std::endl;}archivo_s.close();}else{
            std::cout << "Error al abrir el archivo" << std::endl;
        }
    }
};
int main()
{
RedMonitoreo red("Red-Norte");
Transmisor txA("TX-Norte", 43.0);
red.agregar(txA); // version 1: recibe un objeto
red.agregar("TX-Este", 40.0); // version 2: recibe nombre y potencia
red.agregar("TX-Sur", 37.0);
red.mostrar();
std::cout << "Potencia total: " << red.potenciaTotalDbm() << " dBm\n";
red.guardarLog("log_red.txt");
std::cout << "Log guardado en log_red.txt\n";
return 0;
}