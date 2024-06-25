#include <memory>
#include <iostream>
#include <vector>
#include "types.h"
using namespace std;



vector<shared_ptr<Person>> filtrarMayoresDeEdad(vector<shared_ptr<Person>> const &p)
{
  vector<shared_ptr<Person>> result;
  for (auto const &persona : p)
  {
    if (persona->age >= 18)
      result.push_back(persona);
  }

  return result;
}


int main()
{
    shared_ptr<Person> personaObjetivo = make_shared<Person>(Person{"Lucia",34,true});
    shared_ptr<Person> personaNOObjetivo = make_shared<Person>(Person{"Lucia",34,true});

  vector<shared_ptr<Person>> personas;
    personas.push_back(personaObjetivo);
  personas.push_back(make_shared<Person>(Person{"Alberto", 21, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto2", 16, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto3", 20, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto4", 15, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto5", 14, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto6", 84, true}));
    


    if(includes(personas, personaObjetivo)) {
        cout<<"Mi persona está incluida en el arreglo"<<endl;
    }

  /* auto mayores_edad = filtrarMayoresDeEdad(personas);

  for (auto const &p : mayores_edad)
  {
    p->underAge = false;
  }

  for (auto const &p : personas)
  {
    cout << "Nombre: " << p->name << "\tEdad: " << p->age << "\tUnder Age: " << p->underAge << endl;
  } */


}