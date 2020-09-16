#include <iostream>
#include <vector>

using namespace std;

vector<int> countingSort(vector<int> arr, int l, int h)
{
    int n = arr.size();
    vector<int> freq(h-l+1);

    // Generate freq map for given arr
    for(int i=0; i<n; i++)
    {
        freq[arr[i]-l]++;
    }

    // Calculate cumulative freq
    for(int i=1; i<h-l+1; i++)
    {
        freq[i] = freq[i-1] + freq[i];
    }
    return freq;
}


int main()
{
    int n = 10;
    vector<int> arr(n);

    cout<<"Array is ";
    for (int i=0; i<n; i++)
    {
        arr[i] = n - i;
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    arr = countingSort(arr, 1, 10);

    cout<<"Cum Freq is ";
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}