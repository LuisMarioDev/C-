#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



class Persona {
    private:
    string nombre;
    string direccion;
    int edad;

    public:
    void setNombre(string nombre) {
        this->nombre = nombre;
    }
}

Persona directorio[100];


int main() {
    cout << "Nombre: ";
    getline(cin,directorio[0].nombre);

    cout << "Dirección: ";
    getline(cin, directorio[0].direccion);

    cout << "Edad: ";
    cin>> directorio[0].edad;

    cout<<directorio[0].nombre<<setw(10)<<directorio[0].direccion<<setw(5)<<directorio[0].edad<<endl;
    return 0;
}


