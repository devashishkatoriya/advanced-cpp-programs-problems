
// Program to check if K consecutive elements have zero xor value
// if not print number of changes to be made

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 3, k = 3, xor1, count = 0;
    int arr[] = {1,2,5};

    for(int i=0; i<=n-k; i++)
    {
        xor1 = arr[i];
        for(int j=i+1; j<i+k; j++)
        {
            xor1 = xor1^arr[j];
        }
        if (xor1 != 0)
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}