#include "menu_combates_multiples.hpp"
#include "combate_multiple.hpp"
#include "combate.hpp"

menu_combates_multiples::menu_combates_multiples() {
    salida_menu_combate = false;
}

void menu_combates_multiples::elegir_opcion_menu_combates() {
    combate_multiple combates_multiples;

    cout << TITULO_COMBATES << endl;

    while (!salida_menu_combate) {

        cout << INSTRUCCIONES_MENU_COMBATE << endl;
        cin >> opcion_elegida_menu_combate;

        switch (opcion_elegida_menu_combate) {
            case VOLVER_MENU_PRINCIPAL:
                salida_menu_combate = true;
                break;
            case AGREGAR_COMBATE: {
                combate combate_prueba("Descripcion combate de prueba", 5, 10);
                combates_multiples.agregar_combate(combate_prueba);
            }
                break;
            case PELEAR_COMBATES: {
                size_t poder_trazacamino_gastado = combates_multiples.pelear();
                cout << "El poder total gastado fue: " << poder_trazacamino_gastado << endl;
            }
                break;
            default:
                cout << OPCION_INVALIDA << endl;
                break;
        }
    }
}
