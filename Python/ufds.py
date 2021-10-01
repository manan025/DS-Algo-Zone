def ufds(edges, n):
    dsu = [-1] * n

    for u, v in edges:
        while dsu[u] >= 0:
            u = dsu[u]

        while dsu[v] >= 0:
            v = dsu[v]

        if -dsu[u] < -dsu[v]:
            u, v = v, u

        dsu[u] += dsu[v]
        dsu[v] = u

    return dsu


ufds([(0, 1), (1, 2), (2, 3), (2, 4), (5, 6), (5, 8), (9, 7), (9, 4)], 10)

"""

Union-Find Data Structure using Python

NOTE:
 * Only works for undirected edges
 * Indexing of the nodes start from 0

----------------------------------------
Input:
List of pairs of two integers, denoting the vertices to be connected.
The maximum number of nodes is also required


Output:
List of integers
Negative values denote the size of the sub-component. For example: -3 means that the size of the sub-component is 3
Non-negative values denote the parent of the current node. For example: 2 means the parent of the current node is 2

----------------------------------------
Sample Input:
graph = [(0, 1), (1, 2), (2, 3), (2, 4), (5, 6), (5, 8), (9, 7), (9, 4)]
n = 10

Output:
[-7, 0, 0, 0, 0, -3, 5, 9, 5, 0]

0: Head of the first sub-component with 7 nodes under it (including itself)
5: Head of the second sub-component with 3 nodes under it (including itself)
1, 2, 3, 4, 9: Parent is 0
6, 8: Parent is 5
7: Parent is 9

----------------------------------------
Time Complexity:
Worst case = O(log V + E)
Space Complexity: O(V)

"""
