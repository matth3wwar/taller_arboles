#include "ArbolRN.h"
#include <set> 
#include <list>

template<class T>
arbolRN<T>::arbolRN() {
    this->arbol = new sdt::set<T>;
}

template<class T>
arbolRN<T>::~arbolRN() {
    if (this->arbol != NULL) {
        delete this->raiz;
        this->arbol = NULL;
    }
}

template<class T>
bool arbolRN<T>::esVacio() {
    return (this->arbol)->empty();
}

template<class T>
T arbolRN<T>::datoRaiz() {
    return (this->arbol)->obtenerDato();
}

template<class T>
int arbolRN<T>::altura() {
    return (this->arbol)->size(); //Arreglar
}

template<class T>
int arbolRN<T>::tamano() {
    return (this->arbol)->size(); //Arreglar
}

template<class T>
bool arbolRN<T>::insertar(T val) {
    std::set<T>::iterator it = (this->arbol)->find(val);

    if (it == (this->arbol)->end())
    {
        (this->arbol)->insert(val, val);
        return true;
    } else
        return false;
}

template<class T>
bool arbolRN<T>::eliminar(T val) {
    return (this->arbol)->erase(val);
}

template<class T>
bool arbolRN<T>::buscar(T val) {
    std::set<T>::iterator it = (this->arbol)->find(val);

    if (it == (this->arbol)->end())
        return false;
    else
        return true;
}

//recurrente
template<class T>
void arbolRN<T>::preOrden() {
    // falta
}

//recurrente
template<class T>
void arbolRN<T>::inOrden() {
    // falta
}

template<class T>
void arbolRN<T>::inOrdenLista(std::list<T>* lista) {
    // falta
}

//recurrente
template<class T>
void arbolRN<T>::posOrden() {
    //falta
}
//iterativa
template<class T>
void arbolRN<T>::nivelOrden() {
    //falta
}
