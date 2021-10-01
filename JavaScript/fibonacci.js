fibonacci(n) {
  var a = 0, b = 1;
  while (n--) {
    a = [b, b = a+b][0];
  }
  return a;
}

/*
 * fibonacci number
 * ----------------
 * Input: number
 * Output: nth fibonacci number
 * ----------------
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 */
