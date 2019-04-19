#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //Libreria para usar el getch()"

int main()
{
    float a[5];
    int i;

    for(i=0; i<5; i++)
    {
        printf("%i. Digite un numero: ", i+1);
        scanf("%f", &a[i]);
    }

    printf("\n\n");

    for(i=0; i<5; i++)
    {
        printf("%.2f\n", a[i]);
    }

    getch(); //Para que en el .exe tengas que apretar una letra para salir
    return 0;
}
