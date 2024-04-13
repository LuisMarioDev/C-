#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int opcion;

    do {
        cout << "Menú de Stream\n";
        cout << "1. Escribir\n";
        cout << "2. Leer\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                {
                    string texto;
                    cout << "Ingrese el texto a escribir: ";
                    cin.ignore(); // Limpiar el buffer de entrada
                    getline(cin, texto);

                    ofstream archivoSalida("datos.txt");
                    if (archivoSalida.is_open()) {
                        archivoSalida << texto << endl;
                        archivoSalida.close();
                        cout << "Texto escrito en el archivo 'datos.txt'" << endl;
                    } else {
                        cout << "No se pudo abrir el archivo para escritura." << endl;
                    }
                }
                break;
            case 2:
                {
                    ifstream archivoEntrada("datos.txt");
                    if (archivoEntrada.is_open()) {
                        string linea;
                        cout << "Leyendo texto del archivo 'datos.txt':" << endl;
                        while (getline(archivoEntrada, linea)) {
                            cout << linea << endl;
                        }
                        archivoEntrada.close();
                    } else {
                        cout << "No se pudo abrir el archivo para lectura." << endl;
                    }
                }
                break;
            case 3:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
        }

    } while(opcion != 3);

    return 0;
}
