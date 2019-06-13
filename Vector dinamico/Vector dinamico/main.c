#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "vectordinamico.h"

int main()
{
    vector_t* v1 = vector_crear(3);

    int dato1 = 7;
    float dato2 = 3.1452;
    char* dato3 = "Andres";

    vector_agregar(v1, 0, &dato1);
    vector_agregar(v1, 1, &dato2);
    vector_agregar(v1, 2, dato3);

    int* elemento_en_0 = (int*)(vector_obtener(v1, 0));
    printf("V1 en pos %d = %d\n", 0, *elemento_en_0);

    float* elemento_en_1 = (float*)(vector_obtener(v1, 1));
    printf("V1 en pos %d = %f\n", 1, *elemento_en_1);

    char* elemento_en_2 = (char*)(vector_obtener(v1, 2));
    printf("V1 en pos %d = %s\n", 2, elemento_en_2);

    return 0;
}
