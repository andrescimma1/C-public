/*  Nivel 4
    Realizar el algoritmo que permita ingresar números positivos (validar que sea positivo) hasta que
    el usuario quiera e informar al terminar el ingreso por document.write:

    a) La cantidad de numeros pares
    b) El promedio de todos los números ingresados
    c) La suma de todos los elementos
    d) El numero máximo y el mínimo

*/


#include <stdio.h>
#include <stdlib.h>


int main()
{
    char respuesta;
    int numeroPositivo;
    int numerosPares = 0;
    float promedio = 0;
    int contador = 0;
    int suma = 0;
    int numMax;
    int numMin;

    do
    {
        printf("Ingrese un numero positivo: ");
        scanf("%d", &numeroPositivo);

        while(numeroPositivo < 0)
            {
                printf("Error, ingrese un numero positivo: ");
                scanf("%d", &numeroPositivo);
            }
            if(numeroPositivo % 2 == 0)
            {
                numerosPares = numerosPares + 1;
            }

            promedio = promedio + numeroPositivo;

            suma = suma + numeroPositivo;

            if(contador == 0)
            {
                numMax = numeroPositivo;
                numMin = numeroPositivo;
            }

            if(numeroPositivo > numMax)
            {
                numMax = numeroPositivo;
            }

            if(numeroPositivo < numMin)
            {
                numMin = numeroPositivo;
            }

            contador = contador + 1;

            printf("Presione 's' para seguir\n");
            fflush(stdin);
            scanf("%c", &respuesta);



    }

    while(respuesta == 's');
    promedio = (float) promedio / contador;

    printf("\na) La cantidad de numeros pares es: %d", numerosPares);
    printf("\nb) El promedio de todos los números ingresados es: %f", promedio);
    printf("\nc) La suma de todos los elementos es: %d", suma);
    printf("\nd) El numero máximo es : %d. Y el minimo es: %d", numMax, numMin);
    return 0;
}
