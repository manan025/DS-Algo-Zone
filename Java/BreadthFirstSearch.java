import java.util.*;

class ShortestPath{
  int adjacencyMat[][];
  char nodes[];
  int prev[];
  int visited[];
  int start, end;
 
  ShortestPath(int adjacencyMat[][], char[] nodes, int start, int end){
    this.adjacencyMat = adjacencyMat;
    this.nodes = nodes;
    this.start = start;
    this.end = end;
    this.visited = new int[nodes.length];
    this.prev = new int[nodes.length];
    Arrays.fill(this.prev, -1);
  }
 
  public void bfs(){

    Queue<Integer> queue = new LinkedList<>();
    //Visit and add start node to queue
    visited[start] = 1;
    queue.add(start);
    
    while(!queue.isEmpty()){
      //Pop node for search
      int current_node = queue.poll();
      //Loop through neighbors nodes to find the 'end' node
      int neighbor_node;
      while((neighbor_node =unvisitedNeighbor(current_node)) != -1){
        //visit and add neighbors nodes to the queue
        visited[neighbor_node] = 1;
        queue.add(neighbor_node);
        prev[neighbor_node] = current_node;
        //End BFS if the end node is found
        if(neighbor_node==end){
          queue.clear();
          break;
        }
      }
    }
    //BFS complete, now trace route
    trace_route();
  }
 
  //Function returns index of unvisited neighbors
  private int unvisitedNeighbor(int index){
    for(int i=0; i<adjacencyMat.length; i++){
      if(adjacencyMat[index][i] == 1 && visited[i] == 0){
        return i;
      }
    }
    return -1;
  }

  //Function to trace route using preceding nodes
  private void trace_route(){
    int node = end;
    List<Character> route = new ArrayList<>();

    while(node!=-1){
      route.add(nodes[node]);
      node = prev[node];
    }
    //Reverse route to bring start at front
    Collections.reverse(route);
    //Output the route
    System.out.println(route);
  }
}
 
class Main {
  public static void main(String[] args) {
    //set of vertices
    char nodes[] = {'A', 'B', 'C', 'D', 'E'};
    //Adjacency Matrix
    int adjacencyMat[][] = {{0, 1, 1, 0, 0},
                          {1, 0, 1, 1, 0},
                          {1, 1, 0, 0, 1},
                          {0, 1, 0 ,0, 1},
                          {0, 0, 1, 1, 0}};
    //Driver Code
    ShortestPath shortestPath = new ShortestPath(adjacencyMat, nodes, 0, 3);
    shortestPath.bfs();
    
  }
}

/*
Shortest Path in Unweighted Graph using BFS in Java

Input: Graph Adjacency Matrix, Nodes Array, Start node, End node 
Output: Shortest Route from start to destination node
----------------------------------------
Sample Input:
nodes[] = ['A', 'B', 'C', 'D', 'E'];
adjacencyMat[][] =[[0, 1, 1, 0, 0],
                   [1, 0, 1, 1, 0],
                   [1, 1, 0, 0, 1],
                   [0, 1, 0 ,0, 1],
                   [0, 0, 1, 1, 0]]
start = 0 (A)
end = 3 (D)

Output:
[A, B, D]  (A -> B -> D)
----------------------------------------
Time Complexity: Worst and Average case = O(V + E)
Space Complexity: O(V^2)
*/