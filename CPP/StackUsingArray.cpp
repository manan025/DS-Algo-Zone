
/* C++ program to implement basic stack operations */
#include <bits/stdc++.h>
 using namespace std;
 
#define MAX 1000
 
class Stack {
    int top;
 
public:
    int a[MAX]; // Maximum size of Stack
 
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};
 
bool Stack::push(int x)  // Insert operation : Time Complexity : O(1), Space complexity : O(1)(Average)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}
 
int Stack::pop()  // Delete operation : Time Complexity : O(1)
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()  // Time complexity : O(1)
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}
 
bool Stack::isEmpty()  // Time complexity : O(1)
{
    return (top < 0);
}
 
int main()
{
    class Stack s;
    s.push(10);  // 10 is inserted
    s.push(20);  // 20 is inserted
    s.push(30);  // 30 is inserted
    cout << s.pop() << " Popped from stack\n"; // 30 is popped
    //print all elements in stack :
    cout<<"Elements present in stack : "; // 10 20
    while(!s.isEmpty())
    {
        // print top element in stack
        cout<<s.peek()<<" ";
        // remove top element in stack
        s.pop();
    }
 
    return 0;
}
