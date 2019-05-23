/*

Ejercicio #13: Capturar una o varias teclas en cualquier momento de la ejecucion en nuestro programa
                mediante codigo ASCII.

ASCII = CADA UNA DE NUESTRAS TECLAS EN NUESTRO TECLADO TIENE UN VALOR UNICO DE CODIGO ASCII.

A, B * / @ ! = TIENE UN CODIGO ASCII ÚNICO

a = 97
A = 65

EJERCICIO: IMPRIMIR HOLA MUNDO AL PRESIONAR LA TECLA A

*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //SLEEP

#define letra_a 97  //Definimos la letra 'a' con su valor ASCII (97).

int main()
{
    char letra;

    while(1)
    {
        letra = getch();

        letra = tolower(letra);

        if(letra == letra_a)
        {
            printf("Perfecto, ingresaste la letra a\n");
        }
    }
    return 0;
}
