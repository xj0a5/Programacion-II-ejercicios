#include <stdio.h>

int contadorstr(char str[]){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}
void reemplazopalabra(char palabra[],FILE *lectura,char detectar[],FILE *destino,int limite){
    char lector[100];
    while(fgets(lector, 100, lectura) != NULL){
        int i=0;
        
        while(lector[i] != '\0'){
            int j=0,coincidencia=1;

            while(j<limite){                            //aca el limite es la cantidad de caracteres que tiene la palabra reemplazable
                if(lector[i+j] != detectar[j]){
                    coincidencia=0;
                    break;
                }
                j++;
            }
            if(coincidencia==1){
                fprintf(destino, "%s",palabra);
                i += limite;
            }
            else{
                fprintf(destino,"%c",lector[i]);
                i++;
            }
        }
    }

}
