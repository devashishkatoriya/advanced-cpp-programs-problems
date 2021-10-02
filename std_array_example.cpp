
#include <iostream>
#include <array>
#include <algorithm>

template <class T>
void display_1d(const std::array<T, 3> &arr)
{
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

int main()
{
    std::array<std::string, 3> a1;
    a1[0] = "Hello";
    a1[1] = "My name is";
    a1[2] = "Devashish";
    display_1d<std::string>(a1);

    std::array<int, 3> a2 = {100, 20, 30};
    std::sort(a2.begin(), a2.end());
    display_1d<int>(a2);

    std::array<std::array<int, 4>, 5> matrix;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix[i][j] = i * j;
        }
    }
    matrix[0][1] = 1000;

    std::sort(matrix.begin(), matrix.end());

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}