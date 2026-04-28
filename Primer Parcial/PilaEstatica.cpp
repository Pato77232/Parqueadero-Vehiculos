#include <iostream>
using namespace std;

#define TAMANIO 100

struct Pila {
    int tope;
    int elementosPila[TAMANIO];
};

void PushElemento(Pila *pila, int valorDato) {
    if (pila->tope < TAMANIO - 1) {
        pila->tope++;
        pila->elementosPila[pila->tope] = valorDato;
    } else {
        cout << "La pila está llena\n";
    }
}

int PopElemento(Pila *pila) {
    if (pila->tope >= 0) {
        int valorDato = pila->elementosPila[pila->tope];
        pila->tope--; 
        return valorDato;
    } else {
        cout << "La pila está vacía\n";
        return -1;
    }
}

bool LlenarPila(Pila pila) {
    return (pila.tope == TAMANIO - 1);
}

bool VaciarPila(Pila pila) {
    return (pila.tope == -1);
}

void Mostrar(Pila pila) {
    for (int i = pila.tope; i >= 0; i--) {
        cout << pila.elementosPila[i] << endl;
    }
}

int main() {
    Pila pila;
    pila.tope = -1; 

    PushElemento(&pila, 8);
    PushElemento(&pila, 4);

    cout << "Contenido de la pila:\n";
    Mostrar(pila);

    cout << "\nElemento eliminado: " << PopElemento(&pila) << endl;

    return 0;
}
