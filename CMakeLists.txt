cmake_minimum_required(VERSION 3.27)
project(AlgoritmosOrdenamiento)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AlgoritmosOrdenamiento
        Ejemplo_lista.cpp
        Ejemplo_objeto.cpp
        generador.cpp
        generador.h
        ListaLigada.cpp
        ListaLigada.h
        Nodo.cpp
        Nodo.h
        Persona.cpp
        Persona.h
)
