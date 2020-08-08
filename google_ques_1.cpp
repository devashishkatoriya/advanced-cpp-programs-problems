/*

This question was asked by: Google
You are given the layout of a rectangular building with rooms forming a grid.
Each room has four doors to the room to the north, east, south, and west where
exactly one door is unlocked and the other three doors are locked. In each time
step, you can move to an adjacent room via an unlocked door.

Your task is to determine the minimum number of time steps required to get from
the northwest corner to the southeast corner of the building.

The input is given as:

a non-empty 2d-array of letters 'N', 'E', 'S', 'W' named 'building'
'building[0][0]' represents the open door at the northwest corner.
The rows of this array are associated with north-south direction.
The columns are associated with east-west direction.
Example:

E E S W
N W S N
S E E S
E N W W

Expected Output: 6
*/

#include <iostream>

using namespace std;

void display(char arr[4][4], int n, int m)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    char arr[4][4] = {
        {'E', 'E', 'S', 'W'},
        {'N', 'W', 'S', 'N'},
        {'S', 'E', 'E', 'S'},
        {'E', 'N', 'W', 'W'}};
    int n = 4;
    int m = 4;

    display(arr, n, m);

    int x = 0, y = 0, cnt = 0;

    while (x <= n - 1 && y <= m - 1 && x >= 0 && y >= 0)
    {
        cout << arr[x][y] << " -> ";
        if (arr[x][y] == 'E')
        {
            y = y + 1;
        }
        else if (arr[x][y] == 'N')
        {
            x = x - 1;
        }
        else if (arr[x][y] == 'W')
        {
            y = y - 1;
        }
        else if (arr[x][y] == 'S')
        {
            x = x + 1;
        }
        else
        {
            cout << "Invalid move!" << endl;
            return -1;
        }
        if (x == n - 1 and y == m - 1)
        {
            cout << arr[x][y] << " -> "
                 << "Reached" << endl;
            break;
        }
    }

    if (x < 0)
    {
        cout << "Out of bounds!" << endl;
        return -1;
    }
    else if (y < 0)
    {
        cout << "Out of bounds!" << endl;
        return -1;
    }

    return 0;
}

/*
OUTPUT
E E S W
N W S N
S E E S
E N W W
E -> E -> S -> S -> E -> S -> W -> Reached
*/
