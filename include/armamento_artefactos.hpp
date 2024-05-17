#ifndef AYED_TP3_1C2024_ARMAMENTO_ARTEFACTOS_HPP
#define AYED_TP3_1C2024_ARMAMENTO_ARTEFACTOS_HPP

#include "artefacto.hpp"
#include "lista_circular.hpp"
#include <iostream>

class armamento_artefactos {
private:
    lista_circular<artefacto> armamento;
    std::string nombre_armamento;
    std::string nombre_usuario;

    artefacto crear_artefacto_importado(std::string linea_de_archivo);

public:

    // Constructor
    armamento_artefactos();

    // Constructor
    armamento_artefactos(std::string path_archivo);

    // Pre: No se puede agregar dos veces el mismo artefacto y no se pueden agregar mas de 6 artefactos.
    // Post: Agrega un artefacto a la lista de armamento.
    void agregar_artefacto(artefacto artefacto_a_agregar);

    // Pre: El armamento no puede estar vacio.
    // Post: Muestra el artefacto actual que apunta el cursor.
    void mostrar_artefacto_actual();

    // Pre: El armamento no puede estar vacio.
    // Post: Muestra el artefacto siguiente que apunta el cursor.
    void mostrar_artefacto_siguiente();

    // Pre: El armamento no puede estar vacio.
    // Post: Muestra el artefacto anterior que apunta el cursor.
    void mostrar_artefacto_anterior();

    // Pre: El armamento no puede estar vacio.
    // Post: Muestra todos los artefactos del listado.
    void mostrar_artefactos();

    // Pre: El armamento no puede estar vacio.
    // Post: Elimina el artefacto actual.
    void quitar_artefacto();

    // Pre: El armamento no puede estar vacio.
    // Post: Exporta el armamento en un archivo.
    void exportar_armamento();
};

#endif