#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    char sexo;
    eFecha fechaIngreso;
}eEmpleado;

void mostrarEmpleado(eEmpleado* empleado);
void mostrarEmpleados(eEmpleado* empleados, int tam);

int main()
{

    eEmpleado lista = {
                        {1234, "Juan", 34000, 'm', {21, 9, 2019}},
                        {1252, "Ana", 41200, 'f', {15, 3, 2019}},
                        {1261, "Mario", 34440, 'm', {3, 4, 2019}}
                      };

    eEmpleado* pEmp;

    pEmp = &lista;

    mostrarEmpleados(pEmp, 3);
    return 0;
}

void mostrarEmpleado(eEmpleado* empleado)
{
    printf("%d    %s     %.2f     %c      %02d/%02d/%d\n", empleado->legajo, empleado->nombre, empleado->sueldo,
                                                           empleado->sexo, empleado->fechaIngreso.dia,
                                                           empleado->fechaIngreso.mes,
                                                           empleado->fechaIngreso.anio);
}

void mostrarEmpleados(eEmpleado* empleados, int tam)
{
    printf("Legajo    Nombre    Sueldo    Sexo    Fecha\n\n");
    int i;
    for(i=0; i<tam; i++)
    {
        mostrarEmpleado(empleados + i);
    }

    printf("%s", (*(empleados + 1)).nombre);
}
