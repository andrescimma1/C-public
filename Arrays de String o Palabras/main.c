#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //Libreria para usar el "getch()"

int main()
{
    char a[20]; //Puede guardar hasta 20 caracteres, "Andres" lleva 6.

    printf("Digite su nombre: ");
    scanf("%s", a);

    printf("%s", a);
    getch(); //Para que en el .exe tengas que apretar una letra para salir
    return 0;
}
