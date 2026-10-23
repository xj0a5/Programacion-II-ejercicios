#include <iostream>

/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LA CLASE Antena ====== */
class Antena{
    private:
    double frec;
    double gain;
    public:
    Antena(double frecuencia, double ganancia){
        frec = frecuencia;
        gain = ganancia;
    }
    double getGanancia(void){return gain;}
    double getFrecuencia(void){return frec;}
    void setGanancia(double g){gain = g;}
    void setFrecuencia(double f){frec = f;}
    void mostrar(void){
        std::cout << "Ganancia: " << gain << "\t|Frecuencia: " << frec << std::endl;
    }
};

int main()
{
Antena antenaNorte(2400, 15.0);
Antena antenaSur(900, 12.5);
antenaNorte.mostrar();
antenaSur.mostrar();
antenaNorte.setGanancia(18.0);
std::cout << "Nueva ganancia: " << antenaNorte.getGanancia() << " dBi\n";
std::cout << "Frecuencia: " << antenaSur.getFrecuencia() << " MHz\n";

return 0;
}