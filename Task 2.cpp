#include <iostream>
#include <cmath>
#define PI 3.141
using namespace std;

class Shape 
{ 
public:
    Shape() {}
    virtual void area() const = 0;
    virtual void perimeter() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{ 
public:
    Circle(double radius) : r(radius) {}
    void area() const
    {          
        cout << PI * r * r << endl;
    }
    void perimeter() const 
    {           
        cout << 2 * PI * r << endl;
    }

private:
    double r;
};

class Rectangle : public Shape 
{
public:
    Rectangle(double side_a, double side_b) : a(side_a), b(side_b) {}
    void area() const 
    {           
        cout << a * b << endl;
    }
    void perimeter() const 
    {            
        cout << 2 * (a + b) << endl;
    }

private:
    double a, b;
};

class Square : public Rectangle
{ 
public:
    Square(double side) : Rectangle(side, side) {}
};

int main()
{
    Shape** array = new Shape * [3];
    array[0] = new Circle(2);
    array[1] = new Rectangle(4, 5);
    array[2] = new Square(6);

    for (int i = 0; i < 3; i++)
    {
        array[i]->area();
    }

    delete array[0];
    delete array[1];
    delete array[2];
    delete[] array;

    return 0;
}