#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAMAUT 10
#define TAMMAR 5
#define TAMCOL 5
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
    int estado;
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
void inicializarTrabajos(eTrabajo* listtrabajos, int lentrabajos);
int buscarTrabajoLibre(eTrabajo* listtrabajos, int lentrabajos);
void altaTrabajo(eTrabajo* listtrabajos, int lentrabajos, eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios);
void listarTrabajo(eTrabajo* trabajos, eServicio* listservicios, int lenservicios);
int listarTrabajos(eTrabajo* listtrabajos, int lentrabajos, eServicio* listservicios, int lenservicios);
void mostrarAutosColorNegro(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores);
void mostrarAutosMarcaSeleccionada(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores);
void mostrarTrabajosAutoSeleccionado(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos);

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
    eTrabajo arrayTrabajos[TAMTRA];
    inicializarTrabajos(arrayTrabajos, TAMTRA);

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
                altaTrabajo(arrayTrabajos, TAMTRA, arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayServicios, TAMSER);
                system("pause");
                break;
            case 'i':
                listarTrabajos(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
                system("pause");
                break;
            case '1':
                mostrarAutosColorNegro(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL);
                system("pause");
                break;
            case '2':
                mostrarAutosMarcaSeleccionada(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL);
                system("pause");
                break;
            case '3':
                mostrarTrabajosAutoSeleccionado(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayServicios, TAMSER, arrayTrabajos, TAMTRA);
                system("pause");
                break;
            case '4':
                listarTrabajos(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
                system("pause");
                break;
            case '5':
                listarTrabajos(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
                system("pause");
                break;
            case '6':
                listarTrabajos(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
                system("pause");
                break;
            case '7':
                listarTrabajos(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
                system("pause");
                break;
            case '8':
                listarTrabajos(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
                system("pause");
                break;
            case '9':
                listarTrabajos(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
                system("pause");
                break;
            case '10':
                listarTrabajos(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
                system("pause");
                break;
            case '11':
                listarTrabajos(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
                system("pause");
                break;
            case '12':
                listarTrabajos(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
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

    printf("1- Mostrar autos de color negro.\n");
    printf("2- Mostrar autos de una marca seleccionada.\n");
    printf("3- Mostrar todos los trabajos efectuados al auto seleccionado.\n");
    printf("4- Listar los autos que no tuvieron trabajos.\n");
    printf("5- Informar importe total de los trabajos realizados a un auto seleccionado.\n");
    printf("6- Mostrar el servicio mas pedido.\n");
    printf("7- Mostrar la recaudacion en una fecha en particular.\n");
    printf("8- Mostrar todos los autos que realizaron un encerado y la fecha.\n");
    printf("9- Trabajos realizados a autos blancos.\n");
    printf("10- Facturacion total por los pulidos.\n");
    printf("11- Informar la marca de autos que efectuaron mas lavados completos.\n");
    printf("12- Listar los autos que recibieron trabajos en una fecha determinada.\n\n");

    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    opcion = tolower(opcion);

    return opcion;
}

/** \brief Busca el primer espacio libre, si no se encuentra devoler� -1.
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
 * dado de baja. Recorre los autos para encontrar esa patente y realiza una baja l�gica.
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

/** \brief Inicializa todos los trabajos en estado desocupado, y genera una id autoincremental.
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */

void inicializarTrabajos(eTrabajo* listtrabajos, int lentrabajos)
{
    int i;

    for(i=0; i<lentrabajos; i++)
    {
        listtrabajos[i].id = i;
        listtrabajos[i].estado = 0;
    }
}

/** \brief Busca un trabajo libre.
 *
 * \param int i;
 * \param int indice;
 * \return Devuelve el indice. Si es -1 significa que algo salio mal, si es 0 esta todo ok.
 *
 */

int buscarTrabajoLibre(eTrabajo* listtrabajos, int lentrabajos)
{
    int i;
    int indice = -1;

    for(i=0; i<lentrabajos; i++)
    {
        if(listtrabajos[i].estado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/** \brief Da de alta un trabajo, pidiendo la patente y el servicio.
 *
 * \param int indice;
 * \param
 * \return No devuelve nada.
 *
 */

void altaTrabajo(eTrabajo* listtrabajos, int lentrabajos, eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios)
{
    int indice;

    indice = buscarTrabajoLibre(listtrabajos, lentrabajos);

    if(indice == -1)
    {
        printf("Error, no hay espacio.\n\n");
    }
    else
    {
        system("cls");

        indice = listarAutos(listaut, len, listmarcas, lenmarcas, listcolores, lencolores);

        if(indice == -1)
        {
            printf("\nNo se puede realizar la operacion\n\n");
        }
        else
        {
            printf("\n\nElija un auto por su patente: ");
            fflush(stdin);
            gets(listtrabajos[indice].patente);

            int i;
            int patenteValida = 0;
            for(i=0; i<len; i++)
            {
                if(strcmp(listtrabajos[indice].patente, listaut[i].patente) == 0)
                {
                    patenteValida = 1;
                    break;
                }
            }

            if(patenteValida != 1)
            {
                printf("Error, patente ingresada no valida.\n\n");
            }
            else
            {
                listarServicios(listservicios, lenservicios);

                printf("\n\nElija un servicio por su ID: ");
                fflush(stdin);
                scanf("%d", &listtrabajos[indice].idServicio);

                int j;
                int idServicioValido = 0;

                for(j=0; j<lenservicios; j++)
                {
                    if(listtrabajos[indice].idServicio == listservicios[j].id)
                    {
                        idServicioValido = 1;
                        break;
                    }
                }

                if(idServicioValido != 1)
                {
                    printf("ID de servicio no valido. \n\n");
                }
                else
                {
                    printf("Ingrese la fecha dd/mm/aaaa: ");
                    fflush(stdin);
                    scanf("%d %d %d", &listtrabajos[indice].fecha.dia,
                                      &listtrabajos[indice].fecha.mes,
                                      &listtrabajos[indice].fecha.anio);

                    listtrabajos[indice].estado = 1;
                    printf("Datos ingresados con exito!!\n\n");
                }

            }
        }
    }
}


/** \brief Lista un solo trabajo.
 *
 * \param int i;
 * \param char servicioEncontrado[25];
 * \return No devuelve nada.
 *
 */

void listarTrabajo(eTrabajo* trabajos, eServicio* listservicios, int lenservicios)
{
    int i;
    char servicioEncontrado[25];

    for(i=0; i<lenservicios; i++)
    {
        if(trabajos->idServicio == listservicios[i].id)
        {
            strcpy(servicioEncontrado, listservicios[i].descripcion);
            break;
        }
    }

    printf("%s    %s    %02d/%02d/%d\n", trabajos->patente, servicioEncontrado, trabajos->fecha.dia, trabajos->fecha.mes, trabajos->fecha.anio);
}

/** \brief Lista todos los trabajos que tengan el estado en 1.
 *
 * \param int i;
 * \param int indice = -1;
 * \return Devuelve -1 si no se encontraron trabajos, y sino todo ok.
 *
 */

int listarTrabajos(eTrabajo* listtrabajos, int lentrabajos, eServicio* listservicios, int lenservicios)
{
    int i;
    int indice = -1;

    system("cls");

    printf("LISTADO DE TRABAJOS\n");
    printf("Patente   Servicio   Fecha\n");
    printf("_______________________\n\n");

    for(i=0; i<lentrabajos; i++)
    {
        if(listtrabajos[i].estado == 1)
        {
            listarTrabajo((listtrabajos + i), listservicios, lenservicios);
            indice = i;
        }
    }

    if(indice == -1)
    {
        printf("No se ha encontrado ningun trabajo\n\n");
    }

    return indice;
}


/** \brief Recorre todos los autos buscando que la idColor sea igual a 5000(negro) y
 *          ademas que la id sea igual a 1(que el auto exista)
 * \param int i;
 * \param int indice = -1;
 * \return No devuelve nada.
 *
 */

void mostrarAutosColorNegro(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores)
{
    int i;
    int indice = -1;

    system("cls");

    printf("LISTADO DE AUTOS DE COLOR NEGRO\n");
    printf("_______________________________\n");

    for(i=0; i<len; i++)
    {
        if(listaut[i].idColor == 5000 && listaut[i].id == 1)
        {
            listarAuto((listaut + i), listmarcas, lenmarcas, listcolores, lencolores);
            indice = i;
        }
    }

    if(indice == -1)
    {
        printf("No hay autos de color negro.\n\n");
    }
}


/** \brief Busca los autos que tengan la idMarca igual a la ID de la marca ingresada y
 *          tengan el estado en 1(que el auto exista).
 * \param  int i;
 * \param  int indice = -1;
 * \param  int marcaSeleccionada;
 * \return No devuelve nada.
 *
 */

void mostrarAutosMarcaSeleccionada(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores)
{
    int i;
    int indice = -1;
    int marcaSeleccionada;

    system("cls");

    listarMarcas(listmarcas, lenmarcas);

    printf("\n\nIngrese ID de la marca: ");
    fflush(stdin);
    scanf("%d", &marcaSeleccionada);

    system("cls");

    printf("LISTADO DE AUTOS DE LA MARCA SELECCIONADA\n");
    printf("_________________________________________\n");

    for(i=0; i<len; i++)
    {
        if(marcaSeleccionada == listaut[i].idMarca && listaut[i].id == 1)
        {
            listarAuto((listaut + i), listmarcas, lenmarcas, listcolores, lencolores);
            indice = i;
        }
    }

    if(indice == -1)
    {
        printf("No hay autos de la marca ingresada para mostrar.\n\n");
    }
}


void mostrarTrabajosAutoSeleccionado(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos)
{
    int i;
    int indice = -1;
    int indice2 = -1;
    char patenteIngresada[7];

    system("cls");

    indice = listarAutos(listaut, len, listmarcas, lenmarcas, listcolores, lencolores);

    if(indice != -1)
    {
        printf("Seleccione un auto por su patente: ");
        fflush(stdin);
        gets(patenteIngresada);

        printf("\nLISTADO DE TRABAJOS DEL AUTO SELECCIONADO\n");
        printf("_________________________________________\n");
        for(i=0; i<lentrabajos; i++)
        {
            if(strcmp(patenteIngresada, listtrabajos[i].patente) == 0 && listtrabajos[i].estado == 1)
            {
                listarTrabajo((listtrabajos + i), listservicios, lenservicios);
                indice2 = i;
            }
        }
    }

    if(indice2 == -1)
    {
        printf("No hay trabajos que mostrar.\n\n");
    }
}
