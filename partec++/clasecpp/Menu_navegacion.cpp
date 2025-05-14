#include <iostream>
#include "../clases/Menu_navegacion.h"

using namespace std;


void menuPrincipal() {
    int opcion = 0;

    do {
        cout << "\n=== DEUSTORANTE ===" << endl;
        cout << "1. Iniciar como Cliente" << endl;
        cout << "2. Iniciar como Administrador" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuCliente();
                break;
            case 2:
                menuAdministrador();
                break;
            case 3:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }

    } while (opcion != 3);
}

void menuCliente() {
    int opcion = 0;
    do {
        cout << "\n=== MENÚ CLIENTE ===" << endl;
        cout << "1. Ver Menús" << endl;
        cout << "2. Hacer Reserva" << endl;
        cout << "3. Ver Reservas" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Mostrando menús disponibles..." << endl;
                break;
            case 2:
                cout << "Iniciando proceso de reserva..." << endl;
                break;
            case 3:
                cout << "Mostrando tus reservas..." << endl;
                break;
            case 4:
                cout << "Saliendo del menú cliente..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }

    } while (opcion != 4);
}

void menuAdministrador() {
    int opcion = 0;
    do {
        cout << "\n=== MENÚ ADMINISTRADOR ===" << endl;
        cout << "1. Ver todas las reservas" << endl;
        cout << "2. Eliminar reserva" << endl;
        cout << "3. Ver clientes" << endl;
        cout << "4. Ver menús" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Mostrando todas las reservas..." << endl;
                break;
            case 2:
                cout << "Ingrese ID de reserva a eliminar..." << endl;
                break;
            case 3:
                cout << "Mostrando lista de clientes..." << endl;
                break;
            case 4:
                cout << "Mostrando menús del restaurante..." << endl;
                break;
            case 5:
                cout << "Saliendo del menú administrador..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }

    } while (opcion != 5);
}

