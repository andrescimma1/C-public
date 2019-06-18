#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

struct s_Persona
{
    int edad;
    char nombre[20];
}Persona;

Persona* persona_newPersona(void);

#endif // PERSONA_H_INCLUDED
