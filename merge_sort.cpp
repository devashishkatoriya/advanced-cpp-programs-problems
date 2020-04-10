
// Program for merge sort

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

void merge(int arr[], int l, int mid, int h)
{
    int i, j, k, n;
    i = l;
    j = mid + 1;

    n = h - l + 1;

    int *temp;
    temp = new int[n];

    k = 0;
    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    k = 0;
    while (k < n)
    {
        arr[l + k] = temp[k];
        k++;
    }
}

void merge_sort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;

        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

int main()
{
    int arr[] = {7, 9, 5, 3, 13, 1, 6};
    int n = 7;

    display(arr, n);

    merge_sort(arr, 0, n - 1);

    display(arr, n);

    return 0;
}