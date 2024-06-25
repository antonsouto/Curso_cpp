#pragma once
#include <memory>
#include <iostream>
#include <vector>
#include "types.h"
using namespace std;


bool includes(const vector<shared_ptr<Person>> &a,const vector<shared_ptr<Person>> &b);
bool includes(const vector<shared_ptr<Person>> &a,shared_ptr<Person>const &obj);
const vector<shared_ptr<Person>> interseccion(const vector<shared_ptr<Person>> &a,const vector<shared_ptr<Person>> &b);
const vector<shared_ptr<Person>> unionv(const vector<shared_ptr<Person>> &a,const vector<shared_ptr<Person>> &b);
const vector<shared_ptr<Person>> diferencia(const vector<shared_ptr<Person>> &a,const vector<shared_ptr<Person>> &b);