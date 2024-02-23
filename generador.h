#ifndef GENERADOR_H
#define GENERADOR_H

#include <string>
#include <random>
#include "Persona.h"

char generarSexoAleatorio();
std::string obtenerNombreAleatorio(const std::string& archivo);
std::string generarNombreCompleto(char sexo);
double generarEdad();
Persona generarPersona();

#endif
