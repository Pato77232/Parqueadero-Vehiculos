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
