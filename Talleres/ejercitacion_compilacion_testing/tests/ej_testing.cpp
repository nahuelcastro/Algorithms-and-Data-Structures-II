#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    int calculado = 15 + 7;
    int esperado = 22;
    EXPECT_EQ(calculado,esperado);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    float calculado = pow(10,2);
    float esperado = 100;
    EXPECT_EQ(calculado,esperado);
}

// Ejercicios 6..9

// 6
TEST(Aritmetica, potencia_general){
    for (int i = -5; i <= 5 ; ++i) {
        int calculado= pow(i,2);
        int esperado = i * i;
        EXPECT_EQ(calculado,esperado);
    }
}
