#include <stdio.h>
#include <stdlib.h>



int main()
{
    int* vec;
    int i;

    vec = (int*)malloc(sizeof(int)*5);

    if(vec == NULL)
    {
        printf("No se ha conseguido espacio en memoria\n\n");
        exit(1);
    }

    for(i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", vec + i);
    }

    for(i=0; i<5; i++)
    {
        printf("%d ", *(vec + i));
    }

    printf("\n\n");

    free(vec);
    return 0;
}
