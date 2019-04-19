#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //Libreria para usar el "getch()"

int main()
{
    char a[5]={'a','e','i','o','u'};
    int i;

    for(i=0; i<5; i++)
    {
        printf("%c", a[i]);
    }

    getch(); //Para que en el .exe tengas que apretar una letra para salir
    return 0;
}
