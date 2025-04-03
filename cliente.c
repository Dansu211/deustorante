#include "cliente.h"
#include "db.h"

void realizar_reserva(sqlite3 *db, int num_personas, int tipo_menu, const char* fecha, const char* hora) {
    guardar_reserva(db, num_personas, tipo_menu, fecha, hora);
}

void ver_reservas(sqlite3 *db) {
    mostrar_reservas(db);
}

void modificar_reserva_cliente(sqlite3 *db, int id, const char* nueva_fecha, const char* nueva_hora, int nuevo_num_personas, int nuevo_tipo_menu) {
    modificar_reserva(db, id, nueva_fecha, nueva_hora, nuevo_num_personas, nuevo_tipo_menu);
}

void cancelar_reserva_cliente(sqlite3 *db, int id) {
    cancelar_reserva(db, id);
}