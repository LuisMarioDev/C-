#include <fstream>
#include <iostream>

using namespace std;

int main() {
    fstream archivo("personal.dat", ios::out);
    char nombre[80];
    int codigo;
    double sueldo;

    if (!archivo)
        cout << "Error en la apertura del archivo";
    else {
        do {
            cout << "Escriba el codigo del empleado (0 para salir): ";
            cin >> codigo;
            if (codigo != 0) {
                cout << "Escriba el nombre: ";
                cin >> nombre;
                fflush(stdin);
                cout << "Escriba el sueldo: ";
                cin >> sueldo;
                archivo << codigo << " " << nombre << " " << sueldo << endl;
            }
        } while (codigo != 0);
        archivo.close();
    }

    return 0;
}
