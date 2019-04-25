#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define TAM 16
#define TAMSEC 5

typedef struct
{
    int id;
    char descripcion[20];
}eSector;

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
    char sexo;
    float sueldo;
    eFecha fecha;
    int idSector;
    int ocupado;
} eEmpleado;

int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
void bajaEmpleado(eSector sectores[], int tamsec, eEmpleado vec[], int tam);
void ModificacionEmpleado(eSector sectores[], int tamsec, eEmpleado vec[], int tam);
void sumarSueldos(eEmpleado vec[], int tam);
void empleadosQueMasGanan(eEmpleado vec[], int tam);
void mostrarSectores(eSector sectores[], int tamsec);
int obtenerNombreDeSector(eSector sectores[], int tam, int idSector, char desc[]);


int main()
{
    char seguir = 's';
    char confirma;
    eSector sectores[] =
    {
        {1, "Sistemas"},
        {2, "Ventas"},
        {3, "RRHH"},
        {4, "Industria"},
        {5, "Medicina"},
    };

    eEmpleado lista[TAM]=
    {
        {1234, "Juan", 'm', 30000,{12,3,2000},5, 1},
        {2222, "Ana", 'f', 32000, {2,7,2010}, 2, 1},
        {2211, "Jorge", 'm', 28000,{14,5,2013}, 2, 1},
        {3241, "Alberto", 'm', 35000, {2,9,2010},1, 1},
        {8944, "Sonia", 'f', 39000, {12,3,2012},3, 1},
        {2231, "Miguel", 'm', 29700, {28,7,2009}, 2, 0},
        {6578, "Adrian", 'm', 43200, {11,1,2016},5, 1},
        {3425, "Lucia", 'f', 32300, {19,10,2004}, 2, 1},
        {5546, "Gaston", 'm', 29760, {13,9,2006},4, 1},
        {7654, "Diego", 'm', 35000, {23,6,2010},1, 1},
        {9040, "Viviana", 'f', 47000,{18, 7,2011}, 1, 1},
        {7439, "Gustavo", 'm', 25000, {12,12,2003}, 4, 1},
        {7654, "Diego", 'm', 35000, {23,6,2010},1, 1},
        {9040, "Viviana", 'f', 47000,{18, 7,2011}, 1, 1},
        {7439, "Gustavo", 'm', 25000, {12,12,2003}, 4, 1}
    };
    //inicializarEmpleados(lista, TAM); // llamada

    do
    {
        switch(menu())
        {

        case 1:
            // printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 2:
            //printf("\nBaja empleado\n\n");
            bajaEmpleado(sectores, TAMSEC, lista, TAM);
            system("pause");
            break;

        case 3:
            //printf("\nModificacion empleado\n\n");
            ModificacionEmpleado(sectores, TAMSEC, lista,TAM);
            system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 6:
            sumarSueldos(lista, TAM);
            system("pause");
            break;

        case 7:
            empleadosQueMasGanan(lista, TAM);
            system("pause");
            break;
        case 8:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    int i;
    for(i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Total Sueldos\n");
    printf("7- Empleados que mas ganan\n");
    printf("8- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{

    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].ocupado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp)
{
    char nombreSector[20];
    int consiguioNombre;
    consiguioNombre = obtenerNombreDeSector(sectores, tam, emp.idSector, nombreSector);

    if(!consiguioNombre)
    {
        strcpy(nombreSector, "Sin definir");
    }

    printf("%d   %s   %c   %.2f   %02d/%02d/%02d   %s\n\n\n", emp.legajo, emp.nombre, emp.sexo,
                                                                 emp.sueldo, emp.fecha.dia, emp.fecha.mes,
                                                                 emp.fecha.anio, nombreSector);



}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int cont= 0;
    int i;
    for(i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {

            mostrarEmpleado(sectores, tam, vec[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
}

void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int indice;
    int legajo;
    int esta;

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("No hay lugar");
    }
    else
    {

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta == -1)
        {
            vec[indice].legajo = legajo;


            printf("Ingrese fecha de nacimiento dd mm aaaa: ");
            fflush(stdin);
            scanf("%d %d %d", &vec[indice].fecha.dia, &vec[indice].fecha.mes, &vec[indice].fecha.anio);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo);

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo);

            //Mostrando sectores..
            mostrarSectores(sectores, TAMSEC);

            printf("Ingrese sector: ");
            fflush(stdin);
            scanf("%d", &vec[indice].idSector);

            vec[indice].ocupado = 1;

            printf("\nEl empleado ha sido registrado con exito!!!\n\n");

        }
        else
        {

            printf("Ya existe un empleado con el legajo %d\n", legajo);

            mostrarEmpleado(sectores, tam, vec[esta]);
        }
    }
}

void bajaEmpleado(eSector sectores[], int tamsec, eEmpleado vec[], int tam){

    int legajo;
    char confirma;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1){

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
        mostrarEmpleado(sectores, tam, vec[esta]);

        printf("\nConfirma la eliminacion? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            vec[esta].ocupado = 0;
        }
        else{
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }





}

void ModificacionEmpleado(eSector sectores[], int tamsec, eEmpleado vec[], int tam){

    int legajo;
    char confirma;
    float nuevoSueldo;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1){

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
        mostrarEmpleado(sectores, tam, vec[esta]);

        printf("\nQuiere cambiar el sueldo? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);
            //valido sueldo
            vec[esta].sueldo = nuevoSueldo;
        }
        else{
            printf("\nNo se ha modificado el sueldo\n");
        }

    }





}

void sumarSueldos(eEmpleado vec[], int tam)
{
    int i;
    int totalSueldo = 0;
    for(i=0; i<tam; i++)
    {
        if(vec[i].sueldo >= 0)
        {
        totalSueldo = totalSueldo + vec[i].sueldo;
        fflush(stdin);
        }
    }
    printf("El total de todos los sueldos es: %d \n", totalSueldo);

}

void empleadosQueMasGanan(eEmpleado vec[], int tam)
{
    int flag = 0;
    int i;
    int maximo;
    char maximoEmp[20];

    for(i=0; i<tam; i++)
    {
        if(flag == 0)
        {
            maximo = vec[i].sueldo;
            strcpy(maximoEmp, vec[i].nombre);
            flag = 1;
        }

        if(vec[i].sueldo > maximo)
        {
            maximo = vec[i].sueldo;
            strcpy(maximoEmp, vec[i].nombre);
        }
    }
    printf("El empleado con mejor sueldo es: %s. Con un sueldo de: %d \n\n", maximoEmp, maximo);
}

void mostrarSectores(eSector sectores[], int tamsec)
{
    int i;
    printf("\n    Sectores");
    printf("\n ----------------- ");
    printf("\n Id      Descripcion\n");
    for(i=0; i<tamsec; i++) //Recorro todos los sectores ;D
    {
        printf("  %d      %10s\n", sectores[i].id, sectores[i].descripcion);
        fflush(stdin);
    }
    printf("\n\n");
}

int obtenerNombreDeSector(eSector sectores[], int tam, int idSector, char desc[])
{
    int i;
    int todoOk = 0;
    for(i=0; i<tam; i++)
    {
        if(idSector == sectores[i].id)
        {
            strcpy(desc, sectores[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}




