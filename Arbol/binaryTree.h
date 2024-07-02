#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <memory>
#include <cstdlib> // Para rand()
#include <string>

using namespace std;

// Declaración de la estructura Node
struct Node;
using P_Node = shared_ptr<Node>;

int uuid();

struct Data{
    int value;
    string nombre;
    int id = uuid();
    

    //Data(int value, const string& nombre2) : value(value), nombre(nombre2) , id(uuid()) {}
};

struct Node {
    shared_ptr<Data> data;
    P_Node left;
    P_Node right;

    
    //Node(shared_ptr<Data> data) : data(data), left(nullptr), right(nullptr) {}
};

// Función para insertar un valor en el árbol binario ordenado
P_Node &Push(P_Node &head, shared_ptr<Data> &data);


// Función para insertar un valor en el árbol binario ordenado por el valor
P_Node &Push2(P_Node &head, shared_ptr<Data> &data);

// Función para encontrar un valor dentro del arbol
P_Node Find(P_Node const &head, int id);

// Función para encontrar un valor dentro del arbol segun el valor de data
P_Node Find2(P_Node const &head, int value);

#endif // BINARY_TREE_H
