#include "ListaLigada.h"

ListaLigada::ListaLigada() {
    primerNodo_ = nullptr;
    ultimoNodo_ = nullptr;
    tamanio_ = 0;
}

ListaLigada::~ListaLigada() {
    while (primerNodo_ != nullptr) {
        Nodo* siguiente = primerNodo_->getSiguiente();
        delete primerNodo_;
        primerNodo_ = siguiente;
    }
    tamanio_ = 0;
}

bool ListaLigada::adicionar(const Persona& data) {
    Nodo* nuevoNodo = new Nodo(data);
    if (nuevoNodo == nullptr) {
        return false;
    }

    if (primerNodo_ == nullptr) {
        primerNodo_ = ultimoNodo_ = nuevoNodo;
    } else {
        ultimoNodo_->setSiguiente(nuevoNodo);
        ultimoNodo_ = nuevoNodo;
    }

    tamanio_++;
    return true;
}

bool ListaLigada::eliminar(const Persona& data) {
    Nodo* actual = primerNodo_;
    Nodo* anterior = nullptr;

    while (actual != nullptr && actual->getData() != data) {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    if (actual == nullptr) {
        return false;
    }

    if (actual == primerNodo_) {
        primerNodo_ = actual->getSiguiente();
    } else {
        anterior->setSiguiente(actual->getSiguiente());
    }

    if (actual == ultimoNodo_) {
        ultimoNodo_ = anterior;
    }

    delete actual;
    tamanio_--;
    return true;
}

bool ListaLigada::buscar(const Persona& data) const {
    Nodo* actual = primerNodo_;

    while (actual != nullptr && actual->getData() != data) {
        actual = actual->getSiguiente();
    }

    return actual != nullptr;
}


int ListaLigada::tamanio() const {
    return tamanio_;
}


ListaLigada* ListaLigada::sublista(int indiceInicio, int indiceFin) {
    if (indiceInicio < 0 || indiceInicio >= tamanio_ || indiceFin < 0 || indiceFin >= tamanio_ || indiceInicio > indiceFin) {
        std::cout << "....Fuera de rangos" << std::endl;
        return new ListaLigada();
    }

    ListaLigada* sublista = new ListaLigada();
    Nodo* actual = obtenerNodo(indiceInicio);
    
    while (indiceInicio <= indiceFin) {
        sublista->adicionar(actual->getData());
        actual = actual->getSiguiente();
        indiceInicio++;
    }

    return sublista;
}

Nodo* ListaLigada::obtenerNodo(int indice) const {
    if (indice < 0 || indice >= this->tamanio_) {
        return nullptr;
    }

    Nodo* actual = primerNodo_;

    for (int i = 0; i < indice; i++) {
        actual = actual->getSiguiente();
    }

    return actual;
}

void ListaLigada::listar() const{
    Nodo* actual = primerNodo_;
    int indice = 0;

    if (actual == nullptr){
        std::cout << "Lista Vacia!!" << std::endl;
    } else {
        std::cout << "Ver Lista:" << std::endl;
        while (actual != nullptr) {
            std::cout << "  [" << std::to_string(indice) <<"] : "<< actual << " -> " << actual->getData();
            actual = actual->getSiguiente();
            indice = indice+1;
        }
        std::cout << "... No hay más elementos." << std::endl;
    }
}

Nodo* ListaLigada::obtenerPrimerNodo() const {
    return primerNodo_;
}

void ListaLigada::ordenarBurbuja(const ListaLigada &lista){
    ListaLigada listaOrdenada = lista;
    Nodo* actual = listaOrdenada.primerNodo_;
    while(actual != nullptr) {
        Nodo* siguiente = actual->getSiguiente();
        while (siguiente != nullptr) {
            if (actual->getData().getEdad() > siguiente->getData().getEdad()) {
                Persona temp = actual->getData();
                actual->setData(siguiente->getData());
                siguiente->setData(temp);
            }
            siguiente = siguiente->getSiguiente();
        }
        actual = actual->getSiguiente();
    }
}

void ListaLigada::ordenarMergeSort(Nodo*& cabeza) {
    if (cabeza == nullptr || cabeza->getSiguiente() == nullptr) {
        return; // Lista vacía o con un solo elemento, ya está ordenada
    }

    // Dividir la lista en mitades
    Nodo* mitad = dividirLista(cabeza);

    // Aplicar recursivamente Merge Sort a ambas mitades
    ordenarMergeSort(cabeza);
    ordenarMergeSort(mitad);

    // Combinar las dos mitades ordenadas
    cabeza = mergeListas(cabeza, mitad);
}

Nodo* ListaLigada::dividirLista(Nodo* cabeza) {
    Nodo* rapido = cabeza->getSiguiente();
    Nodo* lento = cabeza;

    // Mover rapido dos nodos y lento un nodo
    while (rapido != nullptr) {
        rapido = rapido->getSiguiente();
        if (rapido != nullptr) {
            lento = lento->getSiguiente();
            rapido = rapido->getSiguiente();
        }
    }

    Nodo* mitad = lento->getSiguiente();
    lento->setSiguiente(nullptr); // Separar las dos mitades
    return mitad;
}

Nodo* ListaLigada::mergeListas(Nodo* primeraMitad, Nodo* segundaMitad) {
    Nodo* cabezaNueva = nullptr;
    if (primeraMitad == nullptr) {
        return segundaMitad;
    }
    if (segundaMitad == nullptr) {
        return primeraMitad;
    }

    // Comparar los datos de los nodos para unir las dos listas ordenadas
    if (primeraMitad->getData().getEdad() <= segundaMitad->getData().getEdad()) {
        cabezaNueva = primeraMitad;
        cabezaNueva->setSiguiente(mergeListas(primeraMitad->getSiguiente(), segundaMitad));
    } else {
        cabezaNueva = segundaMitad;
        cabezaNueva->setSiguiente(mergeListas(primeraMitad, segundaMitad->getSiguiente()));
    }
    return cabezaNueva;
}



void ListaLigada::ordenarQuickSort(Nodo* &cabeza) {
    if (cabeza == nullptr || cabeza->getSiguiente() == nullptr) {
        return; // Lista vacía o con un solo elemento, ya está ordenada
    }

    // Dividir la lista en dos partes alrededor de un pivote
    Nodo* pivote = partirLista(cabeza);

    // Aplicar Quick Sort a las sublistas antes y después del pivote
    ordenarQuickSort(cabeza);
    Nodo* siguientePivote = pivote->getSiguiente();
    ordenarQuickSort(siguientePivote);
}

Nodo* ListaLigada::partirLista(Nodo* cabeza) {
    // Tomar el último nodo como pivote
    Nodo* pivote =cabeza;
    while (pivote->getSiguiente() != nullptr) {
        pivote = pivote->getSiguiente();
    }

    // Partir la lista alrededor del pivote
    Nodo* menorAnterior = nullptr;
    Nodo* menor = cabeza;
    Nodo* actual = cabeza;
    while (actual != pivote) {
        if (actual->getData().getEdad() < pivote->getData().getEdad()) {
            if (menor != actual) {
                intercambiarNodos(menor, actual);
            }
            menorAnterior = menor;
            menor = menor->getSiguiente();
        }
        actual = actual->getSiguiente();
    }
    intercambiarNodos(menor, pivote);

    return menorAnterior;
}

void ListaLigada::intercambiarNodos(Nodo* nodo1, Nodo* nodo2) {
    Persona temp = nodo1->getData();
    nodo1->setData(nodo2->getData());
    nodo2->setData(temp);
}



