#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pnum;

    pnum = (int*)malloc(sizeof(int));

    printf("Ingrese un numero: ");
    scanf("%d", pnum); //No utilizo el "&" porque necesito la direccion de memoria de pnum.

    if(pnum == NULL)
    {
        printf("No se ha conseguido memoria");
        system("pause");
        exit(1); // Normalmente se utiliza en el main cuando queres salir del programa
                 //  directamente si algo salió mal.
    }

    printf("\n\nUsted ha ingresado el: %d\n\n", *pnum);   //Acá si pongo el puntero porque necesito
                                                          // el valor de pnum.

    return 0;
}
