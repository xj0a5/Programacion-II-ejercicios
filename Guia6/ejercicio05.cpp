#include <iostream>
#include <ctime>

class Router{
    private:
    double potencia;

    public:
    Router(double p){
        setPotencia(p);
    }
    void setPotencia(double p){
        if(p>-1 && p<31){
            potencia = p;
        }
        else{
            std::cout << "Valor no permitido" << std::endl;
        }
    }
    double getPotencia(){
        return potencia;
    }
};
int main(void){
    srand(time(NULL));
    double a= (double(rand()%50));
    Router elpepe(a);
    std::cout << a << "W" << std::endl;
    return 0;
}