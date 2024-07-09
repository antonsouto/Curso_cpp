#include "Grafo.hpp"
#include <iostream>



using namespace std;


int main()
{
    // Crear nodos
    auto n1 = make_shared<Node<int>>(Node<int>{1});
    auto n2 = make_shared<Node<int>>(Node<int>{2});
    auto n3 = make_shared<Node<int>>(Node<int>{3});
    auto n4 = make_shared<Node<int>>(Node<int>{4});
    auto n5 = make_shared<Node<int>>(Node<int>{5});

    // Añadir vecinos con pesos
    AddNeighbor(n1, n2, 10);
    AddNeighbor(n1, n3, 20);
    AddNeighbor(n2, n4, 15);
    AddNeighbor(n3, n4, 30);
    AddNeighbor(n2, n5, 50);
    AddNeighbor(n4, n5, 30);

    // Ejecutar Dijkstra desde n1
    vector<P_Node<int>> nodes = {n1, n2, n3, n4, n5};
    auto distancias = Dijkstra(n1, nodes);

    // Imprimir resultados
    cout << "Nodo\tPeso desde n1\tNodo Precedente" << endl;
    for (const auto &[node, info] : distancias)
    {
        cout << "n" << node->data << "\t" << info.second << "\t\t";
        if (info.first)
        {
            cout << "n" << info.first->data << endl;
        }
        else
        {
            cout << "N/A" << endl; // Nodo de inicio no tiene precedente
        }
    }

    return 0;
}
