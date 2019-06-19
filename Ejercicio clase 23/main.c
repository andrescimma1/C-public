#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"

int main()
{

    do
    {
        Persona* persona = persona_newPersona();
        //preguntarNombre(persona->nombre);
        persona_initLista();
        char nombreAux[20];
        nombreAux = preguntarNombre(nombreAux);
        if(persona_setName(persona, nombreAux))
        {
            printf("El nombre no es valido\n");
        }
        //persona->edad = preguntarEdad();
        int edadAux = preguntarEdad();
        if(persona_setEdad(persona, edadAux))
        {
            printf("La edad no es valida\n");
        }

        persona_addPersona(persona);

    }while(preguntarSalir()!='S');

    return 0;
}
