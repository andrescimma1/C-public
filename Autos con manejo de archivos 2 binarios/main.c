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
    int cont = 0;
    int cant;
    eAuto* lista = (eAuto*)malloc( 3 * sizeof(eAuto));

    FILE* f;

    f = fopen("./autos.dat", "rb");

    if(f == NULL)
    {
        exit(1);
    }

    while(!feof(f)) //Mientras no haya llegado al final de archivo
    {
        cant = fread(lista + cont, sizeof(eAuto), 1, f);

        if(cant < 1)
        {
            if(feof(f))
            {
                break;
            }
            else
            {
                printf("Se produjo un error al leer el archivo");
                break;
            }
        }
        cont++;
    }

    fclose(f); //Cerramos el archivo

    mostrarAutos(lista, cont);
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
