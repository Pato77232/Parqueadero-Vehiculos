#include <iostream>
#include <string>
using namespace std;

const int TAMANIO = 5;

struct Cola {
    string datos[TAMANIO];
    int frente = 0;
    int final_ = -1;
};

bool estaLlena(Cola& c) {
    return c.final_ == TAMANIO - 1;
}

bool estaVacia(Cola& c) {
    return c.frente > c.final_;
}

void enqueue(Cola& c, string valor) {
    if (estaLlena(c)) {
        cout << "   Cola llena.\n";
        return;
    }
    c.final_++;
    c.datos[c.final_] = valor;
    cout << "   Enqueue(\"" << valor << "\"): posicion " << c.final_ << "\n";
}

void dequeue(Cola& c) {
    if (estaVacia(c)) {
        cout << "   Cola vacia.\n";
        return;
    }
    string saliente = c.datos[c.frente];
    c.frente++;
    cout << "  ? Dequeue(): salió \"" << saliente
         << "\", nuevo frente en posicion " << c.frente << "\n";
}

void front(Cola& c) {
    if (estaVacia(c)) {
        cout << "  ? Cola vacía.\n";
        return;
    }
    cout << "  ? Front(): el primero en turno es \"" << c.datos[c.frente] << "\"\n";
}

void mostrarCola(Cola& c) {
    if (estaVacia(c)) {
        cout << "  [ Cola vacía ]\n";
        return;
    }
    cout << "  Frente ? ";
    for (int i = c.frente; i <= c.final_; i++) {
        cout << "[ " << c.datos[i] << " ] ";
    }
    cout << "? Final\n";
}

int main() {
    Cola c;
    int opcion;
    string valor;

    cout << "  Cola inicializada: tamaño = " << TAMANIO
         << ", frente = 0, final = -1\n";

    do {
        cout << "      MENU - COLA         \n";
        cout << "  1. Enqueue (insertar)   \n";
        cout << "  2. Dequeue (eliminar)   \n";
        cout << "  3. Front   (ver frente) \n";
        cout << "  4. Mostrar cola         \n";
        cout << "  0. Salir                \n";
        cout << "  Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "  Nombre a insertar: ";
                getline(cin, valor);
                enqueue(c, valor);
                break;

            case 2:
                dequeue(c);
                break;

            case 3:
                front(c);
                break;

            case 4:
                mostrarCola(c);
                break;

            case 0:
                cout << "  Saliendo...\n";
                break;

            default:
                cout << "   Opción invalida.\n";
        }

    } while (opcion != 0);

    return 0;
}
