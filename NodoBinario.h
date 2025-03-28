#ifndef _NODOBINARIO_H_
#define _NODOBINARIO_H_

#include <list>

template< class T >
class NodoBinario {
    protected: 
        T dato;
        NodoBinario<T>* hijoIzq;
        NodoBinario<T>* hijoDer;
    public: 
        NodoBinario();
        NodoBinario(T val);
        ~NodoBinario();
        T obtenerDato();
        void fijarDato(T val);
        NodoBinario<T>* obtenerHijoIzq();
        NodoBinario<T>* obtenerHijoDer();
        void fijarHijoIzq(NodoBinario<T>* izq);
        void fijarHijoDer(NodoBinario<T>* der);
        bool esHoja();      
        int altura();
        void preOrden();
        void inOrden();
        void inOrdenLista(std::list<T>* lista);
        void posOrden();
};

#include "NodoBinario.hxx"

#endif