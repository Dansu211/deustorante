#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include "cliente.h"
#include "db.h"

int main() {
    sqlite3 *db;
    if (inicializar_db(&db) != 0) {
        return 1;
    }

    int opcion = 0;
    while (opcion != 5) {
        printf("=== MENÚ CLIENTE - DEUSTORANTE ===\n");
        printf("1. Realizar una nueva reserva\n");
        printf("2. Ver mis reservas\n");
        printf("3. Modificar una reserva\n");
        printf("4. Cancelar una reserva\n");
        printf("5. Salir\n");
        printf("Seleccione una opción (1-5): ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer

        switch (opcion) {
            case 1: {
                int numero_personas, tipo_menu;
                char fecha[11], hora[6];
                
                printf("Ingrese número de personas: ");
                scanf("%d", &numero_personas);
                getchar();
                
                printf("Seleccione tipo de menú (1. Normal, 2. Vegetariano, 3. Especial): ");
                scanf("%d", &tipo_menu);
                getchar();
                
                printf("Ingrese fecha (dd/mm/aaaa): ");
                fgets(fecha, sizeof(fecha), stdin);
                fecha[strcspn(fecha, "\n")] = 0;
                
                printf("Ingrese hora (hh:mm): ");
                fgets(hora, sizeof(hora), stdin);
                hora[strcspn(hora, "\n")] = 0;
                
                realizar_reserva(db, numero_personas, tipo_menu, fecha, hora);
                printf("Reserva realizada con éxito.\n");
                break;
            }
            case 2: {
                printf("\n=== MIS RESERVAS ===\n");
                ver_reservas(db);
                break;
            }
            case 3: {
                int id_reserva, nuevo_numero_personas, nuevo_tipo_menu;
                char nueva_fecha[11], nueva_hora[6];
                
                printf("Ingrese ID de la reserva a modificar: ");
                scanf("%d", &id_reserva);
                getchar();
                
                printf("Nueva fecha (dd/mm/aaaa): ");
                fgets(nueva_fecha, sizeof(nueva_fecha), stdin);
                nueva_fecha[strcspn(nueva_fecha, "\n")] = 0;
                
                printf("Nueva hora (hh:mm): ");
                fgets(nueva_hora, sizeof(nueva_hora), stdin);
                nueva_hora[strcspn(nueva_hora, "\n")] = 0;
                
                printf("Nuevo número de personas: ");
                scanf("%d", &nuevo_numero_personas);
                getchar();
                
                printf("Nuevo tipo de menú (1. Normal, 2. Vegetariano, 3. Especial): ");
                scanf("%d", &nuevo_tipo_menu);
                getchar();
                
                modificar_reserva_cliente(db, id_reserva, nueva_fecha, nueva_hora, nuevo_numero_personas, nuevo_tipo_menu);
                printf("Reserva modificada con éxito.\n");
                break;
            }
            case 4: {
                int id_reserva;
                printf("Ingrese ID de la reserva a cancelar: ");
                scanf("%d", &id_reserva);
                getchar();
                
                cancelar_reserva_cliente(db, id_reserva);
                printf("Reserva cancelada con éxito.\n");
                break;
            }
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    cerrar_db(db);
    return 0;
}