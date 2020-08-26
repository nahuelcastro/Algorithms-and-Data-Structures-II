//
// Created by nahuel on 3/6/20.
//

#ifndef SOLUCION_TEMPLATES_HPP
#define SOLUCION_TEMPLATES_HPP

//// Ejercicio 1: Pasar a templates
template <class T >
T cuadrado (T t){
    return t * t;
}

//// Ejercicio 2: Pasar a templates
template<class Contenedor, class Elem >
bool contiene(Contenedor s, Elem c){
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

// Ej 3

template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b) {
    if (a.size() >= b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

// Ej 4:

template< class Contenedor, class Elem >
Elem maximo(Contenedor c){
    Elem candidate = c[0];
    for (int i = 0 ; i < c.size() ; ++i) {
        if(candidate < c[i]){
            candidate = c[i];
        }
    }
    return candidate;
}















#endif //SOLUCION_TEMPLATES_HPP
