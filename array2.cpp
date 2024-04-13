//medir las dimensiones de las matrices y validar que se puedan multiplicar
// las columnas de la primera matriz tienen que ser iguales que las filas de la primera
//validar que se puedan multiplicar, medir dimencion de matriz, modificar el codigo de la multiplicacion, mostrar la matriz resultante

#include <iostream>


using namespace std;

int main(){
    int matA[3][2] = {{2, 4}, {3, 2}, {5, 4}};
    int matB[3][2] = {{1, 0}, {2, -3}, {0, 8}};
    int matC[3][2];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            matC[i][j] = matA[i][j] * matB[i][j];
        }
    }
    cout << "Matriz A" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            cout << matA[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Matriz B" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            cout << matB[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Matriz C" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            cout << matC[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
    

}
