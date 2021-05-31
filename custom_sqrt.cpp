// Program to find square root of an integer

#include <iostream>

float getSqrt(const int num, int deci = 10)
{
    if ((num==0) || (num==1))
        return num;

    // Find integeral sqrt of num
    double i = 1, inc = 1;

    while(deci >= 0)
    {
        while(i*i <= num)
        {
            i += inc;
        }
        i -= inc;
        inc = inc / 10;
        deci--;
    }

    return i;
}

int main()
{
    std::cout << getSqrt(31) << std::endl;

    return 0;
}