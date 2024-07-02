#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include <string>
#include <fstream>

using namespace std;

struct Node
{
  int data;
  shared_ptr<Node> next;
};
typedef shared_ptr<Node> P_Node;
P_Node push(P_Node first, int data)
{
  auto it = first;
  while (it->next)
  {
    it = it->next;
  }
  P_Node nNode = make_shared<Node>(Node{data, nullptr});
  it->next = nNode;
  return nNode;
}

P_Node push_r(P_Node first, int data)
{
  if (first->next)
    return push_r(first->next, data);

  P_Node nNode = make_shared<Node>(Node{data, nullptr});
  first->next = nNode;
  return nNode;
}

void imprimir_elems(P_Node first)
{
  // mostrar todos los datos // iterativo
  auto it = first;
  while (it)
  {
    cout<<it->data<<" ";
    it = it->next;
  }
  cout<<endl;
}

void imprimir_recursivo(P_Node first)
{
  // mostrar todos los datos;
  if (first == nullptr) // Base case: end of the list
    return;

  cout << first->data << " "; // Print current node's data
  imprimir_recursivo(first->next); // Recursive call with the next node
  
}

void forEach(P_Node first, function<void(int)> f)
{
  auto it=first;
  while(it){
    f(it->data);
    it=it->next;
  }
}

P_Node deleteNode(P_Node first, P_Node toDelete)
{
  if (!first || !toDelete)
    return first;

  if (first == toDelete)
  {
    first = first->next; // If the head is the node to delete, move head to the next node
    return first;
  }

  auto it = first;
  while (it->next && it->next != toDelete)
  {
    it = it->next;
  }

  if (it->next == toDelete)
  {
    it->next = toDelete->next; // Remove the node by skipping it in the list
  }

  return first;
}


/// agenda 
struct Persona
{
  int id;
  string nombre;
  string telefono;
  shared_ptr<Persona> next;
};

typedef shared_ptr<Persona> P_Persona;
//mostrar personas
void showPersonas(P_Persona head)
{
  auto it = head;
  while (it)
  {
    cout << "ID: " << it->id << ", Nombre: " << it->nombre << ", Telefono: " << it->telefono << endl;
    it = it->next;
  }
}

// añade una persona hay que pasarle id, nombre y telefono
P_Persona addPersona(P_Persona head, int id, const string& nombre, const string& telefono)
{
  P_Persona newNode = make_shared<Persona>(Persona{id, nombre, telefono, nullptr});
  if (!head)
    return newNode;

  auto it = head;
  while (it->next)
  {
    it = it->next;
  }
  it->next = newNode;
  return head;
}

P_Persona deletePersona(P_Persona head, int id)
{
  if (!head)
    return head;

  if (head->id == id)
  {
    head = head->next; // si es la persona al incio la salta
    return head;
  }

  auto it = head;
  while (it->next && it->next->id != id)
  {
    it = it->next;
  }

  if (it->next && it->next->id == id)
  {
    it->next = it->next->next; // si es la persona la salta
  }

  return head;

}
P_Persona findPersona(P_Persona head, int id)
{
  auto it = head;
  while (it)
  {
    if (it->id == id)
    {
      cout << "Encontrado: ID: " << it->id << ", Nombre: " << it->nombre << ", Telefono: " << it->telefono << endl;
      return it;
    }
    it = it->next;
  }
  cout << "Persona with ID: " << id << " not found." << endl;
  return nullptr;
}

void forEachPerson(P_Persona head, function<void(P_Persona)> f)
{
  auto it=head;
  while(it){
    f(it);
    it=it->next;
  }
}
ostream& operator<<(ostream &os, const Persona &p){
    os<<" "<<p.id<<" "<<p.nombre<<" "<<p.telefono<<endl;
    return os;
}
void guardarMemoria(P_Persona head){
    ofstream archivo("Agenda_personas.txt");
    if(archivo.is_open()){
        forEachPerson(head,[&archivo](P_Persona head){
            archivo<<*head;
        });
    }
}

