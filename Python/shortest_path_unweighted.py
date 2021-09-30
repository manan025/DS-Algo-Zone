def shortest_unweighted_path(graph, start, end):
    """

    Finds the shortest path from "start" to "end" in an unweighted graph, where all distances are equal to 1

    :param graph: Graph where graph[node] is a list of indices where there is a path from the node to each index
    :param start: Starting point of the search
    :param end: Ending point of the search
    :return: The distance from "start" to "end". -1 if there is no path from "start" to "end"

    NOTE:
      * The nodes are numbered starting from 0
      * The graph must be in adjacency list form

    """

    from queue import Queue

    node_distance = Queue()
    node_distance.put((start, 0))
    visited = set()

    while not node_distance.empty():
        current_node, current_distance = node_distance.get()

        if current_node in visited:
            continue

        visited.add(current_node)

        if current_node == end:
            return current_distance

        for new_node in graph[current_node]:
            node_distance.put((new_node, current_distance + 1))

    return -1

"""

Shortest Path in Unweighted Graph using Python

Input: List of lists
Output: Sorted array in ascending order
----------------------------------------
Sample Input:
graph = [[1, 2], [2], [3], []]
start = 0
end = 3

Output:
2
----------------------------------------
Time Complexity:
Worst case = O(N)
Space Complexity: O(N)

"""
