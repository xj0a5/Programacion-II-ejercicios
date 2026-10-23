#include <iostream>
#include <cmath>
/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LA CLASE EnlaceRF ====== */
class EnlaceRF{
    private:
    double frecuenciaMHz,distanciaKm,perdidaEstimadaDb;
    public:
    EnlaceRF(double frec, double dist){
        frecuenciaMHz = frec;
        distanciaKm = dist;
        perdidaEstimadaDb = 32.44+20*log10(frec) + 20*log10(dist);
    }
    double getFrecuencia(void){return frecuenciaMHz;}    
    double getDistancia(void){return distanciaKm;}
    double getPerdida(void){return perdidaEstimadaDb;}
    void mostrar(void){
        std::cout << "Frecuencia(MHz): " << frecuenciaMHz << "\t|Distancia(Km): " << distanciaKm << "\t|Perdida(Db): " << perdidaEstimadaDb << std::endl;
    }
};
int main()
{
EnlaceRF enlace(2400, 5.0);
enlace.mostrar();
std::cout << "Perdida: " << enlace.getPerdida() << " dB\n";
std::cout << "Frecuencia: " << enlace.getFrecuencia() << " MHz\n";
std::cout << "Distancia: " << enlace.getDistancia() << " km\n";
return 0;
}