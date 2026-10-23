#include <iostream>
#include <vector>
#include <ctime>

int main(void){
    
    srand(time(NULL));
    std::vector<int> paquete;

    int i;
    for(i=0;i<10;i++){
        paquete.push_back(rand()% 256);
    }
    int suma = 0;
    for(size_t i = 0; i < paquete.size(); i++){
        suma += paquete[i];
    }
    int checksum = suma % 256;
    std::cout << "Suma total bruta: " << suma << "\n";
    std::cout << "Checksum calculado para enviar: " << checksum << "\n";

    return 0;

}