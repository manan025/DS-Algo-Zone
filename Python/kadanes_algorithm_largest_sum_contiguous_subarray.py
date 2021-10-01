import sys
def largestSumSubArray(arr,size):
    """
        * Kadane's algorithm is used to find the largest possible sum in a contiguous subarray

        * The main idea is to find all positive contiguous segments in the array and try to update sum for all positive such
        segments if the sum is greater

        * We find sum for every positive segment and then try to update it.

    """
    max_val=-sys.maxsize-1
    mx=0
    start=0
    end=0
    s=0
    for i in range(0,size):
        mx+=arr[i]
        if max_val<mx:
            max_val=mx
            start=s
            end=i

        if mx<0:
            mx=0
            s=i+1

    print("Largest contiguous sum = ",end="")
    print(max_val)
    print ("Start Index = ",end="")
    print(start)
    print ("End Index = ",end="")
    print(end)
"""
    Getting the size of list as input and getting the list elements as well.
"""
n = int(input())
arr=[]
for i in range(0,n):
    num = int(input())
    arr.append(num)
largestSumSubArray(arr,len(arr))

"""
Check Palindrome in C

    Input : An integer array to find the largest sum contiguous subarray.
    Output : Prints the largest sum, and the starting and ending index of the array which gives that positive sum.

    ----------------------------------------------------------------------

    Sample Input 1 :
    5

    1
    2
    3
    4
    -5

    Sample Output 1 :
    Largest contiguous sum = 10
    Start Index = 0
    End Index = 3

    Sample Input 2 :
    8
    
    -2
    -3
    4
    -1
    -2
    1
    5
    -3

    Sample Output 2 :
    Largest contiguous sum = 7
    Start Index = 2
    End Index = 6

    -----------------------------------------------------------------------

    Time Complexity : O(n)  n-> Size of the array.
    Space Complexity : O(1)


"""