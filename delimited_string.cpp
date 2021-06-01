
// Program to split a given string with the help of given delimiter

#include <iostream>
#include <vector>

std::vector<std::string> split(const std::string str, const char& delim)
{
    std::vector<std::string> result;

    const int n = str.size();

    std::string temp = "";
    for (int i=0; i<n; i++)
    {
        if (str[i] == delim)
        {
            result.push_back(temp);
            temp = "";
        }
        else
        {
            temp += str[i];
        }
    }
    result.push_back(temp);

    return result;
}

int main()
{
    std::vector<std::string> ans;

    ans = split("Hello world how are you? where've you been.", ' ');

    const int n = ans.size();
    for (int i=0; i<n; i++)
    {
        std::cout << ans[i] << std::endl;
    }
}