#ifndef MESA_H
#define MESA_H

#include <string>

class Mesa {
private:
    int id;
    int numero;
    int capacidad;

public:
    Mesa();
    Mesa(int id, int numero, int capacidad);

    // Getters
    int getId() const;
    int getNumero() const;
    int getCapacidad() const;

    // Setters
    void setId(int id);
    void setNumero(int numero);
    void setCapacidad(int capacidad);
};

#endif
