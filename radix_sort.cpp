
// Program for radix sort

#include <iostream>

using namespace std;

int max1 = 3;
int N = 50;

void display(int arr[], int n)
{
    cout << "\nArray:";
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
}

void put_in_bucket(int arr[], int n, int i)
{
    int indexes[10] = {0};
    int bucket[10][N];
    int j, mod, rem, num;

    // Put the elements in bucket
    for (int k = 0; k < n; k++)
    {
        j = i;
        num = arr[k];
        while (j < max1)
        {
            num = num / 10;
            j++;
        }
        rem = num % 10;
        bucket[rem][indexes[rem]++] = arr[k];
    }

    // Put them back in array
    j = 0;
    for (int k = 0; k < 10; k++)
    {
        for (int t = 0; t < indexes[k]; t++)
        {
            arr[j++] = bucket[k][t];
        }
    }
}

void radix_sort(int arr[], int n)
{
    // Select pos
    for (int i = max1; i >= 1; i--)
    {
        put_in_bucket(arr, n, i);
    }
}

int main()
{
    int arr[] = {7, 9, 5, 3, 13, 1, 6};
    int n = 7;

    display(arr, n);

    radix_sort(arr, n);

    display(arr, n);

    return 0;
}