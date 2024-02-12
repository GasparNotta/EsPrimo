#include "primos.h"

//Definimos la funcion para buscar primos utilizando la criba de Eratóstenes
void generadorDeNumPrimos(bool* esPrimo) {
    unsigned int final = static_cast<unsigned int>(sqrt(MAXIMO));

    for (unsigned int i = 2; i <= final; ++i) {
        if (esPrimo[i]) {
            for (unsigned int j = i * i; j <= MAXIMO; j += i) {
                esPrimo[j] = false;
            }
        }
    }
}