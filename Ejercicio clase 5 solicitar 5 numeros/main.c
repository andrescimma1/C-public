/*
    1) Solicitar al usuario 5 números, permitir listarlos por pantalla indicando el máximo, el mínimo y
        el promedio. Permitir Modificar el valor de cualquiera de los números cargados indicando el
         índice del mismo y su nuevo valor.
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main()
{
    int i;
    int numerosIngresados[TAM];
    int auxNum;
    int maximo, minimo;
    int contador = 0;
    int opcion;
    float promedio;




                for(i=0; i<TAM; i++)
                {
                    printf("Ingrese un numero: ");
                    scanf("%d", &numerosIngresados[i]);
                    auxNum = numerosIngresados[i];
                    if(i == 0)
                    {
                        maximo = auxNum;
                        minimo = auxNum;
                    }
                    obtenerMinimo(auxNum, minimo);
                    obtenerMaximo(auxNum, maximo);


                    promedio = promedio + numerosIngresados[i];
                    contador++;
                }


                for(i=0; i<TAM; i++)
                {
                    printf("\nIndice #%d: %d\n", i+1, numerosIngresados[i]);
                }
                promedio = promedio / contador;
                printf("\nEl maximo es: %d", obtenerMaximo(auxNum, maximo));
                printf("\nEl minimo es: %d", obtenerMinimo(auxNum, minimo));
                printf("\nEl promedio es: %.2f\n", promedio);

                return 0;
                }






