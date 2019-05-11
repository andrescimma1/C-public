#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#define TAMAUT 10
#define TAMMAR 5
#define TAMCOL 5

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

typedef struct
{
    int id;
    char patente[10];
    int idMarca;
    int idColor;
    int modelo;
}eAuto;

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

typedef struct
{
    int id;
    char patente[10];
    int idServicio;
    eFecha fecha;
}eTrabajo;

//Prototipos
char menu();
void inicializarAutos(eAuto autos[], int tamaut);
void listarAuto(eAuto autos, int tamaut, eMarca marcas, int tammar, eColor colores, int tamcol);
void listarAutos(eAuto autos[], int tamaut, eMarca marcas, int tammar, eColor colores, int tamcol);
void altaAuto(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores [], int tamcol);

int main()
{
    char seguir = 's';
    eAuto autos[TAMAUT];
    inicializarAutos(autos, TAMAUT);

    eMarca marcas[] =
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"},
    };

    eColor colores[] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"},
    };

    eServicio servicios[] =
    {
        {20000, "Lavado: $", 250},
        {20001, "Pulido: $", 300},
        {20002, "Encerado: $", 400},
        {20003, "Completo: $", 600},
    };

    do
    {
        switch(menu())
        {
            case 'a':
                altaAuto(autos, TAMAUT, marcas, TAMMAR, colores, TAMCOL);
                system("pause");
                break;
            case 'b':
                printf("\nAnda bien\n");
                system("pause");
                break;
            case 'c':
                printf("\nAnda bien\n");
                system("pause");
                break;
            case 'd':
                listarAutos(autos, TAMAUT, marcas, TAMMAR, colores, TAMCOL);
                system("pause");
                break;
            case 'e':
                printf("\nAnda bien\n");
                system("pause");
                break;
            case 'f':
                printf("\nAnda bien\n");
                system("pause");
                break;
            case 'g':
                printf("\nAnda bien\n");
                system("pause");
                break;
            case 'h':
                printf("\nAnda bien\n");
                system("pause");
                break;
            case 'i':
                printf("\nAnda bien\n");
                system("pause");
                break;
            default:
                printf("\nError, opcion invalida\n");
                system("pause");
                break;
        }
    }while(seguir == 's');
    return 0;
}

/** \brief Menu de opciones donde se muestran las opciones y el usuario elige una. Si la ingresa en mayúscula no importa
 *          porque tiene un "tolower" que la pasa a minúscula.
 * \param char opcion;
 * \param
 * \return Devuelve la opcion elegida.
 *
 */

char menu()
{
    char opcion;

    printf("*** MENU DE OPCIONES ***\n\n");
    printf("A. ALTA AUTO\n");
    printf("B. MODIFICAR AUTO\n");
    printf("C. BAJA AUTO\n");
    printf("D. LISTAR AUTOS\n");
    printf("E. LISTAR MARCAS\n");
    printf("F. LISTAR COLORES\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. ALTA TRABAJO\n");
    printf("I. LISTAR TRABAJOS\n\n");
    printf("Ingrese una opcion: ");
    scanf("%c", &opcion);

    opcion = tolower(opcion);
    printf("Opcion: %c", opcion);

    return opcion;
}

void inicializarAutos(eAuto autos[], int tamaut)
{
    int i;
    for(i=0; i<tamaut; i++)
    {
        autos[i].id = 0;
    }
}

void altaAuto(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores [], int tamcol)
{
    system("cls");

    int i;
    int indice = -1;
    for(i=0; i<tamaut; i++)
    {
        if(autos[i].id == 0)
        {
            indice = i;
            break;
        }
    }

    printf("Ingrese patente: ");
    fflush(stdin);
    gets(autos[indice].patente);

    printf("\n\n");

    for(i=0; i<tammar; i++)
    {
        printf("%d    %s\n", marcas[i].id, marcas[i].descripcion);
    }

    printf("\nIngrese marca: ");
    fflush(stdin);
    scanf("%d", &autos[indice].idMarca);

    while(autos[indice].idMarca <= 999 || autos[indice].idMarca >= 1005)
    {
        printf("\nError, ingrese marca: ");
        fflush(stdin);
        scanf("%d", &autos[indice].idMarca);
    }

    printf("\n\n");

    for(i=0; i<tamcol; i++)
    {
        printf("%d    %s\n", colores[i].id, colores[i].nombreColor);
    }

    printf("\nIngrese color: ");
    fflush(stdin);
    scanf("%d", &autos[indice].idColor);

    while(autos[indice].idColor <= 4999 || autos[indice].idColor >= 5005)
    {
        printf("\nError, ingrese marca: ");
        fflush(stdin);
        scanf("%d", &autos[indice].idColor);
    }

    autos[indice].id = 1;

}

void modificarAuto(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol)
{
    char patenteIngresada[20];
    int i, j, k;

    system("cls");

    printf("Ingrese la patente: ");
    gets(patenteIngresada);

    for(i=0; i<tamaut; i++)
    {
        if(patenteIngresada == autos[i].patente)
        {
            printf("\n\n");

            for(j=0; j<tammar; j++)
                {
                    printf("%d    %s\n", marcas[j].id, marcas[j].descripcion);
                }
            printf("\nIngrese marca: ");
            fflush(stdin);
            scanf("%d", &autos[i].idMarca);

            printf("\n\n");

            for(k=0; k<tamcol; k++)
                {
                    printf("%d    %s\n", colores[k].id, colores[k].nombreColor);
                }

                printf("\nIngrese color: ");
                fflush(stdin);
                scanf("%d", &autos[i].idColor);
            break;
        }
    }

}

void listarAuto(eAuto autos, int tamaut, eMarca marcas, int tammar, eColor colores, int tamcol)
{
    int i, j;
    char marcaEncontrada[20];
    char colorEncontrado[20];

    for(i=0; i<tammar; i++)
    {
        if(autos.idMarca == marcas[i].id)
        {
            marcaEncontrada = marcas[i].descripcion;
            break;
        }
    }

    for(i=0; i<tamcol; i++)
    {
        if(autos.idColor == colores[i].id)
        {
            colorEncontrado = colores[i].nombreColor;
            break;
        }
    }

    printf("\n%s      %s       %s", autos.patente, marcaEncontrada, colorEncontrado);
}

void listarAutos(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol)
{

    int cont= 0;
    int i;
    for(i=0; i < tamaut; i++)
    {
        if(autos[i].id == 1)
        {
            listarAuto(autos[i], tamaut, marcas, tammar, colores, tamcol);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("\n\nNo hay autos que mostrar\n\n");
    }
}
