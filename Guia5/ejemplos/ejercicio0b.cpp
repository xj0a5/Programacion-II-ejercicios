#include <iostream>

int main(void){
    int modulacion;
    int rango;

    std::cout << "Ingrese el numero del canal: \n";
    std::cin >> rango;
    std::cout << "Ingrese el tipo de modulacion que desea: \n";
    std::cin >> modulacion;

    if(rango<0 || rango>50){
        std::cout << "El canal supera el rango permitido\n";
        return -1;
    }else{
        std::cout << "El canal está en el rango permitido(1 a 40)\n";
    }
    std::cout << "Modulacion seleccionada: ";
    switch(modulacion){
        case 1: std::cout << "AM\n";break;
        case 2: std::cout << "FM\n";break;
        case 3: std::cout << "Digital\n";break;
        default:std::cout << "Desconocido\n";return -2;break;
    }
    return 0;
}