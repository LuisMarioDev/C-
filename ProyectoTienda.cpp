#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

// Prototipos o Funciones
void Administrador();
void Altas();
void Mostrar();
int Buscar(string);
void Usuarios();
void CopyArrStruc();
void CorteDeCaja();
void Ventas();
void Bajas();
void Consultas();

// Variables globales
// Listas de inventario
int id[100] = {2, 4, 1, 3, 5};
string productos[100] = {"leche", "pan", "agua", "huevos", "refrescos"};
float pc[100] = {12.35, 5.5, 13.39, 22.4, 10.99};
float pv[100] = {15.5, 7.95, 18.55, 30.39, 14.75};
int existencias[100] = {16, 18, 12, 20, 30};
int nr[100] = {5, 6, 4, 7, 8};
bool st[100] = {1, 1, 1, 1, 1};
int totalprod = 5; // Almacena el total de productos en inventario

// Estructura de variables que almacena los datos del inventario
struct prod {
    int id;
    string productos;
    float pc;
    float pv;
    int existencias;
    int nr;
    bool st;

    prod *ant;
    prod *sig;
};

prod *inicio;
prod *nuevo;
prod *actual;
prod *fin;

prod inventario[100];

// Almacena usuarios y contraseñas para autentificación
string vendedor1_username = "vendedor1";
string vendedor1_password = "pass1";
string vendedor2_username = "vendedor2";
string vendedor2_password = "pass2";
string current_user = "";

int main() { // Función principal
    int mainop;
    CopyArrStruc();
    do {
        cout << "Menú Principal" << endl;
        cout << "1. Administrador" << endl;
        cout << "2. Ventas" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese opción: ";
        cin >> mainop;
        switch (mainop) { // Ciclo para Menú Principal
            case 1:
                Administrador();
                break;
            case 2:
                cout << "Entraste a Ventas" << endl;
                Ventas();
                /*Usuarios(); // Solicita acceso con usuario y contraseña
                if (!current_user.empty()) { // Revisa que la información de inicio de sesión no esté vacía
                    Ventas(); // Inicia función ventas
                }*/
                break;
            case 3:
                cout << "Cerrando sistema" << endl;
                break;
            default:
                cout << "Opción inválida, debe ser un valor entre 1 y 3" << endl;
        }
    } while (mainop != 3); // Evalúa que la respuesta no sea 3 para continuar con el ciclo. Al ser 3 se sale.
    return 0;
}

void Administrador() { // Función de Administrador
    system("cls"); // Limpiar pantalla
    int adminop; // Variable local
    string usuario = "admin", clave = "123";
    cout << "Ingrese usuario: ";
    cin >> usuario;
    cout << "Ingrese clave: ";
    cin >> clave;

    if (usuario == "admin" && clave == "123") {
        cout << "Bienvenido Administrador" << endl;
        system("cls");
    } else {
        cout << "Usuario o clave incorrectos" << endl;
        system("pause");
        system("cls");
        return;
    }
    do {
        cout << "Menú Administrador" << endl;
        cout << "1. Altas" << endl;
        cout << "2. Bajas" << endl;
        cout << "3. Consultas" << endl;
        cout << "4. Modificaciones" << endl;
        cout << "5. Mostrar inventario" << endl;
        cout << "6. Administración de cuentas de usuario" << endl;
        cout << "7. Corte de caja general" << endl;
        cout << "8. Regresar al menú anterior" << endl;
        cout << "Ingrese opción o presione 0 para salir: ";
        cin >> adminop;
        switch (adminop) { // Ciclo para Menú de Administrador
            case 1:
                cout << "Entraste a Altas \n";
                Altas(); // Llama a la función de Altas
                break;
            case 2:
                cout << "Entraste a Bajas" << endl;
                Bajas(); // Bajas(); // Llama a la función de Bajas
                break;
            case 3:
                cout << "Entraste a Consultas" << endl;
                Consultas(); // Consultas(); // Llama a la función de Consultas
                break;
            case 4:
                cout << "Entraste a Modificaciones" << endl; // Modificaciones(); // Llama a la función de Modificaciones
                break;
            case 5:
                Mostrar(); // Llama a la función de Mostrar inventario
                break;
            case 6:
                cout << "Entraste a Administración de cuentas de usuario" << endl;
                break;
            case 7:
                CorteDeCaja(); // Llama a la función de CorteDeCaja
                break;
            case 8:
                cout << "Regresaste a Menú anterior" << endl;
                break;
            case 0:
                cout << "Cerrando sistema" << endl;
                break;
            default:
                cout << "Opción incorrecta" << endl;
        }
    } while (adminop != 0);
}

