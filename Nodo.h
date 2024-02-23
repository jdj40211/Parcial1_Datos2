#ifndef NODO_H
#define NODO_H

#include "Persona.h"

class Nodo {
public:
    Nodo();
    Nodo(const Persona& data);
    ~Nodo();

    void setData(const Persona& data);
    Persona getData() const;

    void setSiguiente(Nodo* siguiente);
    Nodo* getSiguiente() const;

private:
    Persona data_;
    Nodo* siguiente_;
};

#endif
