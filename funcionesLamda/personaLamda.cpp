#include <functional>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Estructura que define a una Persona con nombre, edad y un indicador de si es mayor de edad
struct Person
{
    string name;  // Nombre de la persona
    int edad;     // Edad de la persona
};

// Tipos definidos para simplificar el uso de vectores de punteros compartidos a Person y funciones lambda
typedef vector<shared_ptr<Person>> vP;                             // Vector de punteros compartidos a Person
typedef function<void(shared_ptr<Person>)> voidFunPerson;          // Función lambda que toma un puntero compartido a Person y devuelve void
typedef function<bool(shared_ptr<Person>)> boolFunPerson;          // Función lambda que toma un puntero compartido a Person y devuelve bool
typedef function<shared_ptr<Person>(shared_ptr<Person>)> PersonFunPerson; // Función lambda que toma y devuelve un puntero compartido a Person

// Definiciones de tipos adicionales para vectores de enteros y funciones lambda con enteros
typedef vector<int> vi;                         // Vector de enteros
typedef function<void(int,int)> flambda;             // Función lambda que toma un entero y devuelve void
typedef function<bool(int)> boollambda;          // Función lambda que toma un entero y devuelve bool

//Funcion que no devuelve nada, se le pasa un entero y le aplica una funcion lamda
void forEachelem(vi const &v, flambda const &f) {
    for (int i = 0; i < v.size(); i++) {
        f(v.at(i), i);
    }
}

// Función que aplica una función lambda a cada elemento de un vector de punteros a Person
void forEachPersons(vP const &v, voidFunPerson const &f)
{
    for (auto const &elem : v)
    {
        f(elem);  // Aplica la función lambda f a cada elemento del vector v
    }
}

// Función que filtra los elementos de un vector de punteros a Person según una condición dada por una función lambda
vP filterPersons(vP const &v, boolFunPerson const &f)
{
    vP result;
    for (auto const &elem : v)
    {
        if (f(elem))  // Si el elemento cumple la condición, se agrega al resultado
            result.push_back(elem);
    }
    return result;  // Devuelve el vector con los elementos que cumplen la condición
}

// Función que verifica si al menos un elemento de un vector de punteros a Person cumple una condición dada por una función lambda
bool somePersons(vP const &v, boolFunPerson const &f)
{
    for (auto const &elem : v)
    {
        if (f(elem))  // Si algún elemento cumple la condición, devuelve true
            return true;
    }
    return false;  // Si ningún elemento cumple la condición, devuelve false
}

// Función que verifica si todos los elementos de un vector de punteros a Person cumplen una condición dada por una función lambda
bool everyPersons(vP const &v, boolFunPerson const &f)
{
    for (auto const &elem : v)
    {
        if (!f(elem))  // Si algún elemento no cumple la condición, devuelve false
            return false;
    }
    return true;  // Si todos los elementos cumplen la condición, devuelve true
}

// Función que aplica una transformación a cada elemento de un vector de punteros a Person usando una función lambda
vP transformPerson(vP const &v, PersonFunPerson const &f)
{
    vP result;
    for (auto elem : v)
    {
        // Copia profunda de la persona para no modificar el original
        shared_ptr<Person> copiaDeLaPersona = make_shared<Person>(*elem);
        result.push_back(f(copiaDeLaPersona));  // Aplica la función lambda f y agrega el resultado al vector result
    }
    return result;  // Devuelve el vector con los elementos transformados
}

// Función que encuentra el primer elemento de un vector de punteros a Person que cumple una condición dada por una función lambda
shared_ptr<Person> findFirstPerson(vP const &v, boolFunPerson const &f)
{
    for (auto const &elem : v)
    {
        if (f(elem))  // Si el elemento cumple la condición, lo devuelve
            return elem;
    }
    return nullptr;  // Si ningún elemento cumple la condición, devuelve nullptr
}

