#include <iostream>
#include <memory>
#include <algorithm> // Para std::find

using namespace std;

//Declaro la estructura para poder definir el nuevo nombre de los punteros a dicha estructura P_Node
template<typename T>
struct Node;

//Nuevo nombre de los punteros a Node
template<typename T>
using P_Node = shared_ptr<Node<T>>;



template<typename T>
struct Node{
    T data;
    vector<P_Node<T>> neighbors;
};

/**
 * @brief Añade un nodo a la red de vencinos de un nodo.
 *
 *
 * @param param1 Nodo al que le quieres añadir un vecino.
 * @param param2 Vecino que le quieres añadir.
 * @return Devuelve el puntero por referencia al nodo que has añadido un vecino.
 */
template <typename T>
void AddNeighbor(shared_ptr<Node<T>> &node, shared_ptr<Node<T>> &neighbor, bool bidireccional = false)
{
    auto it = std::find(node->neighbors.begin(), node->neighbors.end(), neighbor);
    auto it2 = std::find(neighbor->neighbors.begin(), neighbor->neighbors.end(), node);

    if (bidireccional)
    {
        if (it == node->neighbors.end())
            node->neighbors.push_back(neighbor);
        if (it2 == neighbor->neighbors.end())
            neighbor->neighbors.push_back(node);
    }
    else
    {
        if (it == node->neighbors.end())
            node->neighbors.push_back(neighbor);
    }
}
