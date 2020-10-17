#include <iostream>

using namespace std;

void display(const char arr[], const int n)
{
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void permute(char arr[], const int n, const int pos)
{
    if (pos >= n)
    {
        display(arr, n);
        return;
    }

    for(int k=pos; k<n; k++)
    {
        char temp = arr[pos];
        arr[pos] = arr[k];
        arr[k] = temp;

        permute(arr, n, pos+1);

        temp = arr[pos];
        arr[pos] = arr[k];
        arr[k] = temp;
    }
}

int main()
{
    char arr[] = {'A', 'B', 'C', 'D'};
    const int n = sizeof(arr) / sizeof(arr[0]);

    cout<<n<<endl;
    permute(arr, n, 0);

    return 0;
}