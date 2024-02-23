#include <iostream>
#include "Persona.h"
#include "generador.h"


Persona crearPersonaPorTeclado() {
    std::string nombre;
    int edad;

    std::cout << "Ingrese el nombre: ";
    std::cin >> nombre;

    std::cout << "Ingrese la edad: ";
    std::cin >> edad;

    return Persona(nombre, edad);
}

int main() {
    //Persona persona1("Juan", 25);
    Persona persona2 = crearPersonaPorTeclado();
    Persona persona1 = generarPersona();

    // Comparación de objetos
    if (persona1 == persona2) {
        std::cout << "Las personas son iguales." << std::endl;
    } else {
        std::cout << "Las personas son diferentes." << std::endl;
    }

    // Operadores lógicos
    if (persona1 && persona2) {
        std::cout << "Ambas personas tienen nombre." << std::endl;
    }

    // Impresión de un objeto
    std::cout << persona1 << std::endl;

    return 0;
}

