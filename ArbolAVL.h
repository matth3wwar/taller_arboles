#ifndef _ARBOLBINARIOORD_H_
#define _ARBOLBINARIOORD_H_

#include "NodoBinario.h"
#include <list>

template< class T >
class arbolAVL {
    protected: 
        NodoBinario<T>* raiz;
    public: 
        arbolAVL();
        ~arbolAVL();
        bool esVacio();
        T datoRaiz();
        //void fijarRaiz(NodoBinario<T>* nraiz);
        //bool insertarNodo(T padre, T n);
        //bool eliminarNodo(T n);
        int altura();
        int altura(NodoBinario<T>* nodo);
        int tamano();
        int tamano(NodoBinario<T>* nodo);
        NodoBinario<T>* rotacionIzquierda(NodoBinario<T>* nodo);
        NodoBinario<T>* rotacionDerecha(NodoBinario<T>* nodo);
        NodoBinario<T>* balancear(NodoBinario<T>* nodo);
        NodoBinario<T>* insertar(NodoBinario<T>* nodo, T val);
        NodoBinario<T>* eliminar(NodoBinario<T>* nodo, T val);
        bool insertar(T val);
        bool eliminar(T val);
        //bool insertar(T val);
        //bool eliminar(T val);
        bool buscar(T val);
        void preOrden();
        void inOrden();
        void inOrdenLista(std::list<T>* lista);
        void posOrden();
        void nivelOrden();
};

#include "ArbolAVL.hxx"

#endif