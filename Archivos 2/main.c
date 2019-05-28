#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    float sueldo;
}eEmpleado;

int main()
{
    eEmpleado* lista = (eEmpleado*)malloc(sizeof(eEmpleado));
    eEmpleado* auxEmpleado;
    int cont = 0;
    int i;

    char buffer[4][30];

    int cant;

    FILE* f = fopen("./MOCK_DATA.txt", "r");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    fscanf(f, "%[^,],%[^,],%[^,],%[^,],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    printf("%s %s %s %s\n", atoi(buffer[0]), buffer[1], buffer[2], atof(buffer[3]));

    while(!feof(f))   //Mientras no haya llegado al final del archiv
    {
        cant = fscanf(f, "%[^,],%[^,],%[^,],%[^,],\n", buffer[0], buffer[1], buffer[2], buffer[3]);


        if(cant < 4)
        {
            if(feof(f))
            {
                break;
            }
            else
            {
                printf("Problemas para leer el archivo\n");
                break;
            }

        }
        (lista + cont)->id = atoi(buffer[0]);
        strcpy( (lista + cont)->nombre, buffer[1]);
        strcpy( (lista + cont)->apellido, buffer[2]);
        (lista + cont)->sueldo = atof(buffer[3]);
        cont++;
        auxEmpleado = (eEmpleado*)realloc(lista, sizeof(eEmpleado)* (cont + 1));

        if(auxEmpleado != NULL)
        {
            lista = auxEmpleado;
        }
        printf("%5d %15s %15s %0.2s\n", atoi(buffer[0]), buffer[1], buffer[2], atof(buffer[3]));

    }
    printf("\n\n");
    fclose(f);

    for(i=0; i<cont; i++)
    {
        printf("%5d %15s %15s %0.2s\n", (lista + i)->id, (lista + i)->nombre, (lista + i)->apellido, (lista + i)->sueldo);
    }

    return 0;
}
