#ifndef PEDIDO_H
#define PEDIDO_H

#include "plato.h"

#define ESTADO_PEDIDO_RECIBIDO 0;
#define ESTADO_PEDIDO_EN_PROCESO 1;
#define ESTADO_PEDIDO_EN_REPARTO 2;
#define ESTADO_PEDIDO_ENTREGADO 3;

typedef struct
{
    Plato* plato;
    int cantidad;
} ElementoPedido;  // Plato en el pedido y cantidad

typedef struct
{
    int id;
    int id_usuario;
    // Cliente cliente;
    char* direccion;
    int estado;
    // se podría añadir tambien la fecha del pedido (tiempo)
    ElementoPedido** platos; // Lista de elementos en el pedido
} Pedido;

Pedido* crearPedido(int id,int id_usuario, char* direccion, int estado);

#endif //PEDIDO_H
