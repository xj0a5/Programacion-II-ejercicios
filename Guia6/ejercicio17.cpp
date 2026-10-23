#include <iostream>
#include <string>
#include <ctime>
#include <vector>

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
    virtual void diagnostico(){
        std::cout << "|Estado: " << activo <<"\n"<< std::endl;
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
    void diagnostico()override{
        if(puertos > 10){
            std::cout << "===Calidad:Excelente===\n" << std::endl;
        }
        else if(puertos>4 && puertos <10){
            std::cout << "====Calidad:Estandar===\n" << std::endl;
        }
        else{
            std::cout << "===Calidad:Minima===\n" << std::endl;
        }
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
    void diagnostico() override{
        if(canal<0 || canal>30){
            std::cout << "===CANAL FUERA DE RANGO===\n ====\t DESACTIVANDO \t====" << std::endl;
            activo = false;
        }
        DispositivoRed::diagnostico();
    }
};
class Repetidor:public DispositivoRed{
    private:
    double ganancia;
    public:
    Repetidor(std::string mote, bool estado,double gain):DispositivoRed(mote,estado),ganancia(gain){}
        void mostrarInfo()override{
        std::cout << "Nombre: " << nombre << "\t|Estado: " << activo <<"\t|Ganancia: "<< ganancia << std::endl;
    }
    void diagnostico() override{
        if(ganancia<100 || ganancia>200){
            std::cout << "===GANANCIA MUY BAJA/ALTA===\n ====\t DESACTIVANDO \t====" << std::endl;
            activo = false;
        }
        DispositivoRed::diagnostico();
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
    Nodos.push_back(new Switch(stringrandom(),rand()%2,rand()%15));
    Nodos.push_back(new AccesPoint(stringrandom(),rand()%2,rand()%50));
    Nodos.push_back(new Repetidor(stringrandom(),rand()%2,rand()%150 +70));
    
    for(size_t i=0;i<Nodos.size();i++){
        Nodos[i]->mostrarInfo();
        Nodos[i]->diagnostico();
    }

}