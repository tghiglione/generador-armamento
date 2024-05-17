#ifndef AYED_TP3_1C2024_COMBATE_MULTIPLE_HPP
#define AYED_TP3_1C2024_COMBATE_MULTIPLE_HPP

#include "cola.hpp"
#include "combate.hpp"
#include <iostream>

class combate_multiple {
private:
    cola<combate> cola_de_combates;

public:

    //Constructor
    combate_multiple() = default;

    // Pre: No se puede agregar mas de 6 combates.
    // Post: Agrega un combate a la cola de combates multiples.
    void agregar_combate(combate combate_a_agregar);

    // Pre: -
    // Post: Ejecuta los combates de la cola de combates multiples y al final muestra el poder gastado.
    // Tipo de recursividad: directa por el modo de invocacion, simple por la cantidad de llamados y de cola por que la llamo al final de la funcion
    size_t pelear();

};

#endif