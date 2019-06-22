#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fecha.h"
#include "marca.h"
#include "auto.h"
#include "color.h"
#include "cliente.h"
#include "servicio.h"
#include "trabajo.h"

#define TAMAUT 10
#define TAMCLI 10
#define TAMMAR 5
#define TAMCOL 5
#define TAMSER 4
#define TAMTRA 10

int main()
{
    char seguir = 's';

    eMarca arrayMarcas[] = {
                           {1000, "Renault"},
                           {1001, "Fiat"},
                           {1002, "Ford"},
                           {1003, "Chevrolet"},
                           {1004, "Peugeot"}
                           };
    eColor arrayColores[] = {
                            {5000, "Negro"},
                            {5001, "Blanco"},
                            {5002, "Gris"},
                            {5003, "Rojo"},
                            {5004, "Azul"}
                            };

    eServicio arrayServicios[] = {
                                 {20000, "Lavado", 250},
                                 {20001, "Pulido", 300},
                                 {20002, "Encerado", 400},
                                 {20003, "Completo", 600}
                                 };

    eCliente arrayClientes[TAMCLI];
    inicializarClientes(arrayClientes, TAMCLI);
    eAuto arrayAutos[TAMAUT];
    inicializarAutos(arrayAutos, TAMAUT);
    eTrabajo arrayTrabajos[TAMTRA];
    inicializarTrabajos(arrayTrabajos, TAMTRA);

    do
    {
        switch(menu())
        {
            case 'a':
                altaAuto(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayClientes, TAMCLI);
                system("pause");
                break;
            case 'b':
                modificarAuto(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayClientes, TAMCLI);
                system("pause");
                break;
            case 'c':
                bajaAuto(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayClientes, TAMCLI);
                system("pause");
                break;
            case 'd':
                listarAutos(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayClientes, TAMCLI);
                system("pause");
                break;
            case 'e':
                listarMarcas(arrayMarcas, TAMMAR);
                system("pause");
                break;
            case 'f':
                listarColores(arrayColores, TAMCOL);
                system("pause");
                break;
            case 'g':
                listarServicios(arrayServicios, TAMSER);
                system("pause");
                break;
            case 'h':
                altaTrabajo(arrayTrabajos, TAMTRA, arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayServicios, TAMSER, arrayClientes, TAMCLI);
                system("pause");
                break;
            case 'i':
                listarTrabajos(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
                system("pause");
                break;
            case '1':
                mostrarAutosColorNegro(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayClientes, TAMCLI);
                system("pause");
                break;
            case '2':
                mostrarAutosMarcaSeleccionada(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayClientes, TAMCLI);
                system("pause");
                break;
            case '3':
                mostrarTrabajosAutoSeleccionado(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayServicios, TAMSER, arrayTrabajos, TAMTRA, arrayClientes, TAMCLI);
                system("pause");
                break;
            case '4':
                listarAutosSinTrabajo(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayServicios, TAMSER, arrayTrabajos, TAMTRA, arrayClientes, TAMCLI);
                system("pause");
                break;
            case '5':
                importeTotalAutoSeleccionado(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayServicios, TAMSER, arrayTrabajos, TAMTRA, arrayClientes, TAMCLI);
                system("pause");
                break;
            case '6':
                mostrarServicioMasPedido(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
                system("pause");
                break;
            case '7':
                mostrarRecaudacionSegunFecha(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
                system("pause");
                break;
            case '8':
                mostrarAutosEnceradoYfecha(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayServicios, TAMSER, arrayTrabajos, TAMTRA, arrayClientes, TAMCLI);
                system("pause");
                break;
            case '9':
                trabajosAutosBlancos(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayServicios, TAMSER, arrayTrabajos, TAMTRA);
                system("pause");
                break;
            case 'x':
                totalPulidos(arrayTrabajos, TAMTRA, arrayServicios, TAMSER);
                system("pause");
                break;
            case 'y':
                marcaConMasLavadosCompletos(arrayMarcas, TAMMAR, arrayAutos, TAMAUT, arrayServicios, TAMSER, arrayTrabajos, TAMTRA);
                system("pause");
                break;
            case 'z':
                autosConTrabajoEnFechaDeterminada(arrayAutos, TAMAUT, arrayMarcas, TAMMAR, arrayColores, TAMCOL, arrayTrabajos, TAMTRA, arrayServicios, TAMSER, arrayClientes, TAMCLI);
                system("pause");
                break;
            default:
                system("cls");
                printf("Opcion ingresada no valida\n\n");
                system("pause");
                break;
        }
    }while(seguir == 's');

    return 0;
}
