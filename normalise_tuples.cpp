#include <iostream>

using namespace std;

/*
answer should be {tuples} - >
{
    {'Jason', 0.9},
    {'Tessa', 0.68},
    {'Carla', 0.0},
    {'Matt', 0.08},
    {'Jessica', 1.0}
}
*/

int main()
{

    float tuples[5][2] = {
        {1, 94},
        {2, 80},
        {3, 38},
        {4, 43},
        {5, 100}
    };

    float min1 = tuples[0][1];
    float max1 = tuples[0][1];

    for (int i=1; i<5; i++)
    {
        if (min1 > tuples[i][1])
        {
            min1 = tuples[i][1];
        }
        if (max1 < tuples[i][1])
        {
            max1 = tuples[i][1];
        }
    }

    cout<<min1<<" "<<max1<<endl;

    for (int i=0; i<5; i++)
    {
        tuples[i][1] = (tuples[i][1]-min1) / (max1 - min1);
        cout<<tuples[i][1]<<endl;
    }

    return 0;
}