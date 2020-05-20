/*
Missing number in array

Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.

Input:
The first line of input contains an integer T denoting the number of test cases. For each test case first line contains N(size of array). The subsequent line contains N-1 array elements.

Output:
Print the missing number in array.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 107
1 ≤ C[i] ≤ 107

Example:
Input:
2
5
1 2 3 5
10
1 2 3 4 5 6 7 8 10

Output:
4
9

Explanation:
Testcase 1: Given array : 1 2 3 5. Missing element is 4.
*/

#include <iostream>
using namespace std;
int main()
{
    int t, n, *a, *b, temp, j, k, swapped;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        a = new int[n - 1];
        b = new int[n];

        for (j = 0; j < n - 1; j++)
        {
            cin >> a[j];
            b[a[j] - 1] = 1;
        }

        for (j = 0; j < n; j++)
        {
            if (b[j] != 1)
            {
                cout << (j + 1) << endl;
                break;
            }
        }
    }

    return 0;
}