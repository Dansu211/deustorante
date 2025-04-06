#include <stdio.h>
#include <string.h>
#include "../include/sqlite3.h"
#include "../include/cliente.h"
#include "../include/db.h"
#include "../include/config.h"

void menu_cliente(sqlite3 *db, Config *config);
void menu_administrador(sqlite3 *db);

int main() {
    Config config;
    if (leer_config("../config/config.txt", &config) != 0) {
        printf("Usando configuracion por defecto.\n");
    }

    sqlite3 *db;
    if (inicializar_db(&db, config.db_name) != 0) {
        return 1;
    }

    int modo = 0;
    printf("=== %s ===\n", config.welcome_message);
    printf("1. Modo Cliente\n");
    printf("2. Modo Administrador\n");
    printf("Seleccione un modo (1-2): ");
    scanf("%d", &modo);
    getchar();

    if (modo == 1) {
        menu_cliente(db, &config);
    } else if (modo == 2) {
        menu_administrador(db);
    } else {
        printf("Modo no valido. Saliendo...\n");
    }

    cerrar_db(db);
    return 0;
}

void menu_cliente(sqlite3 *db, Config *config) {
    int opcion = 0;
    while (opcion != 5) {
        printf("=== MENU CLIENTE - DEUSTORANTE ===\n");
        printf("1. Realizar una nueva reserva\n");
        printf("2. Ver mis reservas\n");
        printf("3. Modificar una reserva\n");
        printf("4. Cancelar una reserva\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion (1-5): ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1: {
                char nombre[50], telefono[15], fecha[11], hora[6];
                int id_menu, id_mesa, numero_personas;
                
                printf("Ingrese su nombre: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = 0;
                
                printf("Ingrese su telefono: ");
                fgets(telefono, sizeof(telefono), stdin);
                telefono[strcspn(telefono, "\n")] = 0;
                
                mostrar_menus(db);
                printf("Seleccione ID del menu: ");
                scanf("%d", &id_menu);
                getchar();
                
                mostrar_mesas(db);
                printf("Seleccione ID de la mesa: ");
                scanf("%d", &id_mesa);
                getchar();
                
                printf("Ingrese numero de personas (maximo %d): ", config->max_personas);
                scanf("%d", &numero_personas);
                getchar();
                if (numero_personas > config->max_personas) {
                    printf("Error: El numero de personas excede el maximo permitido (%d).\n", config->max_personas);
                    break;
                }
                
                printf("Ingrese fecha (dd/mm/aaaa): ");
                fgets(fecha, sizeof(fecha), stdin);
                fecha[strcspn(fecha, "\n")] = 0;
                
                printf("Ingrese hora (hh:mm): ");
                fgets(hora, sizeof(hora), stdin);
                hora[strcspn(hora, "\n")] = 0;
                
                if (realizar_reserva(db, nombre, telefono, id_menu, id_mesa, numero_personas, fecha, hora) != -1) {
                    printf("Reserva realizada con exito.\n");
                }
                break;
            }
            case 2: {
                printf("\n=== MIS RESERVAS ===\n");
                ver_reservas(db);
                break;
            }
            case 3: {
                int id_reserva, id_mesa, nuevo_numero_personas, nuevo_id_menu;
                char nueva_fecha[11], nueva_hora[6];
                
                printf("Ingrese ID de la reserva a modificar: ");
                scanf("%d", &id_reserva);
                getchar();
                
                mostrar_mesas(db);
                printf("Nuevo ID de la mesa: ");
                scanf("%d", &id_mesa);
                getchar();
                
                printf("Nueva fecha (dd/mm/aaaa): ");
                fgets(nueva_fecha, sizeof(nueva_fecha), stdin);
                nueva_fecha[strcspn(nueva_fecha, "\n")] = 0;
                
                printf("Nueva hora (hh:mm): ");
                fgets(nueva_hora, sizeof(nueva_hora), stdin);
                nueva_hora[strcspn(nueva_hora, "\n")] = 0;
                
                printf("Nuevo numero de personas (maximo %d): ", config->max_personas);
                scanf("%d", &nuevo_numero_personas);
                getchar();
                if (nuevo_numero_personas > config->max_personas) {
                    printf("Error: El numero de personas excede el maximo permitido (%d).\n", config->max_personas);
                    break;
                }
                
                mostrar_menus(db);
                printf("Nuevo ID del menu: ");
                scanf("%d", &nuevo_id_menu);
                getchar();
                
                modificar_reserva_cliente(db, id_reserva, id_mesa, nueva_fecha, nueva_hora, nuevo_numero_personas, nuevo_id_menu);
                printf("Reserva modificada con exito.\n");
                break;
            }
            case 4: {
                int id_reserva;
                printf("Ingrese ID de la reserva a cancelar: ");
                scanf("%d", &id_reserva);
                getchar();
                
                cancelar_reserva_cliente(db, id_reserva);
                printf("Reserva cancelada con exito.\n");
                break;
            }
            case 5:
                printf("Saliendo del modo cliente...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    }
}

void menu_administrador(sqlite3 *db) {
    int opcion = 0;
    while (opcion != 6) {
        printf("=== MENU ADMINISTRADOR - DEUSTORANTE ===\n");
        printf("1. Ver todas las reservas (activas y canceladas)\n");
        printf("2. Eliminar una reserva permanentemente\n");
        printf("3. Ver clientes\n");
        printf("4. Ver menus\n");
        printf("5. Ver mesas\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion (1-6): ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                mostrar_todas_reservas(db);
                break;
            case 2: {
                int id_reserva;
                printf("Ingrese ID de la reserva a eliminar: ");
                scanf("%d", &id_reserva);
                getchar();
                eliminar_reserva(db, id_reserva);
                printf("Reserva eliminada permanentemente con exito.\n");
                break;
            }
            case 3:
                mostrar_clientes(db);
                break;
            case 4:
                mostrar_menus(db);
                break;
            case 5:
                mostrar_mesas(db);
                break;
            case 6:
                printf("Saliendo del modo administrador...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    }
}