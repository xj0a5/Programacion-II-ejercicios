#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>


class Dispositivo{
    public:
    std::string Nombre;
    std::string Fabricante;

    Dispositivo(){
        Nombre = "Vacio";
        Fabricante = "Vacio";
    }
    Dispositivo(std::string mote, std::string fabri){
        Nombre = mote;
        Fabricante = fabri;
    }
};

class DispositivoRed: public Dispositivo{

    protected:

    bool activo;

    public:

    DispositivoRed(std::string mote,std::string fabri, bool estado):Dispositivo(mote,fabri),activo(estado){};
    std::string virtual mostrarInfo(){
        std::string str = activo ? "Activo" : "Inactivo";
        return "Nombre: "+ Nombre + "\t|Fabricante: "+ Fabricante+ "\t|Estado: " + str;
    }
    double virtual costoMantenimientoAnual(){return 0.0;}

    void virtual imprimir(std::ostream& archivo){
        archivo << "===Nuevo Registro===\t"<< std::endl;
        archivo << this->mostrarInfo();   
    }
};
class Router:public DispositivoRed{
    public:
    
    double potencia;

    Router(std::string mote,std::string fabri, bool estado,double pot):DispositivoRed(mote,fabri,estado),potencia(pot){};

    std::string mostrarInfo()override{
        std::string pot_str = std::to_string(potencia);
        std::string mant_str = std::to_string(costoMantenimientoAnual());
        return DispositivoRed::mostrarInfo()+ "\t|Potencia: "+ pot_str + "Ghz"+ "\t|Resultado: "+ mant_str + "\n";
    }
    double costoMantenimientoAnual() override{
        double resultado;
        resultado= potencia * 2.5;
        return resultado;
    }
};

class Switch:public DispositivoRed{
    
    private:
    double puertos;
    
    public:

    Switch(std::string mote,std::string fabri,bool estado,double puerto):DispositivoRed(mote,fabri,estado),puertos(puerto){}

    std::string mostrarInfo()override{
        std::string port_str = std::to_string(puertos);
        std::string mant_str = std::to_string(costoMantenimientoAnual());
        return DispositivoRed::mostrarInfo()+ "\t|Puertos: "+ port_str + "\t|Resultado: "+ mant_str + "\n";
        
    }
    double costoMantenimientoAnual() override{
        double resultado;
        resultado= puertos * 3;
        return resultado;
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


std::ostream& operator<<(std::ostream& archivo, DispositivoRed& nodo){
    nodo.imprimir(archivo);
    return archivo;   
}

int main(void){
    srand(time(NULL));
    std::vector<DispositivoRed*> Nodos;

    Nodos.push_back(new Router("LabRedes",stringrandom(),rand()%2,2.4));
    Nodos.push_back(new Switch("Alfa",stringrandom(),rand()%2,3));

    std::ofstream archivo_e("Informe.txt");

    if(archivo_e.is_open()){
        for(size_t i = 0; i < Nodos.size(); i++){
            archivo_e << *(Nodos[i]); 
            std::cout << *(Nodos[i]); 
    }
        archivo_e.close();
    } else {
        std::cout << "Error abriendo el archivo.\n";
    }
    return 0;

}