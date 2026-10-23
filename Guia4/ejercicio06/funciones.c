#include <stdio.h>

int verificar_argcpropio(int argc, int limite, int limite2){
    if(argc != limite && argc != limite2){
        printf("Error:Cantidad de argumentos incorrecta\n");
        return 1;
    }
    return 0;
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
int contadorstr(char str[]){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}
int compararcadenas(char cadena1[],char cadena2[]){     //si es 1 son iguales, si es 0 es diferente o uno es mas largo que el otro
    int i=0;

    while(cadena1[i]!='\0' && cadena2[i]!='\0'){
        if(cadena1[i]!=cadena2[i]){
            return 0;
        }
        i++;
    }
    if(cadena1[i]=='\0' && cadena2[i]=='\0'){
        return 1;       
    }
    return 0;
}
int listadoprocesos(char funcion[]){
    int proceso;
    if(compararcadenas(funcion,"reemplazar")==1){
        proceso=5;
    }
    else if(compararcadenas(funcion, "eliminar")==1){
        proceso=6;
    }
    else if(compararcadenas(funcion,"inicio")==1){
        proceso=7;
    }
    else if(compararcadenas(funcion,"fin")==1){
        proceso=8;
    }
    else{
        proceso=-1;
    }
    return proceso;
}
void eliminarlineas(char palabra[],FILE *lectura,FILE *destino,int limite){
    char lector[100];
    while(fgets(lector, 100, lectura) != NULL){
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
                //aca elimino la linea solo salteo la salteo
            }
            i++; //seguimos leyendo
        }
        if(contienelapalabra==0){ // si tiene 1 significa que la encontro y por ende no hace nada
            fprintf(destino,"%s",lector);
        }
    }

}
void iniciolineas(char palabra[],FILE *lectura,FILE *destino){
    char lector[100];
    while(fgets(lector, 100 , lectura) != NULL){
        fprintf(destino,"%s %s",palabra,lector);
    }
}
void finlineas(char palabra[],FILE *lectura,FILE *destino){
    char lector[200];
    while(fgets(lector, 200 , lectura) != NULL){        //tener cuidado con el largo del texto por linea.!
        int i=0;
        while(lector[i] != '\0'){
            if(lector[i] == '\n'){
                lector[i] = '\0';
                break;
            }
            i++;
        }
        fprintf(destino,"%s %s\n",lector,palabra);
    }
}
