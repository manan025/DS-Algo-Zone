# Selection Sort
"""
Example 1:
Input:5 4 3 2 1
Output:[1, 2, 3, 4, 5]

Example 2:
Input:9 5 7 6 1 4 3 1
Output:[1, 1, 3, 4, 5, 6, 7, 9]

Example 3:
Input:2 3 7 5 4 6 8 1 9
Output:[1, 2, 3, 4, 5, 6, 7, 8, 9]
"""


def selectionSort(values):
    for i in range(len(values) - 1):
        for j in range(i + 1, len(values)):
            if values[i] > values[j]:
                values[i], values[j] = values[j], values[i]
    return values


print(selectionSort(list(map(int, input().split(" ")))))

# Time complexity: O(N^2)
# Space complexity: O(1)

