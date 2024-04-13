#include <iostream>
#include <iomanip>
#include <istream>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    string direccion;
    int edad;
};

Persona directorio[100];

int main() {
    string nombre_temp;
    int i = 0;

    do {
        cout << "Nombre: ";
        getline(cin, nombre_temp);
        if (nombre_temp == "*")
            break;
        directorio[i].nombre = nombre_temp;

        cout << "Dirección: ";
        getline(cin, directorio[i].direccion);

        cout << "Edad: ";
        cin >> directorio[i].edad;
        cin.ignore();  // Consumir el salto de línea pendiente después de leer la edad

        i++;
    } while (true);

    // Mostrar todos los registros ingresados
    for (int j = 0; j < i; j++) {
        cout << directorio[j].nombre << setw(10) << directorio[j].direccion << setw(5) << directorio[j].edad << endl;
    }

    return 0;
}
