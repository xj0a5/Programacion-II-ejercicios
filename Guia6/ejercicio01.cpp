#include <iostream>
#include <string>
#include <ctime>

class PuntoAcceso{
    public:
    std::string ssid;
    int canal;
    
    void mostrar(){
        std::cout << "SSID: " << ssid << "\nCANAL: " << canal << std::endl;
    }
};

std::string stringrandom(void){
    switch(rand() % 3){
        case 0:return "alumnos";
        case 1:return "maestros"; 
        case 2:return "uti";
       default: return "dios";
    }
}

int main(void){

    srand(time(NULL));

    PuntoAcceso red1;
    red1.canal = rand() % 10;
    red1.ssid = stringrandom();

    PuntoAcceso red2;
    red2.canal = rand() % 10;
    red2.ssid = stringrandom();
    
    red1.mostrar();
    red2.mostrar();
    return 0;
}