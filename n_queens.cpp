#include <iostream>

using namespace std;

int COUNT = 0;

void display(bool **arr, const int n)
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

bool isSafe(bool **board, const int n, const int row, const int col)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i] == true)
            return false;

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == true)
            return false;

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j] == true)
            return false;

    return true;
}

void n_queens(bool **board, const int n, const int pos)
{
    if (pos >= n)
    {
        display(board, n);
        COUNT++;
        return;
    }

    for(int i=0; i<n; i++)
    {
        if (isSafe(board, n, i, pos))
        {
            board[i][pos] = true;
            n_queens(board, n, pos+1);
            board[i][pos] = false;
        }
    }
}


int main()
{
    const int n = 5;

    bool **board = new bool*[n];
    for(int i=0; i<n; i++)
    {
        board[i] = new bool[n];
        for(int j=0; j<n; j++)
        {
            board[i][j] = false;
        }
    }

    n_queens(board, n, 0);

    cout<<"\n\nTotal possible ways: "<<COUNT<<endl;

    return 0;
}