istream& operator>>(istream &is, Persona &p) {
    is >> p.id >> p.nombre >> p.telefono;
    return is;
}

void leerMemoria (string filename = "Agenda_personas.txt", P_Persona &head){
    
}

int main()
{

//   P_Node start = make_shared<Node>(Node{1, nullptr});
//   auto segundo = push(start, 23);
//   auto tercero = push(segundo, 31);
//   auto cuarto = push(tercero, 45);
  
//     // modo iterativo
//   imprimir_elems(start);
//     // modo recursivo
//   imprimir_recursivo(start);

//     //con el forEach y una funcion que queramos, en este caso es la de sumar 
//     // todos los elementos de la lista
//   int sum=0;
//   forEach(start, [&sum](int value){sum+=value;});

//   cout<<"La suma de todos los elementos de la lista es:"<<sum<<endl;

//     start = deleteNode(start, tercero);

//     imprimir_elems(start);
   
//   return 0;


//Agenda
  P_Persona head = nullptr;
  head = addPersona(head, 1, "Juan Tenorio", "123456789");
  head = addPersona(head, 2, "CApitan trueno", "987654321");
  head = addPersona(head, 3, "maria arrojo", "555555555");
  head = addPersona(head, 4, "Yotoko Kulito", "589235506");

  // cout << "Personas en la lista:" << endl;
  // showPersonas(head);

  // cout << "\nBorrando persona con ID seleccionado" << endl;
  // head = deletePersona(head, 2);
  
  // cout << "\nPersonas en la lista despues de borrar:" << endl;
  // showPersonas(head);

  // cout << "\nBuscando la persona con el ID seleccionado" << endl;
  // findPersona(head, 3);

  // cout << "\nBuscando la persona con el ID seleccionado" << endl;
  // findPersona(head, 4);

  int opcion;
  do{
    cout<< "\n--- Menu ---"<<endl;
    cout<< "--- 1. Añadir persona ---"<<endl;
    cout<< "--- 2. Mostrar persona ---"<<endl;
    cout<< "--- 3. Borrar persona ---"<<endl;
    cout<< "--- 4. Buscar persona ---"<<endl;
    cout<< "--- 5. Guardar en memoria ---"<<endl;
    cout<< "--- 6. Leer de memoria ---"<<endl;
    cout<< "--- 7. Salir ---"<<endl;
    cout<< "Seleccione una opcion: ";
    cin>>opcion;

    switch (opcion){
      case 1: {
        int id;
        string nombre, telefono;
        cout<<"Introduzca ID: ";
        cin>> id;
        cin.ignore();// ignorar entrada
        cout<< "Introduzca nombre: ";
        getline(cin, nombre);
                // Validar la longitud del teléfono
                do {
                    cout << "Introduzca telefono (9 dígitos): ";
                    getline(cin, telefono);
                    if (telefono.length() != 9) {
                        cout << "El telefono debe tener exactamente 9 digitos. Intente de nuevo." << endl;
                    }
                } while (telefono.length() != 9);

                head = addPersona(head, id, nombre, telefono);
                break;
      }
      case 2: {
        cout<< "Personas en la lista: "<<endl;
        showPersonas(head);
        break;
      }
      case 3:{
        int id;
        cout<<"Introduzca ID de la persona a eliminar:";
        cin>>id;
        head=deletePersona(head,id);
        break;
      }
      case 4:{
        int id;
        cout<<"introduzca ID de la persona a buscar: ";
        cin>>id;
        findPersona(head, id);
        break;
      }
      case 5:{
        cout<<"Guardando en la memoria."<<endl;
        guardarMemoria(head);
        break;
      }
      case 6:{
        cout<<"Leyendo de la memoria y mostrando en pantalla."<<endl;
        P_Persona agenda = leerMemoria();
        showPersonas(agenda);
        break;
      }
      case 7: {
        cout<<"Cerrando programa"<<endl;
        break;
      }
      default:{
        cout<<"Opcion no valida. Pruebe con otro numero."<<endl;
      }
    }



  } while(opcion !=7);

  return 0;

}