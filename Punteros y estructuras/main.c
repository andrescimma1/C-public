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

int main()
{
    eEmpleado emp1 = {
                        {1234, "Juan", 34000, 'm', {21, 9, 2019}},
                       };

    eEmpleado* pEmp;

    pEmp = &emp1;

    printf("%s ", emp1.nombre);

    printf("%s ", pEmp->nombre);

    printf("%02d/%02d/%d\n\n", pEmp->fechaIngreso.dia, pEmp->fechaIngreso.mes, pEmp->fechaIngreso.anio);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(pEmp->nombre);

    printf("\n%s \n\n", pEmp->nombre);

    printf("Ingrese nuevo sueldo: ");
    scanf("%f", &pEmp->sueldo);

    printf("%.2f ", pEmp->sueldo);

    return 0;
}
