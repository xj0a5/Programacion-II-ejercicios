#include <stdio.h>

int contadorstr(char str[]){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}
void extraerlineas(char palabra[],FILE *lectura,FILE *destino,int limite){
    char lector[256];
    while(fgets(lector, 256, lectura) != NULL){
        int i=0;
        int contienelapalabra=0;
        while(lector[i] != '\0'){
            int j=0,coincidencia=1;

            while(j<limite){
                if(lector[i+j] != palabra[j]){
                    coincidencia=0;
                    break;
                }
                j++;
            }
            if(coincidencia==1){
                contienelapalabra=1;
                break;
                //aca elimino la linea solo salteo 
            }
            i++; //seguimos leyendo
        }
        if(contienelapalabra==1){ // si tiene 1 significa que la encontro y por 0 no hace nada
            fprintf(destino,"%s",lector);
        }
    }

}
