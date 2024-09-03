#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class Figura {
private:
    string color;

public:
    Figura(const string& c) : color(c) {}

    virtual ~Figura() {}

    // Métodos virtuales para área y perímetro (para ser sobrescritos por clases derivadas)
    virtual double area() const = 0;
    virtual double perimetro() const = 0;

    void setColor(const string& c) {
        color = c;
    }

    string getColor() const {
        return color;
    }

    // Método para mostrar la información de la figura
    virtual void mostrar() const {
        cout << "Color: " << color << endl;
    }
};

class Rectangulo : public Figura {
private:
    double ancho;
    double alto;

public:
    Rectangulo(const string& c, double a, double h) : Figura(c), ancho(a), alto(h) {}

    double area() const override {
        return ancho * alto;
    }

    double perimetro() const override {
        return 2 * (ancho + alto);
    }

    void mostrar() const override {
        cout << "Rectángulo:" << endl;
        Figura::mostrar();
        cout << "Ancho: " << ancho << ", Alto: " << alto << endl;
        cout << "Area: " << area() << ", Perimetro: " << perimetro() << endl;
    }
};

class Cuadrado : public Rectangulo {
public:
    Cuadrado(const string& c, double lado) : Rectangulo(c, lado, lado) {}

    void mostrar() const override {
        cout << "Cuadrado:" << endl;
        Figura::mostrar();
        cout << "Lado: " << perimetro() / 4 << endl; 
        cout << "Area: " << area() << ", Perimetro: " << perimetro() << endl;
    }
};

#include <cmath>

class Triangulo : public Figura {
private:
    double base;
    double altura;

public:
    Triangulo(const string& c, double b, double h) : Figura(c), base(b), altura(h) {}

    double area() const override {
        return (base*altura)/2;
    }

    // Perimetro para un trigangulo equilatero
    double perimetro() const override {
        return 3 * base;
    }

    void mostrar() const override {
        cout << "Triángulo:" << endl;
        Figura::mostrar();
        cout << "Area: " << area() << ", Perimetro: " << perimetro() << endl;
    }
};

class Circulo : public Figura{
private:
    double radio;
public:
    Circulo(const string& c, double r) : Figura(c), radio(r){}

    double area() const override {
        return 3.14159274101257324219 * radio * radio;
    }

    // Perimetro para un trigangulo equilatero
    double perimetro() const override {
        return 2*3.14159274101257324219*radio;
    }

    void mostrar() const override {
        cout << "Circulo:" << endl;
        Figura::mostrar();
        cout << "Area: " << area() << ", Perimetro: " << perimetro() << endl;
    }
};

int main() {
    // Crear un rectángulo
    Rectangulo rect("Rojo", 5.0, 3.0);
    rect.mostrar();

    cout << endl;

    // Crear un cuadrado
    Cuadrado cuad("Azul", 4.0);
    cuad.mostrar();

    cout << endl;

    // Crear un triángulo
    Triangulo tri("Verde", 6.0,  8.0);
    tri.mostrar();

    cout << endl;

    Circulo cir("Amarillo", 5.0);
    cir.mostrar();

    return 0;
}
