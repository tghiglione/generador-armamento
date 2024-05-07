#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <exception>

class vector_exception : public std::exception {
    // Excepción especifica y exclusiva para errores dentro del vector.
    // Usar de la forma "throw vector_exception();" cuando una precondición no se cumpla.

    // Ejemplo:
    //     if (condición_de_error){
    //         throw vector_exception();
    //     }
};

template<typename T>
class vector {
private:
    T* datos;
    size_t cantidad_datos;
    // Tamaño del arreglo "datos".
    size_t tamanio_maximo;
public:
    // Constructor.
    vector();

    // Pre: El índice debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posición indicada, moviendo todos los elementos siguientes.
    void alta(T dato, size_t indice);

    // Pre: -
    // Post: Agrega el dato al final del vector. Equivale a alta(dato, cantidad_datos).
    void alta(T dato);

    // Pre: El vector no puede estar vacío. El índice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posición indicada, moviendo todos los elementos siguientes, y lo devuelve.
    T baja(size_t indice);

    // Pre: El vector no puede estar vacío.
    // Post: Elimina el ultimo dato y lo devuelve. Equivale a baja(cantidad_datos - 1).
    T baja();

    // Pre: -
    // Post: Devuelve true si el vector está vacío (es decir, si no hay datos).
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos del vector.
    size_t tamanio();

    // Pre: El vector no puede estar vacío. El índice debe ser menor que la cantidad de datos.
    // Post: Devuelve una referencia al dato deseado.
    T& operator[](size_t indice);

    // Constructor de copia (ya implementado).
    vector(const vector<T>& vector);

    // Operador de asignación (ya implementado).
    vector<T>& operator=(const vector<T>& vector);

    // Destructor.
    ~vector();
};

template<typename T>
vector<T>::vector() {

}

template<typename T>
void vector<T>::alta(T dato, size_t indice) {

}

template<typename T>
void vector<T>::alta(T dato) {

}

template<typename T>
T vector<T>::baja(size_t indice) {

}

template<typename T>
T vector<T>::baja() {

}

template<typename T>
bool vector<T>::vacio() {

}

template<typename T>
size_t vector<T>::tamanio() {

}

template<typename T>
T& vector<T>::operator[](size_t indice) {

}

template<typename T>
vector<T>::~vector() {

}

// Estos dos métodos ya están implementados. No hace falta modificarlos.
template<typename T>
vector<T>::vector(const vector& vector) {
    datos = nullptr;
    cantidad_datos = vector.cantidad_datos;
    tamanio_maximo = vector.tamanio_maximo;
    if (tamanio_maximo) {
        datos = new T[tamanio_maximo];
        for (size_t i = 0; i < cantidad_datos; i++) {
            datos[i] = vector.datos[i];
        }
    }
}

template<typename T>
vector<T>& vector<T>::operator=(const vector& vector) {
    if (this != &vector) {
        delete[] datos;
        datos = nullptr;
        cantidad_datos = vector.cantidad_datos;
        tamanio_maximo = vector.tamanio_maximo;
        if (tamanio_maximo) {
            datos = new T[tamanio_maximo];
            for (size_t i = 0; i < cantidad_datos; i++) {
                datos[i] = vector.datos[i];
            }
        }
    }
    return *this;
}

#endif