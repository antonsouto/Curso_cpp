#include <memory>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <memory>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

struct Coordinates
{
    int x;
    int y;
};

struct Node;

struct Edge
{
    shared_ptr<Node> node;
    float distance;
    Edge(shared_ptr<Node> nodo, float distancia) : node(nodo), distance(distancia) {}
};

bool operator<(Edge const &e1, Edge const &e2) { return e1.distance < e2.distance; }

struct Node
{
    Coordinates data;
    set<Edge> neighbors;
    float cost = INT32_MAX;
    shared_ptr<Node> prev;
    float estimation = INT32_MAX;
};

float operator-(Coordinates const &c1, Coordinates const &c2)
{
    return (c2.x - c1.x) * (c2.x - c1.x) + (c2.y - c1.y) * (c2.y - c1.y);
}

void push(shared_ptr<Node> &n1, shared_ptr<Node> &n2, bool bidirectional = true)
{
    auto edge = Edge{n2, n2->data - n1->data};
    n1->neighbors.insert(edge);

    if (bidirectional)
    {
        auto edge = Edge(n1, n1->data - n2->data);
        n2->neighbors.insert(edge);
    }
}

void dijkstra(shared_ptr<Node> start, vector<shared_ptr<Node>> nodes)
{
    start->cost = 0;
    auto NOT_VISITED = nodes;

    while (NOT_VISITED.size() > 0)
    {
        auto current = NOT_VISITED.at(0);
        for (auto node : NOT_VISITED)
        {
            if (node->cost < current->cost)
                current = node;
        }

        // remove current from NOT_VISITED
        NOT_VISITED.erase(find(NOT_VISITED.begin(), NOT_VISITED.end(), current));

        for (auto edge : current->neighbors)
        {
            if (edge.node->cost > current->cost + edge.distance)
            {
                edge.node->cost = current->cost + edge.distance;
                edge.node->prev = current;
            }
        }
    }
}

void dijkstra(shared_ptr<Node> start, vector<shared_ptr<Node>> nodes)
{
    start->cost = 0;
    auto NOT_VISITED = nodes;

    while (NOT_VISITED.size() > 0)
    {
        auto current = NOT_VISITED.at(0);
        for (auto node : NOT_VISITED)
        {
            if (node->cost < current->cost)
                current = node;
        }

        // remove current from NOT_VISITED
        NOT_VISITED.erase(find(NOT_VISITED.begin(), NOT_VISITED.end(), current));

        for (auto edge : current->neighbors)
        {
            if (edge.node->cost > current->cost + edge.distance)
            {
                edge.node->cost = current->cost + edge.distance;
                edge.node->prev = current;
            }
        }
    }
}

void estrella(shared_ptr<Node> start, shared_ptr<Node> end, vector<shared_ptr<Node>> nodes)
{
    start->cost = 0;
    auto NOT_VISITED = nodes;

    // Calculamos la estimacion de llegada
    for (auto elem : nodes)
    {
        elem->estimation = end->data - elem->data;
    }
    auto current = start;

    while (NOT_VISITED.size() > 0 && current != end)
    {

        for (auto node : NOT_VISITED)
        {
            if (node->cost + node->estimation < current->cost + current->estimation)
                current = node;
        }

        // remove current from NOT_VISITED
        NOT_VISITED.erase(find(NOT_VISITED.begin(), NOT_VISITED.end(), current));

        for (auto edge : current->neighbors)
        {
            if (edge.node->cost > current->cost + edge.distance)
            {
                edge.node->cost = current->cost + edge.distance;
                edge.node->prev = current;
            }
        }
    }
}

int main()
{
    // Crear nodos
    auto n1 = make_shared<Node>(Node{Coordinates{0, 0}});
    auto n2 = make_shared<Node>(Node{Coordinates{1, 1}});
    auto n3 = make_shared<Node>(Node{Coordinates{2, 2}});
    auto n4 = make_shared<Node>(Node{Coordinates{3, 3}});
    auto n5 = make_shared<Node>(Node{Coordinates{4, 4}});

    // Crear aristas
    push(n1, n2);
    push(n2, n3);
    push(n3, n4);
    push(n4, n5);

    vector<shared_ptr<Node>> nodes = {n1, n2, n3, n4, n5};

    // Ejecutar Dijkstra
    auto start_time = chrono::high_resolution_clock::now();
    dijkstra(n1, nodes);
    auto end_time = chrono::high_resolution_clock::now();
    auto dijkstra_duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    // Reiniciar costos para ejecutar A*
    for (auto node : nodes)
    {
        node->cost = INT32_MAX;
        node->prev = nullptr;
    }

    // Ejecutar A*
    start_time = chrono::high_resolution_clock::now();
    estrella(n1, n5, nodes);
    end_time = chrono::high_resolution_clock::now();
    auto estrella_duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    // Verificar los resultados
    bool same_path = true;
    auto node_d = n5, node_a = n5;
    while (node_d && node_a)
    {
        if (node_d->data.x != node_a->data.x || node_d->data.y != node_a->data.y)
        {
            same_path = false;
            break;
        }
        node_d = node_d->prev;
        node_a = node_a->prev;
    }

    cout << "Dijkstra duration: " << dijkstra_duration << " microseconds" << endl;
    cout << "A* duration: " << estrella_duration << " microseconds" << endl;
    cout << "Both algorithms found the same path: " << (same_path ? "Yes" : "No") << endl;

    return 0;
}