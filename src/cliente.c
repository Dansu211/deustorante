#include "../include/cliente.h"
#include "../include/db.h"

int realizar_reserva(sqlite3 *db, const char *nombre_cliente, const char *telefono, int id_menu, int id_mesa, int num_personas, const char *fecha, const char *hora) {
    int id_cliente = guardar_cliente(db, nombre_cliente, telefono);
    if (id_cliente == -1) {
        return -1;
    }
    return guardar_reserva(db, id_cliente, id_menu, id_mesa, num_personas, fecha, hora);
}

void ver_reservas(sqlite3 *db) {
    mostrar_reservas(db);
}

void modificar_reserva_cliente(sqlite3 *db, int id, int id_mesa, const char *nueva_fecha, const char *nueva_hora, int nuevo_num_personas, int nuevo_id_menu) {
    modificar_reserva(db, id, id_mesa, nueva_fecha, nueva_hora, nuevo_num_personas, nuevo_id_menu);
}

void cancelar_reserva_cliente(sqlite3 *db, int id) {
    cancelar_reserva(db, id);
}

// void iniLC(ListaClientes *lc) {
//     lc->aClient = NULL;
//     lc->numClient = 0;
// }
// void addClient(ListaClientes *lc, Client c) {
//     int i;

//     if (lc->aClient == NULL) {
//         lc->aClient = malloc(1 * sizeof(Client));
//     } else {
//         Client *aux = malloc(lc->numClient * sizeof(Client));
//         for (i = 0; i < lc->numClient; i++) {
//             aux[i] = lc->aClient[i];
//         }
//         free(lc->aClient);
//         lc->aClient = malloc((lc->numClient + 1) * sizeof(Client));
//         for (i = 0; i < lc->numClient; i++) {
//             lc->aClient[i] = aux[i];
//         }
//         free(aux);
//     }
//     lc->aClient[lc->numClient] = c;
//     lc->numClient++;
// }

// void printCli(Client c) {
//     printf("%5d%15s%20s%25s%30s%15s%25s%15s\n", // Ancho por colum en caracteres
//            c.ID,
//            c.dni,
//            c.nombre,
//            c.apellidos,
//            c.direccion,
//            c.tlf,
//            c.email,
//            c.fecha_registro);
// }

// void printLCli(ListaClientes lc) {
//     int i;
//     printf("%5s%15s%20s%25s%30s%15s%25s%15s\n", // Ancho por colum en caracteres
//            "ID",
//            "DNI/NIE",
//            "NOMBRE",
//            "APELLIDOS",
//            "DIRECCION",
//            "TELEFONO",
//            "EMAIL",
//            "FECHA_REG");
//     for (i = 0; i < lc.numClient; i++) {
//         printCli(lc.aClient[i]);
//     }
// }

// Client registrarCliente(ListaClientes lc) {
//     Client c;

//     c.ID = lc.numClient;
//     printf("Introduce el DNI: ");
//     fgets(c.dni, TAM_DNI, stdin);
//     c.dni[strcspn(c.dni, "\n")] = 0;
//     printf("Introduce el nombre: ");
//     fgets(c.nombre, TAM_NOMBRE, stdin);
//     c.nombre[strcspn(c.nombre, "\n")] = 0;
//     printf("Introduce los apellidos: ");
//     fgets(c.apellidos, TAM_APELLIDOS, stdin);
//     c.apellidos[strcspn(c.apellidos, "\n")] = 0;
//     printf("Introduce la dirección: ");
//     fgets(c.direccion, TAM_DIRECCION, stdin);
//     c.direccion[strcspn(c.direccion, "\n")] = 0;
//     printf("Introduce el teléfono: ");
//     fgets(c.tlf, TAM_TELEFONO, stdin);
//     c.tlf[strcspn(c.tlf, "\n")] = 0;
//     printf("Introduce el email: ");
//     fgets(c.email, TAM_EMAIL, stdin);
//     c.email[strcspn(c.email, "\n")] = 0;
//     printf("Introduce la fecha de registro (YYYY-MM-DD): ");
//     fgets(c.fecha_registro, TAM_FECHA, stdin);
//     c.fecha_registro[strcspn(c.fecha_registro, "\n")] = 0;

//     return c;
// }