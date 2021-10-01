V = 4
INF = 99999
def printSolution(dist):
	print "Answer: "
	for i in range(V):
		for j in range(V):
			if(dist[i][j] == INF):
				print "%7s" % ("INF"),
			else:
				print "%7d\t" % (dist[i][j]),
			if j == V-1:
				print ""

def floydWarshall(graph):
	dist = list(map(lambda i: list(map(lambda j: j, i)), graph))
	for k in range(V):
		for i in range(V):
			for j in range(V):
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j])
	printSolution(dist)



graph = [[0, 7, INF, 6],
		[3, 0, 1, INF],
		[INF, 1, 0, INF],
		[INF, INF, INF, 0]]

floydWarshall(graph)

#Time Complexity: O(n^3)
# Sample test Case 1:
'''
graph = [[0, 7, INF, 6],
		[3, 0, 1, INF],
		[INF, 1, 0, INF],
		[INF, INF, INF, 0]]
'''
