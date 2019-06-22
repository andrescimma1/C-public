#include "cliente.h"

/** \brief Inicializa el id de los clientes en 0;
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void inicializarClientes(eCliente listclientes[], int lenclientes)
{
    int i;
    for(i=0; i<lenclientes; i++)
    {
        listclientes[i].id = 0;
    }
}
