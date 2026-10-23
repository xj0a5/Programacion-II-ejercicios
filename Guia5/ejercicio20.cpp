#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <ctime>

std::string errorrandom(void){

    std::time_t tiempo = std::time(nullptr);
    std::tm* hora_local = std::localtime(&tiempo);

    std::ostringstream prefijo;
    prefijo << "[" << std::put_time(hora_local, "%H:%M:%S") << "] ";

    switch(rand() % 4){
        case 0:return prefijo.str() +"[ERROR]DNS";
        case 1:return prefijo.str() +"[ERROR]TIMEOUT"; 
        case 2:return prefijo.str() +"[ERROR]MSGLOST";
        case 3:return prefijo.str() +"[ERROR]LAG";
        case 4:return prefijo.str() +"[ERROR]SEGURIDAD";
       default: return prefijo.str()+"[ERROR]MACRO";
    }
}

int main(void){

    srand(time(NULL));

    std::ofstream archivo_log("registro_errores.txt", std::ios::app);

    if (!archivo_log.is_open()) {
        std::cerr << "No se pudo abrir el archivo de log.\n";
        return 1;
    }
    archivo_log << errorrandom() << "\n";
    archivo_log << errorrandom() << "\n";

    archivo_log.close();

    std::cout << "Errores guardados en el archivo sin borrar los anteriores.\n";
    return 0;
}

