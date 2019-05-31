#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAMAUT 10
#define TAMMAR 5
#define TAMCOL 5
#define TAMSER 4

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
    char patente[7];
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
    char patente[7];
    int idServicio;
    eFecha fecha;
}eTrabajo;

//Prototipos
void inicializarAutos(eAuto* listaut, int len);
int menu();
int buscarLibre(eAuto* listaut, int len);
void altaAuto(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores);
void listarMarcas(eMarca* listmarcas, int lenmarcas);
void listarColores(eColor* listcolores, int lencolores);
int listarAutos(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores);
void listarAuto(eAuto* pAuto, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores);
void listarServicios(eServicio* listservicios, int lenservicios);
void bajaAuto(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores);
void modificarAuto(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores);

int main()
{
    char seguir = 's';

    eMarca arrayMarcas[] = {
                           {1000, "Renault"},
                           {1001, "Fiat"},
                           {1002, "Ford"},
                           {1003, "Chevrolet"},
                           {1004, "Peugeot"}
                           };
    eColor arrayColores[] = {
                            {5000, "Negro"},
                            {5001, "Blanco"},
                            {5002, "Gris"},
                            {5003, "Rojo"},
                            {5004, "Azul"}
                            };

    eServicio arrayServicios[] = {
                                 {20000, "Lavado", 250},
                                 {20001, "Pulido", 300},
                                 {20002, "Encerado", 400},
                                 {20003, "Completo", 600}
                                 };

    eAuto arrayAutos[TAMAUT];
    inicializarAutos(arrayAutos, TAMAUT);

    do
    {
        switch(menu())
        {
            case 'a':
                altaAuto(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL);
                system("pause");
                break;
            case 'b':
                modificarAuto(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL);
                system("pause");
                break;
            case 'c':
                bajaAuto(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL);
                system("pause");
                break;
            case 'd':
                listarAutos(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL);
                system("pause");
                break;
            case 'e':
                listarMarcas(arrayMarcas, TAMMAR);
                system("pause");
                break;
            case 'f':
                listarColores(arrayColores, TAMCOL);
                system("pause");
                break;
            case 'g':
                listarServicios(arrayServicios, TAMSER);
                system("pause");
                break;
            case 'h':

                system("pause");
                break;
            case 'i':

                system("pause");
                break;
            default:
                system("cls");
                printf("Opcion ingresada no valida\n\n");
                system("pause");
                break;
        }
    }while(seguir == 's');

}

/** \brief Inicializa el id de los autos en 0;
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */

void inicializarAutos(eAuto* listaut, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        listaut[i].id = 0;
    }
}

/** \brief Se crea un menu de opciones y pide al usuario que ingrese una opcion.
 *
 * \param int opcion;
 * \param
 * \return Devuelve la opcion elegida por el usuario.
 *
 */

int menu()
{
    char opcion;

    printf("*** MENU DE OPCIONES ***\n");
    printf("________________________\n\n");
    printf("A. Alta auto.\n");
    printf("B. Modificar auto\n");
    printf("C. Baja auto.\n");
    printf("D. Listar autos.\n");
    printf("E. Listar marcas.\n");
    printf("F. Listar colores.\n");
    printf("G. Listar servicios.\n");
    printf("H. Alta trabajo.\n");
    printf("I. Listar trabajos.\n\n");

    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    opcion = tolower(opcion);

    return opcion;
}

/** \brief Busca el primer espacio libre, si no se encuentra devolerá -1.
 *
 * \param int i;
 * \param int indice;
 * \return Devuelve el espacio libre encontrado (indice).
 *
 */

