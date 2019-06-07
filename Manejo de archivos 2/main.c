#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cantidadEscrita, longitudTexto;
    char texto[] = "Hola mundo!!";
    FILE *pArchivo;

    pArchivo = fopen("uno.txt", "w");

    if(pArchivo == NULL)
    {
        printf("Error de apertura.\n");
        exit(1);
    }
    longitudTexto = strlen(texto);

    cantidadEscrita = fwrite(texto, sizeof(char), longitudTexto, pArchivo);
    if(cantidadEscrita<longitudTexto)
    {
        printf("\nError al escribir el archivo.\n");
    }

    fclose(pArchivo);
    return 0;
}
