#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct Persona {
    string nombre;
    int edad;
    bool mayorEdad = false;
};

void mostrarPersonas(const vector<Persona>& personas) {
    for (const auto& persona : personas) {
        cout << "Nombre: " << persona.nombre << ", Edad: " << persona.edad << ", Mayor de Edad: " << (persona.mayorEdad ? "Si" : "No") << endl;
    }
}

void mostrarPersonasPtr(const vector<shared_ptr<Persona>>& personas) {
    for (const auto& persona : personas) {
        cout << "Nombre: " << persona->nombre << ", Edad: " << persona->edad << ", Mayor de Edad: " << (persona->mayorEdad ? "Si" : "No") << endl;
    }
}

int main() {
    vector<shared_ptr<Persona>> mispersonas;

    // Añadiendo 10 personas diferentes al vector
    mispersonas.push_back(make_shared<Persona>(Persona{"Juan Perez", 17}));
    mispersonas.push_back(make_shared<Persona>(Persona{"Maria Garcia", 16}));
    mispersonas.push_back(make_shared<Persona>(Persona{"Carlos Ramirez", 65}));
    mispersonas.push_back(make_shared<Persona>(Persona{"Ana Martinez", 14}));
    mispersonas.push_back(make_shared<Persona>(Persona{"Luis Gomez", 23}));
    mispersonas.push_back(make_shared<Persona>(Persona{"Sofia Hernandez", 42}));
    mispersonas.push_back(make_shared<Persona>(Persona{"Pedro Diaz", 11}));
    mispersonas.push_back(make_shared<Persona>(Persona{"Laura Lopez", 10}));
    mispersonas.push_back(make_shared<Persona>(Persona{"Miguel Sanchez", 79}));
    mispersonas.push_back(make_shared<Persona>(Persona{"Lucia Torres", 8}));

    // Mostrar la lista de personas
    cout << "Personas totales (con punteros): \n\n";
    //mostrarPersonasPtr(mispersonas);

    // Filtrar a un nuevo vector las personas mayores de edad
    vector<shared_ptr<Persona>> mayoresEdad;
    for (const auto& a : mispersonas) {
        if (a->edad >= 18) mayoresEdad.push_back(a);
    }

    // Cambiamos el atributo booleano
    for (auto& persona : mayoresEdad) {
        persona->mayorEdad = true;
    }

    // Mostrar la lista de personas mayores de edad
    cout << "\n\nPersonas mayores de edad (con punteros):\n";
    mostrarPersonasPtr(mispersonas);

    // Parte adicional sin el uso de punteros
    vector<Persona> mispersonasSinPunteros = {
        {"Juan Perez", 17},
        {"Maria Garcia", 16},
        {"Carlos Ramirez", 65},
        {"Ana Martinez", 14},
        {"Luis Gomez", 23},
        {"Sofia Hernandez", 42},
        {"Pedro Diaz", 11},
        {"Laura Lopez", 10},
        {"Miguel Sanchez", 79},
        {"Lucia Torres", 8}
    };

    // Mostrar la lista de personas sin punteros
    cout << "\n\nPersonas totales (sin punteros): \n\n";
    //mostrarPersonas(mispersonasSinPunteros);

    // Filtrar a un nuevo vector las personas mayores de edad sin punteros
    vector<Persona> mayoresEdadSinPunteros;
    for (const auto& a : mispersonasSinPunteros) {
        if (a.edad >= 18) mayoresEdadSinPunteros.push_back(a);
    }

    // Cambiamos el atributo booleano
    for (auto& persona : mayoresEdadSinPunteros) {
        persona.mayorEdad = true;
    }

    // Mostrar la lista de personas mayores de edad sin punteros
    cout << "\n\nPersonas mayores de edad (sin punteros):\n";
    //mostrarPersonas(mayoresEdadSinPunteros);

    return 0;
}

