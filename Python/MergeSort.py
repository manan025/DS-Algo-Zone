def mergeSort(arr):
	if len(arr) > 1:

		# Finding the mid of the array
		mid = len(arr)//2

		# Dividing the array elements
		L = arr[:mid]

		# into 2 halves
		R = arr[mid:]

		# Sorting the first half
		mergeSort(L)

		# Sorting the second half
		mergeSort(R)

		i = j = k = 0

		# Copy data to temp arrays L[] and R[]
		while i < len(L) and j < len(R):
			if L[i] < R[j]:
				arr[k] = L[i]
				i += 1
			else:
				arr[k] = R[j]
				j += 1
			k += 1

		# Checking if any element was left
		while i < len(L):
			arr[k] = L[i]
			i += 1
			k += 1

		while j < len(R):
			arr[k] = R[j]
			j += 1
			k += 1




def printList(arr):
	for i in range(len(arr)):
		print(arr[i], end=" ")
	print()



if __name__ == '__main__':
	
	x = list(map(int,input("Enter the list of numbers separated by space: ").split()))
	print("Given array is", end="\n")
	printList(x)
	mergeSort(x)
	print("Sorted array is: ", end="\n")
	printList(x)

# This code is contributed by Yasas Sandeepa
'''
Input:  x = 1 5 20 3 12 4
Output: x = 1 3 4 5 12 20

Average Time complexity: O(nlogn)
Space complexity: O(n)
'''



