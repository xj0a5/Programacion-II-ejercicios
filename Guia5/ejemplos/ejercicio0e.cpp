#include <iostream>
#include <vector>

double promedio(std::vector<double> valores){
    double suma=0;
    double promedio;
    double i;
    for(i=0;i < valores.size();i++){
        suma += valores[i];
    }
    promedio = suma / valores.size();
    return promedio;
}

int main(void){

    std::vector<double> mediciones;
    double entrada;
    int i;
    double resultado;

    for(i=0; i<5 ; i++){
        std::cout << "Ingresa una medición N°" << (i+1) << ": ";
        std::cin >> entrada;
        mediciones.push_back(entrada);
    }
    resultado = promedio(mediciones);
    std::cout << "El promedio es: " << resultado << "dBm\n";
    return 0;
}