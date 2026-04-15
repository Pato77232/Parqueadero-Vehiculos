#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <limits>
using namespace std;

struct Solicitud {
    string cedula;
    string nombre;
    string motivo;

    Solicitud() {}
    Solicitud(string ced, string nom, string mot)
        : cedula(ced), nombre(nom), motivo(mot) {}

    void mostrar(int num = 0) const {
        if (num > 0) cout << "  " << num << ". ";
        else         cout << "     ";
        cout << "[" << cedula << "] " << nombre
             << " - " << motivo << "\n";
    }
};

class SistemaSolicitudes {
private:
    queue<Solicitud>  pendientes;   // FIFO  — orden de llegada
    list<Solicitud>   atendidos;    // historial completo
    stack<Solicitud>  recientes;    // LIFO  — última atendida al tope

public:
    void agregarSolicitud(const Solicitud& s) {
        pendientes.push(s);
        cout << "  [OK] Solicitud de \"" << s.nombre
             << "\" agregada a la cola.\n";
    }

    void atenderSolicitud() {
        if (pendientes.empty()) {
            cout << "  [!] No hay solicitudes pendientes.\n";
            return;
        }

        Solicitud actual = pendientes.front();  // ver frente
        pendientes.pop();                        // sacar de cola

        atendidos.push_back(actual);             // registrar en historial
        recientes.push(actual);                  // apilar como reciente

        cout << "  [OK] Solicitud atendida:\n";
        actual.mostrar();
    }

    void verProxima() const {
        if (pendientes.empty()) {
            cout << "  [!] No hay solicitudes pendientes.\n";
            return;
        }
        cout << "  Proxima en ser atendida:\n";
        pendientes.front().mostrar();
    }

    void verMasReciente() const {
        if (recientes.empty()) {
            cout << "  [!] Aun no se ha atendido ninguna solicitud.\n";
            return;
        }
        cout << "  Ultima solicitud atendida:\n";
        recientes.top().mostrar();
    }

    void listarPendientes() const {
        if (pendientes.empty()) {
            cout << "  (No hay solicitudes pendientes)\n";
            return;
        }
        cout << "  --- Pendientes (" << pendientes.size() << ") ---\n";
        queue<Solicitud> copia = pendientes;   // copia para no modificar
        int num = 1;
        while (!copia.empty()) {
            copia.front().mostrar(num++);
            copia.pop();
        }
    }

    void listarAtendidos() const {
        if (atendidos.empty()) {
            cout << "  (Aun no se ha atendido ninguna solicitud)\n";
            return;
        }
        cout << "  --- Historial de atendidos (" << atendidos.size() << ") ---\n";
        int num = 1;
        for (const Solicitud& s : atendidos) {
            s.mostrar(num++);
        }
    }

    void listarRecientes() const {
        if (recientes.empty()) {
            cout << "  (Aun no se ha atendido ninguna solicitud)\n";
            return;
        }
        cout << "  --- Recientes (" << recientes.size()
             << ", mas reciente primero) ---\n";
        stack<Solicitud> copia = recientes;
        int num = 1;
        while (!copia.empty()) {
            copia.top().mostrar(num++);
            copia.pop();
        }
    }

    void mostrarEstado() const {
        cout << "  Pendientes : " << pendientes.size() << "\n";
        cout << "  Atendidos  : " << atendidos.size()  << "\n";
        cout << "  Recientes  : " << recientes.size()  << "\n";
    }
};

void limpiarBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int leerEntero(const string& msg, int minV, int maxV) {
    int v;
    while (true) {
        cout << msg;
        if (cin >> v && v >= minV && v <= maxV) { limpiarBuffer(); return v; }
        cout << "  Opcion invalida. Use " << minV << "-" << maxV << ".\n";
        cin.clear(); limpiarBuffer();
    }
}

string leerCadena(const string& msg) {
    string s; cout << msg; getline(cin, s); return s;
}

void mostrarMenu() {
    cout << "\n==========================================\n";
    cout << "       SISTEMA DE SOLICITUDES             \n";
    cout << "==========================================\n";
    cout << "  1. Agregar solicitud   (enqueue)\n";
    cout << "  2. Atender solicitud   (dequeue + push)\n";
    cout << "  3. Ver proxima         (front)\n";
    cout << "  4. Ver mas reciente    (top del stack)\n";
    cout << "  5. Listar pendientes   (queue)\n";
    cout << "  6. Listar atendidos    (list / historial)\n";
    cout << "  7. Listar recientes    (stack)\n";
    cout << "  8. Estado general\n";
    cout << "  9. Salir\n";
    cout << "==========================================\n";
}

int main() {
    SistemaSolicitudes sistema;

    int opcion;
    do {
        mostrarMenu();
        opcion = leerEntero("  Opcion (1-9): ", 1, 9);

        switch (opcion) {

            case 1: {
                string ced = leerCadena("  Cedula  : ");
                string nom = leerCadena("  Nombre  : ");
                string mot = leerCadena("  Motivo  : ");
                sistema.agregarSolicitud(Solicitud(ced, nom, mot));
                break;
            }

            case 2:
                sistema.atenderSolicitud();
                break;

            case 3:
                sistema.verProxima();
                break;

            case 4:
                sistema.verMasReciente();
                break;

            case 5:
                sistema.listarPendientes();
                break;

            case 6:
                sistema.listarAtendidos();
                break;

            case 7:
                sistema.listarRecientes();
                break;

            case 8:
                sistema.mostrarEstado();
                break;

            case 9:
                cout << "\n  Hasta luego.\n";
                break;
        }

    } while (opcion != 9);

    return 0;
}