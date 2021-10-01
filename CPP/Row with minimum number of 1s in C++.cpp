/*
Given a 2D binary matrix A of dimensions NxM, determine the row that contains a minimum number of 1's.
The matrix contains only 1s and 0s.
 
*/

/* Input:
	N=5,M=5
	A=[[1,1,1,1,0],[1,0,1,0,0],[0,0,0,1,1],[1,0,1,1,1],[1,1,1,1,]]
	
	Output:
	2
	
	Explanation:
	Rows 2 and 3 contain the minimum number 
	of 1's(2 each).Since, 2 is less than 3.
	Thus, the answer is 2.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minRow(int N, int M, vector<vector<int>> A) {
        int count_of_one=0;
        //Let say the minimum number of ones be INT_MAX and the row which has min no of 1s be 1.
		 
        int minimum=INT_MAX,ans=1;
        
        //Now iterate through the matrix to update the results
        for(int i=0;i<A.size();i++)
         {
             vector<int>temp=A[i];
             //Using STL to count the number of 1s.
             count_of_one=count(temp.begin(), temp.end(),1);
             if(count_of_one<minimum)
             {
                 minimum=count_of_one;
                 ans=(i+1);
             }
         }
         return ans;
         
    }
};




int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}  
