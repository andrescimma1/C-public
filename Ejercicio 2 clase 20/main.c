#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct S_Person
{
    char name[20];
    int age;
};
typedef struct S_Person Person;

int enterPerson(Person* p);
void printPerson(Person* p);

int main()
{
    Person people[1000]; //Creamos un array muy grande para que no se llene nunca la memoria
    Person p;
    int index = 0;

    while(enterPerson(&p) == 0)
    {
        people[index] = p;
        index++;
    }

    int i;
    for(i=0; i<index; i++)
    {
        printPerson(&people[i]);
    }
    return 0;
}


/** \brief Pide al usuario los datos de una persona y los almacena en la struct
 * \param Person* p puntero a tipo Person donde se guardarán los datos
 * \return 1(si se ingresa salir) o 0(de lo contrario)
 */
int enterPerson(Person* p)
{
    printf("Ingrese el nombre: ");
    scanf("%s", p->name);
    if(strncmp(p->name, "salir", 5) == 0)
    {
        return 1;
    }
    printf("Ingrese la edad: ");
    scanf("%d", &(p->age));
    return 0;
}


/** \brief Imprime los datos de una persona
 * \param Person* p puntero a tipo Person donde se guardarán los datos
 * \return void
 *
 */
void printPerson(Person* p)
{
    printf("Nombre:\t%s \tEdad:%d\r\n", p->name, p->age);
}

