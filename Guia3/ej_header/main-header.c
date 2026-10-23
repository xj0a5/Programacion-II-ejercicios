#include <stdio.h>
#include "mis-funciones.h"

void main()
{
   int x=2, y=4, res_suma;
   float s=5.0, r=1.0, res_resta;
   int l;

   char cad1[15] = "Seminario";
   char cad2[10] = " de C";

   res_suma = suma(x, y);
   res_resta = resta(&s, &r);
   l = len_concat(cad1, cad2);

   printf("\n\nsuma=%d\nresta=%0.1f\nCadena:%s\nlargo cadena=%d\n", res_suma, res_resta, cad1, l);
}

