#include <iostream>

using namespace std;

int main() {
    int x = 25;
    cout << "La dirección de x es: \n " << &x;

    int i = 5;
    int *p, *q;
    p = &i;
    q = p;

    int k = 17, y;
    int *u;
    u = &k;
    cout << "\nEl valor de x es: " << *p << endl; // Imprime 5, no 17
    y = *u + 3; // A 'y' se le asigna 20
    cout << y << endl;

    struct Data {
        char nombre[20];
        int edad;
    };

    Data d;

    Data *pd = &d;
    (*pd).edad = 23; // Acceso al campo 'edad' utilizando el operador '.'
    pd->edad = 23;   // Acceso al campo 'edad' utilizando el operador '->'

    int *p1;
    float *p2;
    int z;
    p1 = &x; // Esto es válido
    //p2 = &x; // Esto no es válido (el compilador genera un error)

    float *p;
    // Se debería asignar memoria antes de usar un puntero
    // p = new float; // Descomenta esta línea si es necesario
    // cout << "El valor apuntado por p es: " << *p << endl; // Incorrecto
    // *p = 3.5; // Incorrecto
    // delete p; // Descomenta esta línea si es necesario

    int v = 40;
    p = &v;
    y = *p; // Correcto
    *p = 23; // Correcto

    // Las siguientes líneas son incorrectas ya que p apunta a un entero, no a un char
    // y = *p; // Incorrecto
    // *p = 25; // Incorrecto

    char c = 'z';
    char *pc = &c;
    char **ppc = &pc;
    char ***pppc = &ppc;
    ***pppc = 'm'; // Cambia el valor de c a 'm'

    return 0;
}
