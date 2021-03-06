#include <iostream>

using namespace std;


// Function to display given array
void display_array(const int a[], const int n)
{
    for (int i=0; i<n; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}


// Function to perform insertion_sort
void insertion_sort(int arr[], const int n)
{
    for (int i=1; i<n; i++)
    {
        int j = i;
        while (true)
        {
            if (j==0 || arr[j] > arr[j-1])
                break;
            if (arr[j] < arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            j--;
        }
    }

    display_array(arr, n);
}


// Main Function
int main()
{
    int arr[] = {8,5,7,3,2,7,9};
    const int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);

    return 0;
}
