typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

typedef struct
{
    int id;
    char patente[10];
    int idMarca;
    int idColor;
    int modelo;
}eAuto;

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

typedef struct
{
    int id;
    char patente[10];
    int idServicio;
    eFecha fecha;
}eTrabajo;

typedef struct
{
    int id;

}eCliente;

char menu();
void inicializarAutos(eAuto autos[], int tamaut);
void altaAuto(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores [], int tamcol);
void modificarAuto(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol);
void listarAuto(eAuto autos, int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol);
void listarAutos(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol);
int buscarAuto(eAuto autos[], int tamaut, char patenteIngresada[10]);
void listarMarcas(eMarca marcas[], int tammar);
void listarColores(eColor colores[], int tamcol);
void listarServicios(eServicio servicios[], int tamser);
void bajaAuto(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol);
void inicializarTrabajos(eTrabajo trabajos[], int tamtra);
int altaTrabajo(eAuto autos[], int tamaut, eMarca marcas[], int tammar, eColor colores[], int tamcol, eServicio servicios[], int tamser, eTrabajo trabajos[], int tamtra, int acumulador);
void listarTrabajos(eTrabajo trabajos[], int tamtra, eServicio servicios[], int tamser, eAuto autos[], int tamaut);
void listarTrabajo(eTrabajo trabajos, int tamtra, eServicio servicios[], int tamser, eAuto autos[], int tamaut);
