#include "binaryTree.h"
#include <iostream>
#include <memory>
#include <cstdlib> // Para rand()

using namespace std;

// Definición de la función uuid
int uuid() {
    return rand() % 10000;
}


// Función para insertar un valor en el árbol binario ordenado
P_Node &Push(P_Node &head, shared_ptr<Data> &data) {
    if (!head) {
        head = make_shared<Node>(Node{data});
        return head;
    }

    if (head->data->id > data->id) {
        head->left = Push(head->left, data);
    } else if (head->data->id < data->id) {
        head->right = Push(head->right, data);
    }

    return head;
}

// Función para insertar un valor en el árbol binario ordenado en este caso por el valor de "Data"
P_Node &Push2(P_Node &head, shared_ptr<Data> &data) {
    if (!head) {
        head = make_shared<Node>(Node{data});
        return head;
    }

    if (head->data->value > data->value) {
        head->left = Push2(head->left, data);
    } else if (head->data->value < data->value) {
        head->right = Push2(head->right, data);
    }

    return head;
}

// Función para encontrar un valor dentro del árbol
P_Node Find(P_Node const &head, int id) {
    if (!head)
        return nullptr;

    if (head->data->id == id)
        return head;

    if (head->data->id > id) {
        return Find(head->left, id);
    } else {
        return Find(head->right, id);
    }
}

// Función para encontrar un valor dentro del árbol en este caso por el value de "Data"
P_Node Find2(P_Node const &head, int value) {
    if (!head)
        return nullptr;

    if (head->data->value == value)
        return head;

    if (head->data->value > value) {
        return Find(head->left, value);
    } else {
        return Find(head->right, value);
    }
}
