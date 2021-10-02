/* Notes : 
    * The idea is to visit a node and on visiting this node, we mark it as visited and then traverse its children
    * I am using the recursive approach to solve this problem
    * Time complexity is O(n^2)
    * space complexntiy has been optimized with the use of adjacency list
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>arr[100];
int vis[100];

void dfs(int v)
{
    vis[v] = 1;
    for(int child:arr[v]) // traverse all the children of the given node
        if(!vis[child])
            dfs(child);
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
        dfs(i); // calling function dfs
    
    cout<<"The Graph has been traversed"; // this message shows that graph has been traverssed

    return 0;
}