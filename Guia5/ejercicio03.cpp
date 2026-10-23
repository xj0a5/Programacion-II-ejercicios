#include <iostream>

int main(void){
    int RSRP;

    std::cout << "Ingrese su RSRP: ";
    std::cin >> RSRP;

    if(RSRP>-80){
        std::cout << "SEÑAL EXCELENTE\n";
    }else if(RSRP>-95){
        std::cout << "SEÑAL BUENA\n";
    }else if(RSRP>-110){
        std::cout << "SEÑAL DEBIL\n";
    }
    else{
        std::cout << "Sin cobertura\n";
    }

}