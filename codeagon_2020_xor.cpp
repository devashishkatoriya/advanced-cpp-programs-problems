
// Program to check if K consecutive elements have zero xor value
// if not print number of changes to be made

#include <iostream>
#include <vector>

using namespace std;

int getCount(const int arr[], const int n, const int k)
{
    int count = 0, xor1;

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

    return count;
}


int main()
{
    int n = 3, k = 3;
    int arr[] = {1,2,5};

    cout<<getCount(arr, n, k)<<endl;
    return 0;
}