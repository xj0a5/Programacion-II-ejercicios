#include <iostream>

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

class Antena{

    private:
    double frecuencia;
    double ganancia;

    public:

    Antena(double ch,double gain){
        frecuencia = ch;
        ganancia = gain;
    }
    
    void mostrarInfo(){
        std::cout << "Frecuencia: "<< frecuencia << "\t|Ganancia"<<ganancia<<std::endl;
    }
};

class EstacionCelular:public DispositivoRed{
    private:
    Antena antenaFisica;

    public:
    EstacionCelular(std::string mote, bool estado, double frec, double gain): 
    DispositivoRed(mote, estado), antenaFisica(frec, gain){}

    void mostrarInfo() override{
        DispositivoRed::mostrarInfo();
        antenaFisica.mostrarInfo();
    }
};

int main() {

    EstacionCelular miBase("Base-Norte", true, 2400.5, 15.0);
    
    miBase.mostrarInfo();
    
    return 0;
}