int main()
{
    // Inicialización de un vector de punteros a Person con varias personas
    vP personas{
        make_shared<Person>(Person{"Alberto", 19}),
        make_shared<Person>(Person{"José", 12}),
        make_shared<Person>(Person{"Juan", 42}),
        make_shared<Person>(Person{"Luis", 13}),
        make_shared<Person>(Person{"María", 65}),
        make_shared<Person>(Person{"Lucía", 19})};

    // Mostrar todas las personas en la lista
    cout << "Lista de personas:\n";
    forEachPersons(personas, [](shared_ptr<Person> p)
                   { cout << "Nombre: " << p->name << ", Edad: " << p->edad << endl; });

    // Mostrar las personas mayores de 18 años
    cout << "\nPersonas mayores de 18 años:\n";
    forEachPersons(personas, [](shared_ptr<Person> p)
                   { if (p->edad >= 18) cout << "Nombre: " << p->name << ", Edad: " << p->edad << endl; });

    // Filtrar personas mayores de 20 años
    auto mayoresDe20 = filterPersons(personas, [](shared_ptr<Person> p)
                                     { return p->edad > 20; });

    // Mostrar las personas mayores de 20 años
    cout << "\nPersonas mayores de 20 años:\n";
    forEachPersons(mayoresDe20, [](shared_ptr<Person> p)
                   { cout << "Nombre: " << p->name << ", Edad: " << p->edad << endl; });

    // Verificar si hay alguna persona llamada "Alberto"
    bool existeAlberto = somePersons(personas, [](shared_ptr<Person> p)
                                     { return p->name == "Alberto"; });
    if (existeAlberto)
        cout << "\nHay algún Alberto\n";

    // Verificar si todas las personas son mayores de 15 años
    bool todosMayoresDe15 = everyPersons(personas, [](shared_ptr<Person> p)
                                         { return p->edad > 15; });

    if (todosMayoresDe15)
        cout << "Todos son mayores de 15\n";

    // Incrementar la edad de todas las personas en 1 año
    auto todosMasViejos = transformPerson(personas, [](shared_ptr<Person> p)
                                          {
                                              p->edad++;
                                              return p; });

    // Mostrar las personas después de incrementar su edad
    cout << "\nPersonas después de incrementar su edad:\n";
    forEachPersons(todosMasViejos, [](shared_ptr<Person> p)
                   { cout << "Nombre: " << p->name << ", Edad: " << p->edad << endl; });

    // Encontrar la primera persona mayor de 50 años
    auto primeraMayorDeCincuenta = findFirstPerson(personas, [](shared_ptr<Person> p)
                                                   { return p->edad > 50; });

    if (primeraMayorDeCincuenta)
    {
        cout << "\nPrimera persona mayor de 50 años: " << primeraMayorDeCincuenta->name << ", Edad: " << primeraMayorDeCincuenta->edad << endl;
    }
    else
    {
        cout << "\nNo hay ninguna persona mayor de 50 años en el vector.\n";
    }

    //----------------------------------------------------------------------------------------------------EJEMPLO FOREACH CON [] 
    // {1,2,3,4,5,6,7}
    // {2,3,4,5,6,6,3}
    
    vector<int> a{1, 2, 3, 4, 5, 6, 7};
    vector<int> b{2, 3, 4, 5, 6, 6, 3};
    vector<int> nuevo;
    
    // [] --> no tengo acceso a nada de fuera
    // [&] --> tengo acceso a lo de fuera como referencia
    // [=] --> tengo acceso a lo de fuera como referencia constante
    
    forEachelem(a, [&nuevo, b](int elem, int i)
    { nuevo.push_back(elem + b.at(i)); });
    
    
    //----------------------------------------------------------------------------------------------------CONSTRUCCION FIBONACCI
    
    vector<int>fibonacci{1,2};
    vector<int>contador{3,4,5,6,7,8,9,10};
    
    forEachelem(contador,[&fibonacci](int elem,int pos){
                int size = fibonacci.size();
                fibonacci.push_back(fibonacci.at(size-1)+fibonacci.at(size-2));});

    //AHORA SUMAMOS LOS DIEZ PRIMEROS ELEMENTOS DE LA SERIE
    int suma{0};
    forEachelem(fibonacci,[&suma](int elem, int pos){
                suma = suma + elem;
                cout<<"Sumando la posicion"<<pos<<" con resultado: "<<suma<<endl;});

    cout<<suma<<" es el resultado de la suma total de los 10 primeros valores de la serie de Fibonacci"<<endl;

    return 0;
}
