/*
Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

Input:
The first line of input contains an integer T denoting the number 
of test cases. Then T test cases follow. Each test case consists 
of two lines. The first line of each test case is N and S, where 
N is the size of array and S is the sum. The second line of each 
test case contains N space separated integers denoting the array elements.

Output:
For each testcase, in a new line, print the starting and ending 
positions(1 indexing) of first such occuring subarray from the 
left if sum equals to subarray, else print -1.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1010

Example:
Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
Output:
2 4
1 5

Explanation :
Testcase1: sum of elements from 2nd position to 4th position is 12
Testcase2: sum of elements from 1st position to 5th position is 15
*/

#include <iostream>
using namespace std;
int main()
{
    int t, n, *a, sum, temp, p1, p2, j, k, m, i;

    cin >> t;
    for (i = 0; i < t; i++)
    {
        cin >> n;
        cin >> sum;
        a = new int[n];
        for (j = 0; j < n; j++)
        {
            cin >> a[j];
        }

        bool flag;
        for (j = 0; j < n; j++)
        {
            temp = a[j];
            if (temp == sum)
            {
                flag = true;
                p1 = p2 = j;
                break;
            }

            for (k = j + 1; k < n; k++)
            {
                flag = false;
                temp = temp + a[k];
                if (temp == sum)
                {
                    flag = true;
                    p1 = j;
                    p2 = k;
                    break;
                }
            }

            if (flag)
                break;
        }
        if (flag)
            cout << (p1 + 1) << " " << (p2 + 1) << endl;
        else
            cout << "-1" << endl;
    }

    return 0;
}