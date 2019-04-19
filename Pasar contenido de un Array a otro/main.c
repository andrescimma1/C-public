// Copiar el contenido de un array a otro array

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void copiandoArrays(int a[], int b[], int tam); // Prototipo

int main()
{
    int array1[5] = {2,5,3,4,1};
    int array2[5];

    printf("Copiando Arrays\n\n");
    copiandoArrays(array1, array2, 5);

    getch();
    return 0;
}

// a[] = array1
// b[] = array2

void copiandoArrays(int a[], int b[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        b[i] = a[i]; //Recorre todos los valores de a y se los pasa a b
    }

    for(i=0; i<tam; i++)
    {
        printf("%d", b[i]);
    }
}