int buscarLibre(eAuto* listaut, int len)
{
    int i;
    int indice = -1;

    for(i=0; i<len; i++)
    {
        if(listaut[i].id == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void altaAuto(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores)
{
    int indice;

    system("cls");

    indice = buscarLibre(listaut, len);

    if(indice == -1)
    {
        printf("No hay espacio libre\n\n");
    }
    else
    {
        //Pido la patente.
        printf("Ingrese patente: ");
        fflush(stdin);
        gets(listaut[indice].patente);

        //Pido el id de la marca.
        listarMarcas(listmarcas, lenmarcas);
        printf("Ingrese la ID de su marca: ");
        fflush(stdin);
        scanf("%d", &listaut[indice].idMarca);

        //Pido el id del color.
        listarColores(listcolores, lencolores);
        printf("Ingrese la ID del color: ");
        fflush(stdin);
        scanf("%d", &listaut[indice].idColor);

        system("cls");

        printf("Ingrese modelo: ");
        scanf("%d", &listaut[indice].modelo);

        listaut[indice].id = 1;
    }

}

/** \brief Muestra una lista de todas las marcas con su id y su descripcion.
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */

void listarMarcas(eMarca* listmarcas, int lenmarcas)
{
    int i;

    system("cls");

    printf("Listado de marcas\n");
    printf("_____________________\n");
    printf("ID          MARCA\n");

    for(i=0; i<lenmarcas; i++)
    {
        printf("%d      %10s\n", listmarcas[i].id, listmarcas[i].descripcion);
    }
}

/** \brief Muestra una lista de todos los colores con su id y su descripcion.
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */

void listarColores(eColor* listcolores, int lencolores)
{
    int i;

    system("cls");

    printf("Listado de colores\n");
    printf("_____________________\n");
    printf("ID          COLOR\n");

    for(i=0; i<lencolores; i++)
    {
        printf("%d      %10s\n", listcolores[i].id, listcolores[i].nombreColor);
    }
}

/** \brief Muestra un solo auto, pero se puede usar en la funcion listarAutos.
 *
 * \param int i, j;
 * \param char marcaEncontrada[20], colorEncontrado[20];
 * \return No devuelve nada.
 *
 */

void listarAuto(eAuto* pAuto, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores)
{
    int i, j;
    char marcaEncontrada[20];
    char colorEncontrado[20];

    for(i=0; i<lenmarcas; i++)
    {
        if(pAuto->idMarca == listmarcas[i].id)
        {
            strcpy(marcaEncontrada, listmarcas[i].descripcion);
            break;
        }
    }

    for(j=0; j<lencolores; j++)
    {
        if(pAuto->idColor == listcolores[j].id)
        {
            strcpy(colorEncontrado, listcolores[j].nombreColor);
            break;
        }
    }

    printf("%7s    %7s    %7s    %d\n", pAuto->patente, marcaEncontrada, colorEncontrado, pAuto->modelo);
}


/** \brief Muestra una lista con todos los autos.
 *
 * \param int i;
 * \param int indice = -1;
 * \return Devuelve -1 si no se encontraron autos, o devuelve 0 si se encontraron.
 *
 */

int listarAutos(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores)
{
    int i;
    int indice = -1;

    system("cls");

    printf("Listado de autos\n");
    printf("____________________________________\n");
    printf("PATENTE    MARCA    COLOR    MODELO\n");

    for(i=0; i<len; i++)
    {
        if(listaut[i].id == 1)
        {
            indice = 0;
            listarAuto((listaut + i), listmarcas, lenmarcas, listcolores, lencolores);
        }
    }

    if(indice == -1)
    {
        printf("\nNo hay autos que mostrar\n\n");
    }

    printf("\n\n");

    return indice;
}

/** \brief Muestra una lista de todos los servicios.
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */

void listarServicios(eServicio* listservicios, int lenservicios)
{
    int i;

    system("cls");

    printf("Listado de servicios\n");
    printf("___________________________\n");
    printf("ID     DESCRIPCION     PRECIO\n");

    for(i=0; i<lenservicios; i++)
    {
        printf("%d     %10s    $ %d\n", listservicios[i].id, listservicios[i].descripcion, listservicios[i].precio);
    }
}

/** \brief Lista todos los autos, le pregunta al usuario la patente del auto que quiere ser
 * dado de baja. Recorre los autos para encontrar esa patente y realiza una baja lógica.
 *
 * \param int i, indice = -1;
 * \param char patenteIngresada[7], seguro;
 * \return No devuelve nada.
 *
 */

void bajaAuto(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores)
{
    int i;
    char patenteIngresada[7];
    char seguro;
    int indice = -1;

    indice = listarAutos(listaut, len, listmarcas, lenmarcas, listcolores, lencolores);

    if(indice == 0)
    {
        printf("\n\nIngrese patente del auto que desea dar de baja: ");
        fflush(stdin);
        gets(patenteIngresada);

        for(i=0; i<len; i++)
        {
            if(strcmp(patenteIngresada, listaut[i].patente) == 0)
            {
                printf("\n\n");
                listarAuto((listaut + i), listmarcas, lenmarcas, listcolores, lencolores);

                printf("\nSeguro que quiere dar de baja este auto?(s/n): ");
                fflush(stdin);
                scanf("%c", &seguro);
                if(seguro == 's')
                {
                    listaut[i].id = 0;
                    printf("\n\nEl auto fue dado de baja con exito!!\n\n");
                    break;
                }
                else
                {
                    printf("\n\nSe ha cancelado la operacion\n\n");
                    break;
                }
            }
        }
    }
}

/** \brief Lista todos los autos, si no hay autos muestra un mensaje en base a ello, sino
 *  pide la patente del auto y da a elegir para modificar el color o el modelo.
 *
 * \param int i;
 * \param int indice = -1;
 * \param int idModificacion;
 * \param char patenteIngresada[7];
 * \return No devuelve nada.
 *
 */

void modificarAuto(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores)
{
    int i;
    int indice = -1;
    int idModificacion;
    char patenteIngresada[7];

    indice = listarAutos(listaut, len, listmarcas, lenmarcas, listcolores, lencolores);

    if(indice == -1)
    {
        printf("\n\nNo hay autos que mostrar\n\n");
    }
    else
    {
        printf("\n\nIngrese la patente del auto que desea modificar: ");
        fflush(stdin);
        gets(patenteIngresada);
        for(i=0; i<len; i++)
        {
            if(strcmp(patenteIngresada, listaut[i].patente) == 0)
            {
                printf("\n\n1. Modificar el color.\n");
                printf("2. Modificar el modelo.\n\n");
                printf("Ingrese el numero: ");
                fflush(stdin);
                scanf("%d", &idModificacion);

                if(idModificacion == 1)
                {
                    listarColores(listcolores, lencolores);
                    printf("\n\nIngrese ID del nuevo color: ");
                    fflush(stdin);
                    scanf("%d", &listaut[i].idColor);
                    break;
                }
                else if(idModificacion == 2)
                {
                    printf("\n\nIngrese nuevo modelo: ");
                    fflush(stdin);
                    scanf("%d", &listaut[i].modelo);
                    break;
                }
                else
                {
                    printf("\n\nID ingresada incorrecta\n\n");
                    break;
                }
            }
        }
    }


}
