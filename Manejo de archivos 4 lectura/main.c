#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cantidadLeida, longitudTexto;
    char texto[50];
    FILE *pArchivo;

    pArchivo = fopen("./lectura.txt", "r");

    if(pArchivo == NULL)
    {
        printf("Error de apertura\n");
    }

    longitudTexto = 50;

    while(!feof(pArchivo)) //Mientras no se haya cerrado el archivo..
    {
        cantidadLeida = fread(texto, sizeof(char), longitudTexto, pArchivo);
        printf("El texto leido es: %s", texto);
    }

    fclose(pArchivo);

    return 0;
}
