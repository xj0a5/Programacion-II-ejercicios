#include <iostream>
#include <ctime>

struct Medicion{

    int canal;
    double rssi;

};

int main(void){

    Medicion valores[5];
    int i;
    srand(time(NULL));

    for(i=0;i<5;i++){
        valores[i].canal= rand() % 15 ;
        valores[i].rssi=(double)(rand() % 26)-85.0;
    }
    std::cout << "=== Mediciones Registradas ===\n";
    for(i=0;i<5;i++){
        std::cout << "===Medicion N°" << i+1 << " ===" << 
        "\nCanal: " << valores[i].canal << 
        "\nRSSI: " << valores[i].rssi << "\n";
    }


}