#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //Libreria para usar el "getch()"

int main()
{
    int a[5]={1,2,3,4,5};
    int i;

    printf("%d", a[4]); //Imprimir el vector numero 4, se empieza desde el 0.

    for(i=0; i<5; i++)
    {
        printf("%d", a[i]);
    }

    getch(); //Para que en el .exe tengas que apretar una letra para salir
    return 0;
}
