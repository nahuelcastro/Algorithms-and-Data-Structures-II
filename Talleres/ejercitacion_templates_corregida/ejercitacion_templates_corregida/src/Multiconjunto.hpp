#import "Diccionario.hpp"

#ifndef SOLUCION_MULTICONJUNTO_HPP
#define SOLUCION_MULTICONJUNTO_HPP


template<class T>
class Multiconjunto {

public:
    Multiconjunto();
    void agregar(T t);
    int ocurrencias(T t) const;
    bool operator<=(Multiconjunto<T>) const;


private:
    Diccionario<T, int> dic_;

};

template<class T>
Multiconjunto<T>::Multiconjunto() {};

template<class T>
void Multiconjunto<T>::agregar(T t) {
    if (dic_.def(t)) {
        int val = dic_.obtener(t);
        dic_.definir(t, val + 1);
    } else {
        dic_.definir(t, 1);
    }
}



template<class T>
int Multiconjunto<T>::ocurrencias(T t) const {
    if(dic_.def(t)){
        return dic_.obtener(t);
    }
    return 0;
}

template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) const{
    int size = this->dic_.claves().size();
    for (int i = 0; i < size ; ++i) {
        int elem = this->dic_.claves()[i];
        if (not( this->ocurrencias(elem) <= otro.ocurrencias(elem) )){
            return false;
        }
    }
    return true;
}

// <(,)(,)(,)(,)(,)(,)>

#endif //SOLUCION_MULTICONJUNTO_HPP
