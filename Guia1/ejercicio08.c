#include <stdio.h>

float celsius,farenheit;
int main(void){
    printf("|TEMPERATURAS EQUIVALENTES|\n");
    printf("|Farenheit\t|Celsius|\n");
        for(farenheit=0; farenheit<=300; farenheit += 20){
            celsius= (5*(farenheit-32))/9;
            printf("|%.2f  \t|%.2f\n|",farenheit,celsius);
    }
}