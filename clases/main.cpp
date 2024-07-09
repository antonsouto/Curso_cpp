#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include "Figuras.h"

using namespace std;


int main() {
    vector<shared_ptr<FiguraGeometrica>> figuras;
    int opcion;

    do {
        system("clear");
        cout << "Menu:\n";
        cout << "1. Añadir un Cuadrado\n";
        cout << "2. Añadir un Triangulo\n";
        cout << "3. Añadir un Pentagono\n";
        cout << "4. Imprimir todas las figuras\n";
        cout << "5. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                float lado;
                cout << "Introduce el lado del cuadrado: ";
                cin >> lado;
                figuras.push_back(make_shared<Cuadrado>(lado));
                break;
            }
            case 2: {
                float base, altura;
                cout << "Introduce la base del triangulo: ";
                cin >> base;
                cout << "Introduce la altura del triangulo: ";
                cin >> altura;
                figuras.push_back(make_unique<Triangulo>(base, altura));
                break;
            }
            case 3: {
                float lado;
                cout << "Introduce el lado del pentagono: ";
                cin >> lado;
                figuras.push_back(make_unique<Pentagono>(lado));
                break;
            }
            case 4: {
                cout << "------------------------\n";
                for (const auto& figura : figuras) {
                    figura->queSoy();
                    cout << "Área: " << figura->getArea() << endl;
                    cout << "Perímetro: " << figura->getPerimetro() << endl;
                    cout << "Número de lados: " << figura->getNumeroLados() << endl;
                    cout << "------------------------\n";
                }
                break;
            }
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida. Inténtalo de nuevo.\n";
        }
        system("read -p 'Press Enter to continue...' var");
    } while (opcion != 5);

    // No es necesario liberar memoria manualmente, ya que std::unique_ptr lo hace automáticamente

    return 0;
}
