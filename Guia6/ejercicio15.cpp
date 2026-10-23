#include <iostream>
#include <ctime>
#include <vector>

class Posicion{
    public:
    double x;
    double y;
    void mostrarPosi(){
        std::cout << "Posicion en x: " << x << "\tPosicion en y: " << y << std::endl;
    }
};

Posicion operator-(const Posicion& a, const Posicion& b){
    Posicion beta;
    beta.x = a.x - b.x;
    beta.y = a.y - b.y;
    return beta;
    }

int main(void){
    srand(time(NULL));
    std::vector<Posicion> vectores;
    for(int i=0;i<2;i++){
        Posicion celda;
        celda.x=(double(rand()%10));
        celda.y=(double(rand()%15));
        vectores.push_back(celda);
        vectores[i].mostrarPosi();
    }
    Posicion resultante = vectores[0] - vectores[1];
    resultante.mostrarPosi();
    return 0;
}