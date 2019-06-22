#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
    printf("X- Facturacion total por los pulidos.\n");
    printf("Y- Informar la marca de autos que efectuaron mas lavados completos.\n");
    printf("Z- Listar los autos que recibieron trabajos en una fecha determinada.\n\n");

    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    opcion = tolower(opcion);

    return opcion;
}

