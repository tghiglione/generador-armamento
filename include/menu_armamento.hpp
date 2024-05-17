#ifndef AYED_TP3_1C2024_MENU_ARMAMENTO_HPP
#define AYED_TP3_1C2024_MENU_ARMAMENTO_HPP

#include <string>
#include "artefacto.hpp"
#include "armamento_artefactos.hpp"


using namespace std;

class menu_armamento {
private:

    enum opciones_armamento{
        VOLVER_MENU_PRINCIPAL = 0,
        AGREGAR_ARTEFACTO = 1,
        MOSTRAR_ARTEFACTO_ACTUAL = 2,
        MOSTRAR_ARTEFACTO_SIGUIENTE = 3,
        MOSTRAR_ARTEFACTO_ANTERIOR = 4,
        MOSTRAR_TODOS_LOS_ARTEFACTOS = 5,
        QUITAR_ARTEFACTO = 6,
        EXPORTAR_ARMAMENTO = 7,
    };

    bool salida_menu_armamento;
    int opcion_elegida_menu_armamento;
    int opcion_crear_o_importar;

    const string TITULO_ARMAMENTO = "Armamento de artefactos \n";
    const string INSTRUCCIONES_CREAR_ARMAMENTO = "Desea crear un armamento o importarlo? Elija una opcion: \n 0- Volver al menu principal \n 1- Crear armamento \n 2- Importar armamento";
    const string INSTRUCCIONES_MENU_ARMAMENTO = "Para continuar elija una opcion: \n 0- Volver al menu principal \n"
                                                "1- Agregar artefacto \n 2- Mostrar artefacto actual \n 3- Mostrar siguiente artefacto \n"
                                                "4- Mostrar anterior artefacto \n 5- Mostrar todos los artefactos \n "
                                                "6- Quitar artefacto \n 7- Exportar armamento";
    const string OPCION_INVALIDA = "Opcion invalida, por favor elija otra";

    artefacto artefacto_ingresado_por_usuario();

    string generador_ruta_armamento_importado();


public:

    //Constructor
    menu_armamento();

    // Pre: -
    // Post:
    void elegir_opcion_menu_armamento(armamento_artefactos& nuevo_armamento);

    void elegir_importar_o_crear_armamento();

};
#endif //AYED_TP3_1C2024_MENU_ARMAMENTO_HPP
