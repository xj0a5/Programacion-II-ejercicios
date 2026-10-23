#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void){
    int i,mediciones[10],k;

    std::srand(std::time(nullptr));
    
    for(i=0;i<10;i++){
        mediciones[i] = rand() % 50 - 90;
        std::cout << "Medicion N°" << i << ":" << mediciones[i]  << " dBm\n";
        if(mediciones[i] < -70){
            k++;
        }
    }
    std::cout << "Son " << k << " mediciones que estan por debajo de -70dBm\n";
}