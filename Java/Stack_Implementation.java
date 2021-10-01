/* Java program to implement basic stack
operations */
import java.util.*;

class Array_Stack {
	int MAX_SIZE;
	int top; //index to track the item in the top 
	int arr[];

	public boolean isEmpty() { //checks if the stack is empty or not
		return (top < 0);
	}
    
	public Array_Stack(int MAX_SIZE) { //constructor to initialize the stack object 
		top = -1;
        this.MAX_SIZE = MAX_SIZE;
        arr = new int[MAX_SIZE];
	}

	public boolean push(int x) { //helper function to push elements into stack
		if (top >= (MAX_SIZE - 1)) {
			System.out.println("Max Limit Reached..OVERFLOW");
			return false;
		}
			
        arr[++top] = x;
		System.out.println(x + " pushed into stack");
		return true;
	}

	public int pop() {  //helper function to pop elements out of stack
		if (top < 0) {
			System.out.println("No elements are present in the stack...UNDERFLOW");
			return 0;
		}
		
        int x = arr[top--];
        System.out.println(x + " popped out of stack");
		return x;
	}

	public int peek() { //helper function to return top element in the stack
		if (top < 0) {
			System.out.println("No elements are present in the stack");
			return 0;
		}
			
        int x = arr[top];
		return x;
	}
	
	public void print() { //helper function to print elements present in the stack
	  for(int i = top;i>-1;i--){
	     System.out.print(" "+ arr[i]);
	   }
	   System.out.println();
    }
}


class Stack_Implementation {
	public static void main(String args[])
	{
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no. of elements that can be added to the stack: ");
        
		int MAX_SIZE= sc.nextInt();
        Array_Stack s = new Array_Stack(MAX_SIZE);
    

        int a = 0;
        while (a < 1)//While loop to perform various operations as the user likes.
        {
        int response;
        System.out.println("Stack Operations : Push = 1  Pop = 2  Peek = 3  Display = 4  End = 5\n\n");
        System.out.println("Enter your choice = ");
        response = sc.nextInt();
        switch (response)//Switch case, works depending on the input by user.
        {
        case 1:
        {
            System.out.println("Enter number to be pushed to stack = ");
            s.push(sc.nextInt());
            break;
        }

        case 2:
        {
            s.pop();
            break;
        }

        case 3:
        {
            System.out.println(s.peek());
            break;
        }

        case 4:
        {
            s.print();
            break;
        }

        case 5:
        {
            a++;
            break;
        }

        default:
        {
            System.out.println("Invalid input. Please try again.\n");
            break;
        }
        }
    }
    System.out.println("");


	}
}
