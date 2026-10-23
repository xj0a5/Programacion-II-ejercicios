#include <iostream>
#include <string>

bool nombrevalido(std::string nombre){
    if(nombre.empty() || nombre.length() < 3){
        return false;
    }
    else{
        return true;
    }
}
int main(void){
    std::string nombre;

    std::cout << "Ingrese un nombre";
    std::cin >> nombre;

    std::cout << nombrevalido(nombre) << "\n";

}