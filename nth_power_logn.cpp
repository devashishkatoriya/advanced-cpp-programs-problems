
// Program for log n multiplication for finding nth power of a number

#include <iostream>

using namespace std;

int power(int num, int p)
{
    if (p == 1)
        return num;
    if (p == 0)
        return 1;
    if (p % 2 == 0)
    {
        return power(num * num, p/2);
    }
    return num * power(num * num, (p-1)/2);
}

int main()
{
    for (int i=0; i<=20; i++)
        cout << power(2, i) << endl;
    return 0;
}