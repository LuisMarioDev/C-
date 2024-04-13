/* Tarea: Crear el código de una función que se llame agregar nodo,
donde se puedan agregar la cantidad de nodos que quieras.
El valor de salida sería el 0 o -1.
Los apuntadores fin, y nuevo se deben de mover*/

/*
Tarea:
1. Borrar primero
2. Borrar dato
3. Insertar inicio
4. Insertar antes de algún numero
y el de salir
*/

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

nodo *inicio=NULL;
nodo *fin=NULL;
nodo *nuevo=NULL;
nodo *temp=NULL;
nodo *exist=NULL;
nodo *nuevoNum=NULL;
nodo *siguiente=NULL;
nodo *anterior=NULL;


int main(){
    int opcion;
    do{
        cout<<"Menu: \n"
            <<"1. Altas. \n"
            <<"2. Desplegar lista. \n"
            <<"3. Borrar ultimo. \n"
            <<"4. Borrar primero. \n"
            <<"5. Borrar dato. \n"
            <<"6. Insertar inicio \n"
            <<"7. Insertar numero antes de otro numero \n"
            <<"0. Salir \n" <<endl
            <<"Opcion: \n";
        cin>>opcion;
        switch(opcion){
            case 1: altas();
            break;
            case 2: desplegarLista();
            break;
            case 3: borrarUltimo();
            break;
            case 4: borrarPrimero();
            break;
            case 5: borrarDato();
            break;
            case 6: insertarinicio();
            break;
            case 7: insertarNumero();
            break;
        }
    } while(opcion!=0);
    return 0;
}

void altas(){
    int temp_key = 0;
    int num_temp=0;
    cout<<"Ingrese los datos o presione 0 para regresar \n";
    do{
        cout<<"Dato: ";
        cin>>temp_key;
        if(temp_key==0)
            break;
        nuevo=new nodo;
        nuevo->num=temp_key;
        nuevo->sig=NULL;
        if(inicio==NULL){
            inicio=nuevo;
            fin=nuevo;
        }
        fin->sig=nuevo;
        fin=nuevo;
    }while(true);
}

void borrarDato(){
    if (inicio == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }

    int dato;
    cout << "\nIngrese el dato a borrar: ";
    cin >> dato;

    nodo *anterior = NULL;
    temp = inicio;

    while (temp != NULL) {
        if (temp->num == dato) {
            if (temp == inicio) {
                inicio = temp->sig;
            } else {
                anterior->sig = temp->sig;
            }

            if (temp == fin) {
                fin = anterior;
            }

            delete temp;
            cout << "Se ha eliminado el dato " << dato << " de la lista." << endl;
            return;
        }
        anterior = temp;
        temp = temp->sig;
    }

    cout << "El dato " << dato << " no se encontró en la lista." << endl;
}


void insertarinicio(){
    int dato;
    cout<<"\n Ingrese el dato a insertar al inicio: ";
    cin>>dato;

    nuevo=new nodo;
    nuevo->num=dato;
    nuevo->sig=inicio;
    inicio=nuevo;
    temp=inicio;
}

void insertarNumero(){
    int dato, dato2;
    cout<<"Ingrese el dato a insertar: ";
    cin>>dato;
    cout<<"Ingrese antes de que numero se insertara: ";
    cin>>dato2;

    nuevo = new nodo;
    nuevo->num = dato;

    temp = inicio;
    exist = inicio;

    while (temp != NULL) {
        if (temp->num == dato2) {
            nuevo->sig = temp;
            if (temp == inicio) {
                inicio = nuevo;
            } else {
                while (exist->sig != temp) {
                    exist = exist->sig;
                }
                exist->sig = nuevo;
            }
            break;
        }
        temp = temp->sig;
    }

    if (temp == NULL) {
        cout << "El numero antes del cual desea insertar no existe en la lista." << endl;
        delete nuevo;
    }
}

void desplegarLista(){
    temp=inicio;
    while(temp!=NULL){
        cout<<temp->num<<" --> ";
        temp=temp->sig;
    }
    cout<<endl;
}

void borrarPrimero(){
    temp=inicio;
    inicio=inicio->sig;
    delete temp;
    temp=NULL;
    }

void borrarUltimo(){
    temp=inicio;
    while(temp->sig!=fin){
        temp=temp->sig;
        if(temp->sig==fin){
            delete temp->sig;
            temp->sig=NULL;
            fin=temp;
            break;
        }
}
    /*
    while(temp->sig!=fin)
    temp=temp->sig;
    fin=temp;
    fin->sig=NULL;
    delete (nuevo);
    */
}

