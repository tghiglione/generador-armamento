#include "armamento_artefactos.hpp"
#include <fstream>
#include <sstream>

armamento_artefactos::armamento_artefactos() {
    cout << "Ingrese UUID del usuario (8 digitos): " << endl;
    cin >> nombre_usuario;
    cout << "Ingrese nombre del armamento: " << endl;
    cin >> nombre_armamento;

}

armamento_artefactos::armamento_artefactos(string path_archivo) {
    stringstream input_stringstream(path_archivo);
    char delimitador_guion = '-';
    char delimitador_punto = '.';
    getline(input_stringstream, nombre_usuario, delimitador_guion);
    getline(input_stringstream, nombre_armamento, delimitador_punto);

    ifstream archivo_armamento_importado(path_archivo);
    string linea_archivo;

    if(archivo_armamento_importado.is_open()){
        while (getline(archivo_armamento_importado, linea_archivo)) {
            artefacto nuevo_artefacto = crear_artefacto_importado(linea_archivo);
            agregar_artefacto(nuevo_artefacto);
        }
    }else{
        cout << "Error al abrir archivo " << endl;
    }

}
artefacto armamento_artefactos::crear_artefacto_importado(string linea_archivo) {
    stringstream artefacto_stringstream(linea_archivo);
    char delimitador_coma = ',';
    string artefacto_id;
    string artefacto_set;
    string artefacto_tipo;
    string artefacto_nivel;
    string artefacto_rareza;
    getline(artefacto_stringstream, artefacto_id, delimitador_coma);
    getline(artefacto_stringstream, artefacto_set, delimitador_coma);
    getline(artefacto_stringstream, artefacto_tipo, delimitador_coma);
    getline(artefacto_stringstream, artefacto_nivel, delimitador_coma);
    getline(artefacto_stringstream, artefacto_rareza, delimitador_coma);

    artefacto nuevo_artefacto(stoi(artefacto_id), artefacto_set,
                              static_cast<tipo>(stoi(artefacto_tipo)), stoul(artefacto_nivel),
                              static_cast<rareza>(stoi(artefacto_rareza)));
    return  nuevo_artefacto;
}

void armamento_artefactos::mostrar_artefacto_actual() {
    if(armamento.vacio()){
        cout << "El armamento esta vacio." << endl;
    }else{
        cout << armamento.actual() << endl;
    }
}

void armamento_artefactos::mostrar_artefacto_siguiente() {
    if(armamento.vacio()){
        cout << "El armamento esta vacio." << endl;
    }else{
        armamento.avanzar();
        mostrar_artefacto_actual();
    }
}

void armamento_artefactos::mostrar_artefacto_anterior() {
    if(armamento.vacio()){
        cout << "El armamento esta vacio." << endl;
    }else{
        armamento.retroceder();
        mostrar_artefacto_actual();
    }
}

void armamento_artefactos::mostrar_artefactos() {
    if(armamento.vacio()){
        cout << "El armamento esta vacio." << endl;
    }else{
        size_t cantidad_artefactos = armamento.tamanio();
        cout << "Los artefactos del armamento " << nombre_armamento << " son:" << endl;
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
                cout << "El artefacto ya está en el armamento." << endl;
            }
            armamento.avanzar();
        }
        while(!artefacto_repetido && !(primer_cursor.operator==(armamento.actual())));
        if(!artefacto_repetido){
            armamento.alta(artefacto_a_agregar);
        }
    }else{
        cout << "El armamento esta completo" << endl;
    }
}

void armamento_artefactos::quitar_artefacto() {
    if(armamento.vacio()){
        cout << "El armamento esta vacio." << endl;
    }else{
        artefacto artefacto_eliminado = armamento.baja();
        cout << "El artefacto eliminado es: " << artefacto_eliminado << endl;
    }
}

void armamento_artefactos::exportar_armamento() {
    string nombre_archivo_armamento = nombre_usuario + "-" + nombre_armamento + ".csv";
    ofstream archivo_armamento(nombre_archivo_armamento,ofstream::out);
    if(archivo_armamento.is_open()){
        for (size_t i = 0; i < armamento.tamanio(); i++){
            artefacto artefacto_a_agregar = armamento.actual();
            archivo_armamento << artefacto_a_agregar << endl;
            armamento.avanzar();
        }
        archivo_armamento.close();

        cout << "Archivo generado exitosamente" << endl;
    }else{
        cout << "Error al abrir el archivo" << endl;
    };
}




