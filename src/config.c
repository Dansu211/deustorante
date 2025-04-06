#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/config.h"

int leer_config(const char *filename, Config *config) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "No se pudo abrir el archivo de configuración: %s\n", filename);
        // Valores por defecto si el archivo no se encuentra
        strcpy(config->db_name, "deustorante.db");
        strcpy(config->welcome_message, "Bienvenido a Deustorante");
        config->max_personas = 50;
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Eliminar salto de línea
        line[strcspn(line, "\n")] = 0;

        // Ignorar líneas vacías o comentarios
        if (strlen(line) == 0 || line[0] == '#') {
            continue;
        }

        // Separar clave y valor
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");
        if (key && value) {
            if (strcmp(key, "DB_NAME") == 0) {
                strncpy(config->db_name, value, MAX_LINE_LENGTH - 1);
                config->db_name[MAX_LINE_LENGTH - 1] = '\0';
            } else if (strcmp(key, "WELCOME_MESSAGE") == 0) {
                strncpy(config->welcome_message, value, MAX_LINE_LENGTH - 1);
                config->welcome_message[MAX_LINE_LENGTH - 1] = '\0';
            } else if (strcmp(key, "MAX_PERSONAS") == 0) {
                config->max_personas = atoi(value);
            }
        }
    }

    fclose(file);
    return 0;
}

void imprimir_config(const Config *config) {
    printf("Configuración cargada:\n");
    printf("  Nombre de la base de datos: %s\n", config->db_name);
    printf("  Mensaje de bienvenida: %s\n", config->welcome_message);
    printf("  Máximo de personas por reserva: %d\n", config->max_personas);
}