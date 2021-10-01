def maxSumIS(arr, n):
	max = 0
	msis = [0 for x in range(n)]
	for i in range(n):
		msis[i] = arr[i]
	for i in range(1, n):
		for j in range(i):
			if (arr[i] > arr[j] and
				msis[i] < msis[j] + arr[i]):
				msis[i] = msis[j] + arr[i]
	for i in range(n):
		if max < msis[i]:
			max = msis[i]
	return max

myarr = [1, 101, 2, 3, 100, 4, 5]
size = len(myarr)
print("Sum of maximum sum increasing " +
					"subsequence is " +
				str(maxSumIS(myarr, size)))

# Time Complexity: O(n^2)
# Sample Test Case:
# myarr = [1, 101, 2, 3, 100, 4, 5]
