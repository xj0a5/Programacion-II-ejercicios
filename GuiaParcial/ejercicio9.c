#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* ====== DECLARÁ E IMPLEMENTÁ ACÁ LAS FUNCIONES QUE FALTAN ====== */

const char *imprimirCalidad(int cali){
    switch(cali)
    {
        case 1:return "No se puso parsear la respuesta";
        case 2:return "Calidad:desconocida(99)";
        case 3:return "Calidad: N/31(debil)";
        case 4:return "Calidad: N/31(buena)";
        case 5:return "Calidad: N/31(excelente)";        
        default:return "Llamen a dios";
    }
}

int evaluarCalidad(int valor){
    if(valor <0){return 1;}
    else if(valor ==99){return 2;}
    else if(valor>=0 && valor<10){return 3;}
    else if(valor>=10 && valor<20){return 4;}
    else if(valor>=20){return 5;}
    else{return 5;}

}
int extraerCalidadSenal(const char *str){
    char prefijo[10] = "";
    int valor1 = -1;
    int valor2 = -1;

    sscanf(str, "%s %d,%d", prefijo, &valor1, &valor2);
    
    return valor1;
}

void mostrarCalidad(int valor){

    int cali=evaluarCalidad(valor);
    printf("%s\n", imprimirCalidad(cali));
}

int main(){
    
    const char *respuesta1 = "+CSQ: 18,99";
    const char *respuesta2 = "+CSQ: 99,99";
    const char *respuesta3 = "ERROR";
    
    mostrarCalidad(extraerCalidadSenal(respuesta1));
    mostrarCalidad(extraerCalidadSenal(respuesta2));
    mostrarCalidad(extraerCalidadSenal(respuesta3));
    
    return 0;
}
