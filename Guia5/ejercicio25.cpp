#include <iostream>
#include <fstream>
#include <vector>

int main(void){

    std::ifstream archivo_e("latencia.txt");
    if (!archivo_e.is_open()) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return -1; 
    }

    std::string lector;
    std::vector<int> valores;

    while(std::getline(archivo_e,lector)){
        size_t pos = lector.find(":");
        if (pos != std::string::npos) {
        

            std::string parte_derecha = lector.substr(pos + 1);

            int valor = std::stoi(parte_derecha);

            valores.push_back(valor);
            }
        }

    archivo_e.close();
    
    int mayor=0,promedio=0,minimo=10000,suma=0,tamanio= valores.size();
    for(size_t i=0;i<valores.size();i++){
        suma += valores[i];
        if(mayor < valores[i]){
            mayor= valores[i];
        }else if(minimo > valores[i]){
            minimo=valores[i];
        }
    }
    promedio= suma / tamanio ;

    std::ofstream archivo_log("reporte_antena.txt");


    if (!archivo_log.is_open()) {
        std::cerr << "No se pudo abrir el archivo de log.\n";
        return 1;
    }
    archivo_log << "PROMEDIO: " << promedio << "\nMINIMO: " << minimo << "\nMAXIMO: " << mayor << std::endl;
    archivo_log.close();
    return 0;
}