#include "trabajo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** \brief Inicializa todos los trabajos en estado desocupado, y genera una id autoincremental.
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void inicializarTrabajos(eTrabajo listtrabajos[], int lentrabajos)
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

int buscarTrabajoLibre(eTrabajo listtrabajos[], int lentrabajos)
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


/** \brief Lista un solo trabajo.
 *
 * \param int i;
 * \param char servicioEncontrado[25];
 * \return No devuelve nada.
 *
 */

void listarTrabajo(eTrabajo trabajos, eServicio listservicios[], int lenservicios)
{
    int i;
    char servicioEncontrado[25];

    for(i=0; i<lenservicios; i++)
    {
        if(trabajos.idServicio == listservicios[i].id)
        {
            strcpy(servicioEncontrado, listservicios[i].descripcion);
            break;
        }
    }

    printf("%s    %s    %02d/%02d/%d\n", trabajos.patente, servicioEncontrado, trabajos.fecha.dia, trabajos.fecha.mes, trabajos.fecha.anio);
}

/** \brief Lista todos los trabajos que tengan el estado en 1.
 *
 * \param int i;
 * \param int indice = -1;
 * \return Devuelve -1 si no se encontraron trabajos, y sino todo ok.
 *
 */

int listarTrabajos(eTrabajo listtrabajos[], int lentrabajos, eServicio listservicios[], int lenservicios)
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
            listarTrabajo(listtrabajos[i], listservicios, lenservicios);
            indice = i;
        }
    }

    if(indice == -1)
    {
        printf("No se ha encontrado ningun trabajo\n\n");
    }

    return indice;
}



/** \brief Recorre todos los trabajos y los servicios, y busca que el idServicio == 20001(Pulido).
 *          Suma todos los pulidos realizados.
 * \param int i, j;
 * \param int acumulador = 0;
 * \return No devuelve nada.
 *
 */

void totalPulidos(eTrabajo listtrabajos[], int lentrabajos, eServicio listservicios[], int lenservicios)
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
