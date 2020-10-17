#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 1, 2, 3, 5};
    int n = 5;

    int mysum = 0, sum;
    float myprod = 1, prod = 1;

    // Calculate mysum and myprod
    for (int i=0; i<n; i++)
    {
        mysum = mysum + arr[i];
        myprod = myprod * arr[i];
    }

    // Calculate sum
    sum = (n*(n+1)) / 2;

    // Calculate prod
    for(int i=1; i<=n; i++)
    {
        prod = prod * i;
    }

    int x, y;
    y = (myprod * (sum-mysum)) / (prod * (1 - (myprod/prod)));
    x = sum - mysum + y;

    cout<<x<<endl;
    cout<<y<<endl;

    return 0;
}

