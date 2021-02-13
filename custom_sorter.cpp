

// Program to custom sort the input array as per frequencies and then in
// decreasing order for same freq

/*
func([5, 3, 2, 4, 1, 2])
[(5, 1), (4, 1), (3, 1), (1, 1), (2, 2)]

func([2, 1, 1, 1])
[(2, 1), (1, 3)]

func([20, 15, 20, 50, 20])
[(50, 1), (15, 1), (20, 3)]
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> custom_sorter(const vector<int> arr)
{
    const int n = arr.size();

    // Compute the frequencies of elements
    map<int, int> omap;
    for (int i=0; i<n; i++)
    {
        omap[arr[i]]++;
    }

    // Copy freq to vector
    vector<vector<int>> freq;
    for(auto i=omap.begin(); i!=omap.end(); i++)
    {
        vector<int> temp(2);
        temp[0] = i->first;
        temp[1] = i->second;
        freq.push_back(temp);
    }

    cout<<"Freq array before sorting:"<<endl;
    for(int i=0; i<freq.size(); i++)
    {
        cout<<freq[i][0]<<" "<<freq[i][1]<<endl;
    }

    // Sort the vector based on freq
    for (int i=0; i<freq.size(); i++)
    {
        for(int j=0; j<freq.size()-i-1; j++)
        {
            if (freq[j][1] > freq[j+1][1])
            {
                int temp = freq[j][0];
                freq[j][0] = freq[j+1][0];
                freq[j+1][0] = temp;

                temp = freq[j][1];
                freq[j][1] = freq[j+1][1];
                freq[j+1][1] = temp;
            }
        }
    }

    cout<<"Freq array after bubble sort:"<<endl;
    for(int i=0; i<freq.size(); i++)
    {
        cout<<freq[i][0]<<" "<<freq[i][1]<<endl;
    }

    for (int k=0; k<freq.size();)
    {
        // Find positions to sort
        int pos1 = k;
        int pos2 = pos1;
        while (freq[pos1][1] == freq[pos2][1])
        {
            pos2++;
            if (pos2 == freq.size())
                break;
        }
        pos2--;

        // Sort the sub array
        for (int i=pos1; i<=pos2; i++)
        {
            for(int j=pos1; j<=pos2-i+pos1-1; j++)
            {
                if (freq[j][0] < freq[j+1][0])
                {
                    int temp = freq[j][0];
                    freq[j][0] = freq[j+1][0];
                    freq[j+1][0] = temp;

                    temp = freq[j][1];
                    freq[j][1] = freq[j+1][1];
                    freq[j+1][1] = temp;
                }
            }
        }

        k = pos2 + 1;
    }

    return freq;
}

int main()
{
    const vector<int> arr = {5, 3, 2, 4, 1, 2, 3, 10, 7, 8, 6, 9, 5};
    const int n = arr.size();

    const vector<vector<int>> freq = custom_sorter(arr);

    cout<<"Freq vector after final sorting:"<<endl;
    for(int i=0; i<freq.size(); i++)
    {
        cout<<freq[i][0]<<" "<<freq[i][1]<<endl;
    }

    return 0;
}
