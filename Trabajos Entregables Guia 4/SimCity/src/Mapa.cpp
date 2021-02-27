
#include "Mapa.h"

Mapa::Mapa() {

}

void Mapa::unirMapa(Mapa m2){

    this->_verticales.splice(this->_verticales.end(),m2._verticales);
    this->_horizontales.splice(this->_horizontales.end(),m2._horizontales);

}


void Mapa::agregarRio(Direccion d, int p) {

    if(d == Horizontal){
        this->_horizontales.push_back(p);
    }else{
        this->_verticales.push_back(p);
    }
}


bool Mapa::hayRio(Casilla c) const {

    for (const int n : this->_horizontales) {
        if (c.second == n) {
            return true;
        }
    }
    for (int n : this->_verticales) {
        if (c.first == n) {
            return true;
        }
    }

    return false;

}