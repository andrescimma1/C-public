#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Cimma.h"

#define TAMAUT 10
#define TAMMAR 5
#define TAMCOL 5
#define TAMMOD 5
#define TAMSER 4
#define TAMTRA 50


int main()
{
    int acumulador = 1;
    char seguir = 's';
    //eAuto autos[TAMAUT];
    eTrabajo trabajos[TAMTRA];
    //inicializarAutos(autos, TAMAUT);
    inicializarTrabajos(trabajos, TAMTRA);

    eServicio servicios[] ={
   {20000, "Lavado", 250},
   {20001, "Pulido", 300},
   {20002, "Encerado", 400},
   {20003, "Completo", 600},
   {20004, "Teflonado", 800}
   };

   eMarca marcas[] ={
   {1000, "Renault"},
   {1001, "Fiat"},
   {1002, "Ford"},
   {1003, "Chevrolet"},
   {1004, "Peugeot"}
   };

    eColor colores[] ={
   {5000, "Negro"},
   {5001, "Blanco"},
   {5002, "Gris"},
   {5003, "Rojo"},
   {5004, "Azul"}
   };

   eAuto autos[]= {
       {1, "AAA201", 1000, 5001, 1995},
       {2, "DFR234", 1003, 5000, 2002},
       {3, "GFT564", 1002, 5003, 2007},
       {4, "ACD321", 1002, 5003, 1995},
       {5, "HTD656", 1004, 5002, 2008},
       {6, "QSZ435", 1003, 5001, 1994},
       {7, "LGX201", 1001, 5000, 2012},
       {8, "SUZ324", 1001, 5002, 1991},
       {9, "HCU762", 1000, 5003, 2008},
       {10, "DYC735", 1003, 5001, 2002},
       {11, "JJK879", 1003, 5001, 2010},
       {12, "FED322", 1004, 5002, 2006},
       {13, "GHV332", 1001, 5003, 2007},
       {14, "BDE221", 1000, 5004, 1996},
       {15, "OPD332", 1000, 5001, 2014},
       {16, "PPD121", 1002, 5001, 2015},
       {17, "IIT230", 1001, 5000, 2009},
       {18, "KOD220", 1004, 5002, 2011},
       {19, "QSZ305", 1004, 5002, 1993},
       {20, "SSD128", 1002, 5003, 1992},
       {21, "SSD240", 1003, 5004, 1992},
       {22, "EDF213", 1001, 5000, 2001},
   };

   eTrabajo trabajos[] = {

       {1, "AAA201", 20000, {12,3,2019}},
       {2, "DFR234", 20000, {2,4,2019}},
       {3, "GFT564", 20001, {7,1,2019}},
       {4, "ACD321", 20002, {9,11,2019}},
       {5, "HTD656", 20003, {12,12,2019}},
       {6, "QSZ435", 20001, {21,7,2019}},
       {7, "LGX201", 20001, {29,8,2019}},
       {8, "SUZ324", 20004, {31,5,2019}},
       {9, "HCU762", 20004, {2,2,2019}},
       {10, "DYC735", 20000, {18,2,2019}},
       {11, "JJK879", 20001, {17,3,2019}},
       {12, "AAA201", 20000, {17,4,2019}},
       {13, "DFR234", 20000, {2,6,2019}},
       {14, "GFT564", 20001, {7,3,2019}},
       {15, "ACD321", 20002, {21,7,2019}},
       {16, "HTD656", 20003, {11,9,2019}},
       {17, "QSZ435", 20001, {3,7,2019}},
       {18, "LGX201", 20001, {21,8,2019}},
       {19, "SUZ324", 20004, {28,5,2019}},
       {20, "HCU762", 20004, {2,8,2019}},
       {21, "DYC735", 20000, {8,2,2019}},
       {22, "JJK879", 20001, {17,3,2019}},
       {23, "KOD220", 20003, {17,4,2019}},
       {24, "QSZ305", 20000, {21,3,2019}},
       {25, "SSD128", 20002, {16,4,2019}},
       {26, "SSD240", 20000, {17,4,2019}},
       {27, "EDF213", 20001, {23,3,2019}},
       {28, "AAA201", 20000, {12,2,2019}},
       {29, "DFR234", 20000, {2,3,2019}},
       {30, "GFT564", 20001, {7,2,2019}},
       {31, "ACD321", 20002, {9,12,2019}},
       {32, "HTD656", 20003, {12,9,2019}},
       {33, "QSZ435", 20001, {21,5,2019}},
       {34, "HTD656", 20002, {12,2,2019}},
       {35, "QSZ435", 20000, {21,1,2019}},
   };

    do
    {
        switch(menu())
        {
            case 'a':
                altaAuto(autos, TAMAUT, marcas, TAMMAR, colores, TAMCOL);
                system("pause");
                break;
            case 'b':
                modificarAuto(autos, TAMAUT, marcas, TAMMAR, colores, TAMCOL);
                system("pause");
                break;
            case 'c':
                bajaAuto(autos, TAMAUT, marcas, TAMMAR, colores, TAMCOL);
                system("pause");
                break;
            case 'd':
                listarAutos(autos, TAMAUT, marcas, TAMMAR, colores, TAMCOL);
                system("pause");
                break;
            case 'e':
                listarMarcas(marcas, TAMMAR);
                system("pause");
                break;
            case 'f':
                listarColores(colores, TAMCOL);
                system("pause");
                break;
            case 'g':
                listarServicios(servicios, TAMSER);
                system("pause");
                break;
            case 'h':
                altaTrabajo(autos, TAMAUT, marcas, TAMMAR, colores, TAMCOL, servicios, TAMSER, trabajos, TAMTRA, acumulador);
                system("pause");
                break;
            case 'i':
                listarTrabajos(trabajos, TAMTRA, servicios, TAMSER, autos, TAMAUT);
                system("pause");
                break;
            case 'j':
                printf("Anda bien");
                system("pause");
                break;
            case 's':
                printf("\n\nDesea salir? (s/n): ");
                fflush(stdin);
                scanf("%c", &seguir);
            default:
                printf("\nError, opcion invalida\n");
                system("pause");
                break;
        }
    }while(seguir == 's');
    return 0;
}
