#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

struct s_Persona
{
    int edad;
    char nombre[20];
};

typedef struct s_Persona Persona;

char preguntarNombre(char* nombre);
int preguntarEdad();
Persona* persona_newPersona(void);
int persona_setEdad(Persona* pPersona, int edad);
int persona_setName(Persona* pPersona, char* pName);
void persona_toString(Persona* pPersona);
int persona_getEdad(Persona* pPersona);
char* persona_getNombre(Persona* pPersona);
void persona_initLista(void);
void persona_addPersona(Persona* p);
void preguntarSalir();

#endif // PERSONA_H_INCLUDED
