#include <stdio.h>
#include <stdlib.h>

int sumar3();  //Void significa que la funci�n no va a devolver nada

int main()
{
    int suma;

    suma = sumar3();

    printf("La suma es: %d\n\n", suma);

    return 0;
}

// Desarrollo de la funci�n
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
