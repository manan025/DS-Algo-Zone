#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int n;
    cout<<"Enter the number of stairs:"<<endl;
    cin>>n;  // number of stairs
    int jumps[n+1]={0};

    cout<<"Enter the jumps at each stairs"<<endl;
    for(int i=0;i<n;i++)
      cin>>jumps[i];
    queue<int>q;
    for(int i=0;i<n;i++)
      q.push(i);

    int dp[n];
    int x=q.front();
     dp[0]=0;
    for(int i=1;i<n;)
    {
        
        if(i<=jumps[x]+x)   //checking the condition
            dp[i]=dp[x]+1,i++;
        else
        {
            x=q.front();
            q.pop();
            
        }
    } 
    cout<<dp[n-1];  //printing min jumps required to reach last stairs.
}

/*
 Input : number of stairs, jumps at every stairs
 Output: minimum jumps to reach last stairs.
 

 Sample input : 
            5
            [2,3,1,1,4]

 Output : 2
       

*/