#include <functional>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Función que aplica una función lambda a cada elemento de un vector de T
template<typename T>
void forEach(vector<T> const &v, function<void(T)> const &f){
    for(auto const &elem:v){
        f(elem);
    }
}


// Función que verifica si al menos un elemento de un vector de T cumple una condición dada por una función lambda
template<typename T>
bool someElem(vector<T> const &v, function<bool(T)> const &f){
    for(auto const&elem:v){
        if(f(elem))return true;
    }
    return false;
}

// Función que verifica si todos los elementos de un vector de T cumplen una condición dada por una función lambda
template<typename T>
bool everyElem(vector<T> const &v, function<bool(T)> const &f){
    for(auto const &elem:v){
        if(!f(elem))return false;
    }
    return true;
}

// Función que aplica una transformación a cada elemento de un vector de T usando una función lambda
template<typename T>
vector<T> transformT(vector<T> const &v,function<T(T)>const &f){
    vector<T> resultado;
    for (auto const &elem : v){
        T aux = elem;
        resultado.push_back(f(aux));
    }
    return resultado;
}

// Función que encuentra el primer elemento de un vector de T que cumple una condición dada por una función lambda
template<typename T>
T findFirst(vector<T> const &v,function<bool(T)> const &f){
    for (auto const &elem : v)
    {
        if (f(elem)) // Si el elemento cumple la condición, lo devuelve
            return elem;
    }
    return v.at(0); // Si ningún elemento cumple la condición, devuelve nullptr
}

// Función que filtra los elementos de un vector de T según una condición dada por una función lambda
template<typename T>
vector<T> filterTvec(vector<T> const &v,function<bool(T)>const &f ){
    vector<T> resultado;
    for (auto const &elem : v)
    {
        if(f(elem))resultado.push_back(elem);
    }
    return resultado;
}



int main() {
    // Ejemplo con vector de enteros
    vector<int> nums = {1, 2, 3, 4, 5};

    // Uso de forEach para imprimir cada número
    cout << "Todos los números: ";
    forEach<int>(nums, [](int n) {
        cout << n << " ";
    });
    cout << endl;

    // Uso de someElem para verificar si hay algún número mayor que 3
    bool hasGreaterThanThree = someElem<int>(nums, [](int n) {
        return n > 3;
    });
    cout << "Hay algún número mayor que 3: " << (hasGreaterThanThree ? "Sí" : "No") << endl;

    // Uso de everyElem para verificar si todos los números son positivos
    bool allPositive = everyElem<int>(nums, [](int n) {
        return n > 0;
    });
    cout << "Todos los números son positivos: " << (allPositive ? "Sí" : "No") << endl;

    // Uso de transformT para incrementar cada número en 1
    vector<int> incrementados = transformT<int>(nums, [](int n) {
        return n + 1;
    });
    cout << "Números incrementados en 1: ";
    forEach<int>(incrementados, [](int n) {
        cout << n << " ";
    });
    cout << endl;

    // Uso de findFirst para encontrar el primer número mayor que 3
    int firstGreaterThanThree = findFirst<int>(nums, [](int n) {
        return n > 3;
    });
    if (firstGreaterThanThree) {
        cout << "El primer número mayor que 3 es: " << firstGreaterThanThree << endl;
    } else {
        cout << "No se encontró ningún número mayor que 3" << endl;
    }

    // Uso de filterTvec para encontrar todos los números mayores que 3
    vector<int> mayor3 = filterTvec<int>(nums, [](int n) {
        return n > 3;
    });
    cout << "Números mayores que 3: ";
    forEach<int>(mayor3, [](int n) {
        cout << n << " ";
    });
    cout << endl;

    // Ejemplo con vector de strings
    vector<string> palabras = {"manzana", "banana", "cereza", "datil"};

    // Uso de forEach para imprimir cada palabra
    cout << "Todas las palabras: ";
    forEach<string>(palabras, [](string s) {
        cout << s << " ";
    });
    cout << endl;

    // Uso de someElem para verificar si alguna palabra tiene más de 5 letras
    bool hasLongWord = someElem<string>(palabras, [](string s) {
        return s.size() > 5;
    });
    cout << "Hay alguna palabra con más de 5 letras: " << (hasLongWord ? "Sí" : "No") << endl;

    // Uso de everyElem para verificar si todas las palabras tienen más de 2 letras
    bool allWordsLong = everyElem<string>(palabras, [](string s) {
        return s.size() > 2;
    });
    cout << "Todas las palabras tienen más de 2 letras: " << (allWordsLong ? "Sí" : "No") << endl;

    // Uso de transformT para convertir cada palabra a mayúsculas
    vector<string> mayusculas = transformT<string>(palabras, [](string s) {
        for (auto &c : s) c = toupper(c);
        return s;
    });
    cout << "Palabras en mayúsculas: ";
    forEach<string>(mayusculas, [](string s) {
        cout << s << " ";
    });
    cout << endl;


    // Uso de filterTvec para encontrar todas las palabras que tienen más de 5 letras
    vector<string> palabrasLargas = filterTvec<string>(palabras, [](string s) {
        return s.size() > 5;
    });
    cout << "Palabras con más de 5 letras: ";
    forEach<string>(palabrasLargas, [](string s) {
        cout << s << " ";
    });
    cout << endl;

    return 0;
}
