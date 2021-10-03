def dnfsort( a, size):
    low = 0 
    high = size - 1 
    mid = 0

    while mid <= high: 
        if a[mid] == 0: 
            a[low], a[mid] = a[mid], a[low]
            low = low + 1
            mid = mid + 1
        elif a[mid] == 1:
            mid = mid + 1 
        else:
            a[mid], a[high] = a[high], a[mid]
            high = high - 1
            
    return a 

ar= eval(input("Enter list:"))

size = len(ar) 

new= dnfsort( ar, size) 

print ("Array after segregation :", new)

"""
DNF SORT IMPLEMENTATION IN PYTHON

Please give input in this format only

Sample INPUT:

[0,1,2,0,1,2]  

OUTPUT: 

[0,0,1,1,2,2]


Time Complexity: O(N)

Space Complexity:O(1)
"""