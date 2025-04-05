#ifndef DB_H
#define DB_H

#include <sqlite3.h>
#include "reserva.h"

int inicializar_db(sqlite3 **db);
void cerrar_db(sqlite3 *db);
void guardar_reserva(sqlite3 *db, int num_personas, int tipo_menu, const char* fecha, const char* hora);
void mostrar_reservas(sqlite3 *db);
void modificar_reserva(sqlite3 *db, int id, const char* nueva_fecha, const char* nueva_hora, int nuevo_num_personas, int nuevo_tipo_menu);
void cancelar_reserva(sqlite3 *db, int id);

#endif