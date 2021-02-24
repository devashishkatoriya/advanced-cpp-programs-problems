#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to diplay dfs path
void display_path(const vector<char> path)
{
    const int n = path.size();
    cout << endl;
    for (int i=0; i<n; i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}


void dfs(int graph[][5], const int n, int current)
{
    // vector to store dfs path
    vector<char> path;

    // Create and initialise is_visited array to false
    bool *is_visited = new bool[n];
    for(int i=0; i<n; i++)
    {
        is_visited[i] = false;
    }

    // Stack to store vertices for dfs
    stack<int> s;

    // Push the starting vertex onto stack
    s.push(current);

    // Mark the starting vertex as visited
    is_visited[current] = true;

    while(!s.empty())
    {
        // Get the top-element and remove it from stack
        current = s.top();
        s.pop();

        // Add top-element to stack
        path.push_back('A'+current);

        // Iterate over all the connected vertices to the top-element
        for(int i=0; i<n; i++)
        {
            // If unvisited then push onto stack
            if (is_visited[i] == false && graph[current][i] == 1)
            {
                s.push(i);

                // Mark that vertex as visited
                is_visited[i] = true;
            }
        }
    }
    display_path(path);
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

    // Call dfs function
    dfs(graph, n, 0);

    return 0;
}
