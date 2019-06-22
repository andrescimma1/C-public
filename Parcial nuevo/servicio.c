#include "servicio.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** \brief Muestra una lista de todos los servicios.
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void listarServicios(eServicio listservicios[], int lenservicios)
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
