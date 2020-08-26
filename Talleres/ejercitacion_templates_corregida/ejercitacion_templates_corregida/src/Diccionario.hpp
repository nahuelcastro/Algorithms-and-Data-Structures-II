//
// Created by nahuel on 3/6/20.
//

#ifndef SOLUCION_DICCIONARIO_HPP
#define SOLUCION_DICCIONARIO_HPP

using namespace std;

template<class Clave, class Valor>
class Diccionario {
public:
    Diccionario();

    void definir(Clave k, Valor v);

    bool def(Clave k) const;

    Valor obtener(Clave k) const;

    vector<Clave> claves() const;

private:
    struct Asociacion {
        Asociacion(Clave k, Valor v);

        Clave clave;
        Valor valor;
    };

    vector<Asociacion> _asociaciones;

    int getMin(vector<Clave> v);
};


template<class Clave, class Valor>
Diccionario<Clave, Valor>::Diccionario() {
}

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {}

template<class Clave, class Valor>
void Diccionario<Clave, Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template<class Clave, class Valor>
bool Diccionario<Clave, Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template<class Clave, class Valor>
Valor Diccionario<Clave, Valor>::obtener(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    assert(false);
}

template<class Clave, class Valor>
vector<Clave> Diccionario<Clave, Valor>::claves() const {
    vector<Clave> res_desordenado;
    vector<Clave> res_ordenado;
    for (int i = 0; i < _asociaciones.size(); ++i) {
        res_desordenado.push_back(_asociaciones[i].clave);
    }
    int sizeDesordenado = res_desordenado.size();
    for (int i = 0; i < sizeDesordenado ; ++i) {

        int cand = res_desordenado[0];
        for (int i = 0; i < res_desordenado.size(); ++i) {
            if (res_desordenado[i] < cand) {
                cand = res_desordenado[i];
            }
        }

        int posMin = cand;
        int size = res_desordenado.size();

        res_ordenado.push_back(res_desordenado[posMin]);
        Clave lastElement = res_desordenado[size - 1];

        res_desordenado[size - 1] = res_desordenado[posMin];
        res_desordenado[posMin] = lastElement;
        res_desordenado.pop_back();
    }

    return res_ordenado;
}

//template<class Clave, class Valor>
//int Diccionario<Clave, Valor>::getMin(vector<Clave> v) {
//    int cand = v[0];
//    for (int i = 0; i < v.size(); ++i) {
//        if (cand < v[i]) {
//            cand = v[i];
//        }
//    }
//    return cand;
//}



#endif //SOLUCION_DICCIONARIO_HPP
