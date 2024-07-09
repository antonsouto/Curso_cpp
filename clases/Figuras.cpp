#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include "Figuras.h"

// Implementación de FiguraGeometrica
void FiguraGeometrica::queSoy() const {
    std::cout << "Soy una figura geometrica." << std::endl;
}

// Implementación de Cuadrado
Cuadrado::Cuadrado(float lado) : lado(lado) {}

void Cuadrado::setLado(float lado) {
    this->lado = lado;
}

float Cuadrado::getLado() const {
    return lado;
}

float Cuadrado::getArea() const {
    return lado * lado;
}

float Cuadrado::getPerimetro() const {
    return 4 * lado;
}

float Cuadrado::getDiagonal() const {
    return lado * sqrt(2);
}

void Cuadrado::queSoy() const {
    std::cout << "Soy un cuadrado." << std::endl;
}

int Cuadrado::getNumeroLados() const {
    return 4;
}

// Implementación de Triangulo
Triangulo::Triangulo(float base, float altura) : base(base), altura(altura) {}

void Triangulo::setBase(float base) {
    this->base = base;
}

void Triangulo::setAltura(float altura) {
    this->altura = altura;
}

float Triangulo::getBase() const {
    return base;
}

float Triangulo::getAltura() const {
    return altura;
}

float Triangulo::getArea() const {
    return (base * altura) / 2;
}

float Triangulo::getPerimetro() const {
    // Supongamos un triángulo equilátero para simplificar
    return 3 * base;
}

void Triangulo::queSoy() const {
    std::cout << "Soy un triangulo." << std::endl;
}

int Triangulo::getNumeroLados() const {
    return 3;
}

// Implementación de Pentagono
Pentagono::Pentagono(float lado) : lado(lado) {}

void Pentagono::setLado(float lado) {
    this->lado = lado;
}

float Pentagono::getLado() const {
    return lado;
}

float Pentagono::getArea() const {
    float apotema = lado / (2 * tan(M_PI / 5));
    return (5 * lado * apotema) / 2;
}

float Pentagono::getPerimetro() const {
    return 5 * lado;
}

void Pentagono::queSoy() const {
    std::cout << "Soy un pentagono." << std::endl;
}

int Pentagono::getNumeroLados() const {
    return 5;
}




