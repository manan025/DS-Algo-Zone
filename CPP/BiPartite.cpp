#include <bits/stdc++.h>
using namespace std;

class graph{
    unordered_map<int,list<int>> up;
    public:
    void addedge(int x,int y)
    {
        up[x].push_back(y);
        up[y].push_back(x);
    }
    bool helper(vector<int>& visited,int node,int parent,int color)
    {
        visited[node]=color;
        for(auto nbr:up[node]){
            if(visited[nbr]==0){
                bool sub = helper(visited,nbr,node,3-color);
                if(sub==false)return false;
            }
            else if(nbr!=parent && color==visited[nbr])return false;
        }
        return true;
    }
    bool is_bipartite(){
        vector<int> visited(up.size(),0);
        return helper(visited,0,-1,1);
    }
};
int main()
{
    graph g;
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(2,4);
    g.addedge(3,4);
    cout<<g.is_bipartite();
    return 0;
}
/*
Time-Complexity: O(n)
Space-Complexity: O(n)

Sample Test Case1:
    graph g;
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(2,4);
    g.addedge(3,4);
    cout<<g.is_bipartite();
*/