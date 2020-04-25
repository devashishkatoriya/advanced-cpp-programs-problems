
// Program for shell sort

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

void shell_sort(int arr[], int n)
{
    int gap, temp, ele;
    gap = n / 2;

    while (gap >= 1)
    {
        for (int j = 0; j < gap; j++)
        {
            // Perform insertion sort
            cout << "\ngap:" << gap << "j:" << j;
            ele = arr[gap - 1];

            for (int i = j; i < n - gap; i = i + gap)
            {
                cout << "\ni:" << i;

                if (arr[i] > arr[i + gap])
                {
                    temp = arr[i];
                    arr[i] = arr[i + gap];
                    arr[i + gap] = temp;
                }
            }

            arr[gap - 1] = ele;
        }
        gap = gap / 2;

        display(arr, n);
    }
}

int main()
{
    int arr[] = {7, 9, 5, 3, 13, 1, 6};
    int n = 7;

    display(arr, n);

    shell_sort(arr, n);

    display(arr, n);

    return 0;
}

/*
OUTPUT

Array: 7 9 5 3 13 1 6
Array: 1 3 5 6 7 9 13

*/