
// Program to generate permutations of an char-array including repeating characters

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Global variable to store number of permutations
int CNT = 0, MIN1, MAX1, i;
vector<char> arr;
ofstream fout;

// Function to display array on screen
void display_array(const vector<char> arr)
{
    const int n = arr.size();
    cout<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<arr[i];
    }
}

void write_to_file(const vector<char> arr)
{
    const int n = arr.size();
    for (int i=0; i<n; i++)
    {
        fout << arr[i];
    }
    fout<<endl;
}

void generate_permutation(vector<char> op, const int k)
{
    if ((k >= MIN1) && (k <= MAX1))
    {
        display_array(op);
        //write_to_file(op);
        CNT++;
    }
    if (k < MAX1)
    {
        const int n = arr.size();
        for(int i=0; i<n; i++)
        {
            op.push_back(arr[i]);
            generate_permutation(op, k+1);
            op.pop_back();
        }
    }
}

int main()
{
    for(int i='a'; i<='z'; i++)
    {
        arr.push_back(char(i));
    }
    for(int i='A'; i<='Z'; i++)
    {
        arr.push_back(char(i));
    }
    for(int i='0'; i<='9'; i++)
    {
        arr.push_back(char(i));
    }
    arr.push_back('!');
    arr.push_back('@');
    arr.push_back('#');
    arr.push_back('$');
    arr.push_back('%');
    arr.push_back('&');
    arr.push_back('*');
    arr.push_back('(');
    arr.push_back(')');
    arr.push_back('+');
    arr.push_back('-');
    arr.push_back('=');
    arr.push_back('_');
    arr.push_back('>');
    arr.push_back('<');

    const int n = arr.size();
    cout<<"\nSize of input space: "<<n<<endl;
    
    MIN1 = 8;
    MAX1 = 8;
    cout<<"\nMinimum Length of Req. Key: "<<MIN1<<endl;
    cout<<"Maximum Length of Req. Key: "<<MAX1<<endl;

    // Open the output file
    fout.open("output_size_8.txt");

    vector<char> op1;

    // Generate all the permutations
    cout<<"\nGenerating permutations...";
    generate_permutation(op1, 0);

    // Close the output file
    fout.close();

    // N
    cout<<"\nTotal number of permutations: "<<CNT<<endl;

    return 0;
}