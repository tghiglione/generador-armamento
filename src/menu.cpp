#include "menu.hpp"
#include "menu_combates_multiples.hpp"
#include "menu_armamento.hpp"

#include <iostream>


menu::menu() {
    salida = false;
}

void menu::elegir_seccion_menu() {

    cout << TITULO_MENU << endl;

    while (!salida) {

        cout << INSTRUCCIONES_DE_MENU << endl;
        cin >> opcion_elegida;

        switch (opcion_elegida) {
            case SALIDA_DEL_MENU:
                salida = true;
                break;
            case SECCION_ARMAMENTO_DE_ARTEFACTOS: {
                menu_armamento menu_armamento_artefactos;
                menu_armamento_artefactos.elegir_importar_o_crear_armamento();
            }
                break;
            case SECCION_COMBATES_MULTIPLES: {
                menu_combates_multiples menu_combates;
                menu_combates.elegir_opcion_menu_combates();
            }
                break;
            default:
                cout << OPCION_INVALIDA << endl;
                break;
        }
    }
}
