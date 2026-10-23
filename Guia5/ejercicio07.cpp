#include <iostream>

int main(void){
    int i,k;
    float mediciones[6];
    float promedio=0,jitter;
    for(i=0;i<6;i++){
        std::cout << "Ingrese su latencia: ";
        std::cin >> mediciones[i];
        promedio +=mediciones[i];
    }

    float medicionesjitter[5];

    for(i=0,k=1;i<5;i++,k++){
        jitter= mediciones[k]-mediciones[i];
        if(jitter<0){
            jitter = jitter * (-1);
        }
        medicionesjitter[i] = jitter ;    
    }

    promedio= promedio/6;
    std::cout << "====Su latencia promedio es: " << promedio << "ms=====\n";
    for(i=0;i<5;i++){
        std::cout << "Su jitter N°" << i+1 << " : " << medicionesjitter[i] << "\n";
    }

    return 0;

}