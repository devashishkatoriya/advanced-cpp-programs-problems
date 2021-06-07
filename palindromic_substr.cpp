
// Find Count of Palindromic sub-string

#include <iostream>

int isPalindromeCount(const std::string str, const int i, const int j)
{
    const int n = str.length();

    if ((i<0) || (j>=n))
    {
        return 0;
    }

    if (str[i] == str[j])
    {
        return 1 + isPalindromeCount(str, i-1, j+1);
    }
    return 0;
}

int getPalindromicSubstring(const std::string str)
{
    int cnt = 0;
    const int n = str.length();

    for (int i=0; i<n; i++)
    {
        cnt += isPalindromeCount(str, i, i);
        if (i < n-1)
            cnt += isPalindromeCount(str, i, i+1);
    }

    return cnt-n;
}

int main()
{
    std::cout << getPalindromicSubstring("abaab") << std::endl;
    std::cout << getPalindromicSubstring("abbaeae") << std::endl;
    std::cout << getPalindromicSubstring("aaaaa") << std::endl;

}