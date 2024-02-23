#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include "Nodo.h"

class ListaLigada {
public:
    ListaLigada();
    ~ListaLigada();

    bool adicionar(const Persona& data);
    bool eliminar(const Persona& data);
    int tamanio() const;
    void listar() const;

    bool buscar(const Persona& data) const;
    Nodo* buscarNodo(const Persona& data) const;
    Nodo* obtenerNodo(int indice) const;
    int buscarIndice(const Persona& data) const;

    void intercambiarNodos(Nodo* nodo1, Nodo* nodo2);
    ListaLigada* sublista(int indiceInicio, int indiceFin);

    Nodo* obtenerPrimerNodo() const;

    //Bubble Sort
    void ordenarBurbuja(const ListaLigada& lista);


    //Merge Sort
    void ordenarMergeSort(Nodo* &lista);
    Nodo* dividirLista(Nodo* cabeza);
    Nodo* mergeListas(Nodo* primeraMitad, Nodo* segundaMitad);


    //Quick Sort
    void ordenarQuickSort(Nodo* &cabeza);
    Nodo* partirLista(Nodo* cabeza);



private:
    Nodo* primerNodo_;
    Nodo* ultimoNodo_;
    int tamanio_;
};

#endif
