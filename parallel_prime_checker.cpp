#include <iostream>
#include <omp.h>

using namespace std;

bool isPrime(const int n)
{
    if (n % 2 == 0)
        return false;

    int i, flag = true;
    #pragma omp parallel for
    for (i=3; i<n; i=i+2)
    {
        if (n % i == 0)
            flag = false;
    }
    return flag;
}

int main()
{
    int n = 5;
    cout<<isPrime(n);
    return 0;
}