""" Author: Anjali Sahu
    Date: 2nd October 2021

    The function below represents an implementation of the 'insertion sort'
    algorithm.  
"""

def insertionSort(l):
    """
    An implementation of insertion sort
    """
    result = l[:]

    lengthData = len(result)
    start = 1

    while start <= lengthData - 1:
        if result[start] < result[start - 1]:
            value = result.pop(start)

            # find insertion point
            for i in range(start):
                if result[i] > value:
                    result.insert(i, value)
                    break
        start += 1

    return result

list=eval(input("Enter the list:"))
print("Sorted list: ",insertionSort(list))

"""
Enter the list: [3,6,2,1,5,7]

Sorted list: [1,2,3,5,6,7]
"""