void Consultas(){
    int opcion, i=0, k;
    string prod;
    cout << "1. Consultar por ID" << endl;
    cout << "2. Consultar por producto" << endl;
    cout << "3. Consultar por precio de compra" << endl;
    cout << "4. Consultar por precio de venta" << endl;
    cout << "5. Consultar por existencias" << endl;
    cout << "6. Consultar por nivel de reorden" << endl;
    cout << "7. Consultar por estado" << endl;
    cout << "8. Regresar al menú anterior" << endl;
    cout << "Ingrese opción: ";
    cin >> opcion;

    switch (opcion) {
        case 1: {
            std::cout << "Entraste a Consultar por ID" << std::endl;
            std::cout << "Favor de ingresar el ID del producto a consultar" << std::endl;
            std::cin >> k;
            while (i < 100 && id[i] != k) {
                i++;
            }
            if (i < 100) {
                std::cout << std::setw(3) << "ID" << std::setw(15) << "Producto" << std::setw(6) << "PC" << std::setw(6)
                          << "PV" << std::setw(13) << "Existencias" << std::setw(9) << "Reorden" << std::setw(3) << "ST"
                          << std::endl;
                std::cout << std::setw(3) << id[i] << std::setw(15) << productos[i] << std::setw(6) << pc[i] << std::setw(6)
                          << pv[i] << std::setw(13) << existencias[i] << std::setw(9) << nr[i] << std::setw(3) << st[i]
                          << std::endl;
            } else {
                std::cout << "Producto no encontrado" << std::endl;
            }
            break;
        }
        case 2: {
            std::cout << "Entraste a Consultar por producto" << std::endl;
            std::cout << "Favor de ingresar el producto a consultar" << std::endl;
            std::string prod;
            std::cin >> prod;
            while (i < 100 && productos[i] != prod) {
                i++;
            }
            if (i < 100) {
                std::cout << std::setw(3) << "ID" << std::setw(15) << "Producto" << std::setw(6) << "PC" << std::setw(6)
                          << "PV" << std::setw(13) << "Existencias" << std::setw(9) << "Reorden" << std::setw(3) << "ST"
                          << std::endl;
                std::cout << std::setw(3) << id[i] << std::setw(15) << productos[i] << std::setw(6) << pc[i] << std::setw(6)
                          << pv[i] << std::setw(13) << existencias[i] << std::setw(9) << nr[i] << std::setw(3) << st[i]
                          << std::endl;
            } else {
                std::cout << "Producto no encontrado" << std::endl;
            }
            break;
        }
        case 3:
            std::cout << "Entraste a Consultar por precio de compra" << std::endl;
            std::cout << "Favor de ingresar el precio de compra a consultar" << std::endl;
            std::cin >> k;
            while(i < 100 && pc[i] != k){
                i++;
            }
            if(i<100){
              std::cout << std::setw(3) << "ID" << std::setw(15) << "Producto" << std::setw(6) << "PC" << std::setw(6)
                          << "PV" << std::setw(13) << "Existencias" << std::setw(9) << "Reorden" << std::setw(3) << "ST"
                          << std::endl;
                std::cout << std::setw(3) << id[i] << std::setw(15) << productos[i] << std::setw(6) << pc[i] << std::setw(6)
                          << pv[i] << std::setw(13) << existencias[i] << std::setw(9) << nr[i] << std::setw(3) << st[i]
                          << std::endl;
            } else {
                std::cout << "Producto no encontrado" << std::endl;
            }
            break;
        case 4:
            std::cout << "Entraste a Consultar por precio de venta" << std::endl;
            break;
        case 5:
            std::cout << "Entraste a Consultar por existencias" << std::endl;
            break;
        case 6:
            std::cout << "Entraste a Consultar por nivel de reorden" << std::endl;
            break;
        case 7:
            std::cout << "Entraste a Consultar por estado" << std::endl;
            break;
        case 8:
            break;
        default:
            std::cout << "Opción no válida" << std::endl;
            break;
    }
}

