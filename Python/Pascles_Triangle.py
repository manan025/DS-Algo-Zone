# This code is contributed by Yasas Sandeepa
def pascal_triangle(n):
   trow = [1]
   y = [0]
   for x in range(max(n,0)):
      print(trow)
      trow=[l+r for l,r in zip(trow+y, y+trow)]
   return n>=1




if __name__ == '__main__':

	x = int(input("Enter the n^th row: "))
	pascal_triangle(x) 







'''
Example 1:
-----------
Input
Enter the n^th row: 4

Output
[1]
[1, 1]
[1, 2, 1]
[1, 3, 3, 1]


Example 2:
----------
Input
Enter the n^th row: 6

Output
[1]
[1, 1]
[1, 2, 1]
[1, 3, 3, 1]
[1, 4, 6, 4, 1]
[1, 5, 10, 10, 5, 1]


TIME COMPLEXITY: O(n^2)
SPACE COMPLEXITY: O(n^2)
'''
