#ifndef _ARBOLRN_H_
#define _ARBOLRN_H_

#include <set>
#include <list>

template< class T >
class arbolRN {
    protected: 
    set<T> arbol;
    public: 
        arbolRN();
        ~arbolRN();
        bool esVacio();
        T datoRaiz();
        int altura();
        int tamano();
        bool insertar(T val);
        bool eliminar(T val);
        bool buscar(T val);
        void preOrden();
        void inOrden();
        void inOrdenLista(std::list<T>* lista);
        void posOrden();
        void nivelOrden();
};

#include "ArbolRN.hxx"

#endif