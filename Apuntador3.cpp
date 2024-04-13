#include <iostream>
#include <iomanip>

using namespace std;

void altas();
void desplegarLista();
void borrarUltimo();
void borrarPrimero();
void borrarDato();
void insertarinicio();
void insertarNumero();

struct nodo {
    int num;
    nodo *sig;
    nodo *ant;
};

nodo *inicio = NULL;
nodo *fin = NULL;
nodo *nuevo = NULL;
nodo *temp = NULL;
nodo *exist = NULL;
nodo *nuevoNum = NULL;
nodo *siguiente = NULL;
nodo *anterior = NULL;

int main() {
    int opcion;
    do {
        cout << "Menu: \n"
             << "1. Altas. \n"
             << "2. Desplegar lista. \n"
             << "3. Borrar ultimo. \n"
             << "4. Borrar primero. \n"
             << "5. Borrar dato. \n"
             << "6. Insertar inicio \n"
             << "7. Insertar numero antes de otro numero \n"
             << "0. Salir \n"
             << endl
             << "Opcion: \n";
        cin >> opcion;
        switch (opcion) {
            case 1:
                altas();
                break;
            case 2:
                desplegarLista();
                break;
            case 3:
                borrarUltimo();
                break;
            case 4:
                borrarPrimero();
                break;
            case 5:
                borrarDato();
                break;
            case 6:
                insertarinicio();
                break;
            case 7:
                insertarNumero();
                break;
        }
    } while (opcion != 0);
    return 0;
}

void altas() {
    int dato = 0;
    cout << "Ingrese los datos o presione 0 para regresar: ";
    cin >> dato;

    while (dato != 0) {
        nuevo = new nodo;
        nuevo->num = dato;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
        if (inicio == NULL) {
            inicio = nuevo;
            fin = nuevo;
        } else {
            fin->sig = nuevo;
            nuevo->ant = fin;
            fin = nuevo;
        }
        cin >> dato;
    }
}

void borrarDato() {
    if (inicio == NULL) {
        cout << "No hay datos en la lista" << endl;
        return;
    }

    int dato;
    cout << "\n Ingrese el dato a borrar: ";
    cin >> dato;

    anterior = NULL;
    temp = inicio;

    while (temp != NULL) {
        siguiente = temp->sig;
        if (temp->num == dato) {
            if (temp == inicio) {
                inicio = temp->sig;
            } else {
                anterior->sig = temp->sig;
            }

            if (temp == fin) {
                fin = anterior;
            } else {
                siguiente->ant = anterior;
            }

            delete temp;
            return;
        }
        anterior = temp;
        temp = siguiente;
    }

    cout << "No hay datos en la lista" << endl;
}

void insertarinicio() {
    int dato;
    cout << "\n Ingrese el dato a insertar al inicio: ";
    cin >> dato;

    nuevo = new nodo;
    nuevo->num = dato;
    nuevo->sig = inicio;
    nuevo->ant = NULL;
    inicio = nuevo;
    temp = inicio;

    if (temp == NULL) {
        cout << "No hay datos en la lista" << endl;
    }
}

void insertarNumero() {
    int dato, dato2;
    cout << "Ingrese el dato a insertar: ";
    cin >> dato;
    cout << "Ingrese antes de qué numero se insertará: ";
    cin >> dato2;

    if (inicio == NULL) {
        cout << "No hay datos en la lista" << endl;
        return;
    }

    nuevo = new nodo;
    nuevo->num = dato;

    temp = inicio;
    exist = inicio;

    while (temp != NULL) {
        if (temp->num == dato2) {
            nuevo->sig = temp;
            nuevo->ant = temp->ant;
            temp->ant = nuevo;
            if (temp == inicio) {
                inicio = nuevo;
            } else {
                while (exist->sig != temp) {
                    exist = exist->sig;
                }
                exist->sig = nuevo;
            }
            return;
        }
        temp = temp->sig;
    }

    cout << "No hay datos en la lista" << endl;
    delete nuevo;
}

void desplegarLista() {
    if (inicio == NULL) {
        cout << "No hay datos en la lista" << endl;
        return;
    }

    temp = inicio;
    while (temp != NULL) {
        cout << temp->num << " -> ";
        temp = temp->sig;
    }
    cout << endl;
}

void borrarPrimero() {
    if (inicio == NULL) {
        cout << "No hay datos en la lista" << endl;
        return;
    }

    temp = inicio;
    inicio = inicio->sig;
    if (inicio != NULL) {
        inicio->ant = NULL;
    }
    delete temp;
    temp = NULL;
}

void borrarUltimo() {
    if (inicio == NULL) {
        cout << "No hay datos en la lista" << endl;
        return;
    }

    temp = fin;
    fin = fin->ant;
    if (fin != NULL) {
        fin->sig = NULL; 
    }
    delete temp;
    temp = NULL;
}
