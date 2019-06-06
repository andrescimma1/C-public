#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
    char nombre[20];
    char sexo;
}eCliente;

typedef struct
{
    int id;
    char patente[7];
    int idMarca;
    int idColor;
    int modelo;
    int idCliente;
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






/** \brief Inicializa el id de los clientes en 0;
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */

void inicializarClientes(eCliente* listclientes, int lenclientes)
{
    int i;
    for(i=0; i<lenclientes; i++)
    {
        listclientes[i].id = 0;
    }
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

void altaAuto(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* listclientes, int lenclientes)
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

        printf("Ingrese su nombre: ");
        fflush(stdin);
        gets(listclientes[indice].nombre);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &listclientes[indice].sexo);

        listclientes[indice].id = 1;
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

void listarAuto(eAuto* pAuto, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* pCliente)
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


    printf("%7s    %7s  %7s   %d   %10s  %c\n", pAuto->patente, marcaEncontrada, colorEncontrado, pAuto->modelo, pCliente->nombre, pCliente->sexo);
}


/** \brief Muestra una lista con todos los autos.
 *
 * \param int i;
 * \param int indice = -1;
 * \return Devuelve -1 si no se encontraron autos, o devuelve 0 si se encontraron.
 *
 */

int listarAutos(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* listclientes, int lenclientes)
{
    int i;
    int indice = -1;

    system("cls");

    printf("Listado de autos\n");
    printf("____________________________________\n");
    printf("PATENTE    MARCA    COLOR    MODELO    NOMBRE    SEXO\n");

    for(i=0; i<len; i++)
    {
        if(listaut[i].id == 1)
        {
            indice = 0;
            listarAuto((listaut + i), listmarcas, lenmarcas, listcolores, lencolores, (listclientes + i));
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

void bajaAuto(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* listclientes, int lenclientes)
{
    int i;
    char patenteIngresada[7];
    char seguro;
    int indice = -1;

    indice = listarAutos(listaut, len, listmarcas, lenmarcas, listcolores, lencolores, listclientes, lenclientes);

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
                listarAuto((listaut + i), listmarcas, lenmarcas, listcolores, lencolores, (listclientes + i));

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

void modificarAuto(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* listclientes, int lenclientes)
{
    int i;
    int indice = -1;
    int idModificacion;
    char patenteIngresada[7];

    indice = listarAutos(listaut, len, listmarcas, lenmarcas, listcolores, lencolores, listclientes, lenclientes);

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

void altaTrabajo(eTrabajo* listtrabajos, int lentrabajos, eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eCliente* listclientes, int lenclientes)
{
    int indice;
    int indice2;

    indice = buscarTrabajoLibre(listtrabajos, lentrabajos);

    if(indice == -1)
    {
        printf("Error, no hay espacio.\n\n");
    }
    else
    {
        system("cls");

        indice2 = listarAutos(listaut, len, listmarcas, lenmarcas, listcolores, lencolores, listclientes, lenclientes);

        if(indice2 == -1)
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

void mostrarAutosColorNegro(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* listclientes, int lenclientes)
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
            listarAuto((listaut + i), listmarcas, lenmarcas, listcolores, lencolores, (listclientes + i));
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

void mostrarAutosMarcaSeleccionada(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* listclientes, int lenclientes)
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
            listarAuto((listaut + i), listmarcas, lenmarcas, listcolores, lencolores, (listclientes + i));
            indice = i;
        }
    }

    if(indice == -1)
    {
        printf("No hay autos de la marca ingresada para mostrar.\n\n");
    }
}


void mostrarTrabajosAutoSeleccionado(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos, eCliente* listclientes, int lenclientes)
{
    int i;
    int indice = -1;
    int indice2 = -1;
    char patenteIngresada[7];

    system("cls");

    indice = listarAutos(listaut, len, listmarcas, lenmarcas, listcolores, lencolores, listclientes, lenclientes);

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


/** \brief Recorre los autos con id == 1 y busca los autos que no tuvieron trabajos.
 *
 * \param int i;
 * \param int j;
 * \return No devuelve nada.
 *
 */

void listarAutosSinTrabajo(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos, eCliente* listclientes, int lenclientes)
{
    int i, j;

    system("cls");

    printf("LISTADO DE AUTOS QUE NO TIENEN TRABAJOS\n");
    printf("_______________________________________\n");

    for(i=0; i<len; i++)
    {
        if(listaut[i].id == 1)
        {
            for(j=0; j<lentrabajos; j++)
            {
                if(listtrabajos[j].estado != 1 && listaut[i].id == 1)
                {
                    listarAuto((listaut + i), listmarcas, lenmarcas, listcolores, lencolores, (listclientes + i));
                }
                i++;
            }
        }
    }

}

/** \brief Pide al usuario la patente de un auto y en base a ese dato la funcion suma
 *          e informa el importe total de los trabajos realizados de ese auto.
 * \param int i, j;
 * \param int todoOk = 0;
 * \param int importeTotal = 0;
 * \param char patenteIngresada[7];
 * \return No devuelve nada.
 *
 */

void importeTotalAutoSeleccionado(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos, eCliente* listclientes, int lenclientes)
{
    int i, j;
    int todoOk = 0;
    int importeTotal = 0;
    char patenteIngresada[7];

    system("cls");

    listarAutos(listaut, len, listmarcas, lenmarcas, listcolores, lencolores, listclientes, lenclientes);

    printf("\nElija un auto por su patente: ");
    fflush(stdin);
    gets(patenteIngresada);

    for(i=0; i<lentrabajos; i++)
    {
        if(strcmp(patenteIngresada, listtrabajos[i].patente) == 0)
        {
            for(j=0; j<lenservicios; j++)
            {
                if(listtrabajos[i].idServicio == listservicios[j].id)
                {
                    importeTotal = importeTotal + listservicios[j].precio;
                    todoOk = 1;
                }
            }
        }
    }
    if(todoOk == 1)
    {
        printf("El importe total del auto seleccionado es de: %d\n\n", importeTotal);
    }
    else
    {
        printf("Ha ocurrido un error.\n\n");
    }
}


/** \brief Recorre los trabajos y busca el servicio mas pedido.
 *
 * \param int i, j;
 * \param int cont = 0, cont1 = 0, cont2 = 0, cont3 = 0;
 * \return No devuelve nada.
 *
 */

void mostrarServicioMasPedido(eTrabajo* listtrabajos, int lentrabajos, eServicio* listservicios, int lenservicios)
{
    int i;
    int cont = 0, cont1 = 0, cont2 = 0, cont3 = 0;

    system("cls");

    for(i=0; i<lentrabajos; i++)
    {
        if(listtrabajos[i].estado == 1)
        {
            if(listtrabajos[i].idServicio == 20000)
            {
                cont++;
            }
            else if(listtrabajos[i].idServicio == 20001)
            {
                cont1++;
            }
            else if(listtrabajos[i].idServicio == 20002)
            {
                cont2++;
            }
            else
            {
                cont3++;
            }
        }
    }

    if(cont > cont1 && cont > cont2 && cont > cont3)
    {
        printf("El servicio mas pedido es el Lavado. Con un total de %d autos.\n\n", cont);
    }
    else if(cont1 > cont && cont1 > cont2 && cont1 > cont3)
    {
        printf("El servicio mas pedido es el Pulido. Con un total de %d autos.\n\n", cont1);
    }
    else if(cont2 > cont && cont2 > cont1 && cont2 > cont3)
    {
        printf("El servicio mas pedido es el Encerado. Con un total de %d autos.\n\n", cont2);
    }
    else if(cont3 > cont && cont3 > cont1 && cont3 > cont2)
    {
        printf("El servicio mas pedido es el Completo. Con un total de %d autos.\n\n", cont3);
    }
    else
    {
        printf("No se han encontrado resultados.\n\n");
    }
}


/** \brief Pide al usuario una fecha en particular, recorre los trabajos y los servicios para
 *          acumular la recaudacion. Muestra la recaudacion segun la fecha en particular.
 * \param int diaIngresado, mesIngresado, anioIngresado;
 * \param int i, j;
 * \param int acumulador;
 * \return No devuelve nada.
 *
 */

void mostrarRecaudacionSegunFecha(eTrabajo* listtrabajos, int lentrabajos, eServicio* listservicios, int lenservicios)
{
    int diaIngresado;
    int mesIngresado;
    int anioIngresado;
    int i, j;
    int acumulador = 0;
    int indice = -1;

    system("cls");

    indice = listarTrabajos(listtrabajos, lenservicios, listservicios, lenservicios);

    if(indice == -1)
    {
        printf("No hay trabajos.\n\n");
    }
    else
    {
        printf("Ingrese la fecha dd/mm/aaaa: ");
        fflush(stdin);
        scanf("%d %d %d", &diaIngresado,
                          &mesIngresado,
                          &anioIngresado);
       for(i=0; i<lentrabajos; i++)
        {
            if(listtrabajos[i].estado == 1 && diaIngresado == listtrabajos[i].fecha.dia && mesIngresado == listtrabajos[i].fecha.mes && anioIngresado == listtrabajos[i].fecha.anio)
            {
                for(j=0; j<lenservicios; j++)
                {
                    if(listtrabajos[i].estado == 1 && listservicios[j].id == listtrabajos[i].idServicio && diaIngresado == listtrabajos[i].fecha.dia && mesIngresado == listtrabajos[i].fecha.mes && anioIngresado == listtrabajos[i].fecha.anio)
                    {
                        acumulador = listservicios[j].precio + acumulador;
                        i++;
                    }
                }
            }
        }
    }

    printf("La recaudacion de la fecha en particular es de: %d\n\n", acumulador);

}

/** \brief Recorro los trabajos y los autos para buscar el idServicio == 20002 (Encerado)
 *
 * \param int i;
 * \param int j;
 * \return No devuelve nada.
 *
 */

void mostrarAutosEnceradoYfecha(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos, eCliente* listclientes, int lenclientes)
{
    int i, j;

    system("cls");

    printf("LISTADO DE AUTOS QUE REALIZARON UN ENCERADO\n");
    printf("___________________________________________\n");

    for(i=0; i<lentrabajos; i++)
    {
        if(listtrabajos[i].estado == 1)
        {
            for(j=0; j<len; j++)
            {
                if(listaut[j].id == 1 && listtrabajos[i].estado == 1 && strcmp(listtrabajos[i].patente, listaut[j].patente) == 0 && listtrabajos[i].idServicio == 20002)
                {
                    listarAuto((listaut + j), listmarcas, lenmarcas, listcolores, lencolores, (listclientes + i));
                    printf("%02d/%02d/%d\n\n", listtrabajos[i].fecha.dia, listtrabajos[i].fecha.mes, listtrabajos[i].fecha.anio);
                    i++;
                }
            }
        }
    }
}


/** \brief Recorre los trabajos y los autos para buscar el idColor == 5001(color blanco)
 *
 * \param int i;
 * \param int j;
 * \return No devuelve nada.
 *
 */

void trabajosAutosBlancos(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos)
{
    int i, j;

    system("cls");

    printf("LISTADO DE TRABAJOS REALIZADOS A AUTOS BLANCOS\n");
    printf("______________________________________________\n");

    for(i=0; i<lentrabajos; i++)
    {
        if(listtrabajos[i].estado == 1)
        {
            for(j=0; j<len; j++)
            {
                if(listtrabajos[i].estado == 1 && strcmp(listtrabajos[i].patente, listaut[j].patente) == 0 && listaut[j].idColor == 5001)
                {
                    listarTrabajo((listtrabajos + i), listservicios, lenservicios);
                    i++;
                }
            }
        }
    }
}


/** \brief Recorre todos los trabajos y los servicios, y busca que el idServicio == 20001(Pulido).
 *          Suma todos los pulidos realizados.
 * \param int i, j;
 * \param int acumulador = 0;
 * \return No devuelve nada.
 *
 */

void totalPulidos(eTrabajo* listtrabajos, int lentrabajos, eServicio* listservicios, int lenservicios)
{
    int i, j;
    int acumulador = 0;

    system("cls");

    for(i=0; i<lentrabajos; i++)
    {
        if(listtrabajos[i].estado == 1)
        {
            for(j=0; j<lenservicios; j++)
            {
                if(listtrabajos[i].estado == 1 && listtrabajos[i].idServicio == 20001 && listtrabajos[i].idServicio == listservicios[j].id)
                {
                    acumulador = acumulador + listservicios[j].precio;
                }
            }
        }
    }

    printf("La facturacion total por los pulidos es de: $ %d\n\n", acumulador);
}


/** \brief Recorre los trabajos y los autos donde la idServicio == 20003, y dentro de los autos
 *          crea un contador para cada marca.
 * \param int i, j;
 * \param int cont = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0;
 * \return No devuelve nada.
 *
 */

void marcaConMasLavadosCompletos(eMarca* listmarcas, int lenmarcas, eAuto* listaut, int len, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos)
{
    int i, j;
    int cont = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0;

    system("cls");

    for(i=0; i<lentrabajos; i++)
    {
        if(listtrabajos[i].estado == 1 && listtrabajos[i].idServicio == 20003)
        {
            for(j=0; j<len; j++)
            {
                if(listtrabajos[i].estado == 1 && listtrabajos[i].idServicio == 20003 && listaut[j].idMarca == 1000)
                {
                    cont++;
                }
                else if(listtrabajos[i].estado == 1 && listtrabajos[i].idServicio == 20003 && listaut[j].idMarca == 1001)
                {
                    cont2++;
                }
                else if(listtrabajos[i].estado == 1 && listtrabajos[i].idServicio == 20003 && listaut[j].idMarca == 1002)
                {
                    cont3++;
                }
                else if(listtrabajos[i].estado == 1 && listtrabajos[i].idServicio == 20003 && listaut[j].idMarca == 1003)
                {
                    cont4++;
                }
                else if(listtrabajos[i].estado == 1 && listtrabajos[i].idServicio == 20003 && listaut[j].idMarca == 1004)
                {
                    cont5++;
                }
                else
                {

                }

            }
        }
    }

    if(cont > cont2 && cont > cont3 && cont > cont4 && cont > cont5)
    {
        printf("La marca de autos que efectuaron mas lavados completos es: Renault\n\n");
    }
    else if(cont2 > cont3 && cont2 > cont3 && cont2 > cont4 && cont2 > cont5)
    {
        printf("La marca de autos que efectuaron mas lavados completos es: Fiat\n\n");
    }
    else if(cont3 > cont2 && cont3 > cont && cont3 > cont4 && cont3 > cont5)
    {
        printf("La marca de autos que efectuaron mas lavados completos es: Ford\n\n");
    }
    else if(cont4 > cont2 && cont4 > cont3 && cont4 > cont && cont4 > cont5)
    {
        printf("La marca de autos que efectuaron mas lavados completos es: Chevrolet\n\n");
    }
    else if(cont5 > cont2 && cont5 > cont3 && cont5 > cont && cont5 > cont4)
    {
        printf("La marca de autos que efectuaron mas lavados completos es: Peugeot\n\n");
    }
    else
    {
        printf("No hay trabajos de lavado completo.\n\n");
    }
}


/** \brief Lista los trabajos y pide una fecha al usuario. Recorre los autos y los trabajos
 *          para comparar la fecha ingresada con la fecha de los trabajos.
 * \param int i, j;
 * \param int indice = -1;
 * \param int diaIngresado, mesIngresado, anioIngresado;
 * \return No devuelve nada.
 *
 */

void autosConTrabajoEnFechaDeterminada(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eTrabajo* listtrabajos, int lentrabajos, eServicio* listservicios, int lenservicios, eCliente* listclientes, int lenclientes)
{
    int i, j;
    int indice = -1;
    int diaIngresado;
    int mesIngresado;
    int anioIngresado;

    system("cls");

    indice = listarTrabajos(listtrabajos, lentrabajos, listservicios, lenservicios);

    if(indice == -1)
    {
        printf("No se puede realizar la operacion.\n\n");
    }
    else
    {
        printf("Ingrese una fecha dd mm aaaa: ");
        fflush(stdin);
        scanf("%d %d %d", &diaIngresado, &mesIngresado, &anioIngresado);

        for(i=0; i<len; i++)
        {
            if(listaut[i].id == 1)
            {
                for(j=0; j<lentrabajos; j++)
                {
                    if(listaut[i].id == 1 && listtrabajos[j].estado == 1 && listtrabajos[j].fecha.dia == diaIngresado && listtrabajos[j].fecha.mes == mesIngresado && listtrabajos[j].fecha.anio == anioIngresado)
                    {
                        listarAuto((listaut + i), listmarcas, lenmarcas, listcolores, lencolores, (listclientes + i));
                        i++;
                    }
                }
            }
        }
    }
}

