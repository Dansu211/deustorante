#include <stdio.h>
#include <string.h>
#include "../include/db.h"
#include "../include/sqlite3.h"
#include <stdlib.h>

int inicializar_db(sqlite3 **db, const char *db_name) {
    int rc = sqlite3_open(db_name, db);
    if (rc) {
        fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(*db));
        return 1;
    }
	// Falta la tabla Plato con sus respectivas operaciones
    const char *sql = 
        "CREATE TABLE IF NOT EXISTS Clientes ("
        "id_cliente INTEGER PRIMARY KEY AUTOINCREMENT, "
        "nombre TEXT NOT NULL, "
        "telefono TEXT NOT NULL);"
        
        "CREATE TABLE IF NOT EXISTS Menus ("
        "id_menu INTEGER PRIMARY KEY AUTOINCREMENT, "
        "nombre_menu TEXT NOT NULL, "
        "descripcion TEXT);"
        
        "CREATE TABLE IF NOT EXISTS Mesas ("
        "id_mesa INTEGER PRIMARY KEY AUTOINCREMENT, "
        "capacidad INTEGER NOT NULL, "
        "ubicacion TEXT);"
        
        "CREATE TABLE IF NOT EXISTS Reservas ("
        "id_reserva INTEGER PRIMARY KEY AUTOINCREMENT, "
        "id_cliente INTEGER, "
        "id_menu INTEGER, "
        "id_mesa INTEGER, "
        "numero_personas INTEGER, "
        "fecha TEXT, "
        "hora TEXT, "
        "activa INTEGER DEFAULT 1, "
        "FOREIGN KEY (id_cliente) REFERENCES Clientes(id_cliente), "
        "FOREIGN KEY (id_menu) REFERENCES Menus(id_menu), "
        "FOREIGN KEY (id_mesa) REFERENCES Mesas(id_mesa));";

    char *err_msg = 0;
    rc = sqlite3_exec(*db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear las tablas: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(*db);
        return 1;
    }

    // Insertar algunos menús iniciales si la tabla está vacía
    const char *menus_iniciales = 
        "INSERT OR IGNORE INTO Menus (id_menu, nombre_menu, descripcion) VALUES "
        "(1, 'Normal', 'Menú estándar con carne y verduras'), "
        "(2, 'Vegetariano', 'Menú sin carne'), "
        "(3, 'Especial', 'Menú gourmet personalizado');";
    rc = sqlite3_exec(*db, menus_iniciales, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al inicializar menús: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    return 0;
}

void cerrar_db(sqlite3 *db) {
    sqlite3_close(db);
}

// --- Clientes ---
int guardar_cliente(sqlite3 *db, const char *nombre, const char *telefono) {
    char sql[200];
    sprintf(sql, "INSERT INTO Clientes (nombre, telefono) VALUES ('%s', '%s');", nombre, telefono);
    
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al guardar cliente: %s\n", err_msg);
        sqlite3_free(err_msg);
        return -1;
    }
    return sqlite3_last_insert_rowid(db); // Devuelve el ID del cliente insertado
}

static int callback_mostrar_clientes(void *data, int argc, char **argv, char **azColName) {
    printf("ID: %s, Nombre: %s, Teléfono: %s\n", argv[0], argv[1], argv[2]);
    return 0;
}

