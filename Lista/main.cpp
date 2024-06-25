#include <memory>
#include <iostream>
#include <functional>
#include <cstdio>
#include <limits> // Incluir la biblioteca <limits> para usar numeric_limits
//#include "menu.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------------DECLARACIÓN DE LA ESTRUCTURA DE NOMBRES



//--------------------------------------------------------------------------------------------------------------MOSTRAR MENU
#include <memory>
#include <iostream>
#include <functional>
#include <cstdio>
#include <limits> // Incluir la biblioteca <limits> para usar numeric_limits
#include "ListaSimple.h"

using namespace std;
//FUNCION PARA ESPERAR INTERACCION DE USUARIO
void esperarTecla() {
    printf("\n\nPresione cualquier tecla para continuar...\n");
    getchar(); // Espera a que se pulse una tecla
}

void mostrarMenu()
{
    P_Node<string> start = nullptr;
    string nombrenuevo;
    bool flag = true;
    while (flag)
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        cout << "\033[1;34m"; // Texto en negrita y azul
        cout << "\n\t+-------------------------------------------+\n";
        cout << "\t|                 \033[1;32mMENU PRINCIPAL\033[1;34m            |\n"; // Título en verde
        cout << "\t+-------------------------------------------+\n";
        cout << "\t| \033[1;33m1.\033[1;34m Mostrar todos (id, nombre)             |\n"; // Números en amarillo
        cout << "\t| \033[1;33m2.\033[1;34m Añadir (nombre)                        |\n";
        cout << "\t| \033[1;33m3.\033[1;34m Borrar (por id)                        |\n";
        cout << "\t| \033[1;33m4.\033[1;34m Buscar (por nombre) -> mostrar         |\n";
        cout << "\t| \033[1;33m5.\033[1;34m Salir                                  |\n";
        cout << "\t+-------------------------------------------+\n";
        cout << "\tIngrese su opción: \033[0m"; // Restablecer formato


        int opcion;
        cin >> opcion;
        // Verificar si la entrada es inválida
        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de fallo
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida
            cout << "Opción inválida. Por favor, intente de nuevo.\n";
            continue;
        }

        cin.ignore(); // Limpiar el buffer de entrada
        switch (opcion)
        {
        case 1:
            cout << "\n\nHas elegido listar.\n\n";
            imprimir_elems(start);
            esperarTecla();
            break;
        case 2:
            cout << "\n\nHas elegido añadir.\n\n";
            // Aquí iría la lógica para añadir
            if(start!=nullptr){
                cout << "\nIntroduce el nombre del nuevo miembro: ";
                getline(cin, nombrenuevo);
                push_r(start, nombrenuevo);
                break;
            }else{
                cout << "\nIntroduce el nombre del nuevo miembro: ";
                getline(cin, nombrenuevo);
                start = make_shared<Node<string>>(nombrenuevo);
                break;
            }
        case 3:
        {
            cout << "\n\nHas elegido borrar.\n\n";
            imprimir_elems(start);
            cout << "\nIntroduce el ID del miembro a borrar: ";
            string id;
            getline(cin, id);
            pop_r(start, id);
            break;
        }
        case 4:{
            cout << "\n\nHas elegido buscar por nombre.\n\n";
            string idborrar;
            string nombrebuscar;
            cout<<"\nElige un nombre a buscar: ";
            getline(cin,nombrebuscar);
            forEach<string>(start, [&idborrar,&nombrebuscar](P_Node<string> p)
                            { if(p->data==nombrebuscar); cout<<"\nSe ha encontrado un "<<nombrebuscar<<" con id: "<<p->id<<endl;});
            
            esperarTecla();
            break;}
        case 5:
            cout << "\n\nSaliendo...\n\n";
            flag = false;
            break;
        default:
            cout << "Opción inválida. Por favor, intente de nuevo.\n";
            break;
        }
    
        
    }
}

int main()
{
    mostrarMenu();
    return 0;
}
