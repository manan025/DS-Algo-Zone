/* Notes : 
    * I am considering non empty subarrays
    * DP[i] represents , max subarray sum ending at index index
    * I have optimised space complexity from O(N) to O(1), solution in O(N) is commented
*/
#include<bits/stdc++.h>
using namespace std;
int kadanesAlgorithm( vector<int> &A ){
    int n=A.size();
    if(n==0) return 0;                      // vector<int> dp( n , 0 ); optimised space
    int ans=A[0];
    int prev=A[0];                          // dp[0]=A[0]; optimised space
    for(int i=1; i<n; i++){
        int curr = max( A[i] , A[i]+prev ); // dp[i] = max( A[i] , A[i]+dp[i-1] ); optimised space
        ans = max(ans,curr);
        prev=curr;
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    vector<int> A(n);
    cout<<"Enter the elements seperated by space : ";
    for(int i=0; i<n; i++) cin>>A[i];
    cout<<"Largest Subarray Sum is : "<<kadanesAlgorithm( A );
    return 0;
}