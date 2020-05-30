/*
Given an image represented as an array of pixels, 
develop an algorithm that flips it 180 degrees.  
*/

#include <iostream>

using namespace std;

int main()
{
    int n, m, i, j, temp;

    int arr[3][4] = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {1, 1, 0, 1}};

    n = 3;
    m = 4;

    for (int i = 0; i <= n / 2; i++)
    {
        for (int j = 0; j <= m / 2; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[n - i - 1][m - j - 1];
            arr[n - i - 1][m - j - 1] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
    }

    return 0;
}