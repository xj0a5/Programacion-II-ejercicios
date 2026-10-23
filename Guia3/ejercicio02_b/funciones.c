#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mayor_string(char a[],char b[],char c[]){
    int n1,n2,n3;
    int mayor;
    n1 = atoi(a);    
    n2 = atoi(b);
    n3 = atoi(c) ;   
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
