#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(void){
    int j;
    std::ofstream archivo_s("latencia.txt");
    if (!archivo_s.is_open()) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return 1; 
    }

    for(j=0;j<10;j++){
            int numero_random = rand() % 50 + 5;
            std::cout << numero_random << " ms\n";
            archivo_s << numero_random << " ms\n";
        }

    archivo_s.close();
    std::ifstream archivo_e("latencia.txt");
    std::vector<int> mediciones;
    std::string linea;
    int sumatoria=0;
    j=0;
    while(std::getline(archivo_e,linea)){
        if(!linea.empty()){
            mediciones.push_back(std::stoi(linea));
        }
        sumatoria += mediciones[j];
        j++;
    }
    int promedio=0;
    promedio=sumatoria/mediciones.size();
    int mayor=0;
    for(j=0;j<10;j++){
        if(mayor<mediciones[j]){
            mayor = mediciones[j];
        }
    }
    std::cout << "El promedio es: " << promedio << std::endl;
    std::cout << "La latencia pico es: " << mayor << std::endl;
    archivo_e.close();
    return 0;
}