import java.util.LinkedList;
import java.util.Queue;

/**
 * Level order  traversal of binary tree prints the data of each level at a time
 * 
 */
public class LevelOrderTraversal {

    static class Node {
        int data;
        Node left, right;
    
        public Node(int data) {
          this.data = data;
          left = null;
          right = null;
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
        printLevelOrder(node);
    }

    static void printLevelOrder(Node node){
        if(node == null)
        return;
        Queue<Node> queue = new LinkedList<>();
        queue.add(node);
        while(!queue.isEmpty()){
            Node temp = queue.peek();
            queue.remove();
            System.out.print(temp.data+",");
            if(temp.left != null)
            queue.add(temp.left);
            if(temp.right != null)
            queue.add(temp.right);
        }
    }

    
}
/*
Input  -      1
            /   \
           2     3
          / \   / \
         4   5  6  7
Output: 1,2,3,4,5,6,7,

Time Complexity : O(n)
Space Complexity: O(n)
*/