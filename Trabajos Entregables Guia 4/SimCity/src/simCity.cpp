//
// Created by gianluca on 6/7/20.
//

#include "simCity.h"

SimCity::SimCity(Mapa m) {
    _popularidad = 0;
    _antiguedad = 0;
    _seConstruyo = false;
    _mapa = m;

}
void SimCity::agregarCasa(Casilla c) {

    Construccion construccion (c,"Casa");
    this->_construcciones.emplace_back(construccion);
    this->_seConstruyo=true;

}

void SimCity::agregarComercio(Casilla c) {
    Construccion construccion (c, "Comercio") ;
    this->_construcciones.push_back(construccion);
    this->_seConstruyo=true;
}

set<Casilla> SimCity::comercios() const {
    set<Casilla> comercios;
    set<Casilla> casas = this->casas();
    for (Construccion c: this->_construcciones) {
        if (!casas.count(c.posicion)) {//Lo negué
            comercios.insert(c.posicion);
        }
    }
    return comercios;
}


set<Casilla> SimCity::casas() const {
    set<Casilla> casas;
    for (Construccion c : this->_construcciones) {
        if(c.tipo == "Casa"){
            casas.insert(c.posicion);
        }
    }
    return casas;
}


void SimCity::unir(SimCity sc) {

    this->_popularidad = this->_popularidad + sc._popularidad + 1;
    this->_antiguedad = max(this->antiguedad(), sc.antiguedad());
    this->_seConstruyo = this->_seConstruyo || sc._seConstruyo;


    this->_mapa.unirMapa(sc._mapa);
    this->_construcciones.splice(this->_construcciones.end(),sc._construcciones);


}

void SimCity::avanzarTurno() {
    for( auto it = _construcciones.begin(); it != _construcciones.end(); ++it ){
        it->antiguedad++;
    }
    this->_antiguedad++;
    this->_seConstruyo = false;
}



Nat SimCity::antiguedad() const {
    return this->_antiguedad;
}

Nat SimCity::distManhattan(const Casilla c1, const Casilla c2) const {
    return abs(c1.first - c2.first) + abs(c1.second - c2.second);
}


Nat SimCity::nivel(Casilla c) const {
    bool esCasa = false;
    bool hayQueVerManhattan = false;
    Nat resCasa = 0;
    Nat resComercio = 0;
    Nat maxManhattan = 0;

    for (const Construccion cons : this->_construcciones) {
        if (cons.posicion == c) {
            if (cons.tipo == "Casa") {
                esCasa = true;
                resCasa = max(cons.antiguedad, resCasa);
            } else {
                resComercio = max(cons.antiguedad, resComercio);
            }
        }
    }

    if (!esCasa) {
        hayQueVerManhattan = true;
    }

    if (hayQueVerManhattan) {
        for (const Construccion cons : this->_construcciones) {
            if (cons.tipo == "Casa" && distManhattan(c, cons.posicion) <= 3) {
                maxManhattan = max(maxManhattan, cons.antiguedad);
            }
        }
        return max(maxManhattan,resComercio);
    }

    return resCasa;
}


Nat SimCity::popularidad() const {
    return this->_popularidad;
}

bool SimCity::huboConstruccion() const {
    return _seConstruyo;
}

Mapa SimCity::mapa() const {
    return _mapa;
}

SimCity::SimCity() {

}
