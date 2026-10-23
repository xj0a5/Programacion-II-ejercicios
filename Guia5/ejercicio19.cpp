#include <iostream>
#include <vector>
#include <string>
#include <ctime>

void menosdel15(std::vector<int> &baterias,std::vector<int> &indices){
    for(size_t i=0;i<baterias.size();i++){
        if (baterias[i]<15){
            indices.push_back(i);
        }
    }
}
int main(void){
   std::vector<int> baterias;
   std::vector<int> indices;

   srand(time(NULL));
   int i;

   for(i=0;i<10;i++){
    baterias.push_back(rand() %50);
   }
   menosdel15(baterias,indices);

   std::cout << "Niveles de bateria generados:\n";
    for (size_t i = 0; i < baterias.size(); i++) {
        std::cout << "Nodo " << i << ": " << baterias[i] << "%\n";
    }

    std::cout << "\n--- REPORTE CRITICO ---\n";
    if (indices.empty()) {
         std::cout << "Todos los nodos estan por encima del 15%.\n";
    } else {

        for (size_t i = 0; i < indices.size(); i++) {
            int indice_falla = indices[i];
            std::cout << "Dispositivo con indice [" << indice_falla << "] requiere atencion! (Nivel: " << baterias[indice_falla] << "%)\n";
        }
    }

    return 0;
}