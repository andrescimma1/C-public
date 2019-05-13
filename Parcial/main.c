#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#define TAMAUT 10
#define TAMMAR 5
#define TAMCOL 5
#define TAMMOD 5
#define TAMSER 4
#define TAMTRA 10

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
void altaAuto(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores [], int tamcol);
void modificarAuto(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol);
void listarAuto(eAuto autos, int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol);
void listarAutos(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol);
int buscarAuto(eAuto autos[], int tamaut, char patenteIngresada[10]);
void listarMarcas(eMarca marcas[], int tammar);
void listarColores(eColor colores[], int tamcol);
void listarServicios(eServicio servicios[], int tamser);
void bajaAuto(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol);
void altaTrabajo(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol, eServicio servicios[], int tamser, eTrabajo trabajos[], int tamtra);
void listarTrabajos(eAuto autos[], int tamaut, eServicio servicios[], int tamser, eTrabajo trabajos[], int tamtra);

int main()
{
    char seguir = 's';
    eAuto autos[TAMAUT];
    eTrabajo trabajos[TAMTRA];
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
        {20000, "Lavado", 250},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600},
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
                modificarAuto(autos, TAMAUT, marcas, TAMMAR, colores, TAMCOL);
                system("pause");
                break;
            case 'c':
                bajaAuto(autos, TAMAUT, marcas, TAMMAR, colores, TAMCOL);
                system("pause");
                break;
            case 'd':
                listarAutos(autos, TAMAUT, marcas, TAMMAR, colores, TAMCOL);
                system("pause");
                break;
            case 'e':
                listarMarcas(marcas, TAMMAR);
                system("pause");
                break;
            case 'f':
                listarColores(colores, TAMCOL);
                system("pause");
                break;
            case 'g':
                listarServicios(servicios, TAMSER);
                system("pause");
                break;
            case 'h':
                altaTrabajo(autos, TAMAUT, marcas, TAMMAR, colores, TAMCOL, servicios, TAMSER, trabajos, TAMTRA);
                system("pause");
                break;
            case 'i':
                listarTrabajos(autos, TAMAUT, servicios, TAMSER, trabajos, TAMTRA);
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

    printf("\n\nID     MARCA\n");

    for(i=0; i<tammar; i++)
    {
        printf("%d    %s\n", marcas[i].id, marcas[i].descripcion);
    }

    printf("\nIngrese ID de la marca: ");
    fflush(stdin);
    scanf("%d", &autos[indice].idMarca);

    while(autos[indice].idMarca <= 999 || autos[indice].idMarca >= 1005)
    {
        printf("\nError, ingrese marca: ");
        fflush(stdin);
        scanf("%d", &autos[indice].idMarca);
    }

    printf("\n\nID     COLOR\n");

    for(i=0; i<tamcol; i++)
    {
        printf("%d    %s\n", colores[i].id, colores[i].nombreColor);
    }

    printf("\nIngrese ID del color: ");
    fflush(stdin);
    scanf("%d", &autos[indice].idColor);

    while(autos[indice].idColor <= 4999 || autos[indice].idColor >= 5005)
    {
        printf("\nError, ingrese marca: ");
        fflush(stdin);
        scanf("%d", &autos[indice].idColor);
    }

    printf("\nIngrese modelo: ");
    fflush(stdin);
    scanf("%d", &autos[indice].modelo);

    autos[indice].id = 1;


}

void modificarAuto(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol)
{
    char patenteIngresada[10];
    int j, k;
    int esta;

    system("cls");

    listarAutos(autos, tamaut, marcas, tammar, colores, tamcol);
    printf("Ingrese la patente: ");
    fflush(stdin);
    gets(patenteIngresada);
    esta = buscarAuto(autos, tamaut, patenteIngresada);
    printf("%s", patenteIngresada);

    if(esta == -1)
    {
        printf("\nLa patente ingresada no se encuentra disponible\n\n");
    }
    else
    {
        printf("\n\nID     MARCA\n");

        for(j=0; j<tammar; j++)
            {
                printf("%d    %s\n", marcas[j].id, marcas[j].descripcion);
            }
        printf("\nIngrese ID de la nueva marca: ");
        fflush(stdin);
        scanf("%d", &autos[esta].idMarca);

        printf("\n\nID     COLOR\n");

        for(k=0; k<tamcol; k++)
            {
                printf("%d    %s\n", colores[k].id, colores[k].nombreColor);
            }

        printf("\nIngrese la ID del nuevo color: ");
        fflush(stdin);
        scanf("%d", &autos[esta].idColor);
    }
}

void listarAuto(eAuto autos, int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol)
{
    int i, j;
    char marcaEncontrada[20];
    char colorEncontrado[20];

    for(i=0; i<tammar; i++)
    {
        if(autos.idMarca == marcas[i].id)
        {
            strcpy(marcaEncontrada, marcas[i].descripcion);
            break;
        }
    }

    for(j=0; j<tamcol; j++)
    {
        if(autos.idColor == colores[j].id)
        {
            strcpy(colorEncontrado, colores[j].nombreColor);
            break;
        }
    }



    printf("\n%10s   %10s   %10s   %d", autos.patente, marcaEncontrada, colorEncontrado, autos.modelo);
}

