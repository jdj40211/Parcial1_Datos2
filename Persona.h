#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

class Persona {
public:
    Persona();
    Persona(const std::string& nombre, int edad);
    ~Persona();

    void setNombre(const std::string& nombre);
    std::string getNombre() const;

    void setEdad(int edad);
    int getEdad() const;

    void saludar() const;

    // Sobrecarga de operadores de comparación
    bool operator==(const Persona& other) const;
    bool operator!=(const Persona& other) const;
    bool operator<(const Persona& other) const;
    bool operator<=(const Persona& other) const;
    bool operator>(const Persona& other) const;
    bool operator>=(const Persona& other) const;

    // Sobrecarga de operadores lógicos
    bool operator&&(const Persona& other) const;
    bool operator||(const Persona& other) const;

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& os, const Persona& persona);

private:
    std::string nombre_;
    int edad_;
};

#endif
