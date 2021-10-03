/* Notes : 
    * The adjacent cells are considered to be common edges and the cells are considered to be connected
    * The idea is to visit all the cells situtated on a particular distance i.e. traversing all the nodes at a particular level
    * Stack of pair has been used to implement this algorithm.
    * Time complexity is O(n^2)
    * space complexntiy has been optimized with the use of adjacency list
*/


#include<bits/stdc++.h>
using namespace std;

int n,m;
int dist[100][100]; 
int vis[100][100]; // 2d visited array

// adjacent cell to cell (x,y) are (x+1,y+0) , (x-1,y+0) , (x+0,y+1) , (x+0,y-1)
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

//to check whether the given cell is valid or not
bool is_valid(int x,int y) 
{
    if(x<1 || x>n || y<1 || y>m)
        return false;
    if(vis[x][y])
        return false;
    return true;
}

void bfs(int srcx,int srcy)
{
    queue<pair<int,int>>q; //Queue of pair has been used
    q.push({srcx,srcy});
    vis[srcx][srcy] = 1;
    dist[srcx][srcy] = 0;

    while(!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            if(is_valid(currx+dx[i] , curry+dy[i])) // function checking if the given cell is valid or not
            {
                int newx = currx + dx[i];
                int newy = curry + dy[i];
                dist[newx][newy] = dist[currx][curry] + 1; // distance has been updated

                vis[newx][newy] = 1; 
                q.push({newx,newy}); // node has been pushed
            }
        }
    }
}

int main()
{

    cout<<"Enter the number of rows and columns"<<endl;
    cin>>n>>m;

    cout<<"Enter the number of source node coordinates"<<endl;
    int x,y;
    cin>>x>>y;

    bfs(x,y);  // called function bfs() 

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
            cout<<dist[i][j]<<" "; // Distance array is printed, this message shows that graph has been traverssed
        cout<<endl;
    }

    cout<<"The grid has been traversed"<<endl;

    return 0;
}