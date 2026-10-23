#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strmayor(char a[]){
    int i,mayor;
    int numeros[3];
    int k=0;
    char limite[5];
    char *puntero=a;
    for(i=0;i<3 ;i++){
        k=0;                                            //reinicio de iteracion                                 
        while( *puntero != ' ' && *puntero !='\0'){
                limite[k] = *puntero;
                k++;
                puntero++;
        }
        limite[k] = '\0';                               //terminamos el string temporal
        numeros[i] = atoi(limite);                      //convertimos el temporal en un entero y guardamos en una sola variable matriz
        if(*puntero == ' '){
            puntero++;
        }
    }
    if(numeros[0]>numeros[1]&& numeros[0]>numeros[2]){
        mayor = numeros[0];
    }
    else if(numeros[1] > numeros[2]){
        mayor = numeros[1];
    }
    else{
        mayor = numeros[2];
    }
    return mayor;
}


int mayortres(char x[],char y[], char z[]){
    int n1,n2,n3;
    n1= atoi(x);
    n2= atoi(y);
    n3= atoi(z);
    int mayor;

    if(n1>n2&& n1>n3){
    mayor = n1;
    }
    else if(n2 > n3){
        mayor = n2;
    }
    else{
        mayor = n3;
    }
    return mayor;
}