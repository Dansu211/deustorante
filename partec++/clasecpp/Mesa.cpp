#include "../clases/Mesa.h"

using namespace std;

Mesa::Mesa() : id(0), numero(0), capacidad(0) {}

Mesa::Mesa(int id, int numero, int capacidad)
    : id(id), numero(numero), capacidad(capacidad) {}

// Getters
int Mesa::getId() const { return id; }
int Mesa::getNumero() const { return numero; }
int Mesa::getCapacidad() const { return capacidad; }

// Setters
void Mesa::setId(int id) { this->id = id; }
void Mesa::setNumero(int numero) { this->numero = numero; }
void Mesa::setCapacidad(int capacidad) { this->capacidad = capacidad; }
