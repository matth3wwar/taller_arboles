#include "NodoBinario.h"

template< class T>
NodoBinario<T>::NodoBinario() {
    this->desc.clear();
}

template< class T>
NodoBinario<T>::NodoBinario(T val) {
    this->dato = val;
}

template< class T>
NodoBinario<T>::~NodoBinario() {
    std::list<NodoBinario<T>>::iterator it;
    for (it = desc.begin(); it != desc.end(); it++)
        delete *it;
    this->desc.clear();
}

template< class T>
T NodoBinario<T>::obtenerDato() {
    return this->dato;
}

template< class T>
void NodoBinario<T>::fijarDato(T val) {
    this->dato = val;
}

template< class T>
bool NodoBinario<T>::esHoja() {
    //return this->desc.empty();
    return (this->desc.size() == 0);
}

template< class T>
int NodoBinario<T>::altura() {
    int valt = -1;
    if (this->esHoja()) {
        valt = 0;
    } else {
        int valt_izq = -1; 
        int valt_der = -1; 
        if (this->hijoIzq() != NULL)
            valt_izq = this->altura(nodo->obtenerHijoIzq());
        if (this->hijoDer() != NULL)
            valt_der = this->altura(nodo->obtenerHijoDer());
        if (valt_izq > valt_der)
            valt = valt_izq + 1;
        else
            valt = valt_der  + 1;
    }

    return alt;
}

template < class T>
void NodoBinario<T>::preOrden() {
    std::cout << this->dato<< " ";
    std:: list<NodoBinario<T>*>::iterator it;
    for (it = this->desc.begin; it != this->desc.end(); it++) {
        (*it)->preOrden();
    }
}

template < class T>
void NodoBinario<T>::inOrden() {
    if (this-> hizoIzq != NULL)
        (this->hijoIzq)->inOrden();
    std::cout << this->dato<< " ";
    if (this->hijoDer != NULL)
        (this->hijoDer)->inOrden();
}

template<class T>
void NodoBinario<T>::inOrdenLista(std::list<T>* lista) {
    if (this-> hizoIzq != NULL)
        (this->hijoIzq)->inOrdenLista(lista);
    lista->push_front(this->dato);
    if (this->hijoDer != NULL)
        (this->hijoDer)->inOrdenLista(lista);
}

template < class T>
void NodoBinario<T>::posOrden() {
    std::cout << this->dato<< " ";
    std:: list<NodoBinario<T>*>::iterator it;
    for (it = this->desc.begin; it != this->desc.end(); it++) {
        (*it)->posOrden();
    }
}