#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vectordinamico.h"

struct vector
{
    size_t tam;
    void** datos;
};

//Crear vector
vector_t* vector_crear(size_t tam_inicial)
{
    int i;

    //Pedimos memoria para la estructura (struct)
    vector_t* vector = malloc(sizeof(vector_t));
    if(vector == NULL)
    {
        return NULL;
    }

    vector->tam = tam_inicial; //Guardamos el tamaño

    //Pedimos memoria para los datos
    vector->datos = malloc(sizeof(void*)*tam_inicial);
    if(vector->datos == NULL)
    {
        free(vector);
        return NULL;
    }

    for(i=0; i<tam_inicial; i++)
    {
        vector->datos[i] = NULL;
    }
    return vector;
}

/*Agrega un elemento en un determinado indice al vector.
  Me devuelve si hubo algún error o no.*/
bool vector_agregar(vector_t* vector, size_t indice, void* elemento)
{
    if(indice < 0 || indice >= vector->tam)
    {
        return false;
    }

    vector->datos[indice] = elemento;

    return true;
}



void* vector_obtener(vector_t* vector, size_t indice)
{
    if(indice < 0 || indice >= vector->tam)
    {
        return NULL;
    }

    return vector->datos[indice];
}


//Devuelve el tamaño actual del vector
size_t vector_obtener_tam(vector_t* vector)
{
    return vector->tam;
}


//Redimensiona el vector
//Devuelve si hubo algun error o no.
bool vector_redimensionar(vector_t* vector, size_t nuevotam)
{
    if(nuevotam < vector->tam) //Validamos el nuevo tam
    {
        return false;
    }

    //Creamos un vector temporal
    void** datos_nuevos = realloc(vector->datos, nuevotam*sizeof(void*));
    if(datos_nuevos == NULL) //Validamos
    {
        return false;
    }

    //Liberamos el anterior
    free(vector->datos);

    vector->datos = datos_nuevos;
    vector->tam = nuevotam;

    return true;
}


//Libera la memoria pedida
void vector_destruir(vector_t* vector)
{
    free(vector->datos);
    free(vector);
}

