#include "Persona.h"

Persona::Persona() {
    nombre_ = "";
    edad_ = 0;
}

Persona::Persona(const std::string& nombre, int edad) {
    nombre_ = nombre;
    edad_ = edad;
}

Persona::~Persona() {}

void Persona::setNombre(const std::string& nombre) {
    nombre_ = nombre;
}

std::string Persona::getNombre() const {
    return nombre_;
}

void Persona::setEdad(int edad) {
    edad_ = edad;
}

int Persona::getEdad() const {
    return edad_;
}


// Sobrecarga de operadores de comparación
bool Persona::operator==(const Persona& other) const {
    return nombre_ == other.nombre_ && edad_ == other.edad_;
}

bool Persona::operator!=(const Persona& other) const {
    return !(*this == other);
}

bool Persona::operator<(const Persona& other) const {
    return nombre_ < other.nombre_ || (nombre_ == other.nombre_ && edad_ < other.edad_);
}

bool Persona::operator<=(const Persona& other) const {
    return *this < other || *this == other;
}

bool Persona::operator>(const Persona& other) const {
    return other < *this;
}

bool Persona::operator>=(const Persona& other) const {
    return *this > other || *this == other;
}

// Sobrecarga de operadores lógicos
bool Persona::operator&&(const Persona& other) const {
    return nombre_ != "" && other.nombre_ != "";
}

bool Persona::operator||(const Persona& other) const {
    return nombre_ != "" || other.nombre_ != "";
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& os, const Persona& persona) {
    os << "(" << persona.nombre_ << ")- " << persona.edad_ << " años." << std::endl;
    return os;
}