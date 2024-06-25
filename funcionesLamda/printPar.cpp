#include <functional>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef function<void(int)> lambda;

// forEach -> recorre un vector y hace "algo" con cada uno de sus elementos
void forEach(vi const &v, lambda const &f) {
    for (auto elem : v) {
        f(elem);
    }
}

// filter -> recibe un vector y una condición, devuelve un vector con los elementos que cumplen la condición
vector<int> filter(vector<int> const &v, function<bool(int)> const &f) {
    vector<int> result;
    for (auto elem : v) {
        if (f(elem)) {
            result.push_back(elem);
        }
    }
    return result;
}

// transform -> recibe un vector y una función lambda, devuelve un vector con los elementos transformados
vector<int> transform(vector<int> const &v, function<int(int)> const &f) {
    vector<int> result;
    for (auto elem : v) {
        result.push_back(f(elem));
    }
    return result;
}

int main() {
    lambda print = [](int a) {
        cout << a << " ";
    };

    vi miVector{1, 2, 3, 4, 5, 6};

    forEach(miVector, print);
    cout << endl;

    // Lambda para evaluar si un elemento es mayor que dos
    auto greaterThanTwo = [](int a) -> bool {
        return a > 2;
    };

    // Filtrar los elementos del vector que son mayores que dos
    vi filteredVector = filter(miVector, greaterThanTwo);

    // Imprimir los elementos filtrados
    forEach(filteredVector, print);
    cout << endl;

    // Lambda para transformar un elemento multiplicándolo por 2
    auto multiplyByTwo = [](int a) -> int {
        return a * 2;
    };

    // Transformar los elementos del vector multiplicándolos por 2
    vi transformedVector = transform(miVector, multiplyByTwo);

    // Imprimir los elementos transformados
    forEach(transformedVector, print);
    cout << endl;

    return 0;
}
