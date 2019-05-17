#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void f1(int x[], int tam);  //Vectorial
void f2(int x[], int tam);  //Puntero
void f3(int* x, int tam);   //Vectorial
void f4(int* x, int tam);   //Puntero

int main()
{
    int vec[] = {3, 2, 5, 4, 1};

    int x = 7;
    int *p;
    int **q;

    p = &x;
    q = p;

    printf("Direccion de memoria de x: %p\n", &x);
    printf("Puntero apuntado a la direccion de memoria de x: %p\n", p);
    printf("Puntero q apuntando a p: %p\n\n", q);

    x = 8;

    printf("Valor de x: %d\n", x);
    printf("Puntero con valor de x: %d\n", *p);
    printf("Puntero con valor de p que pasa por x: %p", *q);

    printf("\n\n");

    f1(vec, 5);
    f2(vec, 5);
    f3(vec, 5);
    f4(vec, 5);
    return 0;
}

void f1(int x[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("%d: %d\n", i, x[i]);
    }
    printf("\n\n");
}

void f2(int x[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("%d: %d\n", i, *(x+i));
    }

    printf("\n\n");
}

void f3(int* x, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d: %d\n", i, x[i]);
    }
    printf("\n\n");
}

void f4(int* x, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d: %d\n", i, *(x+i));
    }
    printf("\n\n");
}
