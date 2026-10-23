#include <iostream>
#include <string>
/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LA CLASE Sensor ====== */
class Sensor{
    private:
    std::string ssid;
    double valorActual;
    public:
    Sensor(std::string mote, double v){
        ssid = mote; valorActual = v;
    }
    std::string getNombre(void){return ssid;}
    double getValor(void){return valorActual;}
    void setValor(double valor){
        if(valor > -40 && valor < 85){
            valorActual = valor;
        }
    }
    void setNombre(std::string mote){
        ssid = mote;
    }
    void mostrar(void){
        std::cout << "Nombre: " << ssid << "\t|Valor Actual: " << valorActual << std::endl;
    }
};

int main()
{
Sensor sensorTemp("Temperatura", 25.0);
Sensor sensorRack("Temp-Rack", 40.0);
sensorTemp.setValor(30.0);
std::cout << sensorTemp.getNombre() << ": " << sensorTemp.getValor() <<
"\n";
sensorTemp.setValor(100.0); // debe rechazar (fuera de rango)
std::cout << sensorTemp.getNombre() << ": " << sensorTemp.getValor() <<
"\n";

sensorRack.mostrar();
return 0;
}