#ifndef _ARBOLRN_H_
#define _ARBOLRN_H_

#include <set>

template< class T >
class arbolRN {
    protected: 
    set<T> arbolRN;
    public: 
        arbolRN();
        ~arbolRN();
        bool esVacio();
        T datoRaiz();
        //void fijarRaiz(NodoBinario<T>* nraiz);
        //bool insertarNodo(T padre, T n);
        //bool eliminarNodo(T n);
        int altura();
        int altura(NodoBinario<T>* nodo);
        int tamano();
        int tamano(NodoBinario<T>* nodo);
        NodoBinario<T>* balancear(NodoBinario<T>* nodo);
        NodoBinario<T>* arbolAVL<T>::insertar(NodoBinario<T>* nodo, T val);
        NodoBinario<T>* arbolAVL<T>::eliminar(NodoBinario<T>* nodo, T val);
        bool arbolAVL<T>::insertar(T val);
        bool arbolAVL<T>::eliminar(T val);
        //bool insertar(T val);
        //bool eliminar(T val);
        bool buscar(T val);
        void preOrden();
        void inOrden();
        void inOrdenLista(std::list<T>* lista);
        void posOrden();
        void nivelOrden();
};

#include "ArbolRN.hxx"

#endif