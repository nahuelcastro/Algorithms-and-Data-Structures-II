#ifndef AED2_SIMCITY_H
#define AED2_SIMCITY_H

#include <iostream>
#include <set>

#include "aed2_Mapa.h"
#include "simCity.h"
using namespace std;

using Nat = unsigned int;


using SimCity = SimCity;

class aed2_SimCity {
public:

    // Generadores:
    aed2_SimCity(aed2_Mapa m);

    // Precondicion: Se puede construir en la Casilla c
    void agregarCasa(Casilla c);

    // Precondicion: Se puede construir en la Casilla c
    void agregarComercio(Casilla c);

    // Precondicion: Hubo construccion en el turno actual
    void avanzarTurno();

    // Precondicion: No se solapan las construcciones con los rios
    void unir(aed2_SimCity sc);

    // Observadores:
    Mapa mapa() const;
    set<Casilla> casas() const;
    set<Casilla> comercios() const;

    // Precondicion: Hay construccion en la Casilla p

    Nat nivel(Casilla c) const;
    bool huboConstruccion() const;
    Nat popularidad() const;
    Nat antiguedad() const;


    // Conversiones
    
    // Esta función sirve para convertir del SimCity de la cátedra al SimCity
    // implementado por ustedes
     SimCity simCity();

private:

    SimCity _simCity;


};

#endif // AED2_SIMCITY_H
