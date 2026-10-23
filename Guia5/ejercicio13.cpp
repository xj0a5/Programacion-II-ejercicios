#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

void delay_segundos(int segundos) {                                 //funcion de timer
    clock_t inicio = clock();
    while ((clock() - inicio) / CLOCKS_PER_SEC < segundos) {
        
    }
}

int main(void){

    srand(time(NULL));      //random mas random

    int intento=1;

    while(rand() %10 != 5){
        int segundos = pow(2,intento);
        std::cout << "Intento #" << intento << "(" << segundos << "s)\n" ;
        delay_segundos(segundos);
        intento++;
    }
    std::cout << "Conexion Exitosa!!!\n";
    return 0;

}