void mostrar_clientes(sqlite3 *db) {
    const char *sql = "SELECT * FROM Clientes;";
    char *err_msg = 0;
    printf("\n=== LISTA DE CLIENTES ===\n");
    int rc = sqlite3_exec(db, sql, callback_mostrar_clientes, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al mostrar clientes: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

// --- Menus ---
int guardar_menu(sqlite3 *db, const char *nombre_menu, const char *descripcion) {
    char sql[200];
    sprintf(sql, "INSERT INTO Menus (nombre_menu, descripcion) VALUES ('%s', '%s');", nombre_menu, descripcion);
    
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al guardar menú: %s\n", err_msg);
        sqlite3_free(err_msg);
        return -1;
    }
    return sqlite3_last_insert_rowid(db);
}

static int callback_mostrar_menus(void *data, int argc, char **argv, char **azColName) {
    printf("ID: %s, Nombre: %s, Descripción: %s\n", argv[0], argv[1], argv[2]);
    return 0;
}

void mostrar_menus(sqlite3 *db) {
    const char *sql = "SELECT * FROM Menus;";
    char *err_msg = 0;
    printf("\n=== LISTA DE MENÚS ===\n");
    int rc = sqlite3_exec(db, sql, callback_mostrar_menus, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al mostrar menús: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

// --- Mesas ---
int guardar_mesa(sqlite3 *db, int capacidad, const char *ubicacion) {
    char sql[200];
    sprintf(sql, "INSERT INTO Mesas (capacidad, ubicacion) VALUES (%d, '%s');", capacidad, ubicacion);
    
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al guardar mesa: %s\n", err_msg);
        sqlite3_free(err_msg);
        return -1;
    }
    return sqlite3_last_insert_rowid(db);
}

static int callback_mostrar_mesas(void *data, int argc, char **argv, char **azColName) {
    printf("ID: %s, Capacidad: %s, Ubicación: %s\n", argv[0], argv[1], argv[2]);
    return 0;
}

void mostrar_mesas(sqlite3 *db) {
    const char *sql = "SELECT * FROM Mesas;";
    char *err_msg = 0;
    printf("\n=== LISTA DE MESAS ===\n");
    int rc = sqlite3_exec(db, sql, callback_mostrar_mesas, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al mostrar mesas: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

// --- Reservas ---
int guardar_reserva(sqlite3 *db, int id_cliente, int id_menu, int id_mesa, int num_personas, const char *fecha, const char *hora) {
    char sql[200];
    sprintf(sql, "INSERT INTO Reservas (id_cliente, id_menu, id_mesa, numero_personas, fecha, hora) VALUES (%d, %d, %d, %d, '%s', '%s');",
            id_cliente, id_menu, id_mesa, num_personas, fecha, hora);
    
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al guardar reserva: %s\n", err_msg);
        sqlite3_free(err_msg);
        return -1;
    }
    return sqlite3_last_insert_rowid(db);
}

static int callback_mostrar_reservas(void *data, int argc, char **argv, char **azColName) {
    if (atoi(argv[7]) == 1) { // Solo reservas activas
        printf("ID Reserva: %s\n", argv[0]);
        printf("Cliente ID: %s\n", argv[1]);
        printf("Menú ID: %s\n", argv[2]);
        printf("Mesa ID: %s\n", argv[3]);
        printf("Número de personas: %s\n", argv[4]);
        printf("Fecha: %s\n", argv[5]);
        printf("Hora: %s\n\n", argv[6]);
    }
    return 0;
}

void mostrar_reservas(sqlite3 *db) {
    const char *sql = "SELECT * FROM Reservas;";
    char *err_msg = 0;
    printf("\n=== MIS RESERVAS ===\n");
    int rc = sqlite3_exec(db, sql, callback_mostrar_reservas, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al mostrar reservas: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

static int callback_mostrar_todas(void *data, int argc, char **argv, char **azColName) {
    printf("ID Reserva: %s\n", argv[0]);
    printf("Cliente ID: %s\n", argv[1]);
    printf("Menú ID: %s\n", argv[2]);
    printf("Mesa ID: %s\n", argv[3]);
    printf("Número de personas: %s\n", argv[4]);
    printf("Fecha: %s\n", argv[5]);
    printf("Hora: %s\n", argv[6]);
    printf("Estado: %s\n\n", atoi(argv[7]) == 1 ? "Activa" : "Cancelada");
    return 0;
}

void mostrar_todas_reservas(sqlite3 *db) {
    const char *sql = "SELECT * FROM Reservas;";
    char *err_msg = 0;
    printf("\n=== TODAS LAS RESERVAS (ADMIN) ===\n");
    int rc = sqlite3_exec(db, sql, callback_mostrar_todas, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al mostrar todas las reservas: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void modificar_reserva(sqlite3 *db, int id, int id_mesa, const char *nueva_fecha, const char *nueva_hora, int nuevo_num_personas, int nuevo_id_menu) {
    char sql[200];
    sprintf(sql, "UPDATE Reservas SET id_mesa=%d, fecha='%s', hora='%s', numero_personas=%d, id_menu=%d WHERE id_reserva=%d AND activa=1;",
            id_mesa, nueva_fecha, nueva_hora, nuevo_num_personas, nuevo_id_menu, id);
    
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

void eliminar_reserva(sqlite3 *db, int id) {
    char sql[100];
    sprintf(sql, "DELETE FROM Reservas WHERE id_reserva=%d;", id);
    
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al eliminar reserva: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}