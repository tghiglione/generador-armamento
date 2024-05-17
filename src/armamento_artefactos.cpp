#include "armamento_artefactos.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

armamento_artefactos::armamento_artefactos() {
    std::cout << "Ingrese nombre del usuario: " << std::endl;
    std::cin >> nombre_usuario;
    std::cout << "Ingrese nombre del armamento: " << std::endl;
    std::cin >> nombre_armamento;

}

armamento_artefactos::armamento_artefactos(std::string path_archivo) {
    std::stringstream input_stringstream(path_archivo);
    char delimitador_guion = '-';
    char delimitador_punto = '.';
    getline(input_stringstream, nombre_usuario, delimitador_guion);
    getline(input_stringstream, nombre_armamento, delimitador_punto);

    std::ifstream archivo_armamento_importado(path_archivo);
    std::string linea_archivo;
    if(archivo_armamento_importado.is_open()){
        while (getline(archivo_armamento_importado, linea_archivo)) {

            artefacto nuevo_artefacto = crear_artefacto_importado(linea_archivo);
            agregar_artefacto(nuevo_artefacto);
        }
    }else{
        std::cout << "Error al abrir archivo ";
    }

}
artefacto armamento_artefactos::crear_artefacto_importado(std::string linea_archivo) {
    std::stringstream artefacto_stringstream(linea_archivo);
    char delimitador_coma = ',';
    std::string artefacto_id;
    std::string artefacto_set;
    std::string artefacto_tipo;
    std::string artefacto_nivel;
    std::string artefacto_rareza;
    getline(artefacto_stringstream, artefacto_id, delimitador_coma);
    getline(artefacto_stringstream, artefacto_set, delimitador_coma);
    getline(artefacto_stringstream, artefacto_tipo, delimitador_coma);
    getline(artefacto_stringstream, artefacto_nivel, delimitador_coma);
    getline(artefacto_stringstream, artefacto_rareza, delimitador_coma);

    artefacto nuevo_artefacto(std::stoi(artefacto_id), artefacto_set,
                              static_cast<tipo>(std::stoi(artefacto_tipo)), std::stoul(artefacto_nivel),
                              static_cast<rareza>(std::stoi(artefacto_rareza)));
    return  nuevo_artefacto;
}

void armamento_artefactos::mostrar_artefacto_actual() {
    if(armamento.vacio()){
        std::cout << "El armamento esta vacio." << std::endl;
    }else{
        std::cout << armamento.actual() << std::endl;
    }
}

void armamento_artefactos::mostrar_artefacto_siguiente() {
    if(armamento.vacio()){
        std::cout << "El armamento esta vacio." << std::endl;
    }else{
        armamento.avanzar();
        mostrar_artefacto_actual();
    }
}

void armamento_artefactos::mostrar_artefacto_anterior() {
    if(armamento.vacio()){
        std::cout << "El armamento esta vacio." << std::endl;
    }else{
        armamento.retroceder();
        mostrar_artefacto_actual();
    }
}

void armamento_artefactos::mostrar_artefactos() {
    if(armamento.vacio()){
        std::cout << "El armamento esta vacio." << std::endl;
    }else{
        size_t cantidad_artefactos = armamento.tamanio();
        std::cout << "Los artefactos del armamento " << nombre_armamento << " son:" << std::endl;
        for(size_t i = 0; i < cantidad_artefactos; i++){
            mostrar_artefacto_actual();
            armamento.avanzar();
        }
    }
}

void armamento_artefactos::agregar_artefacto(artefacto artefacto_a_agregar) {
    if(armamento.tamanio() == 0){
        armamento.alta(artefacto_a_agregar);
    }
    else if(armamento.tamanio() > 0 && armamento.tamanio() < 6 ){
        bool artefacto_repetido = false;
        artefacto primer_cursor = armamento.actual();
        do{
            if(artefacto_a_agregar.operator==(armamento.actual())){
                artefacto_repetido = true;
                std::cout << "El artefacto ya está en el armamento." << std::endl;
            }
            armamento.avanzar();
        }
        while(!artefacto_repetido && !(primer_cursor.operator==(armamento.actual())));
        if(!artefacto_repetido){
            armamento.alta(artefacto_a_agregar);
        }
    }else{
        std::cout << "El armamento esta completo" << std::endl;
    }
}

void armamento_artefactos::quitar_artefacto() {
    if(armamento.vacio()){
        std::cout << "El armamento esta vacio." << std::endl;
    }else{
        artefacto artefacto_eliminado = armamento.baja();
        std::cout << "El artefacto eliminado es: " << artefacto_eliminado << std::endl;
    }
}

void armamento_artefactos::exportar_armamento() {
    std::string nombre_archivo_armamento = nombre_usuario + "-" + nombre_armamento + ".csv";
    std::ofstream archivo_armamento(nombre_archivo_armamento,std::ofstream::out);
    if(archivo_armamento.is_open()){
        for (size_t i = 0; i < armamento.tamanio(); i++){
            artefacto artefacto_a_agregar = armamento.actual();
            archivo_armamento << artefacto_a_agregar << std::endl;
            armamento.avanzar();
        }
        archivo_armamento.close();

        std::cout << "Archivo generado exitosamente" << std::endl;
    }else{
        std::cout << "Error al abrir el archivo" << std::endl;
    };
}




