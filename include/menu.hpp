
#ifndef AYED_TP3_1C2024_MENU_HPP
#define AYED_TP3_1C2024_MENU_HPP
#include <string>

using namespace std;

class menu {
private:
    enum opciones{
        SALIDA_DEL_MENU = 0,
        SECCION_ARMAMENTO_DE_ARTEFACTOS = 1,
        SECCION_COMBATES_MULTIPLES = 2,
    };
    const string TITULO_MENU = "Menu principal \n";
    const string INSTRUCCIONES_DE_MENU = "Para continuar elija una opcion: \n 0- Salir \n 1- Ir al menu de Armamento de Artefactos \n 2- Ir al menu de Combates Multiples";
    const string OPCION_INVALIDA = "Opcion invalida, por favor elija otra";

    bool salida;
    int opcion_elegida;

public:
    // Constructor
    menu();

    // Pre: -
    // Post: Ejecuta la opcion elegida, que puede ser entrar al menu de armamento, entrar al menu de combate o finalizar programa
    void elegir_seccion_menu();

};

#endif //AYED_TP3_1C2024_MENU_HPP
