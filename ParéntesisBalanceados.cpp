#include <iostream>
#include <string>
using namespace std;

const int TAMANIO = 100;

struct Pila {
    char datos[TAMANIO];
    int tope = -1;
};

bool estaVacia(Pila& p) {
    return p.tope == -1;
}

bool estaLlena(Pila& p) {
    return p.tope == TAMANIO - 1;
}

void push(Pila& p, char c) {
    if (estaLlena(p)) {
        cout << "Pila llena" << endl;
        return;
    }
    p.tope++;
    p.datos[p.tope] = c;
    cout << "  PUSH('" << c << "') ? tope = " << p.tope << endl;
}

void pop(Pila& p) {
    if (estaVacia(p)) {
        cout << "  Pila vacía, no se puede hacer POP" << endl;
        return;
    }
    cout << "  POP('" << p.datos[p.tope] << "') ? tope = " << p.tope - 1 << endl;
    p.tope--;
}

bool parentesisBalanceados(string expresion) {
    Pila p;

    cout << "\nAnalizando: \"" << expresion << "\"" << endl;
    cout << "-----------------------------" << endl;

    for (char c : expresion) {
        if (c == '(') {
            push(p, c);
        } else if (c == ')') {
            if (estaVacia(p)) {
                cout << "  ')' encontrado pero pila vacía ? FALSO" << endl;
                return false;
            }
            pop(p);
        }
    }

    return estaVacia(p);
}

int main() {
    string casos[] = {    
        "(x+y)",
		"((x+y)*z)",  
		"(x+y))",
		"((x+y)",
    };

    for (string expr : casos) {
        bool resultado = parentesisBalanceados(expr);
        cout << "Resultado: " << (resultado ? "? VERDADERO (balanceado)" 
                                            : "? FALSO (no balanceado)") << endl;
        cout << endl;
    }

    return 0;
}

