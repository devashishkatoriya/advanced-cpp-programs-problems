#include <iostream>
#include <vector>

using namespace std;

void display_path(const vector<char> path)
{
    const int n = path.size();
    cout<<endl;
    for (int i=0; i<n; i++)
    {
        cout << path[i] << " ";
    }
}

bool all_visited(const bool *arr, const int n)
{
    for(int i=0; i<n; i++)
    {
        if (arr[i] == false)
            return false;
    }
    return true;
}

void dfs(int graph[][5], const int n, const int current, bool *is_visited, vector<char> path)
{
    if (all_visited(is_visited, n))
    {
        display_path(path);
    }
    else
    {

        for(int i=0; i<n; i++)
        {
            if (is_visited[i] == false && graph[current][i] == 1)
            {
                is_visited[i] = true;
                path.push_back('A'+i);

                dfs(graph, n, i, is_visited, path);

                is_visited[i] = false;
                path.pop_back();
            }
        }
    }
}

int main()
{
    const int n = 5;
    int graph[5][5] = {
            {0,1,1,0,0},
            {1,0,0,1,0},
            {1,0,0,0,1},
            {0,1,0,0,1},
            {0,0,1,1,0}
    };

    vector<char> path;
    bool *is_visited = new bool[n];
    for(int i=0; i<n; i++)
    {
        is_visited[i] = false;
    }

    is_visited[0] = true;
    path.push_back('A'+0);

    dfs(graph, n, 0, is_visited, path);

    return 0;
}
