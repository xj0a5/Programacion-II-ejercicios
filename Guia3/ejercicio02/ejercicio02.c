#include <stdio.h>
#include "funciones.h"

int mayor;

int main(int argc, char *argv[]){
    mayor = mayortres(argv[1],argv[2],argv[3]);

    printf("El numero mayor es: %d\n",mayor);
}