#include <iostream>
#include <string>
using namespace std;

//Estructura del empleado (dato que guarda cada nodo) 
struct Empleado {
    int    codigo;
    string nombre;
    string cargo;
};

//Nodo del árbol
struct Nodo {
    Empleado dato;
    Nodo*    izquierdo;  // puntero al hijo izquierdo
    Nodo*    derecho;    // puntero al hijo derecho

    // Constructor: inicializa el nodo con un empleado
    Nodo(Empleado emp) {
        dato       = emp;
        izquierdo  = nullptr;
        derecho    = nullptr;
    }
};

//Funciones
//Insertar 
//Si el código es menor, va a la izquierda; si es mayor, a la derecha.
Nodo* insertar(Nodo* raiz, Empleado emp) {
    if (raiz == nullptr) {
        return new Nodo(emp);          // lugar vacío → insertar aquí
    }
    if (emp.codigo < raiz->dato.codigo) {
        raiz->izquierdo = insertar(raiz->izquierdo, emp);
    } else if (emp.codigo > raiz->dato.codigo) {
        raiz->derecho = insertar(raiz->derecho, emp);
    } else {
        cout << "⚠  El código " << emp.codigo << " ya existe en el árbol.\n";
    }
    return raiz;
}

//Buscar
//Retorna el puntero al nodo encontrado, o nullptr si no existe.
Nodo* buscar(Nodo* raiz, int codigo) {
    if (raiz == nullptr || raiz->dato.codigo == codigo) {
        return raiz;
    }
    if (codigo < raiz->dato.codigo) {
        return buscar(raiz->izquierdo, codigo);
    }
    return buscar(raiz->derecho, codigo);
}

//Recorrido Inorden (Izq → Raíz → Der)
//Muestra los empleados ordenados por código.
void inorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    inorden(raiz->izquierdo);
    cout << "  [" << raiz->dato.codigo << "] "
         << raiz->dato.nombre << " - " << raiz->dato.cargo << "\n";
    inorden(raiz->derecho);
}

//Recorrido Preorden (Raíz → Izq → Der) 
//Muestra primero la raíz, luego los subárboles.
void preorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    cout << "  [" << raiz->dato.codigo << "] "
         << raiz->dato.nombre << " - " << raiz->dato.cargo << "\n";
    preorden(raiz->izquierdo);
    preorden(raiz->derecho);
}

//Recorrido Postorden (Izq → Der → Raíz) 
//Muestra primero los hijos y al final la raíz.
void postorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    postorden(raiz->izquierdo);
    postorden(raiz->derecho);
    cout << "  [" << raiz->dato.codigo << "] "
         << raiz->dato.nombre << " - " << raiz->dato.cargo << "\n";
}

//Altura del árbol
//Cuenta cuántos niveles tiene el árbol desde la raíz hasta la hoja más lejana.
int altura(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    int altIzq = altura(raiz->izquierdo);
    int altDer = altura(raiz->derecho);
    return 1 + (altIzq > altDer ? altIzq : altDer);
}

//Mostrar nodos hoja
//Un nodo es hoja si no tiene hijos (izquierdo ni derecho).
void mostrarHojas(Nodo* raiz) {
    if (raiz == nullptr) return;
    if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) {
        cout << "  [" << raiz->dato.codigo << "] "
             << raiz->dato.nombre << " - " << raiz->dato.cargo << "\n";
        return;
    }
    mostrarHojas(raiz->izquierdo);
    mostrarHojas(raiz->derecho);
}

//Mostrar raíz 
void mostrarRaiz(Nodo* raiz) {
    if (raiz == nullptr) {
        cout << "  El árbol está vacío.\n";
    } else {
        cout << "  Raíz → [" << raiz->dato.codigo << "] "
             << raiz->dato.nombre << " - " << raiz->dato.cargo << "\n";
    }
}

//Menu
void mostrarMenu() {
    cout << "     BST - GESTIÓN DE EMPLEADOS       \n";
    cout << "  1. Insertar empleado                \n";
    cout << "  2. Buscar empleado por código       \n";
    cout << "  3. Recorrido Inorden                \n";
    cout << "  4. Recorrido Preorden               \n";
    cout << "  5. Recorrido Postorden              \n";
    cout << "  6. Mostrar raíz                     \n";
    cout << "  7. Calcular altura del árbol        \n";
    cout << "  8. Mostrar nodos hoja               \n";
    cout << "  0. Salir                            \n";
    cout << "  Opción: ";
}

//Main
int main() {
    Nodo* raiz  = nullptr;   // árbol vacío al inicio
    int   opcion;

    //Datos de prueba cargados automáticamente 
    Empleado prueba[] = {
        {50, "Ana Torres",    "Gerente General"},
        {30, "Carlos Ruiz",   "Jefe de RRHH"},
        {70, "Laura Vega",    "Directora Financiera"},
        {20, "Marco Díaz",    "Analista"},
        {40, "Sofía León",    "Coordinadora"},
        {60, "Pedro Mora",    "Contador"},
        {80, "Elena Soto",    "Auditora"}
    };

    int total = sizeof(prueba) / sizeof(prueba[0]);
    cout << "\n✔ Cargando " << total << " empleados de prueba...\n";
    for (int i = 0; i < total; i++) {
        raiz = insertar(raiz, prueba[i]);
    }
    cout << "✔ Datos cargados correctamente.\n";

    //Ciclo del menú 
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();   // limpiar buffer del teclado

        if (opcion == 1) {
            // Insertar
            Empleado nuevo;
            cout << "\n  Código  : "; cin >> nuevo.codigo; cin.ignore();
            cout << "  Nombre  : "; getline(cin, nuevo.nombre);
            cout << "  Cargo   : "; getline(cin, nuevo.cargo);
            raiz = insertar(raiz, nuevo);
            cout << "✔ Empleado insertado.\n";

        } else if (opcion == 2) {
            // Buscar
            int cod;
            cout << "\n  Código a buscar: "; cin >> cod;
            Nodo* resultado = buscar(raiz, cod);
            if (resultado != nullptr) {
                cout << "\n✔ Empleado encontrado:\n";
                cout << "  Código : " << resultado->dato.codigo << "\n";
                cout << "  Nombre : " << resultado->dato.nombre << "\n";
                cout << "  Cargo  : " << resultado->dato.cargo  << "\n";
            } else {
                cout << "✘ No se encontró ningún empleado con código " << cod << ".\n";
            }

        } else if (opcion == 3) {
            cout << "\n── Inorden (orden ascendente por código) ──\n";
            inorden(raiz);

        } else if (opcion == 4) {
            cout << "\n── Preorden ──\n";
            preorden(raiz);

        } else if (opcion == 5) {
            cout << "\n── Postorden ──\n";
            postorden(raiz);

        } else if (opcion == 6) {
            cout << "\n── Raíz del árbol ──\n";
            mostrarRaiz(raiz);

        } else if (opcion == 7) {
            cout << "\n── Altura del árbol ──\n";
            cout << "  Altura: " << altura(raiz) << " nivel(es)\n";

        } else if (opcion == 8) {
            cout << "\n── Nodos hoja (sin hijos) ──\n";
            mostrarHojas(raiz);

        } else if (opcion != 0) {
            cout << "  Opción inválida. Intente de nuevo.\n";
        }

    } while (opcion != 0);

    cout << "\n¡Hasta luego!\n\n";
    return 0;
}