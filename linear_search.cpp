#include <iostream>

using namespace std;

// Function to search an array linearly
int linear_search(const int arr[], const int n, const int key)
{
    for (int i=0; i<n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    const int arr[] = {1, 2, 3, 4, 5, 6, 7};
    const int n = sizeof(arr) / sizeof(arr[0]);

    const int key = -1;

    const int pos = linear_search(arr, n, key);

    if (pos == -1)
        cout << "Key not found." << endl;
    else
        cout << "Key is at postion: " << pos+1 << endl;

    return 0;
}
