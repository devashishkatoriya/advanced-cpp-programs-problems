
/*
Remove Alternate Duplicate characters from a char array you have to do it in-place.
Like keeping only the odd occurences of each character.

Example: Input: “you got beautiful eyes”
Output: ”you gtbeaiful es”

Allowed Time Complexity was O(n) and Space Complexity was O(1)

-> Dont get confused with O(1) space complexity. It doesnt mean we cannot use additional space.
It just means that we have to use additional space that is irrespective of length of input string.

-> For that we are using constant extra space of 127 (isSeen array) to keep track of seen chars.
*/

#include <iostream>

using namespace std;


// Function to remove alternate duplicate characters from given string
string remove_alternate_duplicates(string str)
{
    // Create a constant length array to maintain track of seen chars
    bool isSeen[127] = {false};
    
    // Length of given string
    const int n = str.length();
    
    // k pointer to keep length of string with removed alt duplicate chars
    int k = 0;
    for (int i=0; i<n; )
    {
        int ch = tolower(str[i]);

        // Case: If we havent encountered char previously
        if (isSeen[ch] == false)
        {
            // Mark it as seen
            isSeen[ch] = true;

            // Copy it into resulting string - inplace only
            str[k] = str[i];

            // Increment the pointers
            k++;
            i++;
        }
        else
        {
            // Case: We have already encountered current char
            
            // Mark its seen as false
            isSeen[ch] = false;

            // Dont copy it into resulting string
            // Simply skip current char
            i++;
        }
    } 

    // Return the substring of given string of length [0, k-1]
    return str.substr(0, k);
}


// Main Function
int main()
{
    // Input string
    string str = "you got beautiful eyes";

    // Print the input string on console - optional
    cout<<"String: "<<str<<endl;

    // Get final result from above function
    string result = remove_alternate_duplicates(str);

    // Display the result
    cout<<"Result: "<<result<<endl;

    return 0;
}