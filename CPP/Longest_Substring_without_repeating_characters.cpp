/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:
Input: s = ""
Output: 0
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string s){
  unordered_map<char,int> m; // For storing the indices of characters in string
  int left=0, n = s.length(),right=0,maxLength=0;  // n - Length of string
  // left - left most index of current substring
  // right - right most index of current substring
  // maxLength - Length of longest substring so far without repeating characters
  while(right < n)
  {
      while(right < n && m.find(s[right])==m.end())  // Executes until repeating character is encountered
      {
          m[s[right]]=right; // storing index of character
          right++;
      }
      maxLength=max(maxLength,right-left);   // computing the max_Length encountered so far 
      int index=m[s[right]]; // index of repeating character
      while(left<=index)
      {
          m.erase(s[left]); // removes all characters before that index
          left++; 
      }
  }
  return maxLength;
}

int main(){
  string S;
  cin>>S;
  int ans = solve(S);
  cout<<"Length of longest substring without repeating characters is : "<<ans<<endl;
  return 0;
}


/*
Space complexity : O(N) -- for storing indices in unordered map
Time complexity : O(N)
*/
