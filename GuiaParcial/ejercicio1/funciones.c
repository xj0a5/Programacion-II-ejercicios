#include <math.h>

void potdBa_W(double pot_e,double *pot_s){
    double resultado;
    resultado = pow(10.0,pot_e/10.0)/1000.0;
    *pot_s = resultado ; 
}
void potW_dBa(double pot_e,double *pot_s){
    double resultado;
    resultado = 10.0*log10(pot_e * 1000.0);
    *pot_s = resultado;
}