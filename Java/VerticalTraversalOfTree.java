import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class VerticalTraversalOfTree {

    static class Node {
        int data;
        Node left, right;
    
        public Node(int data) {
          this.data = data;
          left = null;
          right = null;
        }
    }

    static class VerticalLevel{
        Node node;
        int vertLevel;

        VerticalLevel(Node node, int vertLevel){
            this.node = node;
            this.vertLevel = vertLevel;
        }
    }

    public static void main(String args[]){
        Node node = new Node(1);
        node.left = new Node(2);
        node.right = new Node(3);
        node.left.left= new Node(4);
        node.left.right= new Node(5);
        node.right.left= new Node(6);
        node.right.right= new Node(7);
        printVerticalLevel(node);
    }

    static void printVerticalLevel(Node node){
        Queue<VerticalLevel> queue = new LinkedList<>();
        Map<Integer,List<Integer>> map = new HashMap<>();
        if(node == null)
        return;
        queue.add(new VerticalLevel(node, 0));
        int min = 0,max = 0;
        while(!queue.isEmpty()){
            VerticalLevel verticalLevel = queue.peek();
            queue.remove();
            min = Math.min(min,verticalLevel.vertLevel);
            max = Math.max(max, verticalLevel.vertLevel);
            if(!map.containsKey(verticalLevel.vertLevel)){
                map.put(verticalLevel.vertLevel, new ArrayList<>());
            }
            map.get(verticalLevel.vertLevel).add(verticalLevel.node.data);

            if(verticalLevel.node.left != null){
                queue.add(new VerticalLevel(verticalLevel.node.left, verticalLevel.vertLevel-1));
            }

            if(verticalLevel.node.right != null){
                queue.add(new VerticalLevel(verticalLevel.node.right, verticalLevel.vertLevel+1));
            }
        }

        for(int i = min; i<=max;i++){
            for(Integer num: map.get(i))
                System.out.print(num+",");
            System.out.println();
        }
    }

    
}
/*
Input  -      1
            /   \
           2     3
          / \   / \
         4   5  6  7
Output: 4,
        2,
        1,5,6,
        3,
        7,
Time Complexity - O(N)
Space Complexity - O(N)
*/