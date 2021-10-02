'''
Insertion Sort implementation in Python
Input: Array that user want to sort
Output: Sorted array in ascending order

----------------------------------------

Sample Input 1:
6
[6, 4, 2, 1, 78, 23]
Output:
Sorted Array: 1 2 4 6 23 78
Sample Input 2:
5
[34, 56, 78, 98, 99]
Output:
Sorted Array: 34 56 78 98 99

----------------------------------------

Time Complexity:
Worst and Average case = O(n^2)
Best case (when array is already sorted) = O(n)
Space Complexity: O(1)
'''

l=list(map(int,input().split()))    #take array from user
for i in range(1,len(l)):
    j=i-1
    key=l[i]
    while j>=0 and key<l[j]:
        l[j+1]=l[j]
        j-=1
    l[j+1]=key
print(l)    # print sorted array