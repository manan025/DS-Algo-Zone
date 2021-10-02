#include<bits/stdc++.h>
using namespace std;

vector<int>v[100003]; // adjacency list
int in[100003];  // array to store the in-order of any node
int n,m;  // number of nodes and edges
vector<int>ans; // to store the nodes in topologically sorted order
queue<int>q; 

void topo_sort()  // function used for topological sorting
{
    
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        q.push(i);    // pushing the nodes which have 0 in-order
    }
    
    while(!q.empty())
    {
        int node=q.front();  // selecting the node which have 0 in-order
        q.pop();
        ans.push_back(node);
        for(auto i:v[node])  // iterating over the nodes that are connected directly.
        {
            in[i]--;
            if(in[i]==0) 
            q.push(i);   // if in-order becomes 0 then push it in the queue.
        }
    }
}

int main()
{
    cout<<"Enter the number of nodes and number of edges:"<<endl;
    cin>>n>>m;
    
    cout<<"Enter the edges"<<endl;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        in[b]++;
    }
    topo_sort();
    for(auto i:ans)
    cout<<i<<" ";    // printing the nodes in topologically sorted order.
}

/*
 
 Input: number of nodes and number of edges, edges
 Output: nodes in the topologically sorted order
 
  Time complexity: O(n+m),
     where n is the number of nodes and m is the number of edges.
  Space complexity: O(n);
  
  
  Sample input:
     6  6
    
  edges: 
     6  3
     6  1
     5  1
     5  2
     3  4
     4  2
     
  Output: 5 6 3 1 4 2      
  
  
*/

