#include <iostream>

using namespace std;

// Function to add two non-negative strings
string add_strings(string s1, const string s2)
{
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    int carry = 0;
    while(i>=0 && j>=0)
    {
        short a = s1[i] - '0';
        short b = s2[j] - '0';
        short res = a + b + carry;
        if (res > 9)
            carry = 1;
        else
            carry = 0;
        res = res % 10;

        s1[i] = res + '0';
        i--;
        j--;
    }
    // When first string is larger than second
    while(i>=0)
    {
        short a = s1[i] - '0';
        short res = a + carry;
        if (res > 9)
            carry = 1;
        else
            carry = 0;
        res = res % 10;

        s1[i] = res + '0';
        i--;
    }

    // When second string is larger than first
    while(j>=0)
    {
        short b = s2[j] - '0';
        short res = b + carry;
        if (res > 9)
            carry = 1;
        else
            carry = 0;
        res = res % 10;

        s1 = char(res + '0') + s1;
        j--;
    }

    // Check for final carry
    if (carry == 1)
        s1 = '1' + s1;

    // Return result
    return s1;
}

// Main function
int main()
{
    const string s1 = "1";
    const string s2 = "1";
    string s3;

    s3 = add_strings(s1, s2);
    cout << s3 << endl;

    return 0;
}