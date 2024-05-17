#include "combate_multiple.hpp"
#include <iostream>

using namespace std;

void combate_multiple::agregar_combate(combate combate_a_agregar) {
    if(cola_de_combates.tamanio() < 6 ){
        cola_de_combates.alta(combate_a_agregar);
        cout << "Combate agregado correctamente" << endl;
    }else{
        cout << "No se pueden agregar mas combates \n" << endl;
    }
}

size_t combate_multiple::pelear() {
    size_t poder_trazacamino_total_gastado = 0;
    if(cola_de_combates.vacio()){
        return poder_trazacamino_total_gastado;
    }
    combate combate_actual = cola_de_combates.primero();
    poder_trazacamino_total_gastado += combate_actual.obtener_poder_gastado();
    cout << "Combatiendo...\n" << combate_actual << endl;
    cola_de_combates.baja();

    return poder_trazacamino_total_gastado + pelear();
}