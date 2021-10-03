// minimum distance of every node from source node

#include <bits/stdc++.h>
using namespace std;

const int N = 10000;

struct edge 
{
    int v, u, weight;
};

vector<edge> adj(N);

int main()
{
    cout << "Enter the number of nodes and edges: ";

    int n, m;
    cin >> n >> m;

    vector<int> dis(n + 1, INT_MAX);

    cout << "Enter " << m << " edges:" << endl;

    for (int i = 0; i < m; i++)
    {
        cin >> adj[i].u >> adj[i].v >> adj[i].weight;
    }

    dis[1] = 0;
    //source node

    for (int i = 0; i < (n - 1); i++)
    {
        bool flag = true;

        for (int j = 0; j < m; j++)
        {
            if (dis[adj[j].u] < INT_MAX)
            {
                dis[adj[j].v] = min(dis[adj[j].v], dis[adj[j].u] + adj[j].weight);
                flag = 0;
            }
        }

        if (flag)
            break;
    }

    cout << "Minimum distance from node 1:" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "Minimum distance of node ";
        cout << i << " is " << dis[i] << endl;
    }

    return 0;
}

/*
sample Test case:

Enter the number of nodes and edges: 5 7
Enter 7 edges:
1 2 1 
1 4 3
2 4 -2
2 3 1
3 5 -6
2 5 8
5 4 3
Minimum distance from node 1:
Minimum distance of node 1 is 0
Minimum distance of node 2 is 1
Minimum distance of node 3 is 2
Minimum distance of node 4 is -1
Minimum distance of node 5 is -4

*/
