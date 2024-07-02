#include <iostream>
#include <fstream>

using namespace std;

struct Persona{
    int id;
    string nombre;
};

// Sobrecarga del operador de entrada para una matriz 3x3
istream& operator>>(istream& is, int matrix[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            is >> matrix[i][j];
        }
    }
    return is;
}

// Sobrecarga del operador de salida para una matriz 3x3
ostream& operator<<(ostream& os, const int matrix[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << matrix[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

int main() {
    int matrix[3][3];

    // Recoger la matriz desde el teclado
    cout << "Introduce los 9 elementos de la matriz 3x3, separados por espacios: ";
    cin >> matrix;

    // Imprimir la matriz en un archivoEscritura de texto
    ofstream archivoEscritura("matrix.txt");
    if (archivoEscritura.is_open()) {
        archivoEscritura << matrix;
        archivoEscritura.close();
    } else {
        cerr << "No se pudo abrir el archivoEscritura para escribir." << endl;
        return 1;
    }

    // Leer la matriz del archivoEscritura de texto
    int matrixFromFile[3][3];
    ifstream archivoLectura("matrix.txt");
    if (archivoLectura.is_open()) {
        archivoLectura >> matrixFromFile;
        archivoLectura.close();
    } else {
        cerr << "No se pudo abrir el archivoEscritura para leer." << endl;
        return 1;
    }

    // Imprimir la matriz leída del archivoEscritura
    cout << "La matriz leída del archivoEscritura es:" << endl;
    cout << matrixFromFile;

    return 0;
}
