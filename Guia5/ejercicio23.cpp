#include <iostream>
#include <ctime>
#include <vector>

struct Conexiones{
    std::string ip;
    std::string Estado;
};

std::string crearIp(){
    int octeto4 = 2+(rand() % 253);

    std::string ip = "192.168.1." + std::to_string(octeto4);
    return ip;
}

int main(void){
    srand(time(NULL));

    std::vector<Conexiones> Nodos;
    for(int i=0;i<10;i++){
        Conexiones celda;
        celda.ip = crearIp();
        if(rand()%2){
            celda.Estado = "OK";
        }else{
            celda.Estado = "FALLIDO";
        }
        Nodos.push_back(celda);
    }
    int conexionexitosa=0;
    int conexionfallida=0;
    for(size_t i=0;i<Nodos.size();i++){
        
        if(Nodos[i].Estado=="OK"){
            conexionexitosa++;
        }else{
            conexionfallida++;
        }
        std::cout << Nodos[i].ip << "\t-\t" << Nodos[i].Estado << std::endl;
    }
    std::cout << "Las conexiones exitosas fueron: "<< conexionexitosa << std::endl;
    std::cout << "Las conexiones fallidas fueron: "<< conexionfallida << std::endl;
    return 0;
}