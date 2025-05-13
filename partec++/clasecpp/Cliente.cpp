
#include "../clases/Cliente.h"

using namespace std;

Cliente::Cliente() : id(0), nombre(""), telefono("") {}

Cliente::Cliente(int id, const string& nombre, const string& telefono)
    : id(id), nombre(nombre), telefono(telefono) {}

int Cliente::getId() const { return id; }
string Cliente::getNombre() const { return nombre; }
string Cliente::getTelefono() const { return telefono; }

void Cliente::setId(int id) { this->id = id; }
void Cliente::setNombre(const string& nombre) { this->nombre = nombre; }
void Cliente::setTelefono(const string& telefono) { this->telefono = telefono; }
