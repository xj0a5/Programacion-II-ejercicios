#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "funciones.h"

int main(int argc, char *argv[]){
    float resultado;
    float pot;
    pot = atof(argv[1]);
    resultado = formula(pot);
    printf("El resultado es: %f \n",resultado);

}