#include <iostream>

using namespace std;

int main() {
    int i, j, k, suma, renA, colA, renB, colB;

    int matA[3][2] = {{2, 4}, {3, 2}, {5, 4}};
    int matB[3][2] = {{1, 0}, {2, -3}, {0, 8}};
    int matC[3][2];

    renA = sizeof(matA) / sizeof(matA[0]);
    colA = sizeof(matA[0]) / sizeof(int);
    renB = sizeof(matB) / sizeof(matB[0]);
    colB = sizeof(matB[0]) / sizeof(int);

    cout << "Dimension de la matriz A: " << renA << " x " << colA << endl;
    cout << "Dimension de la matriz B: " << renB << " x " << colB << endl;

    if (colA == renB) {
        for (i = 0; i < renA; i++)
            for (j = 0; j < colB; j++) {
                suma = 0; // Initialize suma to 0
                for (k = 0; k < colA; k++)
                    suma += matA[i][k] * matB[k][j];
                matC[i][j] = suma;
            }

        cout << "Matriz C" << endl;
        for (i = 0; i < renA; i++) {
            for (j = 0; j < colB; j++)
                cout << matC[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No se pueden multiplicar las matrices. Las dimensiones no son compatibles." << endl;
    }

    cout << "Matriz A" << endl;
    for (i = 0; i < renA; i++) {
        for (j = 0; j < colA; j++)
            cout << matA[i][j] << " ";
        cout << endl;
    }

    cout << "Matriz B" << endl;
    for (i = 0; i < renB; i++) {
        for (j = 0; j < colB; j++)
            cout << matB[i][j] << " ";
        cout << endl;
    }

    cout << "Matriz C" << endl;

    for (i = 0; i < renA; i++) {
        for (j = 0; j < colA; j++)
            matC[i][j] = matA[i][j] + matB[i][j];
    }

    for (i = 0; i < renA; i++) {
        for (j = 0; j < colA; j++)
            cout << matC[i][j] << " ";
        cout << endl;
    }

    return 0;
}
