/*
Given a 2D screen, location of a pixel in the screen ie(x,y) 
and a color(K), your task is to replace color of the given pixel 
and all adjacent(excluding diagonally adjacent) same colored 
pixels with the given color K.

Example:

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 2, 2, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 2, 2, 0},
{1, 1, 1, 1, 1, 2, 1, 1},
{1, 1, 1, 1, 1, 2, 2, 1},
 };

 x=4, y=4, color=3 

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1}, 
{1, 3, 3, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 3, 3, 0},
{1, 1, 1, 1, 1, 3, 1, 1},
{1, 1, 1, 1, 1, 3, 3, 1}, };

Note: Use zero based indexing.

Input:
The first line of input contains an integer T denoting the no of 
test cases. Then T test cases follow. The first line of each test 
case contains Two integers N and M denoting the size of the matrix. 
Then in the next line are N*M space separated values of the matrix. 
Then in the next line are three values x, y and K.

Output:
For each test case print the space separated values of the new matrix.

Constraints:
1 <= T <= 100
1 <= M[][] <= 100

Example:
Input:
3
3 4
0 1 1 0 1 1 1 1 0 1 2 3
0 1 5
2 2
1 1 1 1
0 1 8
4 4 
1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
0 2 9

Output:
0 5 5 0 5 5 5 5 0 5 2 3
8 8 8 8
1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4
*/

#include <iostream>

using namespace std;

void display_matrix(int matrix[8][8], int n, int m)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
    }
}

void flood_fill_algo(int matrix[8][8], int n, int m, int i, int j, int old_c, int new_c)
{
    if ((i >= 0 && i < n) && (j >= 0 && j < m))
    {
        if (matrix[i][j] == old_c)
        {
            matrix[i][j] = new_c;
            flood_fill_algo(matrix, n, m, i, j - 1, old_c, new_c);
            flood_fill_algo(matrix, n, m, i - 1, j, old_c, new_c);
            flood_fill_algo(matrix, n, m, i + 1, j, old_c, new_c);
            flood_fill_algo(matrix, n, m, i, j + 1, old_c, new_c);
        }
    }
}

int main()
{
    int n = 8, m = 8;
    int matrix[8][8] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 1},
        {1, 2, 2, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 2, 2, 0},
        {1, 1, 1, 1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1, 2, 2, 1},
    };

    int x = 4, y = 4, color = 3;

    display_matrix(matrix, n, m);

    flood_fill_algo(matrix, n, m, x, y, matrix[x][y], color);

    display_matrix(matrix, n, m);

    return 0;
}