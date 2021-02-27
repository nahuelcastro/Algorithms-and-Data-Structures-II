#include "aed2_SimCity.h"

aed2_SimCity::aed2_SimCity(aed2_Mapa m) {
    SimCity s(m.mapa());
    _simCity = s;
}
void aed2_SimCity::agregarCasa(Casilla c) {

    _simCity.agregarCasa(c);

}

void aed2_SimCity::agregarComercio(Casilla c) {
  _simCity.agregarComercio(c);
}

set<Casilla> aed2_SimCity::comercios() const {
    return _simCity.comercios();
}


set<Casilla> aed2_SimCity::casas() const {
    return _simCity.casas();
}


void aed2_SimCity::unir(aed2_SimCity sc) {

    _simCity.unir(sc.simCity());


}

void aed2_SimCity::avanzarTurno() {
    _simCity.avanzarTurno();}



Nat aed2_SimCity::antiguedad() const {
    return _simCity.antiguedad();
}



Nat aed2_SimCity::nivel(Casilla c) const {
    return _simCity.nivel(c);
}



Nat aed2_SimCity::popularidad() const {
    return _simCity.popularidad();
}

bool aed2_SimCity::huboConstruccion() const {
    return _simCity.huboConstruccion();
}

Mapa aed2_SimCity::mapa() const {
    return _simCity.mapa();
}

SimCity aed2_SimCity::simCity() {
    return _simCity;
}
