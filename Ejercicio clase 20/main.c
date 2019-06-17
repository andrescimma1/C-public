#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[32];
    int edad;
}Persona;

int main()
{
    Persona personas[5];
    int indice = 0;
    /*
    printf("Ingrese nombre: ");
    gets(personas[indice].nombre);
    while(strcmp(personas[indice].nombre, "salir") == 0)
    {
        printf("Ingrese nombre: ");
        gets(personas[indice].nombre);
    }
    printf("Ingrese edad: ");
    scanf("%d", &personas[indice].edad);

    printf("%s   %d\n", personas[indice].nombre, personas[indice].edad);
    */

    do
    {
        printf("Ingrese nombre: ");
        gets(personas[indice].nombre);
        if(strcmp(personas[indice].nombre, "salir") != 0)
        {
            printf("Ingrese edad: ");
            scanf("%d", &personas[indice].edad);
            indice++;
        }
    }while(strcmp(personas[indice].nombre, "salir") != 0);

    int i;
    for(i=0; i<5; i++)
    {
        if(strcmp(personas[i].nombre, "salir") != 0)
        {
            printf("%s   %d\n", personas[i].nombre, personas[i].edad);
        }
    }
    return 0;
}
