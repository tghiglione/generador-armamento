#include "menu_armamento.hpp"
#include "armamento_artefactos.hpp"
#include "artefacto.hpp"

menu_armamento::menu_armamento() {
    salida_menu_armamento = false;
}

artefacto menu_armamento::artefacto_ingresado_por_usuario() {
    string id_artefacto;
    string set_artefacto;
    string tipo_artefacto;
    string nivel_artefacto;
    string rareza_artefacto;

    cout << "Ingrese ID del artefacto: ";
    cin >> id_artefacto;
    cout << "Ingrese set del artefacto: ";
    cin >> set_artefacto;
    cout << "Ingrese tipo, del 1 al 6, del artefacto: ";
    cin >> tipo_artefacto;
    cout << "Ingrese nivel del artefacto: ";
    cin >> nivel_artefacto;
    cout << "Ingrese rareza, del 3 al 5, del artefacto: ";
    cin >> rareza_artefacto;

    artefacto nuevo_artefacto(std::stoi(id_artefacto), set_artefacto,
                              static_cast<tipo>(std::stoi(tipo_artefacto)), std::stoul(nivel_artefacto),
                              static_cast<rareza>(std::stoi(rareza_artefacto)));
    return nuevo_artefacto;
}

string menu_armamento::generador_ruta_armamento_importado() {
    string nombre_archivo;
    cout << "Ingrese nombre del archivo (UUID-Nombre_armamento): ";
    cin >> nombre_archivo;
    nombre_archivo = nombre_archivo + ".txt";
    return nombre_archivo;
}

void menu_armamento::elegir_importar_o_crear_armamento() {
    cout << TITULO_ARMAMENTO << endl;

    cout << INSTRUCCIONES_CREAR_ARMAMENTO << endl;
    cin >> opcion_crear_o_importar;

    switch (opcion_crear_o_importar) {
        case 0:
            salida_menu_armamento = true;
            break;
        case 1: {
            armamento_artefactos nuevo_armamento;
            elegir_opcion_menu_armamento(nuevo_armamento);
            break;
        }
        case 2: {
            string ruta_archivo_armamento = generador_ruta_armamento_importado();
            armamento_artefactos nuevo_armamento(ruta_archivo_armamento);
            elegir_opcion_menu_armamento(nuevo_armamento);
            break;
        }
        default:
            std::cout << OPCION_INVALIDA << std::endl;
            break;
    }

}

void menu_armamento::elegir_opcion_menu_armamento(armamento_artefactos& nuevo_armamento) {

    while (!salida_menu_armamento) {

        cout << INSTRUCCIONES_MENU_ARMAMENTO << endl;
        cin >> opcion_elegida_menu_armamento;

        switch (opcion_elegida_menu_armamento) {
            case VOLVER_MENU_PRINCIPAL:
                salida_menu_armamento = true;
                break;
            case AGREGAR_ARTEFACTO: {
                artefacto artefacto_ingresado = artefacto_ingresado_por_usuario();
                nuevo_armamento.agregar_artefacto(artefacto_ingresado);
            }
                break;
            case MOSTRAR_ARTEFACTO_ACTUAL:{
                nuevo_armamento.mostrar_artefacto_actual();
            }
                break;
            case MOSTRAR_ARTEFACTO_SIGUIENTE: {
                nuevo_armamento.mostrar_artefacto_siguiente();
            }
                break;
            case MOSTRAR_ARTEFACTO_ANTERIOR: {
                nuevo_armamento.mostrar_artefacto_anterior();
            }
                break;
            case MOSTRAR_TODOS_LOS_ARTEFACTOS:{
                nuevo_armamento.mostrar_artefactos();
            }
                break;
            case QUITAR_ARTEFACTO: {
                nuevo_armamento.quitar_artefacto();
            }
                break;
            case EXPORTAR_ARMAMENTO: {
                nuevo_armamento.exportar_armamento();
            }
                break;
            default:
                cout << OPCION_INVALIDA << endl;
                break;
        }
    }
}






