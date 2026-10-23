#include <stdio.h>
#include <math.h>

double dbmAWatts(double pot_e){
    double pot_s;
    pot_s = pow(10,pot_e/10) / 1000;
    return pot_s;
}

double wattsADbm(double pot_e){
    double pot_s;
    pot_s = 10*log10(pot_e*1000);
    return pot_s;
}

int main()
{
double potenciaDbm = -30.0;
double potenciaWatts = dbmAWatts(potenciaDbm);
printf("%.2f dBm = %.6f W\n", potenciaDbm, potenciaWatts);
double watts = 0.001;
double dbm = wattsADbm(watts);
printf("%.4f W = %.2f dBm\n", watts, dbm);

return 0;
}