s = list(map(int,input("Enter the list of numbers separated by space: ").split()))
for i in range(len(s)):
    for j in range(len(s) - 1):
        if s[j] > s[j+1]:
            s[j], s[j+1] = s[j+1], s[j]
print(s)

'''
Input: 1 8 9 5 4 6 10 2 3 7
output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

Average Time complexity: O(n^2)
Space complexity: O(1)
'''
