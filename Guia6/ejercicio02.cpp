#include <iostream>
#include <ctime>

class Cable{
    public:
    double longitudMetros;
    double atenuacionPorMetro;
    
    double atenuacionTotal(){
        double resultado;
        resultado = longitudMetros*atenuacionPorMetro;
        return resultado;
    }
};

int main(void){
    
    srand(time(NULL));

    Cable Aula4;
    Aula4.longitudMetros = rand() %60;
    Aula4.atenuacionPorMetro = 13;
    std::cout << "====PERDIDA POR METRO: " << Aula4.atenuacionPorMetro << "dB/m ====" << std::endl;
    std::cout << "Para una conexion de: " << Aula4.longitudMetros << "m una atenuacion de: " << Aula4.atenuacionTotal() << "dB" << std::endl;
    return 0;
}