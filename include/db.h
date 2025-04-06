#ifndef DB_H
#define DB_H

#include "sqlite3.h"
#include "reserva.h"

int inicializar_db(sqlite3 **db, const char *db_name);
void cerrar_db(sqlite3 *db);

// Funciones para Clientes
int guardar_cliente(sqlite3 *db, const char *nombre, const char *telefono);
void mostrar_clientes(sqlite3 *db);

// Funciones para Menus
int guardar_menu(sqlite3 *db, const char *nombre_menu, const char *descripcion);
void mostrar_menus(sqlite3 *db);

// Funciones para Mesas
int guardar_mesa(sqlite3 *db, int capacidad, const char *ubicacion);
void mostrar_mesas(sqlite3 *db);

// Funciones para Reservas
int guardar_reserva(sqlite3 *db, int id_cliente, int id_menu, int id_mesa, int num_personas, const char *fecha, const char *hora);
void mostrar_reservas(sqlite3 *db);
void mostrar_todas_reservas(sqlite3 *db);
void modificar_reserva(sqlite3 *db, int id, int id_mesa, const char *nueva_fecha, const char *nueva_hora, int nuevo_num_personas, int nuevo_id_menu);
void cancelar_reserva(sqlite3 *db, int id);
void eliminar_reserva(sqlite3 *db, int id);

#endif