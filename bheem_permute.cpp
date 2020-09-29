
// CodeAgon 2020 Bheem Permute Problem

#include <iostream>
#include <vector>

using namespace std;

vector<int> all_permutations(const int A, const int B)
{
    vector<int> arr;

    for(int i=1; i<B; i++)
    {
        arr.push_back(i);
    }
    arr.push_back(A);
    for(int i=B; i<A; i++)
    {
        arr.push_back(i);
    }

    return arr;
}

int main()
{
    int A, B;
    vector<int> result;

    cin>>A;
    cin>>B;
    result = all_permutations(A, B);

    for (int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}