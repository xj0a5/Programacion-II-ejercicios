#include <iostream>

/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LA CLASE Bateria ====== */
class Bateria{
    private:
    double voltaje;
    int porcentajeCarga;
    public:
    Bateria(double volt, int inicio){
        voltaje = volt;
        porcentajeCarga = inicio;
    }
    void consumir(int menos){
        if((porcentajeCarga-menos)<0){
            std::cout << "(BATERIA BAJA)" << std::endl;
            porcentajeCarga = 0;
        }else{
            if((porcentajeCarga-menos)<20){
                std::cout << "(BATERIA BAJA)" << std::endl;
            }
            porcentajeCarga -= menos;
        }
    }
    void cargar(int mas){
        if((porcentajeCarga+mas)>100){
            porcentajeCarga=100;
        }else{porcentajeCarga+=mas;}
    }
    void mostrarEstado(void){
        std::cout << "Voltaje: " << voltaje << "\t|Carga: "<<porcentajeCarga << "%" << std::endl;
    }
};
int main()
{
Bateria bateria(12.6, 85);
bateria.mostrarEstado();
bateria.consumir(70);
bateria.mostrarEstado();
bateria.cargar(50);
bateria.mostrarEstado();
bateria.consumir(200); // no debe bajar de 0
bateria.mostrarEstado();

return 0;
}
