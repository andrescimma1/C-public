#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char marca[20];
    float cilindrada;
}eAuto;

void mostrarAutos(eAuto* lista, int tam);
void mostrarAuto(eAuto* unAuto);

int main()
{
    eAuto auto1 = {1234, "Citroen", 2.0};
    eAuto auto2 = {1457, "Peugeot", 1.6};
    eAuto auto3 = {1467, "Ford", 1.6};

    eAuto* lista = (eAuto*)malloc( 3 * sizeof(eAuto));

    *lista = auto1;
    *(lista + 1) = auto2;
    *(lista + 2) = auto3;

    //mostrarAutos(lista, 3);

    FILE* f;

    f = fopen("./autos.dat", "wb");

    if(f == NULL)
    {
        exit(1);
    }

    int i;
    for(i=0; i<3; i++)
    {
        fwrite(lista + i, sizeof(eAuto), 1, f);
    }
    return 0;
}

void mostrarAutos(eAuto* lista, int tam)
{
    int i;
    printf("ID           MARCA     CILINDRADA\n");
    printf("______________________________\n\n");
    if(lista != NULL && tam > 0)
    {
        for(i=0; i<tam; i++)
        {
            mostrarAuto(lista + i);
        }
    }
}
void mostrarAuto(eAuto* unAuto)
{
    if(unAuto != NULL)
    {
        printf("%d     %10s     %.2f\n", unAuto->id, unAuto->marca, unAuto->cilindrada);
    }
}
