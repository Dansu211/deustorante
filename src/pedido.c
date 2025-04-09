#include "pedido.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Pedido* crearPedido(int id,int id_usuario,char* direccion, int estado) {
    Pedido* p = malloc(sizeof(Pedido));
    p->id = id;
    p->id_usuario = id_usuario;
    p->direccion = direccion;
    p->estado = estado;
    return p;
}
