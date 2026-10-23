int verificar_argcpropio(int argc, int limite,int limite2);
int contadorstr(char str[]);
void reemplazopalabra(char palabra[],FILE *lectura,char detectar[],FILE *destino,int limite);
int listadoprocesos(char funcion[]);
int compararcadenas(char cadena1[],char cadena2[]);
void eliminarlineas(char palabra[],FILE *lectura,FILE *destino,int limite);
void iniciolineas(char palabra[],FILE *lectura,FILE *destino);
void finlineas(char palabra[],FILE *lectura,FILE *destino);