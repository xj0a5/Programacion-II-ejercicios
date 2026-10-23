#include <stdio.h>
#include "funciones.h"
#include <math.h>

int main(void){
    double pot_e,pot_s;
    int i = 1;
    printf("Ingrese conversion que quiere hacer \n"
        "1_dBM a W\n"
        "2_W a dBM\n");
    scanf("%d",&i);
    printf("Ingrese potencia: ");
    scanf("%lf",&pot_e);
    switch(i-1){
        case 0:potdBa_W(pot_e, &pot_s);break;
        case 1:potW_dBa(pot_e,&pot_s);break;
        default: pot_s = 0;
    }
    printf("Resultado: %lf\n", pot_s);
    return 0;
}

