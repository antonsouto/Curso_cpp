#include"ListaDoble.h"



P_Node push_back(P_Node const &head, int dato){
    if(head!=nullptr){
        P_Node node = make_shared<Node>(Node{uuid(), dato, nullptr, nullptr});
        return node;
    }
}