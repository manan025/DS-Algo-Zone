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







