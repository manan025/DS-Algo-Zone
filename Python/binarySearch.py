def binarySearch(x, u):
	l = 0
	h = len(x) - 1
	while l <= h:
		m = (h + l) // 2
		# Right half
		if x[m] < u:
			l = m + 1

		# Left half
		elif x[m] > u:
			h = m - 1

		# Mid
		else:
			return m
	# Not in list
	return False

x = list(map(int,input("Enter the list of numbers separated by space: ").split()))
u = int(input("Enter the number you want to search: "))

res = binarySearch(x, u)

if res != False:
	print("Number is present at:", str(res))
else:
	print("Number is not preset in list")


'''
Input:  x = 0 1 2 3 4 5 6 7 8 9 10
	u = 8
Output: Number is present at: 8

Average Time complexity: O(logN)
Space complexity: O(1)
'''
