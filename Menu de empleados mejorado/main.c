#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define TAM 6

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
    int ocupado;
    eFecha fechaIngreso;

}eEmpleado;

int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam);
void altaEmpleado(eEmpleado vec[], int tam);
void bajaEmpleado(eEmpleado vec[], int tam);
void ModificacionEmpleado(eEmpleado vec[], int tam);
void hardCodearEmpleados(eEmpleado vec[], int tam);
void empleadosXanio(eEmpleado vec[], int tam, int anio);

int main()
{
    char seguir = 's';
    char confirma;
    int anio;
    eEmpleado lista[TAM];
    inicializarEmpleados(lista, TAM); // llamada
    do
    {
        switch(menu())
        {

        case 1:
            // printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM);
            system("pause");
            break;

        case 2:
            //printf("\nBaja empleado\n\n");
            bajaEmpleado(lista, TAM);
            system("pause");
            break;

        case 3:
            //printf("\nModificacion empleado\n\n");
            ModificacionEmpleado(lista,TAM);
            system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM);
            system("pause");
            break;

        /*case 6:
            printf("\nInformes\n");
            printf("Ingrese el año: ");
            fflush(stdin);
            scanf("%d", &anio);
            empleadosXanio(lista, TAM, eEmpleado.fechaIngreso.anio);*/

        case 6:
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

void inicializarEmpleados(eEmpleado vec[], int tam)  //Esta funcion inicializa los empleados y pone como limite 2 empleados.
{
    int i;
    for(i=0; i<tam; i++)
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
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;
    int i;

    for(i=0; i < tam; i++)  //Se ejecuta dos veces
    {
        if(vec[i].ocupado == 0)   //Si algun campo del vector no está ocupado
        {
            indice = i;           //indice toma el valor de i
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int i;
    int indice = -1;

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

void mostrarEmpleado(eEmpleado emp) //Funcion para usarla dentro de "mostrarEmpleados"
{

    printf("  %d   %s   %c    %.2f    %02d/%02d/%d\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio);

}

void mostrarEmpleados(eEmpleado vec[], int tam)  //Funcion que te muestra los empleados, y en caso de que no...
{                                                //.. haya empleados, muestra en mensaje que no los hay.
    int cont= 0;
    int i;

    for(i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {

            mostrarEmpleado(vec[i]);    //Llamando a la funcion para que muestre a un empleado, y como está en...
            cont++;                     //.. un bucle for se va a repetir 2 ve
        }
    }
    if(cont == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
}

void altaEmpleado(eEmpleado vec[], int tam)
{
    int indice;
    int legajo;
    int esta;

    indice = buscarLibre(vec, tam);  //Se llama a la funcion buscarLibre para saber si hay espacio para agregar un nuevo empleado

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

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo);

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo);

            printf("Ingrese fecha de ingreso dd mm aaaa: ");
            fflush(stdin);
            scanf("%d %d %d", &vec[indice].fechaIngreso.dia, &vec[indice].fechaIngreso.mes, &vec[indice].fechaIngreso.anio);



            vec[indice].ocupado = 1;

            printf("\nEl empleado ha sido registrado con exito!!!\n\n");

        }
        else
        {

            printf("Ya existe un empleado con el legajo %d\n", legajo);

            mostrarEmpleado(vec[esta]);
        }
    }
}

void bajaEmpleado(eEmpleado vec[], int tam){

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
        mostrarEmpleado(vec[esta]);

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

void ModificacionEmpleado(eEmpleado vec[], int tam){

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
        mostrarEmpleado(vec[esta]);

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

void hardCodearEmpleados(eEmpleado vec[], int tam)
{
    eEmpleado empleados[10] = {
        {1234, "Juan", 'm', 24000,{5, 4, 2009}, 1},
        {3234, "Juana", 'f', 21200,{12, 9, 2008}, 1},
        {1278, "Alberto", 'm', 32100,{4, 11, 2012}, 1},
        {2133, "Sofia", 'f', 66500,{21, 6, 2011}, 1},
        {7681, "Claudia", 'f', 87660,{3, 8, 2009}, 1},
        {2311, "Esteban", 'm', 23444,{28, 12, 2011}, 1}};

    int i;
    for(i=0; i < tam; i++)
    {
        vec[i] = empleados[i];
    }

}

void empleadosXanio(eEmpleado vec[], int tam, int anio)
{
    int cont= 0;
    int i;

    for(i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].fechaIngreso.anio == anio)
        {

            mostrarEmpleado(vec[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
}

}

