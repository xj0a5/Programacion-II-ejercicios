#include <stdio.h>
#include <string.h>

int main(void){
    int *pnumero;
    int num1, num2;
    char *pchar;
    char letra1;
    num1 = 2;
    num2 = 5;
    letra1 = 'a';

    pnumero = &num1;

    num2 = num1 + *pnumero;

    pchar = &letra1;
    *pchar = 'B';

    *pnumero = 10;
    
}