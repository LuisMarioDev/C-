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

    string getNombre() {
        return nombre;
    }

    Persona(string nombre, string direccion, int edad) {
        this->nombre = nombre;
        this->direccion = direccion;
        this->edad = edad;
        cout<< "Se creo una persona" << endl;
        cout<< "Nombre: " << nombre << endl;
        cout<< "Direccion: " << direccion << endl;
    }
}
;





int main() {
    Persona persona("Juan", "Calle 12", 26);
    //persona.setNombre("Juan");
    //cout<< persona.getNombre();
    return 0;
}


