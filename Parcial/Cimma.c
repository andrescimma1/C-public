#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

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
    printf("I. LISTAR TRABAJOS\n");
    printf("J. MOSTRAR AUTOS DE COLOR NEGRO\n");
    printf("S. SALIR\n\n");
    printf("Ingrese una opcion: ");
    scanf("%c", &opcion);

    opcion = tolower(opcion);
    printf("Opcion: %c", opcion);

    return opcion;
}

/** \brief Recorre el array de autos y pone todos los id en 0.
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void inicializarAutos(eAuto autos[], int tamaut)
{
    int i;
    for(i=0; i<tamaut; i++)
    {
        autos[i].id = 0;
    }
}

/** \brief Da de alta un auto, recibiendo patente, marca, color y modelo.
 *
 * \param int i;
 * \param int indice = -1;
 * \return No devuelve nada.
 *
 */
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

/** \brief Permite modificar un auto, se muestran todos los autos y el usuario tiene que ingresar la patente.
 *          Con ese dato se puede modificar el color y modelo del auto.
 * \param char patenteIngresada[20];
 * \param int j, k;
 * \param int esta;
 * \return No devuelve nada.
 *
 */
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

/** \brief Muestra un solo auto.
 *
 * \param int i, j;
 * \param char marcaEncontrada[20];
 * \param char colorEncontrado[20];
 * \return No devuelve nada.
 *
 */
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

/** \brief Muestra una lista con todos los autos, dentro de esta funcion está "listarAuto".
 *
 * \param int i;
 * \param int cont = 0;
 * \return No devuelve nada.
 *
 */
void listarAutos(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol)
{
    int cont = 0;
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

/** \brief Busca un auto en el array de autos, comparando la patente ingresada con las patentes del array.
 *
 * \param int i;
 * \param int indice = -1;
 * \return Devuelve el indice.
 *
 */
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

/** \brief Muestra en una lista todas las marcas.
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
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

/** \brief Muestra en una lista todos los colores.
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
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

/** \brief Muestra en una lista todos los servicios.
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
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

/** \brief Permite dar de baja un auto, ingresando la patente y confirmando su baja.
 *
 * \param int i;
 * \param char patenteIngresada[20];
 * \param char respuesta;
 * \return No devuelve nada.
 *
 */
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

/** \brief Recorre el array de trabajos y pone todos los id en 0.
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void inicializarTrabajos(eTrabajo trabajos[], int tamtra)
{
    int i;
    for(i=0; i<tamtra; i++)
    {
        trabajos[i].id = 0;
    }
}

/** \brief Permite dar de alta un trabajo, pidiendole al usuario que elija un auto y un servicio.
 *
 * \param int i, j, k;
 * \param int cont = 0;
 * \param int cont2 = 0;
 * \param char patenteIngresada[10];
 * \param int servicioIngresado;
 * \return Devuelve un acumulador.
 *
 */
int altaTrabajo(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol, eServicio servicios[], int tamser, eTrabajo trabajos[], int tamtra, int acumulador)
{
    int i, j, k;
    int indice = -1;
    char patenteIngresada[20];
    int servicioIngresado;

    for(i=0; i<tamtra; i++)
    {
        if(trabajos[i].id == 0)
        {
            indice = i;
            break;
        }
    }
    system("cls");

    listarAutos(autos, tamaut, marcas, tammar, colores, tamcol);
    printf("\n\nElija un auto por su patente: ");
    fflush(stdin);
    gets(patenteIngresada);
    for(j=0; j<tamaut; j++)
    {
       if(strcmp(patenteIngresada, autos[j].patente) == 0 && autos[j].id == 1)
       {
            strcpy(trabajos[indice].patente, patenteIngresada);
            break;
       }
    }

    listarServicios(servicios, tamser);
    printf("\n\nElija un servicio por su ID: ");
    fflush(stdin);
    scanf("%d", &servicioIngresado);
    for(k=0; k<tamser; k++)
    {
        if(servicioIngresado == servicios[k].id)
        {
            trabajos[indice].idServicio = servicioIngresado;
            break;
        }
    }

    printf("\n\nIngrese fecha dd mm aaaa: ");
    scanf("%d %d %d", &trabajos[indice].fecha.dia, &trabajos[indice].fecha.mes, &trabajos[indice].fecha.anio);


    printf("\nDatos ingresados con exito\n\n");
    trabajos[indice].id = acumulador + indice;
    acumulador = trabajos[indice].id;

    return acumulador;
}

/** \brief Permite listar todos los trabajos.
 *
 * \param int i;
 * \param int cont = 0;
 * \return No devuelve nada.
 *
 */
void listarTrabajos(eTrabajo trabajos[], int tamtra, eServicio servicios[], int tamser, eAuto autos[], int tamaut)
{
    int i;
    int cont = 0;

    system("cls");
    printf("Patente     Servicio     Fecha\n\n");
    for(i=0; i<tamtra; i++)
    {
        if(trabajos[i].id >= 1)
        {
            listarTrabajo(trabajos[i], tamtra, servicios, tamser, autos, tamaut);
            cont++;
            break;
        }
    }

    printf("\n\n");
    if(cont == 0)
    {
        printf("\n\nNo hay trabajos que mostrar\n\n");
    }
}

/** \brief Permite mostrar un trabajo.
 *
 * \param int i, j;
 * \param char patenteIngresada[10];
 * \param char servicioIngresado[20];
 * \return No devuelve nada.
 *
 */
void listarTrabajo(eTrabajo trabajos, int tamtra, eServicio servicios[], int tamser, eAuto autos[], int tamaut)
{
    int i, j;
    char patenteEncontrada[10];
    char servicioEncontrado[20];

    for(i=0; i<tamaut; i++)
    {
        if(strcmp(trabajos.patente, autos[i].patente) == 0)
        {
            fflush(stdin);
            strcpy(patenteEncontrada, autos[i].patente);
            break;
        }
    }

    for(j=0; j<tamser; j++)
    {
        if(trabajos.idServicio == servicios[j].id)
        {
            fflush(stdin);
            strcpy(servicioEncontrado, servicios[j].descripcion);
            break;
        }
    }

    printf("\n%s   %s    %02d/%02d/%02d", patenteEncontrada, servicioEncontrado, trabajos.fecha.dia, trabajos.fecha.mes, trabajos.fecha.anio);
}


