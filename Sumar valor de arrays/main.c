#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 1


int main()
{
    int num1[TAM];
    int num2[TAM];
    int num3[TAM];
    int num4[TAM];
    int num5[TAM];
    int i;

    for(i=0; i<TAM; i++)
    {
        printf("\nIngrese el primer numero: ");
        scanf("%d", &num1[i]);
        printf("\nIngrese el segundo numero: ");
        scanf("%d", &num2[i]);
        printf("\nIngrese el tercer numero: ");
        scanf("%d", &num3[i]);
        printf("\nIngrese el cuarto numero: ");
        scanf("%d", &num4[i]);
        printf("\nIngrese el quinto numero: ");
        scanf("%d", &num5[i]);
    }

    for(i=0; i<TAM; i++)
    {
        printf("\nEl valor del primer numero sumado por si mismo es: %d", num1[i]+num1[i]);
        printf("\nEl valor del segundo numero sumado por si mismo es: %d", num2[i]+num2[i]);
        printf("\nEl valor del tercer numero sumado por si mismo es: %d", num3[i]+num3[i]);
        printf("\nEl valor del cuarto numero sumado por si mismo es: %d", num4[i]+num4[i]);
        printf("\nEl valor del quinto numero sumado por si mismo es: %d", num5[i]+num5[i]);
    }


    getch();

    return 0;
}


