#ifndef AYED_TP3_1C2024_LISTA_CIRCULAR_HPP
#define AYED_TP3_1C2024_LISTA_CIRCULAR_HPP

#include <exception>
#include "nodo.hpp"

class lista_circular_exception : public std::exception {
    // Excepción especifica y exclusiva para errores dentro de la lista circular.
    // Usar de la forma "throw lista_circular_exception();" cuando una precondición no se cumple.

    // Ejemplo:
    //     if (condición_de_error) {
    //         throw lista_circular_exception();
    //     }
};

template<typename T>
class lista_circular {
private:
    nodo<T>* primer_nodo;
    // El cursor es el elemento actual.
    nodo<T>* cursor;
    size_t cantidad_datos;
public:
    // Constructor.
    lista_circular();

    // Pre: -
    // Post: Agrega el dato en la posición del cursor (el nuevo dato es "anterior" al cursor). Por ejemplo:
    //
    // 1  2  4  6  8
    //    ^
    // alta(5);
    // 1  5  2  4  6  8
    //       ^
    //
    // 1  2  4  6  8
    // ^
    // alta(9);
    // 1  2  4  6  8  9
    // ^
    //
    // El cursor debe quedar apuntando al mismo nodo.
    // Si la lista está vacía, el cursor apuntará al primer nodo.
    void alta(T dato);

    // Pre: La lista no puede estar vacía.
    // Post: Devuelve el dato actual (cursor).
    T actual();

    // Pre: La lista no puede estar vacía.
    // Post: Elimina y devuelve el dato actual (cursor). Por ejemplo:
    //
    // 1  2  4  6  8
    //    ^
    // baja();
    // 1  4  6  8
    //    ^
    //
    // 1  2  4  6  8
    // ^
    // baja();
    // 2  4  6  8
    // ^
    //
    // El cursor debe quedar apuntando al nodo siguiente del eliminado.
    // Si se elimina el primer nodo, se debe reasignar con su siguiente.
    // Si la lista está vacía, debe volver a su estado inicial.
    T baja();

    // Pre: -
    // Post: Mueve el cursor al siguiente del cursor actual. Si no hay datos, no hace nada.
    void avanzar();

    // Pre: -
    // Post: Mueve el cursor al anterior del cursor actual. Si no hay datos, no hace nada.
    void retroceder();

    // Pre: -
    // Post: Devuelve la cantidad de datos de la lista.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la lista está vacía.
    bool vacio();

    // El constructor de copia está deshabilitado.
    lista_circular(const lista_circular& l) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const lista_circular& l) = delete;

    // Destructor.
    ~lista_circular();
};

template<typename T>
lista_circular<T>::lista_circular() {

}

template<typename T>
void lista_circular<T>::alta(T dato) {

}

template<typename T>
T lista_circular<T>::actual() {

}

template<typename T>
T lista_circular<T>::baja() {

}

template<typename T>
void lista_circular<T>::avanzar() {

}

template<typename T>
void lista_circular<T>::retroceder() {

}

template<typename T>
size_t lista_circular<T>::tamanio() {

}

template<typename T>
bool lista_circular<T>::vacio() {

}

template<typename T>
lista_circular<T>::~lista_circular() {

}

#endif