#include <stdio.h>
#include "funciones.h"

FILE *lectura;
FILE *proceso;

int main(int argc,char *argv[]){

    if(verificar_argcpropio(argc, 6,5)!=0){                 //se modifico esta funcion para 2 valores de argumentos
        return 1;
    }
    if (argc==6){
        lectura=fopen(argv[4],"r");
            if(lectura == NULL){
                printf("Error: NO SE ENCUENTRA EL ARCHIVO.\n");
                return -1;
            }
        proceso=fopen(argv[5],"w");
            if(proceso == NULL){
               printf("Error: NO SE ENCUENTRA EL ARCHIVO.\n");
               fclose(lectura);
               return -2;
            }
        int funcion;
        funcion = listadoprocesos(argv[1]);
        switch (funcion)
        {
        case 5:{
            int limite = contadorstr(argv[2]);
            reemplazopalabra(argv[3],lectura,argv[2],proceso,limite);
            printf("Se reemplazo la palabra %s por la palabra %s\n",argv[2],argv[3]);
        }break;
        default:{
            printf("COMANDO NO RECONOCIDO\n");
            return -3;
        }break;
    }
}
else{
    lectura=fopen(argv[3],"r");
        if(lectura == NULL){
            printf("Error: NO SE ENCUENTRA EL ARCHIVO.\n");
            return -1;
            }
    proceso=fopen(argv[4],"w");
        if(proceso == NULL){
            printf("Error: NO SE ENCUENTRA EL ARCHIVO.\n");
            fclose(lectura);
            return -2;
    }

    int funcion;
    funcion = listadoprocesos(argv[1]);

    switch (funcion)
        {
    case 6:{
            int limite = contadorstr(argv[2]);
            eliminarlineas(argv[2],lectura,proceso,limite);
            printf("Se eliminaron las lineas que contenian %s\n",argv[2]);
        }break;
    case 7:{
            iniciolineas(argv[2],lectura,proceso);
            printf("Se agrego %s a cada comienzo de linea.\n",argv[2]);
        }break;
    case 8:{
            finlineas(argv[2],lectura,proceso);                                 //fijarse antes si el texto tiene muchos caracteres antes de finalizar la linea
            printf("Se agrego %s a cada final de linea.\n",argv[2]);         
        }break;
    default:{
            printf("COMANDO NO RECONOCIDO\n");
            return -3;
    }break;
}
}

fclose(lectura);
fclose(proceso);

return 0;
}
