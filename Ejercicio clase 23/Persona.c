#include <stdio.h>
#include "Persona.h"

int size;
int index;
Persona** lista;

char preguntarNombre(char nombre)
{
    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(nombre);
    return nombre;
}

int preguntarEdad()
{
    int edad;
    printf("Ingrese edad: ");
    scanf("%d", &edad);
    return edad;
}

Persona* persona_newPersona(void)
{
    Persona* persona = (Persona*)malloc(sizeof(Persona));
    return persona;
}

int persona_setEdad(Persona* pPersona, int edad)
{
    if(edad>0)
    {
        pPersona->edad = edad;
        return 0; // OK
    }
    return 1; // error
}

int persona_setName(Persona* pPersona, char* pName)
{
    if(strlen(pName)>3)
    {
        strcpy(pPersona->nombre, pName);
    }
}

void persona_toString(Persona* pPersona)
{
    printf("Nombre:%s - Edad:%d", pPersona->nombre, pPersona->edad);
}

int persona_getEdad(Persona* pPersona)
{
    return pPersona->edad;
}

char* persona_getNombre(Persona* pPersona)
{
    return pPersona->nombre;
}

void persona_initLista(void)
{
    size = 10;
    index = 0;
    lista = (Persona**)malloc(sizeof(Persona*)*size);
}

void persona_addPersona(Persona* p)
{
    lista[index] = p;
    index++;

    if(index>=size)
    {
        printf("No hay mas lugar, redefinimos el array\n");
        size = size + 10;
        lista = (Persona**)realloc(lista, sizeof(Persona*)*size);
    }
}

void preguntarSalir()
{
    char respuesta;
    printf("Desea salir? (S/N): ");
    scanf("%c", &respuesta);
    return respuesta;
}
