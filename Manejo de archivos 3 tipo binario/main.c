#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[10];
    int edad;
}ePersona;

int main()
{
    ePersona auxiliar;
    int cantidadEscrita;
    FILE *pArchivo;

    strcpy(auxiliar.nombre, "Andres");
    auxiliar.edad = 21;

    pArchivo = fopen("dos.bin", "wb");

    if(pArchivo == NULL)
    {
        exit(1);
    }

    cantidadEscrita = fwrite(&auxiliar, sizeof(auxiliar), 1, pArchivo);
    if(cantidadEscrita<1)
    {
        printf("\nError al escribir el archivo.");
    }

    fclose(pArchivo); //IMPORTANTISIMO CERRAR SIEMPRE EL ARCHIVO ANTES DE FINALIZAR EL PROGRAMA!!

    return 0;
}
