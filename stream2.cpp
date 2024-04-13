#include <fstream>
#include <iostream>
#include <iomanip> // Para setw()

using namespace std;

int main() {
    int opcion;
    fstream archivo("datos.txt", ios::in | ios::out | ios::binary);

    if (!archivo) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    do {
        cout << "Menú de Opciones\n";
        cout << "1. Escribir\n";
        cout << "2. Leer\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                {
                    char nombre[80];
                    int codigo;
                    double sueldo;

                    cout << "Escriba el codigo del empleado (0 para salir): ";
                    cin >> codigo;
                    if (codigo != 0) {
                        cout << "Escriba el nombre: ";
                        cin >> nombre;
                        cout << "Escriba el sueldo: ";
                        cin >> sueldo;
                        archivo.write(reinterpret_cast<char*>(&codigo), sizeof(codigo));
                        archivo.write(nombre, 80);
                        archivo.write(reinterpret_cast<char*>(&sueldo), sizeof(sueldo));
                    }
                }
                break;
            case 2:
                {
                    archivo.seekg(0, ios::beg); // Colocar el puntero al inicio del archivo

                    int codigo;
                    char nombre[80];
                    double sueldo;

                    cout << left << setw(8) << "Codigo" << setw(20);
                    cout << "Nombre" << setw(10) << "Sueldo" << endl;

                    while (archivo.read(reinterpret_cast<char*>(&codigo), sizeof(codigo))) {
                        archivo.read(nombre, 80);
                        archivo.read(reinterpret_cast<char*>(&sueldo), sizeof(sueldo));

                        cout << left << setw(8) << codigo << setw(20);
                        cout << nombre << setw(10) << sueldo << endl;
                    }
                }
                break;
            case 3:
                cout << "Cerrando programa" << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
        }

    } while (opcion != 3);

    archivo.close();

    return 0;
}
