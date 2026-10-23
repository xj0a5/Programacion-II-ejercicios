#include <stdio.h>

int main(void)
{
    int entero = 10;
    float real = 2.5f;
    double real_doble = 3.141592;
    char caracter = 'A';

    int vector[5] = {10, 20, 30, 40, 50};
    char cadena[] = "abcde";

    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int *puntero = &entero;
    int *pvector = vector;

    int i;
    int fila;
    int columna;
    int suma = 0;

    printf("Inicio del programa\n");

    /* BLOQUE A: variables escalares */
    entero = entero + 5;
    real = real * 2.0f;
    real_doble = real_doble / 2.0;
    caracter = caracter + 1;

    /* BLOQUE B: vector */
    for (i = 0; i < 5; i++) {
        vector[i] = vector[i] + 1;
    }

    /* BLOQUE C: cadena de caracteres */
    cadena[2] = 'X';

    /* BLOQUE D: matriz */
    for (fila = 0; fila < 2; fila++) {
        for (columna = 0; columna < 3; columna++) {
            matriz[fila][columna] =
                matriz[fila][columna] + 10;
        }
    }

    /* BLOQUE E: punteros */
    *puntero = 50;

    pvector++;

    *pvector = *pvector + 100;

    /* BLOQUE F: revisar cuidadosamente con el debugger */
    for (i = 0; i < 4; i++) {
        suma = suma + vector[i];
    }

    printf("\nEstado final:\n");
    printf("entero = %d\n", entero);
    printf("real = %.2f\n", real);
    printf("real_doble = %.6f\n", real_doble);
    printf("caracter = %c\n", caracter);
    printf("cadena = %s\n", cadena);
    printf("suma = %d\n", suma);

    return 0;
}