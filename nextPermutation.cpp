
/*
Given an array of unique elements, design a function that will return a
unique sequence of all its elements every time it is called.
*/

#include <iostream>
#include <vector>

using namespace std;

int permute_no = 1;             // Used to track current permutation
int disp = 0;                   // Used to track which permutation of all to display

// Function used to display char vector
void displayArr(vector<char> arr, int disp)
{
    if (disp!=permute_no)
        return;
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    disp++;
}

// Function used to generate every possible permutation
void nextPermutation(vector<char> arr, const int pos, const int n)
{
    if (pos == n)
        displayArr(arr, ++disp);
    else
    {
        int current = pos;
        while(current <= n)
        {
            char temp = arr[pos];
            arr[pos] = arr[current];
            arr[current] = temp;

            nextPermutation(arr, pos+1, n);

            temp = arr[pos];
            arr[pos] = arr[current];
            arr[current] = temp;

            current++;
        }
    }
}

// Main Function
int main()
{
    int n = 6;
    vector<char> arr(n);

    for(int i=0; i<n; i++)
    {
        arr[i] = 'A' + i;
    }

    for (int i=0; i<10; i++)
    {
        nextPermutation(arr, 0, arr.size()-1);
        permute_no++;
        disp = 0;
    }
    return 0;
}