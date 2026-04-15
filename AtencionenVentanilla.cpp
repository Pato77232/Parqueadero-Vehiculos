#include <iostream>
#include <string>
using namespace std;

const int TAMANIO = 10;

struct Cola {
    string datos[TAMANIO];
    int frente = 0;
    int final_ = -1;
    int cantidad = 0;
};

bool estaVacia(Cola& c) {
    return c.cantidad == 0;
}

bool estaLlena(Cola& c) {
    return c.cantidad == TAMANIO;
}

void clienteLlega(Cola& c, string nombre) {
    if (estaLlena(c)) {
        cout << "   Cola llena, " << nombre << " no puede entrar." << endl;
        return;
    }
    c.final_ = (c.final_ + 1) % TAMANIO;  
    c.datos[c.final_] = nombre;
    c.cantidad++;
    cout << "   " << nombre << " en fila. (posicion " << c.cantidad << ")" << endl;
}

void atenderSiguiente(Cola& c) {
    if (estaVacia(c)) {
        cout << "   No hay clientes." << endl;
        return;
    }
    string atendido = c.datos[c.frente];
    c.frente = (c.frente + 1) % TAMANIO;  
    c.cantidad--;
    cout << "   Atendiendo a: " << atendido 
         << " (quedan " << c.cantidad << " en fila)" << endl;
}

void mostrarFila(Cola& c) {
    if (estaVacia(c)) {
        cout << "  [Fila vacia]" << endl;
        return;
    }
    cout << "  Fila actual: ";
    for (int i = 0; i < c.cantidad; i++) {
        int idx = (c.frente + i) % TAMANIO;
        cout << c.datos[idx];
        if (i < c.cantidad - 1) cout << " | ";
    }
    cout << endl;
}

int main() {
    Cola ventanilla;
	cout << "FARMACIA" << endl;
    cout << "" << endl;
    clienteLlega(ventanilla, "P1");
    clienteLlega(ventanilla, "P2");
    clienteLlega(ventanilla, "P3");
    clienteLlega(ventanilla, "P4");
    mostrarFila(ventanilla);

    cout << " " << endl;
    atenderSiguiente(ventanilla);
    atenderSiguiente(ventanilla);
    mostrarFila(ventanilla);



    return 0;
}
