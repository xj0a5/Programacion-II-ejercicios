#include <stdio.h>

int main(void){

    int numeroa,numerob,mayor;
    printf("Ingresar el primer número\n");
    scanf("%d", &numeroa);
    printf("Ingresar el segundo número\n");
    scanf("%d", &numerob);

    if(numeroa>numerob){
        printf("El número mayor es: %d (primero)\n",numeroa);
    }
    else if(numeroa==numerob){
        printf("Los números son iguales\n");
    }
    else{
        printf("El número mayor es: %d (segundo)\n",numerob);
    }
    return 0;
}