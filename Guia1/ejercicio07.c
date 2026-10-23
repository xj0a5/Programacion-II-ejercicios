#include <stdio.h>

int a=0,b=1,n,suma=0;
int main(void){
    printf("%d,",b);
for( n=1; n<9 ; n++){
    
    suma = a+b;
    printf("%d,",suma);
    a=b;
    b=suma;

}
printf("...\n");
}