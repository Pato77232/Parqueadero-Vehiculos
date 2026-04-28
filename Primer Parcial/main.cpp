#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura Vehiculo
struct Vehiculo {
    int id;
    string placa;
    string tipo;
    string propietario;
    string horaEntrada;

    // Mostrar datos del vehículo
    void mostrar() {
        cout << "ID: " << id << " | Placa: " << placa << " | Tipo: " << tipo
             << " | Propietario: " << propietario << " | Entrada: " << horaEntrada << endl;
    }
};
//La estructura vehiculo guarda 5 datos principales para identificación del vehiculo como id o placa
// Por otra parte el vector Vehiculo dentro de la clase parqueadero guarda estas estructuras para sus respectivas operaciones
// Clase Parqueadero
class Parqueadero {
private:
    vector<Vehiculo> vehiculos;
    int nextId;
    int capacidad;

public:
    // Constructor con algunos registros
    Parqueadero() {
        nextId = 11;
        capacidad = 80;
        vehiculos.push_back({1,  "ABC-1234", "Auto",      "Carlos Perez",   "08:00"});
        vehiculos.push_back({2,  "XYZ-5678", "Moto",      "Maria Lopez",    "08:15"});
        vehiculos.push_back({3,  "LMN-9012", "Camioneta", "Juan Rodriguez", "08:30"});
        vehiculos.push_back({4,  "PQR-3456", "Auto",      "Ana Martinez",   "09:00"});
        vehiculos.push_back({5,  "TUV-7890", "Auto",      "Pedro Gomez",    "09:20"});
        vehiculos.push_back({6,  "GHI-2345", "Moto",      "Lucia Torres",   "09:45"});
        vehiculos.push_back({7,  "JKL-6789", "Camioneta", "Roberto Diaz",   "10:00"});
        vehiculos.push_back({8,  "MNO-0123", "Auto",      "Sofia Herrera",  "10:30"});
        vehiculos.push_back({9,  "STU-4567", "Bus",       "Diego Vargas",   "11:00"});
        vehiculos.push_back({10, "VWX-8901", "Auto",      "Valentina Cruz", "11:15"});
    }

    // Registrar vehiculo
    void registrar() {
        if (vehiculos.size() >= capacidad) {
            cout << "Parqueadero lleno. Capacidad maxima: " << capacidad << endl;
            return;
        }
        Vehiculo v;
        v.id = nextId++;
        cout << "Registrar Nuevo Vehiculo" << endl;
        cout << "Placa: ";        cin >> v.placa;
        cout << "Tipo: ";         cin >> v.tipo;
        cout << "Propietario: ";  cin >> v.propietario;
        cout << "Hora entrada: "; cin >> v.horaEntrada;

        vehiculos.push_back(v);
        cout << "Vehiculo registrado correctamente." << endl;
    }

    // Listar todos los vehiculos
    void mostrarTodos() {
        if (vehiculos.empty()) {
            cout << "No hay vehiculos registrados." << endl;
            return;
        }
        for (int i = 0; i < vehiculos.size(); i++) {
            vehiculos[i].mostrar();
        }
    }

    // Busqueda por Placa
    void buscarPorPlaca() {
        string placa;
        cout << "Ingrese la placa: "; cin >> placa;

        bool encontrado = false;
        for (int i = 0; i < vehiculos.size(); i++) {
            if (vehiculos[i].placa == placa) {
                vehiculos[i].mostrar();
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "No se encontro ningun vehiculo con esa placa." << endl;
        }
    }

    // Modificar registro
    void modificar() {
        int id;
        cout << "Ingrese el ID a modificar: "; cin >> id;

        for (int i = 0; i < vehiculos.size(); i++) {
            if (vehiculos[i].id == id) {
                cout << "Nueva placa: ";        cin >> vehiculos[i].placa;
                cout << "Nuevo tipo: ";         cin >> vehiculos[i].tipo;
                cout << "Nuevo propietario: ";  cin >> vehiculos[i].propietario;
                cout << "Nueva hora entrada: "; cin >> vehiculos[i].horaEntrada;
                cout << "Registro modificado correctamente." << endl;
                return;
            }
        }
        cout << "No se encontro un vehiculo con ID: " << id << endl;
    }

    // Eliminar un registro
    void eliminar() {
        int id;
        cout << "Ingrese el ID a eliminar: "; cin >> id;

        for (int i = 0; i < vehiculos.size(); i++) {
            if (vehiculos[i].id == id) {
                vehiculos.erase(vehiculos.begin() + i);
                cout << "Vehiculo eliminado correctamente." << endl;
                return;
            }
        }
        cout << "No se encontro un vehiculo con ID: " << id << endl;
    }

    // Reporte final
    void reporte() {
        cout << "Espacio en parqueadero: " << capacidad << endl;
        cout << "Total de vehiculos: " << vehiculos.size() << endl;

        int autos = 0, motos = 0, otros = 0;
        for (int i = 0; i < vehiculos.size(); i++) {
            if (vehiculos[i].tipo == "Auto")      autos++;
            else if (vehiculos[i].tipo == "Moto") motos++;
            else                                  otros++;
        }
        cout << "Autos: " << autos << endl;
        cout << "Motos: " << motos << endl;
        cout << "Otros: " << otros << endl;
    }
};

// Main con menu
int main() {
    Parqueadero p;
    int opcion;

    do {
        cout << "---------------------------------" << endl;
        cout << "  Sistema de Parqueadero " << endl;
        cout << "1. Registrar vehiculo" << endl;
        cout << "2. Mostrar todos" << endl;
        cout << "3. Buscar por placa" << endl;
        cout << "4. Modificar registro" << endl;
        cout << "5. Eliminar registro" << endl;
        cout << "6. Reporte final" << endl;
        cout << "7. Salir" << endl;
        cout << "Opcion: "; cin >> opcion;

        switch (opcion) {
            case 1: p.registrar();       break;
            case 2: p.mostrarTodos();    break;
            case 3: p.buscarPorPlaca();  break;
            case 4: p.modificar();       break;
            case 5: p.eliminar();        break;
            case 6: p.reporte();         break;
            case 7: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion no valida." << endl;
        }

    } while (opcion != 7);

    return 0;
}
private:
    vector<Vehiculo> vehiculos;
    int nextId;
    int capacidad;
