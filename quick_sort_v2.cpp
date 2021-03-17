
// Program for quick sort with first element as pivot

#include <iostream>


// Function to display array
void display_array(int arr[], const int n)
{
    for (int i=0; i<n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
} 


// Function to partition quick sort
int partition(int arr[], const int l, const int h)
{
    const int pivot = arr[l];
    int i = l+1, j = h;

    while(i<=j)
    {
        if (arr[i] <= pivot)
        {
            i++;
        }
        else if (arr[j] > pivot)
        {
            j--;
        }
        else {
            const int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    const int temp = arr[l];
    arr[l] = arr[i-1];
    arr[i-1] = temp;

    return (i-1);
}


// Function for quick sort
void quick_sort(int arr[], const int l, const int h)
{
    if (l < h)
    {
        const int pos = partition(arr, l, h);

        quick_sort(arr, l, pos-1);
        quick_sort(arr, pos+1, h);
    }
}

int main()
{
    int arr[] = {5,3,6,9,5,3,1,4,6,8};
    const int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, n-1);

    display_array(arr, n);

    return 0;
}