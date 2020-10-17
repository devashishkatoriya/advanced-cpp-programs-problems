#include <iostream>

using namespace std;

void display(int **arr, const int n)
{
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<endl;
        for(int j=0; j<n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
}

bool isSafe(int **board, const int n, const int row, const int col)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j] == 1)
            return false;

    return true;
}

void n_queens(int **board, const int n, const int pos)
{
    if (pos >= n)
    {
        display(board, n);
        return;
    }

    for(int i=0; i<n; i++)
    {
        if (isSafe(board, n, i, pos))
        {
            board[i][pos] = 1;
            n_queens(board, n, pos+1);
            board[i][pos] = 0;
        }
    }
}


int main()
{
    const int n = 4;

    int **board = new int*[n];
    for(int i=0; i<n; i++)
    {
        board[i] = new int[n];
    }

    n_queens(board, n, 0);

    return 0;
}