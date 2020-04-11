
// Program for quick sort

#include <iostream>

using namespace std;

void display(int arr[], int n)
{
    cout << "\nArray:";
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[h];

    int i = l, j = h - 1, temp;

    while (i <= j)
    {
        if (arr[i] > arr[j])
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    return pivot;
}

void quick_sort(int arr[], int l, int h)
{
    if (l < h)
    {
        int pos = partition(arr, l, h);

        quick_sort(arr, l, pos);
        quick_sort(arr, pos + 1, h);
    }
}

int main()
{
    int arr[] = {7, 9, 5, 3, 13, 1, 6};
    int n = 7;

    display(arr, n);

    quick_sort(arr, 0, n - 1);

    display(arr, n);

    return 0;
}