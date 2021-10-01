#include <stdio.h>
#include <stdlib.h>

int top = -1; //Since the stack is not yet created, initialized the top of the stack as -1 since it doesnt exist yet.

void push(int la[], int x) //Function to add elements on top of the stack
{

    if (top >= x - 1)//If the stack is full ie the top value is equal to the specified no. of elements - 1, the no elements can be added.
    {
        printf("Stack is overflow\n\n");//Condition is called overflow.
    }
    else//If stack is not full
    {
        int item;
        printf("Enter a value to be pushed : ");
        scanf("%d", &item);
        top++;          //Before adding the item first increment top variable so element is added at the next position.
        la[top] = item; //Added the item in the respective place.
    }
    printf("\n");
}

void pop(int la[]) //Function to remove elements from top of the stack.
{

    if (top <= -1)//If the top value is -1, this means that stack is empty and there is nothing to delete. This is called underflow condtion.
    {
        printf("Stack is underflow\n\n");
    }
    else //If the stack is not empty.
    {
        printf("The popped element is " "%d" "\n\n", la[top]);//Print the element which is deleted.
        top--;//Decrement the top value since the previous top item is removed
    }
}

int peek(int la[])//Function to display and return the top element of the stack
{

    if (top == -1)//If the top value is -1, this means that stack is empty and there is nothing to delete. This is called underflow condtion.
    {
        printf("Underflow\n\n");
        return 0;
    }
    else
    {
        printf("The top element is " "%d" "\n\n", la[top]);
        return la[top];
    }
}

void display(int la[])//Function to display the contents of the stack.
{

    if (top >= 0)//If top is greater than equal to 0, ie stack is not empty.
    {
        printf("Stack : ");
        for (int i = top; i >= 0; i--)//Loop to print the stack in reverse order in which elements were added.
        {
            printf("%d ", la[i]);
        }
        printf("\n\n");
    }
    else//If stack is empty
    {
        printf("The stack is empty.\n\n");
    }
}

int main()
{
    int stack[100];//Initialize array for the stack to be made. Specified initialize size to avoid to stackdump.
    int m;//Variable to store the maximum number of elements the stack can have. Fixes the size of stack.
    printf("Enter the no. of elements in the stack (1 - 100) : ");
    scanf(" %d", &m);
    printf("\n");

    int a = 0;
    while (a < 1)//While loop to perform various operations as the user likes.
    {
        int response;
        printf("Stack Operations : Push = 1  Pop = 2  Peek = 3  Display = 4  End = 5\n\n");
        printf("Enter your choice = ");
        scanf(" %d", &response);
        switch (response)//Switch case, works depending on the input by user.
        {
        case 1:
        {
            push(stack, m);
            break;
        }

        case 2:
        {
            pop(stack);
            break;
        }

        case 3:
        {
            peek(stack);
            break;
        }

        case 4:
        {
            display(stack);
            break;
        }

        case 5:
        {
            a++;
            break;
        }

        default:
        {
            printf("Invalid input. Please try again.\n\n");
            break;
        }
        }
    }
    printf("\n");

    return 0;
}

/* Size of stack (m) = 6

Pushed the elements in this order = 1 2 3 4 5 6(top)

Display = 6 5 4 3 2 1

Pop = Removed 6
Pop = Removed 5

Peek = Displayed and returned 4

Display = 4 3 2 1

Time Complexity of 
1.Push, Pop, Peek = O(1)
2.Display = O(n)
*/
