//Método Burbuja o burbujeo

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int array[5] = {3,2,5,1,4};
    int i, j, aux;

    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            if(array[j]>array[j+1])  //array[j] = 5 > array[j+1] = 4
            {
                aux = array[j];  // aux = 5
                array[j] = array[j+1]; // array[j] = 4
                array[j+1] = aux; // array[j+1] = 5
            }
        }
    }

    //Ascendente (1,2,3,4,5)
    for(i=0; i<5; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n\n"); //Dos saltos de linea

    //Descendente (5,4,3,2,1)
    for(i=4; i>=0; i--)
    {
        printf("%d ", array[i]);
    }

    getch();

    return 0;
}
