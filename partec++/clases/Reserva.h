
#ifndef RESERVA_H
#define RESERVA_H

#include <string>

class Reserva {
private:
    int id;
    std::string nombre_cliente;
    std::string telefono;
    int id_menu;
    int id_mesa;
    int numero_personas;
    std::string fecha;
    std::string hora;

public:
    Reserva();
    Reserva(int id, const std::string& nombre, const std::string& tel, int menu, int mesa,
            int personas, const std::string& fecha, const std::string& hora);

    // Getters
    int getId() const;
    std::string getNombreCliente() const;
    std::string getTelefono() const;
    int getIdMenu() const;
    int getIdMesa() const;
    int getNumeroPersonas() const;
    std::string getFecha() const;
    std::string getHora() const;

    // Setters
    void setId(int id);
    void setNombreCliente(const std::string& nombre);
    void setTelefono(const std::string& tel);
    void setIdMenu(int menu);
    void setIdMesa(int mesa);
    void setNumeroPersonas(int personas);
    void setFecha(const std::string& fecha);
    void setHora(const std::string& hora);
};

#endif
