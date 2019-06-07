#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pArchivo;

    pArchivo = fopen("uno.txt", "rb");

    if(pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    fclose(pArchivo);
    return 0;
}
