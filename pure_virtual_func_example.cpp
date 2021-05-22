#include <iostream>

using namespace std;

// A class is considered abstract if any one of its member function is pure virtual
class Shape
{
public:
    int sides;
    Shape(int s)
    {
        sides = s;
    }
    virtual double getArea() = 0;       // Virtual functions are converted into pure-virtual by adding '=0'
};

class Rectangle : public Shape
{
    int l, b;
public:
    Rectangle(int length, int breadth) : Shape(2)           // way to pass parameters to base class constructor
    {
        l = length;
        b = breadth;
    }

    // Definition of pure virtual function
    double getArea()
    {
        return l * b;
    }

};

int main()
{
    Shape *s = new Rectangle(4, 5);
    std::cout << s->getArea() << std::endl;
}