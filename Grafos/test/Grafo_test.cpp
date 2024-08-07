#include <gtest/gtest.h>
#include "../Grafo.hpp"

TEST(AñadonodoUnidireccional, Nodo_añadido_correctamente)
{
    auto n1 = make_shared<Node<int>>(1);
    auto n2 = make_shared<Node<int>>(2);
    auto n3 = make_shared<Node<int>>(3);
    auto n4 = make_shared<Node<int>>(4);

    // Añadimos conexiones unidireccionales
    AddNeighbor(n1, n2);
    AddNeighbor(n1, n3);
    AddNeighbor(n1, n3); // Añado una de mas para comprobar que no se añade a la lista de vecinos
    AddNeighbor(n2, n4);

    // Verificamos que los nodos se han añadido correctamente
    EXPECT_EQ(n1->neighbors.size(), 2);
    EXPECT_EQ(n2->neighbors.size(), 1);
    EXPECT_EQ(n3->neighbors.size(), 0);
    EXPECT_EQ(n4->neighbors.size(), 0);

    // Verificamos los datos de los nodos vecinos
    auto it = n1->neighbors.begin();
    EXPECT_EQ((*it)->data, 2);
    ++it;
    EXPECT_EQ((*it)->data, 3);

    it = n2->neighbors.begin();
    EXPECT_EQ((*it)->data, 4);
}

TEST(AñadonodoBidireccional, Nodo_añadido_correctamente)
{
    auto n1 = make_shared<Node<int>>(1);
    auto n2 = make_shared<Node<int>>(2);
    auto n3 = make_shared<Node<int>>(3);
    auto n4 = make_shared<Node<int>>(4);

    // Añadimos conexiones bidireccionales
    AddNeighbor(n1, n2, true);
    AddNeighbor(n1, n3, true);
    AddNeighbor(n1, n3, true); // Igual que antes hago otra conexión bidirecional para comprobar que no se añade
    AddNeighbor(n2, n4, true);

    // Verificamos que los nodos se han añadido correctamente y que las conexiones son bidireccionales
    EXPECT_EQ(n1->neighbors.size(), 2);
    EXPECT_EQ(n2->neighbors.size(), 2);
    EXPECT_EQ(n3->neighbors.size(), 1);
    EXPECT_EQ(n4->neighbors.size(), 1);

    // Verificamos los datos de los nodos vecinos
    auto it = n1->neighbors.begin();
    EXPECT_EQ((*it)->data, 2);
    ++it;
    EXPECT_EQ((*it)->data, 3);

    it = n2->neighbors.begin();
    EXPECT_EQ((*it)->data, 1);
    ++it;
    EXPECT_EQ((*it)->data, 4);

    it = n3->neighbors.begin();
    EXPECT_EQ((*it)->data, 1);

    it = n4->neighbors.begin();
    EXPECT_EQ((*it)->data, 2);
}
