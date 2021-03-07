
// Write your own implementation of memcpy()

#include <iostream>

using namespace std;


void my_memcpy(void *dest, void *source, const int size)
{
    char *t1 = (char *)dest;
    char *t2 = (char *)source;

    for (int i=0; i<size; i++)
    {
        t1[i] = t2[i];
    }
}

void display_arr(int arr[], const int n)
{
    for(int i=0; i<n; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}

int main()
{
    int a[] = {1,2,3,4,5};
    const int n = sizeof(a) / sizeof(a[0]);
    int b[n];

    display_arr(b, n);

    my_memcpy(b, a, sizeof(a));

    display_arr(b, n);

    return 0;
}