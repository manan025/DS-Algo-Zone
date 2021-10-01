// C# program to check if linked list
// is palindrome recursively
using System;
using System.Collections.Generic;
 
class linkeList{
     
// Driver code
public static void Main(String []args)
{
    Node one = new Node(1);
    Node two = new Node(2);
    Node three = new Node(3);
    Node four = new Node(4);
    Node five = new Node(3);
    Node six = new Node(2);
    Node seven = new Node(1);
     
    one.ptr = two;
    two.ptr = three;
    three.ptr = four;
    four.ptr = five;
    five.ptr = six;
    six.ptr = seven;
     
    bool condition = isPalindrome(one);
    Console.WriteLine("isPalidrome :" + condition);
}
 
static bool isPalindrome(Node head)
{
    Node slow = head;
    bool ispalin = true;
    Stack<int> stack = new Stack<int>();
 
    while (slow != null)
    {
        stack.Push(slow.data);
        slow = slow.ptr;
    }
 
    while (head != null)
    {
        int i = stack.Pop();
        if (head.data == i)
        {
            ispalin = true;
        }
        else
        {
            ispalin = false;
            break;
        }
        head = head.ptr;
    }
    return ispalin;
}
}
 
class Node
{
    public int data;
    public Node ptr;
    public Node(int d)
    {
        ptr = null;
        data = d;
    }
}