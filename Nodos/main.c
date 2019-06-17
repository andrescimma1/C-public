#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[20];
    int edad;
    struct nodo* siguiente;
}

nodo* inicLista();
nodo* crearNodo(char nombre[20], int edad);
nodo* agregarPrincipio(nodo* lista, nodo* nuevo);
void recorrerYmostrar(nodo* lista);
void escribir(nodo* aux);

int main()
{
    nodo* lista = inicLista();

    nodo* nuevo = crearNodo("Gabriel", 45);
    lista = agregarPrincipio(lista, nuevo);

    nodo* nuevo = crearNodo("Gustavo", 38);
    lista = agregarPrincipio(lista, nuevo);

    return 0;
}



nodo* inicLista()
{
    return NULL;
}

nodo* crearNodo(char nombre[20], int edad)
{
    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->edad = edad;
    strcpy(aux->nombre, nombre);
    aux->siguiente = NULL;
    return aux;
}

nodo* agregarPrincipio(nodo* lista, nodo* nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }

    return lista;
}

void recorrerYmostrar(nodo* lista)
{
    nodo* seg = lista;
    while(seg!=NULL)
    {
        escribir(seg);
        seg = seg->siguiente;
    }
}

void escribir(nodo* aux)
{
    printf("nombre: %s\n", aux->nombre);
    printf("edad: %d\n\n", aux->edad);
}

nodo* borrarNodo(char nombre[20], nodo* lista)
{
    nodo* aux;
    nodo* ante;
    if(   (lista)!=NULL && (strcmp(nombre, lista->nombre)==0)   )
    {
        nodo* aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        aux = lista;
        while(   (aux!=NULL) && (strcmp(nombre, aux->nombre)!=0)   )
        {
            ante = aux;
            aux = aux->siguiente;
        }

        if(aux!=NULL)
        {
            ante->siguiente = aux->siguiente;
            free(aux); //Elimina el nodo.
        }
        return lista;
    }
}
