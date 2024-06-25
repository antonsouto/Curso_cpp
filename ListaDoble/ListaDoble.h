#pragma once 
#include<iostream>
#include<memory>
using namespace std;


//FUNCION QUE GENERA UN ID ALEATORIO
string uuid()
{
    string id = "";
    for (int i = 0; i < 5; i++)
    {
        id += 'a' + rand() % 26;
    }
    return id;
}

//ESTRUCTURA DE CADA UNO DE LOS NODOS DE LA LISTA
using P_Node = shared_ptr<int>;
struct Node{
    string id;
    int data;
    P_Node next;
    P_Node prec;
};



P_Node push_back(P_Node const &head, int dato);
P_Node push_front(P_Node const &head, int dato);
P_Node push_at(P_Node const &head, int dato, int pos);
P_Node push_in_order(P_Node const &head, int dato, bool asc =  true);

