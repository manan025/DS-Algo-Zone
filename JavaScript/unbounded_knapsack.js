//function which returns the maximum value for a given knapsack
const negativeInfinity = -2147483648;
const positiveInfinity = 2147483648;
// Create an array to be used for memoization.
let dp;

const unboundedKnapsack = (currentIndex, weights, values, W, n) => {
  // The base conditions are checked
  // 1. The weight of the knapsack is equal to 0 - means that the knapsack is full so return 0.
  // 2. Either the currentIndex is out of bounds or the weight of the knapsack is < 0 - means return -ve infinity.
  if (W == 0) return 0;
  if (currentIndex >= n || W < 0) return negativeInfinity;

  if (dp[currentIndex][W] !== -1) return dp[currentIndex][W];

  // If the knapsack has enough capacity to hold the current product, then we have two choices,
  // 1. Either take the current product some 'k' number of times(that is why the index is not incremented in the recursive call) and move on.
  // 2. Do not take the current product and move on.
  if (W - weights[currentIndex] >= 0) {
    return (dp[currentIndex][W] = Math.max(
      values[currentIndex] +
        unboundedKnapsack(
          currentIndex,
          weights,
          values,
          W - weights[currentIndex],
          n
        ),
      unboundedKnapsack(currentIndex + 1, weights, values, W, n)
    ));
    // If the knapsack doesn't have the enough capacity, then move on to the next product.
  } else {
    return (dp[currentIndex][W] = unboundedKnapsack(
      currentIndex + 1,
      weights,
      values,
      W,
      n
    ));
  }
};

const main = () => {
  // Initialising values to be passed for the unboundedKnapsack function
  const values = [10, 30, 20],
    weights = [5, 10, 15];
  const W = 100,
    n = 3;

  // Resizing the dp array and reinitializing it
  dp = new Array(n + 1);
  for (let i = 0; i < n + 1; ++i) {
    dp[i] = new Array(W + 1);
    for (let j = 0; j < W + 1; ++j) dp[i][j] = -1;
  }

  const maxSumOfValues = unboundedKnapsack(0, weights, values, W, n);

  console.log(
    "The Maximum sum of values that can be put into the knapsack of weight",
    W,
    "is:",
    maxSumOfValues
  );
};

main();

/*
Refer: https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/ for the complete problem statement
Input: An array of numbers that are to be sorted
Output: Returns the sorted array

----------------------------------------
Sample Input:
    values = [10, 30, 20]
    weights = [5, 10, 15]
    W = 100
Output: 
The Maximum sum of values that can be put into the knapsack of weight 100 is: 300

----------------------------------------

Time Complexity:
Worst and Average case = O(n*n) = O(n²)
Best case = O(n*n) = O(n²)

Space Complexity: O(n²)
*/
