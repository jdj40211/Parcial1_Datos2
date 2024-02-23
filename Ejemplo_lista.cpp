#include <iostream>
#include <string>
#include "Persona.h"
#include "ListaLigada.h"
#include "generador.h"

int main() {
    // Crear una lista ligada
    ListaLigada lista;

    int tamanio;

    // Solicitar al usuario que ingrese el valor
    std::cout << "Ingrese el valor para el tamaño del bucle: ";
    std::cin >> tamanio;

    //Validar que el valor sea mayor a 0
    if (tamanio <= 0){
        std::cout << "El valor ingresado no es valido" << std::endl;
        return 1; // Salir del programa
    }

    // Agregar algunos nodos random a la lista
    for (int i=0; i < tamanio; ++i){
        lista.adicionar(generarPersona());
    }


    // Mostrar el tamaño de la lista
    std::cout << "Tamaño de la lista: " << lista.tamanio() << std::endl;
    lista.listar();
    std::cout << "===================" << std::endl;

    // Obtener apuntador por indice
    std::cout << "Obtener Nodo[0]" << std::endl;
    Nodo* nodo_i = lista.obtenerNodo(0);
    std::cout << "Nodo[0] : "<< nodo_i << " -> " << nodo_i->getData();
    std::cout << "===================" << std::endl;

    // Obtener apuntador por indice
    std::cout << "Obtener Nodo[final]" << std::endl;
    nodo_i = lista.obtenerNodo(lista.tamanio()-1);
    std::cout << "Nodo[final] : "<< nodo_i << " -> " << nodo_i->getData();
    std::cout << "===================" << std::endl;

    // Obtener sublista: cabeza has indice
    std::cout << "SubLista: cabeza hasta mitad " << std::endl;
    ListaLigada* sublistaBaja = lista.sublista(0, lista.tamanio()/2);
    std::cout << "    Tamaño de la sublista: " << std::to_string(sublistaBaja->tamanio()) << std::endl;
    sublistaBaja->listar();
    std::cout << "===================" << std::endl;

    // Obtener sublista: inidice hasta cola
    std::cout << "SubLista: mita hasta cola " << std::endl;
    ListaLigada* sublistaAlta = lista.sublista(lista.tamanio()/2, lista.tamanio()-1);
    std::cout << "     Tamaño de la sublista: " << std::to_string(sublistaAlta->tamanio()) << std::endl;
    sublistaAlta->listar();
    std::cout << "===================" << std::endl;

    // Ordenar por BubbleSort
    std::cout << "Ordenar por BubbleSort" << std::endl;
    lista.ordenarBurbuja(lista);
    lista.listar();
    std::cout << "===================" << std::endl;


    // Ordenar por MergeSort
    std::cout << "Ordenar por MergeSort" << std::endl;
    Nodo* primerNodoMergeSort = lista.obtenerPrimerNodo();
    lista.ordenarMergeSort(primerNodoMergeSort);
    lista.listar();
    std::cout << "===================" << std::endl;







    return 0;
}
