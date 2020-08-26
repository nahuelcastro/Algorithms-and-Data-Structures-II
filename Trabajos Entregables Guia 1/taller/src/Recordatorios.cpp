#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
            // ene, feb, mar, abr, may, jun
            31, 28, 31, 30, 31, 30,
            // jul, ago, sep, oct, nov, dic
            31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
public:
    Fecha(int mes, int dia);

    int mes();

    int dia();

    bool operator==(Fecha f);

    void incrementar_dia();

//    #if EJ >= 9 // Para ejercicio 9
//    bool operator==(Fecha o);
//    #endif

private:
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia) {}

int Fecha::mes() {
    return mes_;
}

int Fecha::dia() {
    return dia_;
}

ostream &operator<<(ostream &os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

bool Fecha::operator==(Fecha f) {
    return (this->mes() == f.mes() and this->dia() == f.dia());
}

void Fecha::incrementar_dia() {
    if (this->dia() == dias_en_mes(this->mes())) {
        if (this->mes() == 12) {
            mes_ = 1;
            dia_ = 1;
        } else {
            mes_++;
            dia_ = 1;
        }
    } else {
        dia_++;
    }
}

class Horario {
public:
    Horario(uint hora, uint min);

    uint hora();

    uint min();

    bool operator<(Horario h);

private:
    uint hora_;
    uint min_;
};

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min) {}

uint Horario::min() {
    return min_;
}

uint Horario::hora() {
    return hora_;
}

ostream &operator<<(ostream &os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}

bool Horario::operator<(Horario h) {
    if (hora() < h.hora()) {
        return true;
    } else if (hora() > h.hora()) {
        return false;
    } else {
        if (min() < h.min()) {
            return true;
        }
        return false;
    }

}

// Ejercicio 13

// Clase Recordatorio

class Recordatorio {
public:
    Recordatorio(Fecha fecha, Horario horario, string mensaje);

    Fecha fecha();

    Horario horario();

    string mensaje();

private:
    Fecha fecha_;
    Horario horario_;
    string mensaje_;

};

Recordatorio::Recordatorio(Fecha fecha, Horario horario, string mensaje) : fecha_(fecha), horario_(horario),
                                                                           mensaje_(mensaje) {}

Fecha Recordatorio::fecha() {
    return fecha_;
}

Horario Recordatorio::horario() {
    return horario_;
}

string Recordatorio::mensaje() {
    return mensaje_;
}

ostream &operator<<(ostream &os, Recordatorio r) {
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
    return os;
}

// Ejercicio 14

class Agenda {
public:
    Agenda(Fecha fecha_inicial);

    void agregar_recordatorio(Recordatorio rec);

    void incrementar_dia();

    list <Recordatorio> recordatorios_de_hoy();

    vector<Recordatorio> filtrar_recordatorios_de_hoy();

    Fecha hoy();

    void bubbleSort(vector<Recordatorio> &a);

private:
    list <Recordatorio> recordatorios_de_hoy_;
    Fecha hoy_;
    vector<Recordatorio> v_todos_los_recordatorios;

    void Swap(vector<Recordatorio> &a, int i, int j);
};

Agenda::Agenda(Fecha fecha_inicial) : recordatorios_de_hoy_(), hoy_(fecha_inicial) {}

list <Recordatorio> Agenda::recordatorios_de_hoy() {
    return recordatorios_de_hoy_;
}

Fecha Agenda::hoy() {
    return hoy_;
}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    v_todos_los_recordatorios.push_back(rec);
}

void Agenda::incrementar_dia() {
    hoy_.incrementar_dia();
}


void Agenda::bubbleSort(vector<Recordatorio> &v) {

    int vz = v.size();
    if (vz >
        0) { // si no pongo esta condicion, debugguenado me doy cuenta que si vz es cero, entra igual al for y accede a memoria invalida
        for (int i = 0; i < v.size() - 1; i++) {
            int j = 0;
            for (j = 0; j < v.size() - 1; j++) {
                if (v[j + 1].horario().hora() < v[j].horario().hora()) {
                    Swap(v, j, j + 1);
                }
            }
        }
    }
}

void Agenda::Swap(vector<Recordatorio> &a, int i, int j) {
    Recordatorio aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

vector<Recordatorio> Agenda::filtrar_recordatorios_de_hoy() {
    vector<Recordatorio> vr;
    for (int i = 0; i < v_todos_los_recordatorios.size(); i++) {
        if (v_todos_los_recordatorios[i].fecha() == hoy()) {
            vr.push_back(v_todos_los_recordatorios[i]);
        }
    }
    return vr;
}


ostream &operator<<(ostream &os, Agenda a) {
    vector<Recordatorio> vr = a.filtrar_recordatorios_de_hoy(); // vr tiene todos los Recordatorios de hoy
    a.bubbleSort(vr); // ordeno vr
    os << a.hoy() << endl << "=====" << endl;
    for (int i = 0; i < vr.size(); ++i) {
        os << vr[i] << endl;
    }
    return os;
}

