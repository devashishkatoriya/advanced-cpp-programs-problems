
// Sample program for demonstrating use of function pointer

#include <iostream>

void Log(std::string msg)
{
    std::cout << msg << std::endl;
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    void (*f_ptr)(std::string) = &Log;

    f_ptr("Hello");
    f_ptr("World");

    int (*f_add)(int, int) = &add;

    std::cout << f_add(5, 7) << std::endl;

    return 0;
}