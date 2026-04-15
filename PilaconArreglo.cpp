#include <iostream>
using namespace std;

#define TAM 5

int pila[TAM];
int tope = -1;

void push(int x) {
    if (tope == TAM - 1) {
        cout << "Pila llena\n";
    } else {
        tope++;
        pila[tope] = x;
    }
}

int pop() {
    if (tope == -1) {
        cout << "Pila vacía\n";
        return -1;
    } else {
        int dato = pila[tope];
        tope--;
        return dato;
    }
}

int top() {
    if (tope == -1) {
        cout << "Pila vacía\n";
        return -1;
    } else {
        return pila[tope];
    }
}

int main() {
    push(8);
    push(15);
    push(22);

    cout << "Pop: " << pop() << endl;
    cout << "Top: " << top() << endl;

    return 0;
}
