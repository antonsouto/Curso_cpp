#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Car
{
  string brand;
  string plate;
};

struct Person
{
  string name;
  int age;
  string dni;
  string email;
  Car car;
};

void printPersonMayores(vector<Person> const &p)
{
  for(int i=0;i<p.size();i++){
    if(p[i].age >= 18){
        cout<<"La persona "<<p[i].name<<" es mayor de edad"<<endl;
    }
  }
}

void printPersonMayores2(vector<Person> const &p)
{
  for(Person p : p){
    if(p.age >= 18){
        cout<<"La persona "<<p.name<<" es mayor de edad"<<endl;
    }
  }
}

int main()
{
  Person alberto{"Alberto", 18, "123456789J", "alberto.valero@bq.com", Car{"Hyundai", "1234ABC"}};
  Person maria{"Maria", 20, "123436789J", "maria@bq.com", Car{"Kia", "1234ABC"}};
  Person Lucia{"Lucia", 17, "234534563A", "lucia@gmail.com", Car{"Mercedes", "52465ASD"}};
  Person Anton{"Anton", 14, "32718488W", "anton@gmail.com", Car{"Honda", "8854JGF"}};
  Person Mariano{"Mariano Rajoy", 63, "45673433A", "marianorajoy@gmail.com", Car{"Volkswagen", "3366GHD"}};
  
  vector<Person> personas{alberto, maria, Lucia, Anton, Mariano};

  printPersonMayores2(personas);


  personas[0];    // alberto
  personas.at(1); // maria
  personas.at(2); // alberto
  personas.at(3); // maria

  cout << "Tenemos actualmente un total de " <<personas.size() <<" personas en total"<< endl; //5

  return 0;
}
