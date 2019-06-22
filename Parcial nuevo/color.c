#include "color.h"
#include <stdio.h>
#include <stdlib.h>

/** \brief Muestra una lista de todos los colores con su id y su descripcion.
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void listarColores(eColor listcolores[], int lencolores)
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
