#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class DispositivoRed{

    protected:

    std::string nombre;
    bool activo;

    public:

    DispositivoRed(std::string mote, bool estado){
        nombre = mote;
        activo = estado;
    }
    virtual void mostrarInfo(){
        std::cout << "Nombre: " << nombre << "\t|Estado: " << activo << std::endl;
    }
};

class Switch:public DispositivoRed{
    
    private:
    double puertos;
    
    public:

    Switch(std::string mote,bool estado,double puerto):DispositivoRed(mote,estado),puertos(puerto){}

    void mostrarInfo()override{
        std::cout << "Nombre: " << nombre << "\t|Estado: " << activo << "\t|Cantidad de puertos: " << puertos << std::endl;
    }
};
class AccesPoint:public DispositivoRed{

    private:
    double canal;

    public:

    AccesPoint(std::string mote,bool estado,double ch):DispositivoRed(mote,estado),canal(ch){}
    
    void mostrarInfo()override{
        std::cout << "Nombre: " << nombre << "\t|Estado: " << activo <<"\t|Canal: "<< canal << std::endl;
    }
};

std::string stringrandom(void){
    switch(rand() % 3){
        case 0:return "MKT";
        case 1:return "Cisco"; 
        case 2:return "Netgear";
       default: return "dios";
    }
}

int main(void){
    srand(time(NULL));
    std::vector<DispositivoRed*> Nodos;

    Nodos.push_back(new DispositivoRed(stringrandom(),rand()%2));
    Nodos.push_back(new Switch(stringrandom(),rand()%2,rand()%65));
    Nodos.push_back(new AccesPoint(stringrandom(),rand()%2,rand()%200));
    
    for(size_t i=0;i<Nodos.size();i++){
        Nodos[i]->mostrarInfo();
    }

}
