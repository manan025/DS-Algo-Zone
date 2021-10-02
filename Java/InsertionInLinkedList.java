import java.util.*;
import java.util.Scanner;
class Node {
    int data;
    Node next;
}
class LinkedList {

    private Node head;
 
    public void insert(int data) {
        //create a new Node and store the data.
        Node node = new Node();
        node.data = data;
        node.next = null;

        //check the head is null or not.
        //if head is null, assign the Node and exit.
        if (this.head == null) {
            head = node;
            return;
        }

        //assign a head into the temp Node and loop it until find the null reference/Last Element.
        Node tempNode = this.head;
        while (tempNode.next != null) {
            tempNode = tempNode.next;
        }

        //assign new node.
        tempNode.next = node;
    }

    public void insertAtNth(int data, int position) {
        //creating a new node
        Node node = new Node();
        node.data = data;
        node.next = null;

        //travelling till one node before the new node position
        
        if (this.head == null) {
            //if head is null and position is zero then exit.
            if (position != 0) {
                return;
            } else { //node set to the head.
                this.head = node;
            }
        }

        if (head != null && position == 0) {
            node.next = this.head;
            this.head = node;
            return;
        }

        Node current = this.head;
        Node previous = null;

        int i = 0;

        while (i < position) {
            previous = current;
            current = current.next;

            if (current == null) {
                break;
            }

            i++;
        }

        node.next = current;
        previous.next = node;
    }
    
    //To print the linked list
    public void printlist() {
        if (this.head == null) {
            return;
        }
        //print all nodes
        Node tempNode = this.head;
        while (tempNode != null) {
            System.out.print(tempNode.data + "->");
            tempNode = tempNode.next;
        }
        System.out.println("NULL");
    }
   

}
public class Main {

  public static void main(String[] args) {
      LinkedList li = new LinkedList();
      Scanner in = new Scanner(System.in);
      System.out.println("Enter Element1: ");
      int a = in.nextInt();
      System.out.println("Enter Element2: ");
      int b = in.nextInt();
      System.out.println("Enter Element3: ");
      int c = in.nextInt();
      li.insert(a);
      li.insert(b);
      li.insert(c);
      li.printlist();
      int info,locate;
      System.out.println("Enter Element: ");
      info = in.nextInt();
      System.out.println("Enter Position: ");
      locate = in.nextInt();
      li.insertAtNth(info, locate);
      li.printlist();
  }
}
