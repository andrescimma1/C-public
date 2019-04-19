#include <stdio.h>
#include <stdlib.h>

int sumar3();  //Void significa que la función no va a devolver nada

int main()
{
    int suma;

    suma = sumar3();

    printf("La suma es: %d\n\n", suma);

    return 0;
}

// Desarrollo de la función
int sumar3()
{
    int x;
    int y;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &x);

    printf("Ingrese un numero: ");
    scanf("%d", &y);

    resultado = x + y;
}
