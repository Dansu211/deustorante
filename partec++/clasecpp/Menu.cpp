#include "../clases/Menu.h"

using namespace std;

Menu::Menu() : id(0), precio(0.0) {}

Menu::Menu(int id, const string& nombre, const string& descripcion, double precio)
    : id(id), nombre(nombre), descripcion(descripcion), precio(precio) {}

// Getters
int Menu::getId() const { return id; }
string Menu::getNombre() const { return nombre; }
string Menu::getDescripcion() const { return descripcion; }
double Menu::getPrecio() const { return precio; }

// Setters
void Menu::setId(int id) { this->id = id; }
void Menu::setNombre(const string& nombre) { this->nombre = nombre; }
void Menu::setDescripcion(const string& descripcion) { this->descripcion = descripcion; }
void Menu::setPrecio(double precio) { this->precio = precio; }
