/* 1) Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman los siguientes
        datos (utilizar una estructura para representar a la persona.):

Nombre
Apellido
Legajo (NO SE PUEDE REPETIR)
a- Realizar un programa con un menú de opciones para hacer altas , bajas y modificaciones (ABM) de una agenda.

b- Mostrar un listado ordenado por Apellido
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define TAM 2

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[20];
}ePersona;

int main()
{
    struct ePersona p1;
    for(i=0; i<=tam; i++)
    {
        printf("Ingrese el legajo de la persona #%d:", i);
        scanf("%d", p1.nombre);
    }



    return 0;
}
