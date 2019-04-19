#include <stdio.h>
#include <stdlib.h>

void sumar4();  //Void significa que la función no va a devolver nada

int main()
{
    sumar4();

    return 0;
}

// Desarrollo de la función
void sumar4()
{
    int x;
    int y;

    printf("Ingrese un numero: ");
    scanf("%d", &x);

    printf("Ingrese un numero: ");
    scanf("%d", &y);

    sumar4(x, y);
}
