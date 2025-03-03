#include <stdio.h>
#include <string.h>
#include "interfaz.h"



void menulogin();
void menuadmin();

void menulogin() {
    char usuario[50];
    char contrasena[50];

    printf("Nombre de usuario: ");
    scanf("%49s", usuario); 

    printf("Contraseña: ");
    scanf("%49s", contrasena);

    if (strcmp(usuario, "admin") == 0 && strcmp(contrasena, "admin123") == 0) {
        menuadmin();
    } else {
        printf("Credenciales incorrectas.\n");
    }
}

void menuadmin() {
    int opcion;

    do {
        printf("\n----- Menú de Administrador -----\n");
        printf("1. Ver usuarios\n");
        printf("2. Anadir usuario\n");
        printf("3. Eliminar usuario\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Opcion seleccionada: Ver usuarios.\n");
                break;
            case 2:
                printf("Opcion seleccionada: Anadir usuario.\n");
                break;
            case 3:
                printf("Opcion seleccionada: Eliminar usuario.\n");
                break;
            case 4:
                printf("Saliendo del menú de administrador...\n");
                break;
            default:
                printf("Opción no valida. Intente de nuevo.\n");
        }
    } while(opcion != 4);
}

int main(void) {
    menulogin();
    return 0;   
}
