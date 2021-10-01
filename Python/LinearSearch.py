# Complexit O(n)
# Here arr is the array and x is the element to be searched
def linearSearch(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i    # Return index if found
    return -1   # Return -1 if not found

if __name__=='__main__':
    arr = [1,2,4,5,3,7]
    item1 = 10
    item2 = 4
    print(linearSearch(arr,item1))
    print(linearSearch(arr,item2))
