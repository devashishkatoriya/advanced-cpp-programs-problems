#include <iostream>
#include <cstdarg>

int my_variadic_function(int n_arg, ...)
{
    // Create a variable to store arguements
    va_list arg_list;

    va_start(arg_list, n_arg);          // feed 'n_arg' number of arguements into arg_list

    int sum = 0;
    for (int i=0; i < n_arg; i++)
    {
        sum = sum + int(va_arg(arg_list, int));          //access the next element inside arg_list
    }

    va_end(arg_list);               // clean memory reserved for arg_list

    return sum;
}

int main()
{
    std::cout << my_variadic_function(6,1,2,3,4,5,6) << std::endl;
    std::cout << my_variadic_function(3,40,50,60) << std::endl;
}