#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
}eCliente;

void inicializarClientes(eCliente listclientes[], int lenclientes);

#endif // CLIENTE_H_INCLUDED
