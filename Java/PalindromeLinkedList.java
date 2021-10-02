import java.util.Scanner;
import java.util.Stack;

public class PalindromeLinkedList {

    static class Node{
        int data;
        Node next;

        Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements in linked list");
        int n = sc.nextInt();
        Node node = new Node(-1);
        Node temp = node;
        System.out.println("Enter the elements of the linked list");
        for(int i = 0; i < n;i++){
            temp.next = new Node(sc.nextInt());
            temp = temp.next;
        }

        boolean isPalindrome = isLinkedListPalindrome(node.next);
        if(isPalindrome){
            System.out.println("Linked list is palindrome");
        }else{
            System.out.println("Linked list is not palindrome");
        }

    }

    private static boolean isLinkedListPalindrome(Node head) {
        Stack<Integer> stack = new Stack<>();
        Node temp = head;
        while(temp != null){
            stack.push(temp.data);
            temp = temp.next;
        }

        temp = head;

        while(temp != null && !stack.isEmpty()){
            if(temp.data == stack.peek()){
                stack.pop();
                temp = temp.next;
            }else{
                return false;
            }
        }

        return true;
    }
    
}

/*
---Sample inputs & output---
Example - 1
Input : 1,2,3,2,1
Output: Linked list is palindrome
---Time Complexity---
O(n)
---Space Complexity---
O(n)
 */