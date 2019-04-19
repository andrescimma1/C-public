#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
}Eempleado;

int main()
{
    char auxCad[100];
    Eempleado emp1; //Le pasamos el contenido de la estructura a "emp1"

    Eempleado nomina[] = {{1111, "andres", 'm',  45000},{2222, "laura", 'f', 32000},{3333, "daniela", 'f', 65300}};




    /*
    printf("Ingrese legajo: ");
    scanf("%d", &emp1.legajo);
    while(emp1.legajo < 0)
    {
        printf("Error ingrese legajo: ");
        scanf("%d", &emp1.legajo);
    }

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad) > 19)
    {
        printf("Error. Nombre demasiado largo. Reingrese nombre: ");
        fflush(stdin);
        gets(auxCad);
    }

    strcpy(emp1.nombre, auxCad);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &emp1.sexo);
    while(emp1.sexo != 'f' && emp1.sexo != 'm')
    {
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &emp1.sexo);
    }

    printf("Ingrese sueldo: ");
    scanf("%f", &emp1.sueldo);

    printf("\nLegajo %d", emp1.legajo);
    printf("\nNombre %s", emp1.nombre);
    printf("\nSexo %c", emp1.sexo);
    printf("\nSueldo %.2f", emp1.sueldo);
    */
    printf("Legajo  Nombre  Sexo   Sueldo\n");
    printf("%d    %s  %c      %.2f\n", nomina[0].legajo, nomina[0].nombre, nomina[0].sexo, nomina[0].sueldo);
    printf("%d    %s   %c      %.2f\n", nomina[1].legajo, nomina[1].nombre, nomina[1].sexo, nomina[1].sueldo);
    printf("%d    %s %c      %.2f\n", nomina[2].legajo, nomina[2].nombre, nomina[2].sexo, nomina[2].sueldo);
    return 0;
}
