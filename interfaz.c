#include <stdio.h>
#include <string.h>

#define MAX_RESERVAS 100

// Estructura para almacenar una reserva
// typedef struct {
//     int id_reserva;
//     int numero_personas;
//     int tipo_menu; // 1: Normal, 2: Vegetariano, 3: Especial
//     char fecha[11]; // Formato dd/mm/aaaa
//     char hora[6];   // Formato hh:mm
//     int activa;     // 1: activa, 0: cancelada
// } Reserva;

// Reserva reservas[MAX_RESERVAS];
// int total_reservas = 0;

// // Prototipos de funciones
// void guardar_reserva(int num_personas, int tipo_menu, char* fecha, char* hora);
// void mostrar_reservas();
// void modificar_reserva(int id, char* nueva_fecha, char* nueva_hora, int nuevo_num_personas, int nuevo_tipo_menu);
// void cancelar_reserva(int id);

// int main() {
//     int opcion = 0;
    
//     while (opcion != 5) {
//         printf("=== MENU CLIENTE - DEUSTORANTE ===\n");
//         printf("1. Realizar una nueva reserva\n");
//         printf("2. Ver mis reservas\n");
//         printf("3. Modificar una reserva\n");
//         printf("4. Cancelar una reserva\n");
//         printf("5. Salir\n");
//         printf("Seleccione una opcion (1-5): ");
//         scanf("%d", &opcion);
//         getchar(); // Limpiar el buffer de entrada

//         switch (opcion) {
//             case 1: {
//                 int numero_personas, tipo_menu;
//                 char fecha[11], hora[6];
                
//                 printf("Ingrese numero de personas: ");
//                 scanf("%d", &numero_personas);
//                 getchar();
                
//                 printf("Seleccione tipo de menu (1. Normal, 2. Vegetariano, 3. Especial): ");
//                 scanf("%d", &tipo_menu);
//                 getchar();
                
//                 printf("Ingrese fecha (dd/mm/aaaa): ");
//                 fgets(fecha, sizeof(fecha), stdin);
//                 fecha[strcspn(fecha, "\n")] = 0; // Eliminar salto de línea
                
//                 printf("Ingrese hora (hh:mm): ");
//                 fgets(hora, sizeof(hora), stdin);
//                 hora[strcspn(hora, "\n")] = 0;
                
//                 guardar_reserva(numero_personas, tipo_menu, fecha, hora);
//                 printf("Reserva realizada con exito.\n");
//                 break;
//             }
//             case 2:
//                 mostrar_reservas();
//                 break;
//             case 3: {
//                 int id_reserva, nuevo_numero_personas, nuevo_tipo_menu;
//                 char nueva_fecha[11], nueva_hora[6];
                
//                 printf("Ingrese ID de la reserva a modificar: ");
//                 scanf("%d", &id_reserva);
//                 getchar();
                
//                 printf("Nueva fecha (dd/mm/aaaa): ");
//                 fgets(nueva_fecha, sizeof(nueva_fecha), stdin);
//                 nueva_fecha[strcspn(nueva_fecha, "\n")] = 0;
                
//                 printf("Nueva hora (hh:mm): ");
//                 fgets(nueva_hora, sizeof(nueva_hora), stdin);
//                 nueva_hora[strcspn(nueva_hora, "\n")] = 0;
                
//                 printf("Nuevo numero de personas: ");
//                 scanf("%d", &nuevo_numero_personas);
//                 getchar();
                
//                 printf("Nuevo tipo de menu (1. Normal, 2. Vegetariano, 3. Especial): ");
//                 scanf("%d", &nuevo_tipo_menu);
//                 getchar();
                
//                 modificar_reserva(id_reserva, nueva_fecha, nueva_hora, nuevo_numero_personas, nuevo_tipo_menu);
//                 printf("Reserva modificada con exito.\n");
//                 break;
//             }
//             case 4: {
//                 int id_reserva;
//                 printf("Ingrese ID de la reserva a cancelar: ");
//                 scanf("%d", &id_reserva);
//                 getchar();
                
//                 cancelar_reserva(id_reserva);
//                 printf("Reserva cancelada con exito.\n");
//                 break;
//             }
//             case 5:
//                 printf("Saliendo del programa...\n");
//                 break;
//             default:
//                 printf("Opción no válida. Intente de nuevo.\n");
//         }
//     }
//     return 0;
// }

// // Funciones de gestión de reservas
// void guardar_reserva(int num_personas, int tipo_menu, char* fecha, char* hora) {
//     if (total_reservas < MAX_RESERVAS) {
//         reservas[total_reservas].id_reserva = total_reservas + 1;
//         reservas[total_reservas].numero_personas = num_personas;
//         reservas[total_reservas].tipo_menu = tipo_menu;
//         strcpy(reservas[total_reservas].fecha, fecha);
//         strcpy(reservas[total_reservas].hora, hora);
//         reservas[total_reservas].activa = 1;
//         total_reservas++;
//     } else {
//         printf("No hay espacio para más reservas.\n");
//     }
// }

// void mostrar_reservas() {
//     printf("\n=== MIS RESERVAS ===\n");
//     for (int i = 0; i < total_reservas; i++) {
//         if (reservas[i].activa) {
//             printf("ID: %d\n", reservas[i].id_reserva);
//             printf("Numero de personas: %d\n", reservas[i].numero_personas);
//             printf("Tipo de menu: %d (%s)\n", reservas[i].tipo_menu,
//                    reservas[i].tipo_menu == 1 ? "Normal" :
//                    reservas[i].tipo_menu == 2 ? "Vegetariano" : "Especial");
//             printf("Fecha: %s\n", reservas[i].fecha);
//             printf("Hora: %s\n\n", reservas[i].hora);
//         }
//     }
// }

// void modificar_reserva(int id, char* nueva_fecha, char* nueva_hora, int nuevo_num_personas, int nuevo_tipo_menu) {
//     for (int i = 0; i < total_reservas; i++) {
//         if (reservas[i].id_reserva == id && reservas[i].activa) {
//             strcpy(reservas[i].fecha, nueva_fecha);
//             strcpy(reservas[i].hora, nueva_hora);
//             reservas[i].numero_personas = nuevo_num_personas;
//             reservas[i].tipo_menu = nuevo_tipo_menu;
//             return;
//         }
//     }
//     printf("Reserva no encontrada o ya cancelada.\n");
// }

// void cancelar_reserva(int id) {
//     for (int i = 0; i < total_reservas; i++) {
//         if (reservas[i].id_reserva == id && reservas[i].activa) {
//             reservas[i].activa = 0;
//             return;
//         }
//     }
//     printf("Reserva no encontrada o ya cancelada.\n");
// }