#include <iostream>

using namespace std;

int binary_search(const int arr[], const int l, const int h, const int key)
{
    if (l>h)
        return -1;

    const int mid = (l + h) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
    {
        return binary_search(arr, l, mid-1, key);
    }
    else
    {
        return binary_search(arr, mid+1, h, key);
    }
}

int main()
{
    const int arr[] = {1, 2, 3, 4, 5, 6, 7};
    const int n = sizeof(arr) / sizeof(arr[0]);

    const int key = 5;

    const int pos = binary_search(arr, 0, n-1, key);

    if (pos == -1)
        cout << "Key not found." << endl;
    else
        cout << "Key is at postion: " << pos+1 << endl;

    return 0;
}
