/*
#include "ListaSimple.h"

//-----------------------------------------------------------------------------------------------------------------------------FUNCIONES PARA MODIFICAR LA LISTA
// FUNCION PUSH PARA AÑADIR ELEMENTOS
template <typename T>
P_Node<T> push_r(P_Node<T> first, T data)
{
    auto it = first;
    while (it->next)
    {
        it = it->next;
    }
    P_Node<T> nNode = make_shared<Node<T>>(Node<T>{data, nullptr});
    it->next = nNode;
    return nNode;
}

// FUNCION POP PARA ELIMINAR UN ELEMENTO
template <typename T>
void pop_r(P_Node<T> &head, string const &id)
{
    if (head->id == id)
    {
        head = head->next;
        return;
    }

    auto it = head;
    while (it->next && it->next->id != id)
    {
        it = it->next;
    }
    if (it->next)
    {
        it->next = it->next->next;
    }
}

//------------------------------------------------------------------------------------------------------------------------------FUNCIONES PARA IMPRIMIR LA LISTA
// FUNCION PARA IMPRIMIR ELEMENTOS DE FORMA SIMPLE
template <typename T>
void imprimir_elems(P_Node<T> first)
{
    auto it = first;
    while (it)
    {
        cout << it->id << ":\t" << it->data << endl;
        it = it->next;
    }
}

// FUNCION PARA IMPRIMIR ELEMENTOS DE FORMA RECURSIVA
template <typename T>
void imprimir_recursivo(P_Node<T> p)
{
    if (p)
    {
        cout << p->id << ":\t" << p->data << endl;
        imprimir_recursivo<T>(p->next);
    }
}

// FUNCION PARA IMPRIMIR ELEMENTOS CON FUNCIÓN LAMBDA
template <typename T>
void forEach(P_Node<T> &first, function<void(P_Node<T>)> const &f)
{
    auto it = first;
    while (it)
    {
        f(it);
        it = it->next;
    }
}
*/