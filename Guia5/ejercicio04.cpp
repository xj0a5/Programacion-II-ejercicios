#include <iostream>
#include <ctime>

int main(void){
    int red,i=0,j;

    std::cout << "\t\t====SELECCIONE SU TIPO DE RED====\t\t Simulador de latencia\n[1]-WIFI\n[2]-4G\n[3]-5G\n[4]-Ethernet\n";
    std::cin >> red;
    srand(time(NULL));
    switch(red){
        case 1: std::cout << "Selecciono Wifi\n";break;
        case 2: std::cout << "Selecciono 4G\n";break;
        case 3: std::cout << "Selecciono 5G\n";break;
        case 4: std::cout << "Selecciono Ethernet\n";break;
        default:std::cout << "Opcion no valida\n";i=1;break;
    }
    if(i==0){
        for(j=0;j<8;j++){
            std::cout << rand()%50 + 5 << "ms\n";
        }
    }else{
        return -1;
    }
    return 0;
}