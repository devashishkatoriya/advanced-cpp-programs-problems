
// Program to demonstrate the use of padding for structs or classes which have sizes not in multiple of 8

#include <iostream>

struct test1
{
    char a;
    char b;
    int n;
};

class test2
{
public:
    char a;
    char b;
    int n;
    test2(int a, int b, int c)
    {

    }
};


int main()
{
    struct test1 o1;
    test2 o2(1, 2, 3);
    
    std::cout << sizeof(o1) << std::endl;
    std::cout << sizeof(o2) << std::endl;

}