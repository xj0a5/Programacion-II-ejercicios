#include <iostream>
#include <cstdlib>
#include <ctime>

void normalizarpotencia(int *potencia){
    int reajuste;
    if(*potencia <0 || *potencia > 46){
        reajuste = rand() % 47;
        std::cout << "Se reajusta el valor: " << *potencia << " con el valor " << reajuste << "\n";
        *potencia = reajuste;
    }
}

int main(void){
    int mediciones[10],i;

    std::srand(std::time(nullptr));

    for(i=0;i<10;i++){
        mediciones[i] = rand() % 60;
        std::cout << "Medicion N°" << i << ": " << mediciones[i]  << "W\n";
        normalizarpotencia(&mediciones[i]);
    }

}