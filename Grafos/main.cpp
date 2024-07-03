#include "Grafo.cpp"
#include <iostream>



using namespace std;




int main(){

    auto node1 = make_shared<Node<int>>(1);
    auto node2 = make_shared<Node<int>>(2);
    auto node3 = make_shared<Node<int>>(3);

    // Añadir vecinos
    AddNeighbor(node1, node2, true);
    AddNeighbor(node1, node3);

    // Imprimir los vecinos de node1
    cout << "Neighbors of node 1:" << endl;
    for (auto& neighbor : node1->neighbors) {
        cout << neighbor->data << " ";
    }
    cout << endl;

    // Imprimir los vecinos de node2
    cout << "Neighbors of node 2:" << endl;
    for (auto& neighbor : node2->neighbors) {
        cout << neighbor->data << " ";
    }
    cout << endl;

    // Imprimir los vecinos de node3
    cout << "Neighbors of node 3:" << endl;
    for (auto& neighbor : node3->neighbors) {
        cout << neighbor->data << " ";
    }
    cout << endl;



    return 0;
}