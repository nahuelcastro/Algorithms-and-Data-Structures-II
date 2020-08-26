#include "SistemaDeMensajes.h"

// Completar...
SistemaDeMensajes::SistemaDeMensajes(){
    _conns[0] = nullptr;
    _conns[1] = nullptr;
    _conns[2] = nullptr;
    _conns[3] = nullptr;
}

void SistemaDeMensajes::registrarJugador(int id, string ip){
    _conns[id] = new ConexionJugador(ip);
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    _conns[id]->enviarMensaje(mensaje);
}

bool SistemaDeMensajes::registrado(int id) const{
    return _conns[id] != nullptr;
}

string SistemaDeMensajes::ipJugador(int id) const{
    return _conns[id]->ip();
}

SistemaDeMensajes::~SistemaDeMensajes(){
    delete (_conns[0]);
    delete (_conns[1]);
    delete (_conns[2]);
    delete (_conns[3]);
}