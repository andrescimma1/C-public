#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    char nombre[80];
    int tel;
    eFecha fecha_de_nacimiento;


}eContacto;

eFecha crear_fecha()
{
    eFecha nueva_fecha;
    printf("Ingrese el dia: ");
    scanf("%d", &nueva_fecha.dia);
    printf("Ingrese el mes: ");
    scanf("%d", &nueva_fecha.mes);
    printf("Ingrese el anio: ");
    scanf("%d", &nueva_fecha.anio);

    return nueva_fecha;
}



eContacto crear_contacto()
{
    eContacto nuevo_contacto;

    //Asigno el nombre
    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(nuevo_contacto.nombre);

    //Asigno el telefono
    printf("Ingrese su numero de telefono: ");
    fflush(stdin);
    scanf("%d", &nuevo_contacto.tel);

    //Asigno la fecha
    nuevo_contacto.fecha_de_nacimiento = crear_fecha();

    return nuevo_contacto;
}

void imprimir_contacto(eContacto contacto)
{
    system("cls"); //Limpio la pantalla
    printf("El nombre es: %s\nEl telefono es: %d\nLa fecha de nacimiento es: %02d/%02d/%d", contacto.nombre, contacto.tel
           , contacto.fecha_de_nacimiento.dia, contacto.fecha_de_nacimiento.mes, contacto.fecha_de_nacimiento.anio);
}


int main()
{
    eContacto c1;
    c1 = crear_contacto();

    imprimir_contacto(c1);
    return 0;
}
