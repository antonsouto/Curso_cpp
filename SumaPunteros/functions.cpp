#include "functions.h"
#include <memory>
#include <iostream>
#include <vector>
using namespace std;

bool includes(const vector<shared_ptr<Person>> &a,shared_ptr<Person>const &obj){
    bool flag = false;
    for(auto&s:a){
        if(s == obj){flag = true;}
    }
    return flag;
}

bool includes(const vector<shared_ptr<Person>> &a,const vector<shared_ptr<Person>> &b){
    
    for(auto&aux:b){
        bool flag = false;
        for (const auto& personA : a) {
            if (personA == aux) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            return false;
        }
    }
    return true;
}

const vector<shared_ptr<Person>> interseccion(const vector<shared_ptr<Person>> &a,const vector<shared_ptr<Person>> &b){
    vector<shared_ptr<Person>> resultado;
    for(auto&aux:b){
        for (const auto& personA : a) {
            if (personA == aux) {
               resultado.push_back(aux);                
            }        // Si algún elemento de b no se encuentra en a, devuelve false
        }
    }
    return resultado;
}
const vector<shared_ptr<Person>> diferencia(const vector<shared_ptr<Person>> &a,const vector<shared_ptr<Person>> &b){
    vector<shared_ptr<Person>> resultado;
    bool flag = false;
    for(auto&aux:a){
        for (const auto& personA : b) {
            if (personA == aux) {
               flag = true;                
            }
        }
        if(!flag){
            resultado.push_back(aux);
        }else{flag = false;}
    }
    return resultado;
}

const vector<shared_ptr<Person>> unionv(const vector<shared_ptr<Person>> &a,const vector<shared_ptr<Person>> &b){
    vector<shared_ptr<Person>> resultado;
    for(auto& aux:a){
        bool repetido= false;
        for(auto& aux2:b){
            if(aux==aux2){repetido = true;break;}
        }
        if(!repetido){
            resultado.push_back(aux);
        }
    }
    for(const auto& aux2:b){
            resultado.push_back(aux2);
        }
    return resultado;
}