#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto), ancho_(ancho) {};

uint Rectangulo::alto() {
    return alto_;
}

uint Rectangulo::ancho() {
    return ancho_;
}

float Rectangulo::area() {
    return alto_ * ancho_;
}

// Ejercicio 2

class Elipse {
    public:
        Elipse(uint a,uint b);
        uint r_a();
        uint r_b();
        float area();

    private:
        float PI = 3.14;
        uint r_a_;
        uint r_b_;
        float area_;
};

Elipse::Elipse(uint a,uint b): r_a_(a),r_b_(b),area_() {}

uint Elipse::r_a() {
    return r_a_;
}

uint Elipse::r_b() {
    return r_b_;
}

float Elipse:: area() {
    return r_a_*r_b_*PI ;
}

// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    return r_.alto();
}

float Cuadrado::area() {
    return r_.area();
}

// Ejercicio 4

class Circulo {
    public:
        Circulo(uint radio);
        uint radio();
        float area();

    private:
        Elipse e_;
};

Circulo::Circulo(uint radio): e_(radio,radio) {}

uint Circulo::radio(){
    return e_.r_a();
}
float Circulo::area() {
    return e_.area()
}

// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.ancho() << ", " << r.alto() << ")";
    return os;
}

ostream& operator<<(ostream& os, Elipse e){
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}

//Elipse e(10,15);
//cout << e << endl;

// Ejercicio 6

ostream& operator<<(ostream& os, Circulo c){
    os << "Circulo(" << c.radio() << ")";
    return os;
}

ostream& operator<<(ostream& os, Cuadrado c){
    os << "Circulo(" << c.lado() << ")";
    return os;
}










