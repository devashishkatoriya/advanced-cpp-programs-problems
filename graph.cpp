
#include <iostream>
#include "queue.cpp"
#include "stack.cpp"

using namespace std;

class Graph
{
    int matrix[5][5] = {
            {0, 1, 0, 1, 0},
            {1, 0, 1, 0, 1},
            {0, 1, 0, 0, 1},
            {1, 0, 0, 0, 1},
            {0, 1, 1, 1, 0}
        }, n;
public:
    Graph()
    {
        n = 5;
        /*
        matrix = new int[n];
        for (int i=0; i<n; i++)
        {
            matrix[i] = new int[n];
        }
        */

        // {(A,B),(B,C),(A,D),(D,E),(E,C),(B,E)}

        /*
        A--B--C
        |  | /
        |  |/
        D--E
        */
    }

    void dfs(int start)
    {
        bool *visited;
        Stack <int> s;

        visited = new bool[n];

        cout<<"\nDFS:";

        s.push(start);
        while (!s.isEmpty())
        {
            int next = s.pop();

            if (visited[next] == false)
            {
                cout<<" "<<next;
                visited[next] = true;
                for (int j=0; j<n; j++)
                {
                    if (next != j && matrix[next][j] == 1)
                    {
                        s.push(j);
                    }
                } 
            }
        }
    }

    void display()
    {
        for (int i=0; i<n; i++)
        {
            cout<<endl;
            for (int j=0; j<n; j++)
            {
                cout<<matrix[i][j]<<" ";
            }
        }
    }

    void bfs(int start)
    {
        bool *visited;
        Queue <int> q;

        visited = new bool[n];

        cout<<"\nBFS:";

        q.enqueue(start);
        while (!q.isEmpty())
        {
            int next = q.dequeue();

            if (visited[next] == false)
            {
                cout<<" "<<next;
                visited[next] = true;
                for (int j=0; j<n; j++)
                {
                    if (next != j && matrix[next][j] == 1)
                    {
                        q.enqueue(j);
                    }
                } 
            }
        }
    }
};


int main()
{
    Graph g;
    g.display();

    g.dfs(0);

    g.bfs(0);

    return 0;
}