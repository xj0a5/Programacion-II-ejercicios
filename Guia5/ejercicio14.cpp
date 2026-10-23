#include <iostream>
#include <vector>
#include <string>

void contarFueraDeRango(std::vector<double> potencias,double minimo,double maximo,int &cantidad){
    int i,aux=0;
    int limite= potencias.size();

    for(i=0;i<limite;i++){
        double valor_actual = potencias[i];
        if(valor_actual<minimo || valor_actual>maximo){
            aux++;
            std::cout << "Direccion de memoria de red: " << &potencias[i] << "\n"; 
        }
    }
    cantidad = aux;
}

int main(void){
    
    int cantidad,i;
    double minimo=0,maximo=46;
    std::vector<double> potencias;

    srand(time(NULL));      //random mas random    

    for(i=0;i<10;i++){
        double valor= -100 + (double)(rand()%201);
        potencias.push_back(valor); 
    }
    contarFueraDeRango(potencias,minimo,maximo,cantidad);

    std::cout << "Son " << cantidad << " Redes que estan fuera de rango\n";
    return 0;
}