// BasicShape.h
// Defines BasicShape (abstract), Circle, Rectangle, and Square classes.

#ifndef BASICSHAPE_H
#define BASICSHAPE_H

#include <iostream>
#include <string>
using namespace std;

// =============================================================
//                   ABSTRACT BASE CLASS
// =============================================================
class BasicShape {
private:
    double area;
    string name;

public:
    // Constructor
    BasicShape() : area(0.0), name("") {}

    // Getters
    double getArea() const { return area; }
    string getName() const { return name; }

    // Setters
    void setArea(double a) { area = a; }
    void setName(const string &n) { name = n; }

    // Pure virtual function
    virtual void calcArea() = 0;

    // Virtual destructor
    virtual ~BasicShape() {}
};

// =============================================================
//                          CIRCLE
// =============================================================
class Circle : public BasicShape {
private:
    double xCenter;
    double yCenter;
    double radius;

public:
    Circle(double x, double y, double r, string n = "Circle")
        : xCenter(x), yCenter(y), radius(r)
    {
        setName(n);
        calcArea();
    }

    // Getter functions
    double getX() const { return xCenter; }
    double getY() const { return yCenter; }
    double getRadius() const { return radius; }

    // Calculates area of a circle
    void calcArea() override {
        double a = 3.14159 * radius * radius;
        setArea(a);
    }
};

// =============================================================
//                        RECTANGLE
// =============================================================
class Rectangle : public BasicShape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w, string n = "Rectangle")
        : length(l), width(w)
    {
        setName(n);
        calcArea();
    }

    // Getter functions
    double getLength() const { return length; }
    double getWidth() const { return width; }

    // Calculates area of a rectangle
    void calcArea() override {
        double a = length * width;
        setArea(a);
    }
};

// =============================================================
//                          SQUARE
// =============================================================
class Square : public Rectangle {
private:
    double side;

public:
    Square(double s, string n = "Square")
        : Rectangle(s, s, n), side(s)
    {
        setName(n);
        // Rectangle constructor already called calcArea()
    }

    double getSide() const { return side; }
};

#endif