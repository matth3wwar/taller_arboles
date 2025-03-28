#include "ArbolAVL.h"
#include <list> 


template<class T>
arbolAVL<T>::arbolAVL() {
    this->raiz = NULL;
}

template<class T>
arbolAVL<T>::~arbolAVL() {
    if (this->raiz != NULL) {
        delete this->raiz;
        this->raiz = NULL;
    }
     
}

template<class T>
bool arbolAVL<T>::esVacio() {
    return this->raiz == NULL;
}

template<class T>
T arbolAVL<T>::datoRaiz() {
    return (this->raiz)->obtenerDato();
}

template<class T>
int arbolAVL<T>::altura() {
    if (this->esVacio()) {
        return -1;
    } else {
        return (this->raiz)->altura();
    }
}

template<class T>
int arbolAVL<T>::altura(NodoBinario<T>* nodo) {
    int valt = -1;
    if (nodo->esHoja()) <{
        valt = 0;
    } else {
        std::list<NodoBinario<T>*>::iterator it;
        int valt_izq = -1; 
        int valt_der = -1; 
        if (nodo->obtenerHijoIzq() != NULL)
            valt_izq = this->altura(nodo->obtenerHijoIzq());
        if (nodo->obtenerHijoDer() != NULL)
            valt_der = this->altura(nodo->obtenerHijoDer());
        if (valt_izq > valt_der)
            valt = valt_izq + 1;
        else
            valt = valt_der  + 1;
    }

    return valt;
}

template<class T>
int arbolAVL<T>::tamano() {
    return tamano(this->raiz);
}

template<class T>
int arbolAVL<T>::tamano(NodoBinario<T>* nodo) {
    if (nodo == NULL) {
        return 0;
    }
    return 1 + tamano(nodo->obtenerHijoIzq()) + tamano(nodo->obtenerHijoDer());
}


