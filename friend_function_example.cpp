
// Program to demonstrate the use of friend function in C++

#include <iostream>

using namespace std;

class Demo
{
    int x;
protected:
    int y;
public:
    int z;

    Demo()
    {
        x = 1;
        y = 2;
        z = 3;
    }

    friend void display_params(Demo);
};


void display_params(Demo obj)
{
    cout << "X: " << obj.x << endl;
    cout << "Y: " << obj.y << endl;
    cout << "Z: " << obj.z << endl;
}

int main()
{
    Demo obj;
    display_params(obj);

    return 0;
}
