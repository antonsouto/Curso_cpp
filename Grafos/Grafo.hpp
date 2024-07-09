#include <iostream>
#include <memory>
#include <set>
#include <map>
#include <algorithm>
#include <limits>
#include <utility>

using namespace std;

// Pre-Declaro la estructura para poder definir el nuevo nombre de los punteros a dicha estructura P_Node
template <typename T>
struct Node;

// Nuevo nombre de los punteros a Node
template <typename T>
using P_Node = shared_ptr<Node<T>>;

template <typename T>
struct Node
{
    T data;
    set<pair<P_Node<T>, int>> neighbors;
};

/**
 * @brief Añade un nodo a la red de vencinos de un nodo.
 *
 * @param node Nodo al que le quieres añadir un vecino.
 * @param neighbor Vecino que le quieres añadir.
 * @param bidireccional Si es verdadero, añade la conexión en ambos sentidos.
 */

// Función para añadir un vecino con un peso al nodo
template <typename T>
void AddNeighbor(P_Node<T> const &node, P_Node<T> const &neighbor, int weight, bool bidirectional = false, int reverseWeight = 0)
{
    if (reverseWeight < 0 || weight < 0)
        return;
    auto it = find_if(node->neighbors.begin(), node->neighbors.end(),
                      [&neighbor](const pair<P_Node<T>, int> &p)
                      { return p.first == neighbor; });

    if (it == node->neighbors.end()) // Si llega al final es que no existe
    {
        node->neighbors.insert({neighbor, weight});
        if (bidirectional)
        {
            auto it2 = find_if(neighbor->neighbors.begin(), neighbor->neighbors.end(),
                               [&node](const pair<P_Node<T>, int> &p)
                               { return p.first == node; });
            if (it2 == neighbor->neighbors.end())
            {
                neighbor->neighbors.insert({node, reverseWeight});
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------> DIJKSTRA
template <typename T>
map<P_Node<T>, pair<P_Node<T>, int>> Dijkstra(P_Node<T> START, const vector<P_Node<T>> &nodes) // devuelve un mapa con el
{

    map<P_Node<T>, pair<P_Node<T>, int>> distancias; // mapa donde almaceno el P_Node, el P_Node de procedencia y el peso para llegar a el
    auto no_visit = nodes;                           // vector que contiene todos los nodos de un grafo, podria haber creado el objeto Graph realmente

    // Establezco todos los pesos a infinito
    for (auto &a : nodes)
    {
        distancias[a].second = INT32_MAX;
    }
    distancias[START] = {nullptr, 0};
    P_Node<T> current; // El primer nodo en evaluar vecinos es el que se pasa como START
    int pesocurrent;   // Peso del nodo current

    while (!no_visit.empty())
    {
        int pesoaux = INT32_MAX;
        for (auto it = no_visit.begin(); it != no_visit.end(); it++)
        {
            if (distancias[*it].second < pesoaux)
            {
                pesoaux = distancias[*it].second;
                current = *it;
                pesocurrent = pesoaux;
            }
        }
        no_visit.erase(std::remove(no_visit.begin(), no_visit.end(), current), no_visit.end());

        for (auto distIT = distancias.begin(); distIT != distancias.end(); distIT++)
        {
            for (auto neighIT = current->neighbors.begin(); neighIT != current->neighbors.end(); neighIT++)
            {
                if (distIT->first == neighIT->first)
                { // Comparo los nombres de los nodos en la lista de vecinos del nodo current con el mapa de distancias totales
                    if ((pesocurrent + neighIT->second) < distIT->second.second)
                    {
                        distIT->second.second = pesocurrent + neighIT->second; // Actualizo en el peso en el mapa en caso de que sea menor que el peso current + lo que cuesta llegar desde current al nodo que itero
                        distIT->second.first = current;
                    }
                }
            }
        }
    }

    return distancias;
}


