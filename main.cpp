#include <iostream>
#include <fstream>
#include <ctime>
#include "primos.h"

int main() {
    // Empezamos a contar el tiempo de ejecución
    unsigned int ti = clock();

    // Definimos el array dinámico de números primos
    bool* esPrimo = new bool[MAXIMO + 1];

    // Establecemos los valores conocidos
    esPrimo[0] = esPrimo[1] = false;
    for (unsigned int i = 2; i <= MAXIMO; ++i) {
        esPrimo[i] = true;
    }

    // Generamos los números primos
    generadorDeNumPrimos(esPrimo);

    // Creamos el archivo que contenga los números primos
    std::ofstream archivo("primos.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        delete[] esPrimo;  // Liberamos la memoria antes de salir del programa
        return 1;
    }

    // Guardamos los números primos en el archivo
    int cantidadPrimos = 0;
    for (unsigned int i = 2; i <= MAXIMO; ++i) {
        if (esPrimo[i]) {
            archivo << i << std::endl;
            ++cantidadPrimos;
        }
    }

    // Cerramos el archivo
    archivo.close();

    // Detenemos el contador de tiempo
    unsigned int tf = clock();
    double tiempo_total = static_cast<double>(tf - ti) / CLOCKS_PER_SEC;

    // Imprimimos la cantidad de números primos y el tiempo empleado para el usuario
    std::cout << "Cantidad de números primos guardados: " << cantidadPrimos << std::endl;
    std::cout << "Tiempo empleado: " << tiempo_total << " segundos." << std::endl;

    // Avisamos la finalización del programa al usuario
    std::cout << "Programa completado con éxito." << std::endl;

    // Liberamos la memoria antes de salir del programa
    delete[] esPrimo;

    return 0;
}