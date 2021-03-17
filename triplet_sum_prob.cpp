#include <iostream>
#include <unordered_map>

using namespace std;

void triplet_sum_brute(int arr[], const int n, const int target)
{
    std::cout<<"Using brute force..."<<std::endl;
    for (int i=0; i<n-2; i++)
    {
        for (int j=i+1; j<n-1; j++)
        {
            for (int k=j+1; k<n; k++)
            {
                if (arr[i]+arr[j]+arr[k] == target)
                {
                    std::cout << "Triplet found:" << arr[i] << arr[j] << arr[k] << std::endl;
                }
            }
        }
    }
}

void triplet_sum(int arr[], const int n, const int target)
{
    // Insert all elements into hashmap
    unordered_map <int, int>umap;
    for(int i=0; i<n; i++)
    {
        umap[arr[i]] = i;
    }
        
    int p, q, r;
    for (int i=0; i<n-2; i++)
    {
        p = arr[i];
        for (int j=i+1; j<n-1; j++)
        {
            q = arr[j];
            r = target - p - q;
            if (umap.find(r) != umap.end())
            {
                if (umap[r] != i && umap[r] != j)
                {
                    std::cout << "Triplet found:" << p << q << r << std::endl;
                    umap.erase(r);
                    umap.erase(p);
                    umap.erase(q);
                }
            }
        }
    }
}

int main()
{
    int arr[] = {1,2,3,4,7,8,9,43};
    const int n = sizeof(arr)/sizeof(arr[0]);
    const int target = 15;

    triplet_sum(arr, n, target);

    triplet_sum_brute(arr, n, target);

    return 0;
}