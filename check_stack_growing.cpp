#include <iostream>


void func1(int *p)
{
    int var2;

    if (p < &var2)
        std::cout << "Stack is growing." << std::endl;
    else
        std::cout << "Stack is shrinking." << std::endl;
}

int main()
{
    int var1;

    func1(&var1);
}