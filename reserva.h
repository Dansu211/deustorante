#ifndef RESERVA_H
#define RESERVA_H

typedef struct {
    int id_reserva;
    int numero_personas;
    int tipo_menu; // 1: Normal, 2: Vegetariano, 3: Especial
    char fecha[11]; // Formato dd/mm/aaaa
    char hora[6];   // Formato hh:mm
} Reserva;

#endif