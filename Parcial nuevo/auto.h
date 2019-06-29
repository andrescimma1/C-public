#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "marca.h"
#include "color.h"
#include "cliente.h"
#include "servicio.h"
#include "trabajo.h"

typedef struct
{
    int id;
    char patente[7];
    int idMarca;
    int idColor;
    int modelo;
    int idCliente;
}eAuto;

void inicializarAutos(eAuto listaut[], int len);
int buscarLibre(eAuto listaut[], int len);
void altaAuto(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eCliente listclientes[], int lenclientes);
int listarAutos(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eCliente listclientes[], int lenclientes);
void listarAuto(eAuto pAuto, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eCliente pCliente);
void bajaAuto(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eCliente listclientes[], int lenclientes);
void modificarAuto(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eCliente listclientes[], int lenclientes);
void mostrarAutosColorNegro(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eCliente listclientes[], int lenclientes);
void mostrarAutosMarcaSeleccionada(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eCliente listclientes[], int lenclientes);
void mostrarTrabajosAutoSeleccionado(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eServicio listservicios[], int lenservicios, eTrabajo listtrabajos[], int lentrabajos, eCliente listclientes[], int lenclientes);
void listarAutosSinTrabajo(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eServicio listservicios[], int lenservicios, eTrabajo listtrabajos[], int lentrabajos, eCliente listclientes[], int lenclientes);
void importeTotalAutoSeleccionado(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eServicio listservicios[], int lenservicios, eTrabajo listtrabajos[], int lentrabajos, eCliente listclientes[], int lenclientes);
void mostrarServicioMasPedido(eTrabajo listtrabajos[], int lentrabajos, eServicio listservicios[], int lenservicios);
void mostrarRecaudacionSegunFecha(eTrabajo listtrabajos[], int lentrabajos, eServicio listservicios[], int lenservicios);
void mostrarAutosEnceradoYfecha(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eServicio listservicios[], int lenservicios, eTrabajo listtrabajos[], int lentrabajos, eCliente listclientes[], int lenclientes);
void trabajosAutosBlancos(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eServicio listservicios[], int lenservicios, eTrabajo listtrabajos[], int lentrabajos);
void altaTrabajo(eTrabajo listtrabajos[], int lentrabajos, eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eServicio listservicios[], int lenservicios, eCliente listclientes[], int lenclientes);
void marcaConMasLavadosCompletos(eMarca listmarcas[], int lenmarcas, eAuto listaut[], int len, eServicio listservicios[], int lenservicios, eTrabajo listtrabajos[], int lentrabajos);
void autosConTrabajoEnFechaDeterminada(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eTrabajo listtrabajos[], int lentrabajos, eServicio listservicios[], int lenservicios, eCliente listclientes[], int lenclientes);
void cantidadAutosDeCadaColorPorMarca(eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eAuto listaut[], int len);
void mostrarPatentesAutosGrises(eAuto listaut[], int len);
void mostrarAutosMismaMarcaPatenteIngresada(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eCliente listclientes[], int lenclientes);
void listarAutosHombre(eAuto listaut[], int len, eMarca listmarcas[], int lenmarcas, eColor listcolores[], int lencolores, eCliente listclientes[], int lenclientes);
void listarNombreClientesRenault(eAuto listaut[], int len, eCliente listclientes[], int lenclientes);
void cantidadDePulidosAmujeres(eTrabajo listtrabajos[], int lentrabajos, eCliente listclientes[], int lenclientes);
void listarMarcaElegidaPorMujeres(eAuto listaut[], int len, eCliente listclientes[], int lenclientes);
void mostrarNombresPersonasConLavados(eTrabajo listtrabajos[], int lentrabajos, eCliente listclientes[], int lenclientes);

#endif // AUTO_H_INCLUDED
