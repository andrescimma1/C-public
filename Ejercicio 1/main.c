// 1. Ingresar 5 números y calcular su media

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int uno;
    int dos;
    int tres;
    int cuatro;
    int cinco;
    float media;

    printf("Ingrese el primer numero: ");
    scanf("%d", &uno);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &dos);
    printf("Ingrese el tercer numero: ");
    scanf("%d", &tres);
    printf("Ingrese el cuarto numero: ");
    scanf("%d", &cuatro);
    printf("Ingrese el quinto numero: ");
    scanf("%d", &cinco);

    media = (float) (uno + dos + tres + cuatro + cinco) / 5;

    printf("La media de los números es: %.2f", media);



    return 0;
}
