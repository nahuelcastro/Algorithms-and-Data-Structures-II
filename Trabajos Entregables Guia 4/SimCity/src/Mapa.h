//
// Created by gianluca on 6/7/20.
//

#ifndef TP3_SIMCITY_MAPA_H
#define TP3_SIMCITY_MAPA_H

#include <iostream>
#include "Tipos.h"
#include <list>
#include <vector>


class Mapa {
public:

    // Generadores:

    Mapa();
    void agregarRio(Direccion d, int p);

    // Observadores:
    bool hayRio(Casilla c) const;

    // Otras operaciones:
    void unirMapa(Mapa m2);



private:
    list<int> _verticales;
    list<int> _horizontales;
};



#endif //TP3_SIMCITY_MAPA_H
