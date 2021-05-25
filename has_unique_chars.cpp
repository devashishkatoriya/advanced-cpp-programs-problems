
// The task was to create a program to see if a string contains just one of each charter, and no duplicates

#include <iostream>

bool hasUniqueChars(std::string str)
{
    bool hasSeen[255] = {false};
    int n = str.length();

    for (int i=0; i<n; i++)
    {
        if (!hasSeen[str[i]])
        {
            hasSeen[str[i]] = true;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::string s1 = "Hello!@@$#^!";
    std::string s2 = "abcdefghijkl";

    std::cout << hasUniqueChars(s1) << std::endl;
    std::cout << hasUniqueChars(s2) << std::endl;
}