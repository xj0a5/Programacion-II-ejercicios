#include <iostream>
#include <vector>


void minMaxSNR(std::vector<double> valores, double &minimo, double &maximo){
    double menor,mayor;

    menor=valores[0];
    mayor=valores[0];

    for(size_t i=1;i<valores.size();i++){
        if(menor>valores[i]){
            menor= valores[i];
        }
        if(mayor<valores[i]){
            mayor=valores[i];
        }
    }

    minimo=menor;
    maximo=mayor;
}

int main(void){
    std::vector<double> valores;
    double prueba;
    int i=0;

    while(i==0){
        std::cout << "Ingrese un valor(PARA FINALIZAR COLOQUE 0): ";
        std::cin >> prueba;
        if(prueba == 0){
            i=1;
        } 
        else{
            valores.push_back(prueba);
        }
    }
    double minimo,maximo;
    minMaxSNR(valores,minimo,maximo);
    std::cout << "El valor maximo es: " << maximo << "\nEl valor minimo es: " << minimo << "\n";
}