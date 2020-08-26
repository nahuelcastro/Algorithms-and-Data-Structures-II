#include "Lista.h"


Lista::Lista() {
    _primero = new Nodo;
    _ultimo = new Nodo;

    _primero->siguiente = _ultimo; //?
    _primero->anterior = nullptr;
    _primero->valor = 0;

    _ultimo->anterior = _primero; //?
    _ultimo->siguiente = nullptr;
    _ultimo->valor = 0;

    longitud_ = 0;
}

Lista::Lista(const Lista &l) : Lista() {

    *this = l;
}

Lista::~Lista() {
    while (_primero->siguiente != _ultimo) {
        eliminar(0);
    }
    delete _primero;
    delete _ultimo;

}


Lista &Lista::operator=(const Lista &aCopiar) {
    int len_original = this->longitud_;
    for (int i = 0; i < len_original; i++) {
        this->eliminar(0);
    }

    this->_primero->anterior = nullptr;
    this->_primero->siguiente = this->_ultimo;
    this->_primero->valor = 0;

    this->_ultimo->anterior = this->_primero;
    this->_ultimo->siguiente = nullptr;
    this->_ultimo->valor = 0;

    for (int i = 0; i < aCopiar.longitud(); i++) {
        this->agregarAtras(aCopiar.iesimo(i));
    }

    return *this;
}


void Lista::agregarAdelante(const int &elem) {
    Nodo *nodo = new Nodo;
    nodo->valor = elem;

    nodo->siguiente = _primero->siguiente;
    _primero->siguiente->anterior = nodo;
    nodo->anterior = _primero;
    _primero->siguiente = nodo;

    longitud_++;

}

void Lista::agregarAtras(const int &elem) {
    Nodo *nodo = new Nodo;
    nodo->valor = elem;

    nodo->siguiente = _ultimo;
    nodo->anterior = _ultimo->anterior;
    _ultimo->anterior->siguiente = nodo;
    _ultimo->anterior = nodo;

    longitud_++;
}

void Lista::eliminar(Nat i) {
    Nodo *nodo = _primero;

    for (int j = 0; j <= i; j++) {
        nodo = nodo->siguiente;
    }

    nodo->anterior->siguiente = nodo->siguiente;
    nodo->siguiente->anterior = nodo->anterior;

    delete nodo;
    longitud_--;
}

int Lista::longitud() const {
    return longitud_;
}

const int &Lista::iesimo(Nat i) const {
    Nodo *nodo = _primero;

    for (int j = 0; j <= i; j++) {
        nodo = nodo->siguiente;
    }

    return nodo->valor;
}

int &Lista::iesimo(Nat i) {
    Nodo *nodo = _primero;

    for (int j = 0; j <= i; j++) {
        nodo = nodo->siguiente;
    }

    return nodo->valor;
}

void Lista::mostrar(ostream &o) {  // tendria que probar no se como que esto ande

    o << "[";

    for (int i = 0; i < longitud_; i++) {
        if (i == 0) {
            o << iesimo(i);
        } else {
            o << "," << iesimo(i);
        }
    }

    o << "]";

}

//int main(){ // para probar rapidamente el mostrar
//    Lista l;
//
//    l.agregarAtras(1);
//    l.agregarAtras(2);
//    l.agregarAtras(3);
//
//    l.eliminar(1);
//    l.agregarAdelante(0);
//
//    cout << l;
//
//    return 0;
//}

// Matias Nahuel Castro Russo, 203/19
