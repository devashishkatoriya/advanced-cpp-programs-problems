#include<iostream>

using namespace std;

int main()
{
   int p = 2, q = 3;

   p += p++ + q++;

   cout << p << endl;
   cout << q << endl;

   return 0;
}