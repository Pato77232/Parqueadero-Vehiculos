#include <iostream>
using namespace std;

struct Nodo {
    int valorDato;
    Nodo* siguiente;
};

void PushElemento(Nodo*& tope, int valorDato) {
    Nodo* nuevoDato = new Nodo(); 
    if (nuevoDato == NULL) {
        cout << "No existe memoria\n";
    } else {
        nuevoDato->valorDato = valorDato;
        nuevoDato->siguiente = tope;
        tope = nuevoDato;
    }
}

int PopElemento(Nodo*& tope) {
    if (tope == NULL) {
        cout << "Pila vacía\n";
        return -1;
    }

    Nodo* temporal = tope;
    int elemento = temporal->valorDato;

    tope = tope->siguiente;
    delete temporal;

    return elemento;
}

void Mostrar(Nodo* tope) {
    Nodo* actual = tope;
    while (actual != NULL) {
        cout << actual->valorDato << endl;
        actual = actual->siguiente;
    }
}

int main() {
    Nodo* tope = NULL;

    PushElemento(tope, 1);
    PushElemento(tope, 9);
    PushElemento(tope, 8);
    PushElemento(tope, 4);

    cout << "Contenido de la pila:\n";
    Mostrar(tope);

    cout << "\nElemento eliminado: " << PopElemento(tope) << endl;

    return 0;
}
