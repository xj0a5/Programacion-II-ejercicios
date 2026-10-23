#include <stdio.h>

int main(void){
    
    int a,b,n,r;

    printf("Ingrese el primer número: ");
    scanf("%d",&a);
    printf("Ingrese el segundo número: ");
    scanf("%d",&b);
    for(n=0;n<13;n++){
        switch(n){
            case 0:r= a+b ; printf("Operación: %d + %d =",a,b); break;
            case 1:r= a-b ; printf("Operación: %d - %d =",a,b); break;
            case 2:r= a/b ; printf("Operación: %d / %d =",a,b); break;
            case 3:r= a*b ; printf("Operación: %d * %d =",a,b); break;
            case 4:r= a%b ; printf("Operación: %d %% %d =",a,b); break;
            case 5:printf("Operación con número b: %d++ =",b);r= b++ ; break;
            case 6:printf("Operación con número b: ++%d =",b);r= ++b ; break;
            case 7:printf("Operación con número b: %d-- =",b);r= b-- ; break;
            case 8:printf("Operación con número b: --%d =",b);r= --b ; break;
            case 9:printf("Operacion con número a: %d++ =",a);r= a++ ; break;
            case 10:printf("Operacion con número a: ++%d =",a);r= ++a ; break;
            case 11:printf("Operacion con número a: %d-- =",a);r= a-- ; break;
            case 12:printf("Operacion con número a: --%d =",a);r= --a ; break;

        }
        printf("%d \n",r);
    }
}