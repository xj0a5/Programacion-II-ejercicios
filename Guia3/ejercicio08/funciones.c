#include <math.h>

float formula(float a){
    float dbm;
    double aux;
    aux = log10(a*1000);
    dbm = 10 * aux;
    return dbm;
}