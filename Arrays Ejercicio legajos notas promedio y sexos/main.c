#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int legajos[5];
    int nota1[5];
    int nota2[5];
    int i;
    float promedio[5];
    char sexos[5];
    char auxChar;

    //Tomando los datos
    for(i=0; i<5; i++)
    {
        printf("\nIngrese su legajo: ");
        scanf("%d", &legajos[i]);
        printf("Ingrese su primer nota: ");
        scanf("%d", &nota1[i]);
        printf("Ingrese su segunda nota: ");
        scanf("%d", &nota2[i]);
        printf("Ingrese su sexo: ");
        fflush(stdin);  //Limpiando la basura de los int anteriores
        scanf("%c", &auxChar);
        sexos[i] = auxChar;
        promedio[i] = (float)(nota1[i] + nota2[i]) / 2;
    }

    printf("Legajo \t Nota1 \t Nota2 \t Promedio \t Sexo ");
    printf("\n\n");

    for(i=0; i<5; i++)
    {
        printf("\n%d \t %d \t %d \t %.2f \t\t %c", legajos[i], nota1[i], nota2[i], promedio[i], sexos[i]);
    }

    getch();
    return 0;
}
