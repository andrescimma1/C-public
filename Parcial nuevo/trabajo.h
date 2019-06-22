#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "servicio.h"

typedef struct
{
    int id;
    int estado;
    char patente[7];
    int idServicio;
    eFecha fecha;
}eTrabajo;

void inicializarTrabajos(eTrabajo listtrabajos[], int lentrabajos);
int buscarTrabajoLibre(eTrabajo listtrabajos[], int lentrabajos);
void listarTrabajo(eTrabajo trabajos, eServicio listservicios[], int lenservicios);
int listarTrabajos(eTrabajo listtrabajos[], int lentrabajos, eServicio listservicios[], int lenservicios);
void totalPulidos(eTrabajo listtrabajos[], int lentrabajos, eServicio listservicios[], int lenservicios);


#endif // TRABAJO_H_INCLUDED
