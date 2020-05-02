/*
The problem is to count all the possible paths from top left 
to bottom right of a MxN matrix with the constraints that from 
each cell you can either move to right or down.

Input:
The first line of input contains an integer T, denoting the 
number of test cases. The first line of each test case is M 
and N, M is number of rows and N is number of columns.

Output:
For each test case, print the number of paths.

Constraints:
1 ≤ T ≤ 30
1 ≤ M,N ≤ 10

Example:
Input
2
3 3
2 8

Output
6
8

Explanation:
Testcase 1: Let the given input 3*3 matrix is filled as such:
A B C
D E F
G H I
The possible paths which exists to reach 'I' from 'A' following 
above conditions are as follows:
ABCFI, ABEHI, ADGHI, ADEFI, ADEHI, ABEFI.
*/

#include <iostream>

using namespace std;

void n_paths(int r, int c, int i, int j, int *n)
{
    cout << endl;
    cout << i << j << endl;

    if (i == r - 1 && j == c - 1)
        *n = *n + 1;
    else
    {
        if (i < r - 1)
            n_paths(r, c, i + 1, j, n);
        if (j < c - 1)
            n_paths(r, c, i, j + 1, n);
    }
}

int main()
{
    int r = 2, c = 8, n = 0;

    n_paths(r, c, 0, 0, &n);
    cout << "\nAns:" << n << endl;

    return 0;
}