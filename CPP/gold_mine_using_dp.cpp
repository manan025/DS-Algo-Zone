#include<bits/stdc++.h>
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl	'\n'
using namespace std;
/*
    Given a gold mine of n*m dimensions.
    Each field in this mine contains a positive integer which is the amount of gold in tons.
    The miner can move to the cell diagonally up towards the right or right or diagonally down towards the right.
    Find out maximum amount of gold he can collect. 
*/
void solve(){
    /*
        * Since all cells are positive, we must cover maximum cells as possible.

        * Every step, we move one step towards right, col=col+1

        * Once we reach last column we can't move elsewhere.

        * So we can use DP to find all possible steps from the 1st column to last column.

        * We store the number of gold collected in variable answer.

        * Update answer when value is greater.
    */
    int m,n,row,col,i,j,answer;
    cin>>m>>n;
    //Getting input from user (Dimensions and cell values)
    int gold[m][n];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
           cin>>gold[i][j];
        }
    }
    //DP
    for(col=n-2;col>=0;col--){
        for(row=0;row<m;row++){
            int right=gold[row][col+1];
            int right_up=(row==0)? 0:gold[row-1][col+1];
            int right_dowm=(row==m-1)? 0:gold[row+1][col+1];
            gold[row][col]=gold[row][col]+max({right,right_up,right_dowm});
        }
    }
    answer=gold[0][0];
    //Max gold updation
    for(i=1;i<m;i++){
        answer=max(answer,gold[i][0]);
    }
    cout<<answer<<endl;

}
int main(){
    ios
    int test=1;
    //cin>>test;
    while(test--){
        solve();
    }
    return 0;
}

/*
    Gold Mine using DP
    Input : A valid table(2D Array) with dimensions and cell entries.
    Output : Returns the maximum number of gold that can be collected.
    ----------------------------------------------------------------------
    Sample Input 1 :
    4 4
    1 3 1 5
    2 2 4 1
    5 0 2 3 
    0 6 1 2
    Sample Output 1 :
    16
    Sample Input 2 :
    4 4
    10 33 13 15
    22 21 4 1
    5 0 2 3
    0 6 14 2
    Sample Output 2 :
    83
    -----------------------------------------------------------------------
    Time Complexity : O(m*n)
    Space Complexity : O(m*n)
*/