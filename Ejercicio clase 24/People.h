#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED

struct S_Person
{
       char name[20];
       int age;
};
typedef struct S_Person Person;

int list_enterPerson(Person* p);
void list_printPerson(Person* p);

void list_initPeopleList(void);
void list_addPerson(Person* p);
void list_remove(int indexToDelete);
Person* list_newPerson(void);
int list_getSize(void);
Person* list_get(int i);
void list_free(void);


#endif // PEOPLE_H_INCLUDED
