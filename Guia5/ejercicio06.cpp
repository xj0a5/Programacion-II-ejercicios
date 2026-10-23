#include <iostream>

bool formatoIpValido(std::string ip){
    int k=0;
    for(size_t i=0; i < ip.size();i++){
        if(ip[i]=='.'){
            k++;
        }
    }
    if(k!=3){
        return false;
    }
    return true;
}

int main(void){
    std::string ip;
    std::cout << "Ingrese su direccion: ";
    std::cin >> ip;
    if(formatoIpValido(ip)){
        std::cout << "===Su ip es: " << ip << " ===\n";
        return 0;
    }
    else{
        std::cout << "===La direccion: " << ip << " No es una direccion IP===\n";
        return 1;   
    }

}