#include "marca.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/** \brief Muestra una lista de todas las marcas con su id y su descripcion.
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void listarMarcas(eMarca listmarcas[], int lenmarcas)
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