void Altas() { // Función Alta de productos
    int i = totalprod; // Iguala el valor de i al del total de productos
    string prod_temp; // Variable temporal para productos
    int indice;
    do { // Ciclo para generar alta de varios productos
        cout << "Productos: ";
        cin >> prod_temp;
        if (prod_temp == "*") // Se declara * como tecla para salir del ciclo cuando ya no se quieren generar altas
            break;
        inventario[i].productos = prod_temp;
        indice = Buscar(prod_temp); // Función de buscar producto
        if (indice == -1) { // Evalúa que los productos existan
            cout << "ID: ";
            cin >> inventario[i].id;
            do { // Ciclo para comparar que el pv sea mayor que el pc
                cout << "Precio de compra: ";
                cin >> inventario[i].pc;
                cout << "Precio de ventas: ";
                cin >> inventario[i].pv;
                if (inventario[i].pv <= inventario[i].pc)
                    cout << "Error. El precio de venta no puede ser igual o menor que el precio de compra" << endl;
            } while (inventario[i].pv <= inventario[i].pc);
            do { // Ciclo para comparar que las existencias sean mayores que el nivel de reorden
                cout << "Existencias: ";
                cin >> inventario[i].existencias;
                cout << "Nivel de reorden: ";
                cin >> inventario[i].nr;
                if (inventario[i].existencias <= inventario[i].nr) // Evalúa que las existencias sean menores al nivel de reorden
                    cout << "Error. Las existencias no pueden ser iguales o menores que el nivel de reorden" << endl;
            } while (inventario[i].existencias <= inventario[i].nr);
        } else if (indice != 1 && st[indice] == false) { // Evalúa que el producto exista, pero tenga estatus 0
            cout << "El producto existe pero se encuentra dado de baja" << endl;
            cout << "¿Quieres volver a darlo de alta? 1 Sí / 0 No" << endl;
            cin >> st[indice];
        } else {
            cout << "El producto no se puede dar de alta porque ya existe" << endl;
        }
        inventario[i].st = 1; // Variable para validar la alta de producto con estatus disponible
        i++; // Se agrega para sumar consecuentemente el valor de la variable
    } while (true); // Se valida prod temp para ciclar, mientras no se teclee * el proceso seguirá ciclado
    totalprod = i; // Se hace para que la variable temporal adquiera el último valor de i y no se sobre escriba el producto
}

