#include <stdio.h>
#include <string.h>
#include "db.h"
#include "sqlite3.h"
#include <stdlib.h>
#include <sqlite3.h>

int inicializar_db(sqlite3 **db) {
    int rc = sqlite3_open("deustorante.db", db);
    if (rc) {
        fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(*db));
        return 1;
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS Reservas ("
                      "id_reserva INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "numero_personas INTEGER, "
                      "tipo_menu INTEGER, "
                      "fecha TEXT, "
                      "hora TEXT, "
                      "activa INTEGER DEFAULT 1);";
    char *err_msg = 0;
    rc = sqlite3_exec(*db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear la tabla: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(*db);
        return 1;
    }
    return 0;
}

void cerrar_db(sqlite3 *db) {
    sqlite3_close(db);
}

void guardar_reserva(sqlite3 *db, int num_personas, int tipo_menu, const char* fecha, const char* hora) {
    char sql[200];
    sprintf(sql, "INSERT INTO Reservas (numero_personas, tipo_menu, fecha, hora) VALUES (%d, %d, '%s', '%s');",
            num_personas, tipo_menu, fecha, hora);
    
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al guardar reserva: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

static int callback_mostrar(void *data, int argc, char **argv, char **azColName) {
    if (atoi(argv[5]) == 1) { // Solo mostrar reservas activas
        printf("ID: %s\n", argv[0]);
        printf("Número de personas: %s\n", argv[1]);
        printf("Tipo de menú: %s (%s)\n", argv[2],
               atoi(argv[2]) == 1 ? "Normal" :
               atoi(argv[2]) == 2 ? "Vegetariano" : "Especial");
        printf("Fecha: %s\n", argv[3]);
        printf("Hora: %s\n\n", argv[4]);
    }
    return 0;
}

void mostrar_reservas(sqlite3 *db) {
    const char *sql = "SELECT * FROM Reservas;";
    char *err_msg = 0;
    printf("\n=== MIS RESERVAS ===\n");
    int rc = sqlite3_exec(db, sql, callback_mostrar, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al mostrar reservas: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void modificar_reserva(sqlite3 *db, int id, const char* nueva_fecha, const char* nueva_hora, int nuevo_num_personas, int nuevo_tipo_menu) {
    char sql[200];
    sprintf(sql, "UPDATE Reservas SET fecha='%s', hora='%s', numero_personas=%d, tipo_menu=%d WHERE id_reserva=%d AND activa=1;",
            nueva_fecha, nueva_hora, nuevo_num_personas, nuevo_tipo_menu, id);
    
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al modificar reserva: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void cancelar_reserva(sqlite3 *db, int id) {
    char sql[100];
    sprintf(sql, "UPDATE Reservas SET activa=0 WHERE id_reserva=%d AND activa=1;", id);
    
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al cancelar reserva: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}