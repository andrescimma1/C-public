#ifndef VECTORDINAMICO_H_INCLUDED
#define VECTORDINAMICO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector vector_t;

//Firmas de funciones
//Crear vector
vector_t* vector_crear(size_t tam_inicial);


/*Agrega un elemento en un determinado indice al vector.
  Me devuelve si hubo algún error o no.*/
bool vector_agregar(vector_t* vector, size_t indice, void* elemento);


//Devuelve el elemento en el indice
void* vector_obtener(vector_t* vector, size_t indice);


//Devuelve el tamaño actual del vector
size_t vector_obtener_tam(vector_t* vector);


//Redimensiona el vector
//Devuelve si hubo algun error o no.
bool vector_redimensionar(vector_t* vector, size_t nuevotam);


//Libera la memoria pedida
void vector_destruir(vector_t* vector);


#endif // VECTORDINAMICO_H_INCLUDED
