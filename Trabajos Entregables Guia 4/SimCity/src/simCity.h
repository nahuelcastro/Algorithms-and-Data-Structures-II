#ifndef TP3_SIMCITY_SIMCITY_H
#define TP3_SIMCITY_SIMCITY_H
#include <iostream>
#include <set>

#include "aed2_Mapa.h"

#include "Mapa.h"


class SimCity {
public:

    // Generadores:
    SimCity(Mapa m);

    SimCity();

    // Precondicion: Se puede construir en la Casilla c
    void agregarCasa(Casilla c);

    // Precondicion: Se puede construir en la Casilla c
    void agregarComercio(Casilla c);

    // Precondicion: Hubo construccion en el turno actual
    void avanzarTurno();

    // Precondicion: No se solapan las construcciones con los rios
    //  ni las construcciones de nivel maximo de ambas partidas
    void unir(SimCity sc);

    // Observadores:
    Mapa mapa() const;
    set<Casilla> casas() const;
    set<Casilla> comercios() const;
    Nat distManhattan(const Casilla c1, const Casilla c2) const;

    // Precondicion: Hay construccion en la Casilla p

    Nat nivel(Casilla c) const;
    bool huboConstruccion() const;
    Nat popularidad() const;
    Nat antiguedad() const;




private:

    struct Construccion {
        Casilla posicion;
        string tipo;
        Nat antiguedad;

        Construccion(Casilla posicion,string tipo) : posicion(posicion), tipo(tipo), antiguedad(0){};

    };

    list<Construccion> _construcciones;
    Nat _popularidad;
    Nat _antiguedad;
    bool _seConstruyo;
    Mapa _mapa;



};




#endif //TP3_SIMCITY_SIMCITY_H