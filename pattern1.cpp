#include <iostream>

using namespace std;

void displayPattern(const int n)
{
    int p=1;
    int d = 1;

    if (n % 2 == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                for (int j = 1; j <= 2 * n - 1; j++)
                {
                    if (j % 2 == 1)
                    {
                        cout<<p++;
                    }
                    else
                        cout<<"*";
                }
                cout<<endl;
            }

            if ((i > 1) && (i <= n / 2))
            {
                int j = 1;
                while (j <= 2 * n - 1)
                {
                    if (j % 2 == 1)
                    {
                        if (j == 1)
                        {
                            p = p + n;
                        }
                        cout<<p;
                        p++;
                    }
                    else
                        cout<<"*";
                    j++;
                }
                cout<<endl;
            }

            if (i == n / 2 + 1)
            {
                for (int j = 1; j <= 2 * n - 1; j++)
                {
                    if (j % 2 == 1)
                    {
                        cout<<p++;
                    }
                    else
                        cout<<"*";
                }
                cout<<endl;
            }

            if ((i < n) && (i > n / 2))
            {
                int j = 1;
                while (j <= 2 * n - 1)
                {
                    if (j % 2 == 1)
                    {
                        if (j == 1)
                        {
                            p = p - n + 1;
                            p = p - (n * 2) - d;
                        }
                        cout<<p;
                        p++;
                    }
                    else
                        cout<<"*";
                    j++;
                }
                cout<<endl;
            }
        }
    }

    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                for (int j = 1; j <= 2 * n - 1; j++)
                {
                    if (j % 2 == 1)
                    {
                        cout<<p++;
                    }
                    else
                        cout<<"*";
                }
                cout<<endl;
            }

            if ((i > 1) && (i <= n / 2 + 1))
            {
                int j = 1;
                while (j <= 2 * n - 1)
                {
                    if (j % 2 == 1)
                    {
                        if (j == 1)
                        {
                            p = p + n;
                        }
                        cout<<p;
                        p++;
                    }
                    else
                        cout<<"*";
                    j++;
                }
                cout<<endl;
            }
            if ((i < n) && (i > n / 2))
            {
                int j = 1;
                while (j <= 2 * n - 1)	//for(int j=1;j<=2*n-1;j++)
                {
                    if (j % 2 == 1)
                    {
                        if (j == 1)
                        {
                            p = p - (2 * n) - n;
                        }
                        cout<<p+n;
                        p++;
                    }
                    else
                        cout<<"*";
                    j++;
                }
                cout<<endl;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    displayPattern(n);
    return 0;
}

/* OUTPUT
4
1*2*3*4
9*10*11*12
13*14*15*16
5*6*7*8
*/