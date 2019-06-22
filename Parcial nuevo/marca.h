#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;

void listarMarcas(eMarca listmarcas[], int lenmarcas);

#endif // MARCA_H_INCLUDED