void Mostrar() { // Función de Mostrar
    int i, j, inv_req; // Variables locales
    char opc;
    prod aux;
    do {
        cout << "1. Mostrar por ID" << endl;
        cout << "2. Mostrar por Nombre del producto" << endl;
        cout << "3. Regresar al menú anterior" << endl;
        cout << "Ingrese opción: ";
        cin >> inv_req;
        switch (inv_req) {
            case 1: // Comparará valores de ID
                cout << "Presione A para ascendente o presione D para descendente";
                cin >> opc;
                switch (opc) {
                    case 'A':
                        for (i = 0; i < totalprod - 1; i++) { // Evalúa el valor de las variables
                            for (j = 0; j < totalprod - i - 1; j++) { // Comparación
                                if (inventario[j].id > inventario[j + 1].id) { // Intercambio de posiciones
                                    aux = inventario[j];
                                    inventario[j] = inventario[j + 1];
                                    inventario[j + 1] = aux;
                                }
                            }
                        }
                        break;
                    case 'D':
                        for (i = 0; i < totalprod - 1; i++) { // Evalúa el valor de las variables
                            for (j = 0; j < totalprod - i - 1; j++) { // Comparación
                                if (inventario[j].id < inventario[j + 1].id) { // Intercambio de posiciones
                                    aux = inventario[j];
                                    inventario[j] = inventario[j + 1];
                                    inventario[j + 1] = aux;
                                }
                            }
                        }
                        break;
                }
                break;
            case 2: // Comparará valores del nombre del producto
                cout << "Presione A para ascendente o presione D para descendente";
                cin >> opc;
                switch (opc) {
                    case 'A':
                        for (i = 0; i < totalprod - 1; i++) { // Evalúa el valor de las variables
                            for (j = 0; j < totalprod - i - 1; j++) { // Comparación
                                if (inventario[j].productos > inventario[j + 1].productos) { // Intercambio de posiciones
                                    aux = inventario[j];
                                    inventario[j] = inventario[j + 1];
                                    inventario[j + 1] = aux;
                                }
                            }
                        }
                        break;
                    case 'D':
                        for (i = 0; i < totalprod - 1; i++) { // Evalúa el valor de las variables
                            for (j = 0; j < totalprod - i - 1; j++) { // Comparación
                                if (inventario[j].productos < inventario[j + 1].productos) { // Intercambio de posiciones
                                    aux = inventario[j];
                                    inventario[j] = inventario[j + 1];
                                    inventario[j + 1] = aux;
                                }
                            }
                        }
                        break;
                }
                break;
            case 3:
                cout << "Regresaste a menú anterior" << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
        cout << setw(10) << "ID" << setw(15) << "PRODUCTOS" << setw(10) << "PC" << setw(10) << "PV"
             << setw(20) << "EXISTENCIAS" << setw(10) << "NR" << setw(15) << "RESURTIR" << endl;
        for (i = 0; i < totalprod; i++) {
            if (inventario[i].st == 1) { // Evalúa que el producto esté en existencia
                string nr_ind = (inventario[i].existencias <= inventario[i].nr) ? "*" : ""; // Indicador para colocar * si está por debajo del NR
                cout << setw(10) << inventario[i].id << setw(15) << inventario[i].productos << setw(10) << inventario[i].pc << setw(10)
                     << inventario[i].pv << setw(20) << inventario[i].existencias << setw(10) << inventario[i].nr << setw(15) << nr_ind << endl;
            }
        }
    } while (inv_req != 3);
}

void Usuarios() {
    string username, password;
    cout << "Ingrese nombre de usuario: ";
    cin >> username;
    cout << "Ingrese contraseña: ";
    cin >> password;
    if ((username == vendedor1_username && password == vendedor1_password) || // Evalúa si el nombre y la contraseña corresponden para acceder
        (username == vendedor2_username && password == vendedor2_password)) {
        cout << "Autenticación exitosa. Bienvenido, " << username << "!" << endl;
        current_user = username; // Una vez confirmado asigna el valor del acceso al usuario
    } else {
        cout << "Error de autenticación. Usuario o contraseña incorrectos." << endl;
    }
}

int Buscar(string pconsult) { // Función Buscar
    int i = 0;
    do {
        if (i == totalprod || pconsult == productos[i]) // Revisa si los valores son iguales para encontrar la variable
            break;
        i++;
    } while (true);
    if (pconsult == productos[i]) // Se asegura que los valores coincidan
        return i;
    else
        return -1; // -1 indica que no existe el producto
}

void CopyArrStruc() {
    for (int i = 0; i < totalprod; i++) {
        inventario[i].id = id[i];
        inventario[i].productos = productos[i];
        inventario[i].pc = pc[i];
        inventario[i].pv = pv[i];
        inventario[i].existencias = existencias[i];
        inventario[i].nr = nr[i];
        inventario[i].st = st[i];
    }
}

void Ventas() {
    int id_producto, cantidad_venta;
    bool encontrado = false;

    cout << "Ingrese el ID del producto a vender: ";
    cin >> id_producto;

    // Buscar el producto en el inventario
    for (int i = 0; i < totalprod; ++i) {
        if (inventario[i].id == id_producto && inventario[i].st) { // Verificar si el producto está disponible
            encontrado = true;
            cout << "Producto: " << inventario[i].productos << endl;
            cout << "Existencias disponibles: " << inventario[i].existencias << endl;

            cout << "Ingrese la cantidad a vender: ";
            cin >> cantidad_venta;

            // Verificar si hay suficientes existencias para la venta
            if (cantidad_venta <= inventario[i].existencias) {
                inventario[i].existencias -= cantidad_venta; // Actualizar las existencias
                cout << "Venta realizada correctamente." << endl;
            } else {
                cout << "No hay suficientes existencias para realizar la venta." << endl;
            }

            break;
        }
    }

    if (!encontrado) {
        cout << "Producto no encontrado o no disponible." << endl;
    }
}

void Bajas(){
    int id_producto;
    bool encontrado = false;

    cout << "Ingrese el ID del producto a dar de baja: ";
    cin >> id_producto;

    // Buscar el producto en el inventario
    for (int i = 0; i < totalprod; ++i) {
        if (inventario[i].id == id_producto) { // Verificar si el producto existe
            encontrado = true;
            inventario[i].st = 0; // Cambiar el estado del producto a 0 (dado de baja)
            cout << "Producto dado de baja correctamente." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
    }
}

void listaStruc() {
    int i = 0;
    nuevo = new prod;

    nuevo->id = id[i];
    nuevo->productos = productos[i];
    nuevo->id = inventario[i].id;
    nuevo->pc = inventario[i].pc;
    nuevo->pv = inventario[i].pv;
    nuevo->existencias = inventario[i].existencias;
    nuevo->nr = inventario[i].nr;
    nuevo->st = inventario[i].st;
    nuevo->sig = NULL;
    nuevo->ant = NULL;

    while (i < totalprod) {
        nuevo = new prod;
        nuevo->id = id[i];
        nuevo->productos = productos[i];
        nuevo->id = inventario[i].id;
        nuevo->pc = inventario[i].pc;
        nuevo->pv = inventario[i].pv;
        nuevo->existencias = inventario[i].existencias;
        nuevo->nr = inventario[i].nr;
        nuevo->st = inventario[i].st;

        if (inicio == NULL) {
            inicio = nuevo;
            fin = nuevo;
        } else {
            fin->sig = nuevo;
            nuevo->ant = fin;
            fin = nuevo;
        }

        inicio->ant = nuevo;
        nuevo->sig = new prod;
        nuevo->ant = NULL;

        i++;
    }
}

void CorteDeCaja() {
    int i = 0, total = 0;
    do {
        cout << "Ingrese el ID del producto: ";
        cin >> id[i];
        cout << "Ingrese la cantidad vendida: ";
        cin >> existencias[i];
        i++;
    } while (i < totalprod);
    for (i = 0; i < totalprod; i++) {
        total += inventario[i].pc * existencias[i];
    }
    cout << "El total de la venta es: " << total << endl;
    CopyArrStruc();
    listaStruc();
    Mostrar();
    cout << "Gracias por su compra" << endl;
    current_user = "";
    system("pause");
    system("cls");
}