void listarAutos(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol)
{
    int cont= 0;
    int i;

    system("cls");
    printf("Patente     Marca     Color     Modelo\n\n");
    for(i=0; i<tamaut; i++)
    {
        if(autos[i].id == 1)
        {
            listarAuto(autos[i], tamaut, marcas, tammar, colores, tamcol);
            cont++;
        }
    }

    printf("\n\n");
    if(cont == 0)
    {
        printf("\n\nNo hay autos que mostrar\n\n");
    }
}

int buscarAuto(eAuto autos[], int tamaut, char patenteIngresada[10])
{
    int i;
    int indice = -1;
    for(i=0; i<tamaut; i++)
    {
        if(strcmp(patenteIngresada, autos[i].patente) == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void listarMarcas(eMarca marcas[], int tammar)
{
    int i;
    printf("\n\nListado de Marcas\n\n");
    printf("ID      MARCA\n");

    for(i=0; i<tammar; i++)
    {
        printf("%d      %s\n", marcas[i].id, marcas[i].descripcion);
    }
    printf("\n\n");
}

void listarColores(eColor colores[], int tamcol)
{
    int i;
    printf("\n\nListado de Colores\n\n");
    printf("ID      COLOR\n");

    for(i=0; i<tamcol; i++)
    {
        printf("%d      %s\n", colores[i].id, colores[i].nombreColor);
    }
    printf("\n\n");
}

void listarServicios(eServicio servicios[], int tamser)
{
    int i;
    printf("\n\nListado de Servicios\n\n");
    printf("ID      Descripcion      Precio\n");

    for(i=0; i<tamser; i++)
    {
        printf("%d      %10s      $%d\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
    }
    printf("\n\n");
}

void bajaAuto(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol)
{
    int i;
    char patenteIngresada[20];
    char respuesta;
    system("cls");

    listarAutos(autos, tamaut, marcas, tammar, colores, tamcol);
    printf("Ingrese la patente: ");
    fflush(stdin);
    gets(patenteIngresada);

    for(i=0; i<tamaut; i++)
    {
        if(strcmp(patenteIngresada, autos[i].patente) == 0)
        {
            listarAuto(autos[i], tamaut, marcas, tammar, colores, tamcol);
            printf("\n\nSeguro que quiere dar de baja el auto (s/n): ");
            fflush(stdin);
            scanf("%c", &respuesta);
            respuesta = tolower(respuesta);
            if(respuesta == 's')
            {
                autos[i].id = 0;
                printf("\nLa eliminacion se ha realizado con exito\n\n");
            }
            else
            {
                printf("\nLa eliminacion ha sido cancelada\n\n");
            }
        }
    }
}

void altaTrabajo(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol, eServicio servicios[], int tamser, eTrabajo trabajos[], int tamtra)
{
    int i, j, k;
    int cont = 0;
    char patenteIngresada[10];
    int servicioIngresado;

    listarAutos(autos, tamaut, marcas, tammar, colores, tamcol);
    printf("\n\nElija un auto por su patente: ");
    fflush(stdin);
    gets(patenteIngresada);
    listarServicios(servicios, tamser);
    printf("\n\nElija un servicio por su ID: ");
    fflush(stdin);
    scanf("%d", &servicioIngresado);

    for(i=0; i<tamtra; i++)
    {
        for(j=0; j<tamaut; j++)
        {
            if(strcmp(patenteIngresada, autos[j].patente) == 0)
            {
                strcpy(trabajos[i].patente, patenteIngresada);
                break;
            }
        }

        for(k=0; k<tamser; k++)
        {
            if(servicioIngresado == servicios[k].id && autos[j].id == 1)
            {
                trabajos[i].idServicio = servicioIngresado;
                cont++;
                break;
            }
        }
    }
    if(cont == 0)
    {
        printf("\nError, patente o ID servicio incorrecto\n\n");
    }
    else
    {
        printf("\nDatos ingresados con exito");
    }
}

void listarTrabajos(eAuto autos[], int tamaut, eServicio servicios[], int tamser, eTrabajo trabajos[], int tamtra)
{
    int i, j, k;
    int cont1 = 0;
    int cont2 = 0;
    char patenteEncontrada[10];
    char servicioEncontrado[20];
    system("cls");
    printf("Listado de Trabajos\n\n");

    for(i=0; i<tamtra; i++)
    {
        for(j=0; j<tamaut; j++)
        {
            if(trabajos[i].patente == autos[j].patente)
            {
                strcpy(patenteEncontrada, autos[j].patente);
                cont1++;
                break;
            }
        }
        for(k=0; k<tamser; k++)
        {
            if(trabajos[i].idServicio == servicios[j].id)
            {
                strcpy(servicioEncontrado, servicios[j].descripcion);
                cont2++;
                break;
            }
        }
        if(cont1 > 0 && cont2 > 0)
        {
            printf("\n%s    %s", patenteEncontrada, servicioEncontrado);
        }
        cont1 = 0;
        cont2 = 0;
    }
}
