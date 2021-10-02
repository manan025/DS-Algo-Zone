#include<stdio.h>

#include<stdlib.h>

int main() {
  int n;
  printf("Enter the number of elements:\n");
  scanf("%d", & n);
  int a[n + 1];
  printf("Enter the elements\n");
  for (int i = 1; i <= n; i++)
    scanf("%d", & a[i]);
  long long sum = 0;
  for (int i = 1; i <= n; i++)
    sum += a[i];              //calculating sum of all elements of array.

  if (sum % 2) {
    printf("NO");   // if sum of all elements is odd then the array cannot be divided into two parts having equal sum.
    return 0;
  }
  sum = sum / 2;  

  long long dp[sum + 1];
  for (int i = 0; i <= sum; i++) dp[i] = 0;
  dp[0] = 1;   // initializing 
  for (int i = 1; i <= n; i++) {
    int curr = a[i];            // taking one element at a time and iterate over other to check for sum.
    for (int j = sum; j >= curr; j--) {
      if ((dp[j - curr] == 0) || (dp[j]))  // checking whether this can be included in answer or not.
        continue;
      else {
        dp[j] = 1;       
      }
    }
  }
  if (dp[sum])  // if dp[sum] is 1 then answer exists.
    printf("YES");
  else
    printf("NO");
}