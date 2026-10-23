#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
    for(size_t i=0;i<valores.size();i++){
        std::cout <<"Valor N#" <<i+1<<" "<< valores[i]<< std::endl;
        }
    return 0;
}
