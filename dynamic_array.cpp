#include <iostream>

using namespace std;

int main()
{
    int *a = NULL;  // Pointer to int, initialize to nothing.
    int n;          // Size needed for array
    cin >> n;       // Read in the size
    a = new int[n]; // Allocate n ints and save ptr in a.
    for (int i = 0; i < n; i++)
    {
        a[i] = i; // Initialize all elements to zero.
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    delete[] a; // When done, free memory pointed to by a.
    a = NULL;
    return 0;
}