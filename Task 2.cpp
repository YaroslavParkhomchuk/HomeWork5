#include <iostream>
#include <cmath>
#define PI 3.141
using namespace std;

class Shape 
{ 
public:
    Shape() {}
    virtual void square() const = 0;
    virtual void perimeter() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{ 
public:
    Circle(double radius) : r(radius) {}
    void square() const
    {          
        cout << PI * r * r;
    }
    void perimeter() const 
    {           
        cout << 2 * PI * r;
    }

private:
    double r;
};

class Rectangle : public Shape 
{
public:
    Rectangle(double side_a, double side_b) : a(side_a), b(side_b) {}
    void square() const 
    {           
        cout << a * b;
    }
    void perimeter() const 
    {            
        cout << 2 * (a + b);
    }

private:
    double a, b;
};

class Square : public Shape 
{ 
public:
    Square(double side_a) : a(side_a) {}
    void square() const
    {            
        cout << a * a;
    }
    void perimeter() const 
    {            
        cout << 4 * a;
    }

private:
    double a;
};

int main()
{
    Circle circle(5);
    cout << "Circle: " << endl;
    circle.square();
    cout << endl;
    circle.perimeter();
    cout << endl;

    Rectangle rectangle(3, 4);
    cout << "\nRectangle: " << endl;
    rectangle.square();
    cout << endl;
    rectangle.perimeter();
    cout << endl;

    Square square(6);
    cout << "\nSquare: " << endl;
    square.square();
    cout << endl;
    square.perimeter();
    cout << endl;

    return 0;
}