#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

void listarServicios(eServicio listservicios[], int lenservicios);

#endif // SERVICIO_H_INCLUDED
