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

//#if EJ >= 9
//bool Fecha::operator==(Fecha o) {
//    bool igual_dia = this->dia() == o.dia();
//    // Completar iguadad (ej 9)
//    return igual_dia;
//}
//#endif

// Ejercicio 11, 12

// Clase Horario

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

    Fecha hoy();

    list<Recordatorio> filtrar_recordatorios_de_hoy(list <Recordatorio> lr);

    vector<Recordatorio> ordenar_recordatorios(list <Recordatorio>);
    vector<Recordatorio> pasar_list_a_vectorr(list <Recordatorio> lr);

private:
    list <Recordatorio> recordatorios_de_hoy_;

    Fecha hoy_;

    vector<Recordatorio> v_recordatorios_de_hoy_;

    vector<Recordatorio> v_todos_los_recordatorios;

    void pasar_list_a_vector(list <Recordatorio> &lr, vector<Recordatorio> &vr);



    void bubbleSort(vector<Recordatorio> &a);

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

vector<Recordatorio> Agenda::ordenar_recordatorios(list <Recordatorio> lr) {
    v_recordatorios_de_hoy_ = {};
    pasar_list_a_vector(lr, v_recordatorios_de_hoy_);
    bubbleSort(v_recordatorios_de_hoy_);
    return v_recordatorios_de_hoy_;
}

void Agenda::pasar_list_a_vector(list <Recordatorio> &lr, vector<Recordatorio> &vr) {
    int recordatoriosRealSize = lr.size();
    for (int i = 0; i < recordatoriosRealSize; ++i) {
        vr.push_back(lr.front());
        lr.pop_front();
    }
}

vector<Recordatorio> Agenda::pasar_list_a_vectorr(list <Recordatorio> lr){
    vector<Recordatorio> vr;
    int recordatoriosRealSize = lr.size();
    for (int i = 0; i < recordatoriosRealSize; ++i) {
        vr.push_back(lr.front());
        lr.pop_front();
    }
    return vr;
}


//void Agenda::bubbleSort(vector<Recordatorio> &a) {
//    int i = 0;
//    int j = 0;
//    while (i < a.size() - 1) {
//        j = 0;
//        while (j < a.size() - 1) {
//            if (a[j + 1].horario().hora() < a[j].horario().hora()) {
//                Swap(a, j, j + 1);
//            }
//            j++;
//        }
//        i++;
//    }
//}
//
//void Agenda::Swap(vector<Recordatorio> &a, int i, int j) {
//    Recordatorio aux = a[i];
//    a[i] = a[j];
//    a[j] = aux;
//}

list <Recordatorio> Agenda::filtrar_recordatorios_de_hoy(list <Recordatorio> lr){
    list <Recordatorio> lrr  = lr;
    lrr.clear();
    for (Recordatorio x : v_todos_los_recordatorios ) {
        if(x.fecha() == hoy()){
            lrr.push_back(x);
        }
    }
}


ostream &operator<<(ostream &os, Agenda a) {
    list<Recordatorio> f = a.filtrar_recordatorios_de_hoy(a.recordatorios_de_hoy());
    //a.ordenar_recordatorios(a.recordatorios_de_hoy());
    //vector<Recordatorio> vr = a.ordenar_recordatorios(a.recordatorios_de_hoy());
    a.recordatorios_de_hoy().sort(std::greater<>());
    //vector<Recordatorio> vr = a.ordenar_recordatorios(f);
    vector<Recordatorio> vr = a.pasar_list_a_vectorr(a.recordatorios_de_hoy());
    os << a.hoy() << endl << "=====" << endl;
    //int recordatoriosRealSize = a.recordatorios_de_hoy().size();
    for (int i = 0; i < vr.size(); ++i) {
        os << vr[i] << endl;
    }

    return os;
}























