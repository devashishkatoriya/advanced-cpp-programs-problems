
// Program to show the use of inheritance in C++

#include <iostream>

using namespace std;

class Shape
{
protected:
    float area;
    float perimeter;
    float *sides;
public:
    Shape()
    {
        area = 0;
        perimeter = 0;
        sides = NULL;
    }
    void calc_area();
};

class Rectangle: protected Shape
{
    int sides, l, b;
    void calc_area()
    {
        area = l * b;
    }
public:
    Rectangle()
    {
        sides = 0;
        l = 0;
        b = 0;
    }
    void set_sides(int x, int y)
    {
        l = x;
        b = y;
        calc_area();
    }

    void display_area()
    {
        cout << "Area: " << area << endl;
    }

};



int main()
{
    Rectangle a;
    a.set_sides(4, 5);
    a.display_area();
    return 0;
}
