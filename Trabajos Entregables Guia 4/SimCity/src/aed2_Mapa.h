#ifndef AED2_MAPA_H
#define AED2_MAPA_H

#include <iostream>
#include "Tipos.h"
#include <list>
#include <vector>
#include "Mapa.h"
using namespace std;
using Nat = unsigned int;

class aed2_Mapa {
public:

    // Generadores:
    aed2_Mapa();
    void agregarRio(Direccion d, int p);

    // Observadores:
    bool hayRio(Casilla c) const;

    // Otras operaciones:
    void unirMapa(aed2_Mapa m2);

    // Conversiones
    
    // Esta función sirve para convertir del Mapa implementado por ustedes
    // a la clase Mapa de la cátedra
    aed2_Mapa(Mapa m);

    // Esta función sirve para convertir del Mapa de la cátedra (aed2_Mapa)
    // a la clase Mapa definida por ustedes
    Mapa mapa();

private:
    Mapa _mapa;
};


#endif // AED2_MAPA_H
