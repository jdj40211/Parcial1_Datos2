// generador.cpp
#include "generador.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Persona.h"

char generarSexoAleatorio() {
    // Generar aleatoriamente 'H' para hombre o 'M' para mujer
    return (rand() % 2 == 0) ? 'H' : 'M';
}

std::string obtenerNombreAleatorio(const std::string& archivo) {
    std::ifstream archivoNombres(archivo);
    std::vector<std::string> nombres;
    if (archivoNombres.is_open()) {
        std::string nombre;
        while (getline(archivoNombres, nombre)) {
            nombres.push_back(nombre);
        }
        archivoNombres.close();
    }
    if (!nombres.empty()) {
        int indiceAleatorio = rand() % nombres.size();
        return nombres[indiceAleatorio];
    }
    return "SinNombre";
}

std::string generarNombreCompleto(char sexo) {
    //char sexo = generarSexoAleatorio();
    std::string nombre;
    std::string nombresHombres = (sexo == 'H') ? obtenerNombreAleatorio("./datos/nombres_hombres.txt") : "";
    std::string nombresMujeres = (sexo == 'M') ? obtenerNombreAleatorio("./datos/nombres_mujeres.txt") : "";
    
    // Elegir aleatoriamente entre nombres de hombres y mujeres
    if (sexo == 'H') {
        nombre = nombresHombres;
    } else if (sexo == 'M') {
        nombre = nombresMujeres;
    }

    std::string apellido1 = obtenerNombreAleatorio("./datos/apellidos.txt");
    std::string apellido2 = obtenerNombreAleatorio("./datos/apellidos.txt");

    return nombre + " " + apellido1 + " " + apellido2;
}


double generarEdad() {
    // Generar una edad aleatorio entre 18 y 100 años
    return 18 + static_cast<double>(rand()) / RAND_MAX * (100 - 18);
}


Persona generarPersona() {

    char sexo = generarSexoAleatorio();
    std::string nombreCompleto = generarNombreCompleto(sexo);
    
    int edad = generarEdad();
    
    return Persona(nombreCompleto, edad);

}

