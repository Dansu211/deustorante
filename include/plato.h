#ifndef PLATO_H
#define PLATO_H

typedef struct
{
    int id;
    char* nombre;
    char* descripcion;
    float precio;
    int disponible;
} Plato;

Plato* crear_plato(
    int id,
    const char* nombre,
    const char* descripcion,
    float precio,
    int disponible
);

void free_plato(Plato*);

#endif //PLATO_H
