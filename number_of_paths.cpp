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

void display_char(int i, int j)
{
    char disp[3][3] = {{'A', 'B', 'C'},
                       {'D', 'E', 'F'},
                       {'G', 'H', 'I'}};

    cout << disp[i][j] << endl;
}

void n_paths(int r, int c, int i, int j, int *n)
{
    cout << endl;
    //cout << i << j << endl;

    if (i < r - 1)
    {
        display_char(i, j);
        i = i + 1;
        n_paths(r, c, i, j, n);
    }
    if (j < c - 1)
    {
        display_char(i, j);
        j = j + 1;
        n_paths(r, c, i, j, n);
    }
    display_char(i, j);
    if (i == r - 1 && j == c - 1)
        *n = *n + 1;
}

int main()
{
    int r = 3, c = 3, n = 0;

    n_paths(r, c, 0, 0, &n);
    cout << "Ans:" << n << endl;

    return 0;
}