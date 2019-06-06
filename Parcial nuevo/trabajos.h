#define TAMAUT 10
#define TAMCLI 10
#define TAMMAR 5
#define TAMCOL 5
#define TAMSER 4
#define TAMTRA 10

typedef struct
{
    int id;
    int estado;
    char patente[7];
    int idServicio;
    eFecha fecha;
}eTrabajo;


//Prototipos
void inicializarClientes(eCliente* listclientes, int lenclientes);
void inicializarAutos(eAuto* listaut, int len);
int menu();
int buscarLibre(eAuto* listaut, int len);
void altaAuto(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* listclientes, int lenclientes);
void listarMarcas(eMarca* listmarcas, int lenmarcas);
void listarColores(eColor* listcolores, int lencolores);
int listarAutos(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* listclientes, int lenclientes);
void listarAuto(eAuto* pAuto, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* pCliente);
void listarServicios(eServicio* listservicios, int lenservicios);
void bajaAuto(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* listclientes, int lenclientes);
void modificarAuto(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* listclientes, int lenclientes);
void inicializarTrabajos(eTrabajo* listtrabajos, int lentrabajos);
int buscarTrabajoLibre(eTrabajo* listtrabajos, int lentrabajos);
void altaTrabajo(eTrabajo* listtrabajos, int lentrabajos, eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eCliente* listclientes, int lenclientes);
void listarTrabajo(eTrabajo* trabajos, eServicio* listservicios, int lenservicios);
int listarTrabajos(eTrabajo* listtrabajos, int lentrabajos, eServicio* listservicios, int lenservicios);
void mostrarAutosColorNegro(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* listclientes, int lenclientes);
void mostrarAutosMarcaSeleccionada(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eCliente* listclientes, int lenclientes);
void mostrarTrabajosAutoSeleccionado(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos, eCliente* listclientes, int lenclientes);
void listarAutosSinTrabajo(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos, eCliente* listclientes, int lenclientes);
void importeTotalAutoSeleccionado(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos, eCliente* listclientes, int lenclientes);
void mostrarServicioMasPedido(eTrabajo* listtrabajos, int lentrabajos, eServicio* listservicios, int lenservicios);
void mostrarRecaudacionSegunFecha(eTrabajo* listtrabajos, int lentrabajos, eServicio* listservicios, int lenservicios);
void mostrarAutosEnceradoYfecha(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos, eCliente* listclientes, int lenclientes);
void trabajosAutosBlancos(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos);
void totalPulidos(eTrabajo* listtrabajos, int lentrabajos, eServicio* listservicios, int lenservicios);
void marcaConMasLavadosCompletos(eMarca* listmarcas, int lenmarcas, eAuto* listaut, int len, eServicio* listservicios, int lenservicios, eTrabajo* listtrabajos, int lentrabajos);
void autosConTrabajoEnFechaDeterminada(eAuto* listaut, int len, eMarca* listmarcas, int lenmarcas, eColor* listcolores, int lencolores, eTrabajo* listtrabajos, int lentrabajos, eServicio* listservicios, int lenservicios, eCliente* listclientes, int lenclientes);
