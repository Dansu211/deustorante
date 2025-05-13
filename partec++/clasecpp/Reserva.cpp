
#include "../clases/Reserva.h"

using namespace std;

Reserva::Reserva() 
    : id(0), id_menu(0), id_mesa(0), numero_personas(0) {}

Reserva::Reserva(int id, const string& nombre, const string& tel, int menu, int mesa, int personas, const string& fecha, const string& hora) 
    : id(id), nombre_cliente(nombre), telefono(tel), id_menu(menu), id_mesa(mesa), numero_personas(personas), fecha(fecha), hora(hora) {}

int Reserva::getId() const { return id; }
string Reserva::getNombreCliente() const { return nombre_cliente; }
string Reserva::getTelefono() const { return telefono; }
int Reserva::getIdMenu() const { return id_menu; }
int Reserva::getIdMesa() const { return id_mesa; }
int Reserva::getNumeroPersonas() const { return numero_personas; }
string Reserva::getFecha() const { return fecha; }
string Reserva::getHora() const { return hora; }

void Reserva::setId(int id) { this->id = id; }
void Reserva::setNombreCliente(const string& nombre) { nombre_cliente = nombre; }
void Reserva::setTelefono(const string& tel) { telefono = tel; }
void Reserva::setIdMenu(int menu) { id_menu = menu; }
void Reserva::setIdMesa(int mesa) { id_mesa = mesa; }
void Reserva::setNumeroPersonas(int personas) { numero_personas = personas; }
void Reserva::setFecha(const string& fecha) { this->fecha = fecha; }
void Reserva::setHora(const string& hora) { this->hora = hora; }


Reserva::Reserva() : id(0), id_menu(0), id_mesa(0), numero_personas(0) {}

Reserva::Reserva(int id, const std::string & nombre, const std::string & tel, int menu, int mesa, int personas, const std::string& fecha, const std::string& hora): id(id), nombre_cliente(nombre), telefono(tel), id_menu(menu), id_mesa(mesa), numero_personas(personas), fecha(fecha), hora(hora) {}

int Reserva::getId() const { return id; }
std::string Reserva::getNombreCliente() const { return nombre_cliente; }
std::string Reserva::getTelefono() const { return telefono; }
int Reserva::getIdMenu() const { return id_menu; }
int Reserva::getIdMesa() const { return id_mesa; }
int Reserva::getNumeroPersonas() const { return numero_personas; }
std::string Reserva::getFecha() const { return fecha; }
std::string Reserva::getHora() const { return hora; }

void Reserva::setId(int id) { this->id = id; }
void Reserva::setNombreCliente(const std::string& nombre) { nombre_cliente = nombre; }
void Reserva::setTelefono(const std::string& tel) { telefono = tel; }
void Reserva::setIdMenu(int menu) { id_menu = menu; }
void Reserva::setIdMesa(int mesa) { id_mesa = mesa; }
void Reserva::setNumeroPersonas(int personas) { numero_personas = personas; }
void Reserva::setFecha(const std::string& fecha) { this->fecha = fecha; }
void Reserva::setHora(const std::string& hora) { this->hora = hora; }
