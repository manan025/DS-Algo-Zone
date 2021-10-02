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
    sum += a[i];

  if (sum % 2) {
    printf("NO");
    return 0;
  }
  sum = sum / 2;

  long long dp[sum + 1];
  for (int i = 0; i <= sum; i++) dp[i] = 0;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    int curr = a[i];
    for (int j = sum; j >= curr; j--) {
      if ((dp[j - curr] == 0) || (dp[j]))
        continue;
      else {
        dp[j] = 1;
      }
    }
  }
  if (dp[sum])
    printf("YES");
  else
    printf("NO");
}