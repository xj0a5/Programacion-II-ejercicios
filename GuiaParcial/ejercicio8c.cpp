#include <iostream>
#include <cmath>
/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LA CLASE Radioenlace ====== */
class Radioenlace{
    private:
    double frecuenciaMHz,distanciaKm;
    public:
    Radioenlace(void){
        frecuenciaMHz = 2400;
        distanciaKm = 1 ;
    }
    Radioenlace(double frec){
        frecuenciaMHz = frec;
        distanciaKm=1;
    }
    Radioenlace(double frec, double dist){
        frecuenciaMHz = frec;
        distanciaKm = dist;
    }
    double calcularPerdida(void){
        double fspl = 32.44+20*log10(frecuenciaMHz)+20*log10(distanciaKm);
        return fspl;
    }
    double calcularPerdida(double dist){
        double result = 32.44 + 20*log10(frecuenciaMHz)+20*log10(dist);
        return result;
    }
    double calcularPerdida(double dist, double extra){
        double result = calcularPerdida(dist)-extra;
        return result;
    }
    void mostrar(void){
        std::cout << "Frecuencia(MHz): " << frecuenciaMHz << "\t|Distancia(Km): " << distanciaKm << std::endl;
    }
};

int main()
{
Radioenlace a; // constructor por defecto
Radioenlace b(5800); // solo frecuencia
Radioenlace c(900, 12.5); // frecuencia y distancia
a.mostrar();
b.mostrar();
c.mostrar();
std::cout << "Perdida de a: " << a.calcularPerdida() << " dB\n";
std::cout << "Perdida de c: " << c.calcularPerdida() << " dB\n";
std::cout << "Perdida de c a 20 km: " << c.calcularPerdida(20.0) << "dB\n";
std::cout << "Perdida de c a 20 km con obstaculos: " << c.calcularPerdida(20.0, 6.5) << " dB\n";

return 0;
}