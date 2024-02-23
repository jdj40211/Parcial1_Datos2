#include "Nodo.h"

Nodo::Nodo() {
    siguiente_ = nullptr;
}

Nodo::Nodo(const Persona& data) {
    data_ = data;
    siguiente_ = nullptr;
}

Nodo::~Nodo() {}

void Nodo::setData(const Persona& data) {
    data_ = data;
}

Persona Nodo::getData() const {
    return data_;
}

void Nodo::setSiguiente(Nodo* siguiente) {
    siguiente_ = siguiente;
}

Nodo* Nodo::getSiguiente() const {
    return siguiente_;
}
