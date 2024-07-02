#include <memory>
#include <iostream>
#include "binaryTree.h"

using namespace std;

int main(void)
{
    // Crear dos árboles: uno ordenado por valor y otro por ID
    shared_ptr<Node> arbolPorValor;
    shared_ptr<Node> arbolPorId;

    auto data1 = make_shared<Data>(Data{3, "Anton"});
    auto data2 = make_shared<Data>(Data{2, "Bartolome"});
    auto data3 = make_shared<Data>(Data{4, "Carlos"});
    auto data4 = make_shared<Data>(Data{1, "Dante"});

    // Insertar datos en ambos árboles
    arbolPorValor = Push2(arbolPorValor, data1);
    Push2(arbolPorValor, data2);
    Push2(arbolPorValor, data3);
    Push2(arbolPorValor, data4);

    arbolPorId = Push(arbolPorId, data1);
    Push(arbolPorId, data2);
    Push(arbolPorId, data3);
    Push(arbolPorId, data4);

    // Modificar un valor a través del árbol ordenado por ID
    P_Node nodeToModify = Find(arbolPorId, data3->id);
    if (nodeToModify) {
        nodeToModify->data->value = 10; // Modificar el valor
        cout<<"Nombre: "<<nodeToModify->data->nombre<<"   Value: "<<nodeToModify->data->value<<endl;
    }

    // Buscar la modificación a través del árbol ordenado por valor
    auto modifiedNode = Find2(arbolPorValor, 10);
    if (modifiedNode) {
        cout << "Found node with new value 10" << endl;
        cout << "ID: " << modifiedNode->data->id << endl;
        cout << "Nombre: " << modifiedNode->data->nombre << endl;
    } else {
        cout << "Node not found with new value 10" << endl;
    }

    return 0;
}
