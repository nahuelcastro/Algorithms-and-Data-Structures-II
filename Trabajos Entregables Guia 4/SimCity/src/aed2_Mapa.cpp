#include "aed2_Mapa.h"

aed2_Mapa::aed2_Mapa() {

}

void aed2_Mapa::unirMapa(aed2_Mapa m2){

    _mapa.unirMapa(m2.mapa());

}


void aed2_Mapa::agregarRio(Direccion d, int p) {

   _mapa.agregarRio(d,p);
}


bool aed2_Mapa::hayRio(Casilla c) const {

    return _mapa.hayRio(c);
}

aed2_Mapa::aed2_Mapa(Mapa m) {
    _mapa = m;

}

Mapa aed2_Mapa::mapa() {
    return _mapa;
}