/*
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    +Código por GPT - START OF CODE
    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

template<class T>
NodoBinario<T>* arbolAVL<T>::rotacionIzquierda(NodoBinario<T>* nodo) {
    NodoBinario<T>* nuevaRaiz = nodo->obtenerHijoDer();
    nodo->fijarHijoDer(nuevaRaiz->obtenerHijoIzq());
    nuevaRaiz->fijarHijoIzq(nodo);
    return nuevaRaiz;
}

template<class T>
NodoBinario<T>* arbolAVL<T>::rotacionDerecha(NodoBinario<T>* nodo) {
    NodoBinario<T>* nuevaRaiz = nodo->obtenerHijoIzq();
    nodo->fijarHijoIzq(nuevaRaiz->obtenerHijoDer());
    nuevaRaiz->fijarHijoDer(nodo);
    return nuevaRaiz;
}

template<class T>
NodoBinario<T>* arbolAVL<T>::balancear(NodoBinario<T>* nodo) {
    if (!nodo) return nodo;
    int balance = altura(nodo->obtenerHijoIzq()) - altura(nodo->obtenerHijoDer());
    
    if (balance > 1) {
        if (altura(nodo->obtenerHijoIzq()->obtenerHijoIzq()) >= altura(nodo->obtenerHijoIzq()->obtenerHijoDer())) {
            return rotacionDerecha(nodo);
        } else {
            nodo->fijarHijoIzq(rotacionIzquierda(nodo->obtenerHijoIzq()));
            return rotacionDerecha(nodo);
        }
    }
    if (balance < -1) {
        if (altura(nodo->obtenerHijoDer()->obtenerHijoDer()) >= altura(nodo->obtenerHijoDer()->obtenerHijoIzq())) {
            return rotacionIzquierda(nodo);
        } else {
            nodo->fijarHijoDer(rotacionDerecha(nodo->obtenerHijoDer()));
            return rotacionIzquierda(nodo);
        }
    }
    return nodo;
}

template<class T>
NodoBinario<T>* arbolAVL<T>::insertar(NodoBinario<T>* nodo, T val) {
    if (!nodo) return new NodoBinario<T>(val);
    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(insertarNodo(nodo->obtenerHijoIzq(), val));
    } else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(insertarNodo(nodo->obtenerHijoDer(), val));
    } else {
        return nodo;
    }
    return balancear(nodo);
}

template<class T>
bool arbolAVL<T>::insertar(T val) {
    this->raiz = insertarNodo(this->raiz, val);
    return true;
}

template<class T>
NodoBinario<T>* arbolAVL<T>::eliminar(NodoBinario<T>* nodo, T val) {
    if (!nodo) return nodo;
    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(eliminarNodo(nodo->obtenerHijoIzq(), val));
    } else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(eliminarNodo(nodo->obtenerHijoDer(), val));
    } else {
        if (!nodo->obtenerHijoIzq() || !nodo->obtenerHijoDer()) {
            NodoBinario<T>* temp = nodo->obtenerHijoIzq() ? nodo->obtenerHijoIzq() : nodo->obtenerHijoDer();
            delete nodo;
            return temp;
        } else {
            NodoBinario<T>* temp = nodo->obtenerHijoDer();
            while (temp->obtenerHijoIzq()) temp = temp->obtenerHijoIzq();
            nodo->fijarDato(temp->obtenerDato());
            nodo->fijarHijoDer(eliminarNodo(nodo->obtenerHijoDer(), temp->obtenerDato()));
        }
    }
    return balancear(nodo);
}

template<class T>
bool arbolAVL<T>::eliminar(T val) {
    this->raiz = eliminarNodo(this->raiz, val);
    return true;
}
/*
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    +Código por GPT - END OF CODE
    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

/*
template<class T>
bool arbolAVL<T>::insertar(T val) {
    NodoBinario<T>* nodo = this->raiz;
    NodoBinario<T>* padre = this->raiz;
    bool insertado = false;
    bool duplicado = false;

    while (nodo != NULL) {
        padre = nodo;
        if (val < nodo->obtenerDato()) {
            nodo = nodo->obtenerHijoIzq();
        } else if (val > nodo->obtenerDato()) {
            nodo = nodo->obtenerHijoDer();
        } else {
            duplicado = true;
            break;
        }

        if (!duplicado) {
            NodoBinario<T>* nuevo = new NodoBinario<T>(val);
            if (nuevo != NULL) {
                if (val < padre->obtenerDato())
                    padre->fijarHijoIzq(nuevo);
                else    
                    padre->fijarHijoDer(nuevo);

                insertado = true;
            }
            return insertado;
        }
    }

    return encontrado;
}

template<class T>
bool arbolAVL<T>::eliminar(T val) {
    //Comparar con dato en nodo para bajar por izquierda o derecha
    //y para saber si val está en el árbol
    //Verificar siruación de eliminación
    // 1. nodo hoja, borrarlo
    // 2. nodo con un solo hijo, usar hijo para reemplazar nodo
    // 3. nodo con dos hijos, usar máximo del subárbol izquierdo
    //  para reemplazar nodo
    //
    NodoBinario<T>* nodo = this->raiz;
    NodoBinario<T>* padre = NULL;

    while (nodo != NULL && nodo->obtenerDato() != val) {
        padre = nodo;
        if (val < nodo->obtenerDato()) {
            nodo = nodo->obtenerHijoIzq();
        } else {
            nodo = nodo->obtenerHijoDer();
        }
    }

    if (nodo == NULL) {
        return false; // No se encontró el valor
    }

    // Caso 1: Nodo hoja
    if (nodo->obtenerHijoIzq() == NULL && nodo->obtenerHijoDer() == NULL) {
        if (padre == NULL) {
            this->raiz = NULL;
        } else if (padre->obtenerHijoIzq() == nodo) {
            padre->fijarHijoIzq(NULL);
        } else {
            padre->fijarHijoDer(NULL);
        }
        delete nodo;
    }
    // Caso 2: Nodo con un solo hijo
    else if (nodo->obtenerHijoIzq() == NULL || nodo->obtenerHijoDer() == NULL) {
        NodoBinario<T>* hijo = (nodo->obtenerHijoIzq() != NULL) ? nodo->obtenerHijoIzq() : nodo->obtenerHijoDer();
        if (padre == NULL) {
            this->raiz = hijo;
        } else if (padre->obtenerHijoIzq() == nodo) {
            padre->fijarHijoIzq(hijo);
        } else {
            padre->fijarHijoDer(hijo);
        }
        delete nodo;
    }
    // Caso 3: Nodo con dos hijos
    else {
        NodoBinario<T>* sucesorPadre = nodo;
        NodoBinario<T>* sucesor = nodo->obtenerHijoDer();
        while (sucesor->obtenerHijoIzq() != NULL) {
            sucesorPadre = sucesor;
            sucesor = sucesor->obtenerHijoIzq();
        }
        nodo->fijarDato(sucesor->obtenerDato());
        if (sucesorPadre->obtenerHijoIzq() == sucesor) {
            sucesorPadre->fijarHijoIzq(sucesor->obtenerHijoDer());
        } else {
            sucesorPadre->fijarHijoDer(sucesor->obtenerHijoDer());
        }
        delete sucesor;
    }
    return true;
}

*/

template<class T>
bool arbolAVL<T>::buscar(T val) {
    NodoBinario<T>* nodo = this->raiz;
    bool encontrado = false;

    while (nodo != NULL && !encontrado) {
        if (val < nodo->obtenerDato()) {
            nodo = nodo->obtenerHijoIzq();
        } else if (val > nodo->obtenerDato()) {
            nodo = nodo->obtenerHijoDer();
        } else {
            encontrado = true;
        }
    }

    return encontrado;
}

//recurrente
template<class T>
void arbolAVL<T>::preOrden() {
    if (!this->esVacio())
        (this->raiz)->preOrden();
}

//recurrente
template<class T>
void arbolAVL<T>::inOrden() {
    if (!this->esVacio())
        (this->raiz)->inOrden();
}

template<class T>
void arbolAVL<T>::inOrdenLista(std::list<T>* lista) {
    if (!this->esVacio())
        (this->raiz)->inOrdenLista(lista);
}

//recurrente
template<class T>
void arbolAVL<T>::posOrden() {
    if (!this->esVacio())
        (this->raiz)->posOrden();
}
//iterativa
template<class T>
void arbolAVL<T>::nivelOrden() {
    if (!this->esVacio()) {
        std::queue<NodoBinario<T>*> cola;
        cola.push(this->raiz);
        NodoBinario<T>* nodo;
        while (!cola.empty()) {
            nodo = cola.front();
            cola.pop();
            std::cout << nodo->obtenerDato() << " ";
            if (nodo->obtenerHijoIzq() != NULL)
                cola.push(nodo->obtenerHijoIzq());
                std::cout << nodo->obtenerDato() << " ";
            if (nodo->obtenerHijoDer() != NULL)
                cola.push(nodo->obtenerHijoDer());
        }
    }
}
