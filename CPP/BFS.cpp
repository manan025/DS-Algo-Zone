/* Notes : 
    * The idea is to visit all the nodes situtated non a single level i.e. traversing all the nodes at a particular level
    * Stack has been used to implement this algorithm.
    * Time complexity is O(n^2)
    * space complexntiy has been optimized with the use of adjacency list
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>arr[100];
int vis[100];

void bfs(int src)
{
    vis[src] = 1;
    queue<int>q; // stack has been used to implement
    q.push(src);

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int child:arr[curr])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = 1;
            }
        }
    }
}

int main()
{
    
    int n,m;
    cout<<"Enter the number of vertices and edges of graph"<<endl;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b; //this shows that there is an edge between a and b
        arr[a].push_back(b); // pushing a in adjacency list of b
        arr[b].push_back(a); // pushing b in adjacency list of a
    }

    for(int i = 1;i<n+1;i++)
        bfs(1); // calling funciotn bfs
    
     cout<<"The Graph has been traversed"; // this message shows that graph has been traverssed

    return 0;
}