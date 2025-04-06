#ifndef CONFIG_H
#define CONFIG_H

#define MAX_LINE_LENGTH 256

typedef struct {
    char db_name[MAX_LINE_LENGTH];
    char welcome_message[MAX_LINE_LENGTH];
    int max_personas;
} Config;

int leer_config(const char *filename, Config *config);
void imprimir_config(const Config *config);

#endif