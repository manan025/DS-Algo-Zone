/* Notes : 
    * The adjacent cells are considered to be common edges and the cells are considered to be connected
    * The idea is to visit a node and on visiting this cell, we mark it as visited and then traverse its children
    * I am using the recursive approach to solve this problem
    * Time complexity is O(n*m)
*/

#include<bits/stdc++.h>
using namespace std;

int vis[100][100]; // 2d visited array
int n,m;

//to check whether the given cell is valid or not
bool is_valid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m)
        return false;
    if(vis[x][y])
        return false;
    return true;
}

// adjacent cell to cell (x,y) are (x+1,y+0) , (x-1,y+0) , (x+0,y+1) , (x+0,y-1)
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int x,int y)
{
    vis[x][y] = 1; // visited cell is marrked 1

    for(int i=0;i<4;i++)
        if(is_valid(x + dx[i] , y + dy[i])) // function checking if the given cell is valid or not
            dfs(x + dx[i] , y + dy[i]);
}

int main()
{

    cout<<"Enter the number of rows and columns"<<endl;
    cin>>n>>m;

    dfs(1,1); // called function dfs()

    cout<<"The grid has been traversed"<<endl; // this message shows that graph has been traverssed

    return 0;
}