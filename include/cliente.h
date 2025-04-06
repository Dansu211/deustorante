#ifndef CLIENTE_H
#define CLIENTE_H

#define TAM_DNI 10
#define TAM_NOMBRE 50
#define TAM_APELLIDOS 100
#define TAM_DIRECCION 150
#define TAM_TELEFONO 15
#define TAM_EMAIL 100
#define TAM_FECHA 11

typedef struct {
    int ID;
    char dni[TAM_DNI];
    char nombre[TAM_NOMBRE];
    char apellidos[TAM_APELLIDOS];
    char direccion[TAM_DIRECCION];
    char tlf[TAM_TELEFONO];
    char email[TAM_EMAIL];
    char fecha_registro[TAM_FECHA];
} Client;

typedef struct {
    Client *aClient;
    int numClient;
} ListaClientes;

// void iniLC(ListaClientes *lc);
// void addClient(ListaClientes *lc, Client c);
// void printCli(Client c);
// void printLCli(ListaClientes lc);
// Client registrarCliente(ListaClientes lc);

#include "sqlite3.h"

int realizar_reserva(sqlite3 *db, const char *nombre_cliente, const char *telefono, int id_menu, int id_mesa, int num_personas, const char *fecha, const char *hora);
void ver_reservas(sqlite3 *db);
void modificar_reserva_cliente(sqlite3 *db, int id, int id_mesa, const char *nueva_fecha, const char *nueva_hora, int nuevo_num_personas, int nuevo_id_menu);
void cancelar_reserva_cliente(sqlite3 *db, int id);

#endif