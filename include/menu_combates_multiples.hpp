#ifndef AYED_TP3_1C2024_MENU_COMBATES_MULTIPLES_HPP
#define AYED_TP3_1C2024_MENU_COMBATES_MULTIPLES_HPP

#include <string>

using namespace std;

class menu_combates_multiples {
private:
    enum opciones_combate{
        VOLVER_MENU_PRINCIPAL = 0,
        AGREGAR_COMBATE = 1,
        PELEAR_COMBATES = 2,
    };

    bool salida_menu_combate;
    int opcion_elegida_menu_combate;

    const string TITULO_COMBATES = "Combates Multiples \n";
    const string INSTRUCCIONES_MENU_COMBATE = "Para continuar elija una opcion: \n 0- Volver al menu principal \n 1- Agregar combate \n 2- Pelear combates multiples";
    const string OPCION_INVALIDA = "Opcion invalida, por favor elija otra";

public:

    menu_combates_multiples();

    // Pre: -
    // Post: Ejecuta la opcion elegida, que puede ser agregar combate, pelear combates multiples o volver al menu inicial
    void elegir_opcion_menu_combates();

};


#endif //AYED_TP3_1C2024_MENU_COMBATES_MULTIPLES_HPP
