#ifndef FIGURAS_H
#define FIGURAS_H

class FiguraGeometrica {
private:
    int nlados = 0;
public:
    virtual float getArea() const = 0;
    virtual float getPerimetro() const = 0;
    virtual void queSoy() const;
    virtual int getNumeroLados() const = 0;
};

class Cuadrado : public FiguraGeometrica {
private:
    float lado;
public:
    Cuadrado(float lado);
    void setLado(float lado);
    float getLado() const;
    float getArea() const ;
    float getPerimetro() const ;
    float getDiagonal() const;
    void queSoy() const ;
    int getNumeroLados() const ;
};

class Triangulo : public FiguraGeometrica {
private:
    float base, altura;
public:
    Triangulo(float base, float altura);
    void setBase(float base);
    void setAltura(float altura);
    float getBase() const;
    float getAltura() const;
    float getArea() const ;
    float getPerimetro() const;
    void queSoy() const ;
    int getNumeroLados() const ;
};

class Pentagono : public FiguraGeometrica {
private:
    float lado;
public:
    Pentagono(float lado);
    void setLado(float lado);
    float getLado() const;
    float getArea() const ;
    float getPerimetro() const ;
    void queSoy() const ;
    int getNumeroLados() const ;
};

#endif // FIGURAS_H
