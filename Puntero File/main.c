#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE* f;
    char cadena[] = "utn fra";

    f = fopen("archivo.txt", "r");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    fprintf(f, "Esto es un texto %s\nY sigo en el renglon de abajo", cadena);
    fclose(f);

    return 0;
}
