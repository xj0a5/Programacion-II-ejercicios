#include <iostream>
#include <string>
#include <vector>


class Enlace{
    public:
    std::string origen;
    std::string destino;
    double anchoBandaMbps;
    Enlace(std::string O,std::string D, double Mbps){
        origen = O;
        destino = D;
        anchoBandaMbps = Mbps;
    }
};
std::ostream& operator<<(std::ostream& beta, const Enlace& a){
    beta << "Origen: " << a.origen << "\tDestino: " << a.destino << "\tAncho de Banda: " 
        << a.anchoBandaMbps<<" Mbps" << std::endl;
    return beta;
}

int main(void){
    std::string origen,destino;
    double Mbps;
    std::cout << "Ingrese Origen: ";
    std::cin >> origen;
    std::cout << "Ingrese Destino: ";
    std::cin >> destino;
    std::cout << "Ingrese Ancho de banda: ";
    std::cin >> Mbps;
    Enlace nodoprincipal(origen, destino, Mbps);
    std::cout << nodoprincipal;
}