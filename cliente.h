#ifndef CLIENTE_H
#define CLIENTE_H

#include <sqlite3.h>

void realizar_reserva(sqlite3 *db, int num_personas, int tipo_menu, const char* fecha, const char* hora);
void ver_reservas(sqlite3 *db);
void modificar_reserva_cliente(sqlite3 *db, int id, const char* nueva_fecha, const char* nueva_hora, int nuevo_num_personas, int nuevo_tipo_menu);
void cancelar_reserva_cliente(sqlite3 *db, int id);

#endif