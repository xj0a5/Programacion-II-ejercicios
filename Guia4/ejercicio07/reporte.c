#include <stdio.h>
#include "funciones.h"

FILE *proceso;
int main(void){
    int mediciones[10],x;
    int i=0;
    while(i<10){
        printf("Ingrese la medicion N° %d: ",i+1);
        scanf("%d",&x);
        if(comprobarmediciones(x,-30,-120)==1){
            mediciones[i]=x;
            i++;
        }
    }
    proceso= fopen("reporte.txt","w");
        if(proceso == NULL){
               printf("Error: NO SE ENCUENTRA EL ARCHIVO.\n");
               return -1;
            }
    
    int promedio,sumatoria=0,j=0,k=0;
    int menores[10];
    int mayores[10];

    for(i=0;i<10;i++){
        sumatoria +=mediciones[i];
    }
    promedio = sumatoria/10;
    
    for(i=0;i<10;i++){
        if(mediciones[i]<-80){
            menores[j]= mediciones[i];
            j++;
        }
        else if(mediciones[i]>-60){
            mayores[k]= mediciones[i];
            k++;
        }
    }
    for(i=0;i<10;i++){
        fprintf(proceso,"Medición Nro %d:%d dBm\n",i,mediciones[i]);
    }
    fprintf(proceso,"===Promedio:%d ===\n",promedio);
    fprintf(proceso,"===Mediciones menores a -80dBm===(%d mediciones)\n",j);
    for(i=0;i<j;i++){
        fprintf(proceso,"%d dBm\n",menores[i]);
    }
    fprintf(proceso,"===Mediciones mayores a -60dBm===(%d mediciones)\n",k);
    for(i=0;i<k;i++){
        fprintf(proceso,"%d dBm\n",mayores[i]);
    }
    //fprintf mediciones: (antes poner fopen) , luego calculo y lo demas fprintf
}