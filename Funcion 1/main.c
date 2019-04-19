#include <stdio.h>
#include <stdlib.h>

int sumar1(int, int);  //Prototipo de la función (resumen de la función)

int main()
{
    int x;
    int y;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &x);
    printf("Ingrese un numero: ");
    scanf("%d", &y);

    resultado = sumar1(x, y);  //Llamando a la función

    printf("La suma de los numeros es: %d\n\n", resultado);

    return 0;
}

// Desarrollo de la función
sumar1(int numero1, int numero2)
{
    int suma;

    suma = numero1 + numero2;
}
