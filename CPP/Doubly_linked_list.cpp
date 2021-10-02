#include <bits/stdc++.h>
using namespace std;

//Node of DOUBLY LINKED LIST
class node
{
public:
    int data;
    node *next; // Pointer to next node in DOUBLY LINKED LIST
    node *prev; // Pointer to previous node in DOUBLY LINKED LIST

    //constructor
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

//function for insertion at head
void insert_head(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    //if head points to NULL
    if (head != NULL)
    {
        head->prev = n;
    }

    head = n;
}

//function for insertion at tail
void insert_tail(node *&head, int val)
{
    //edge case : when head is NULL
    if (head == NULL)
    {
        insert_head(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;

    //reaching end of the list
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    //adding val after reaching end of list
    temp->next = n;
    n->prev = temp;
}

//function for deletion at head
void delete_head(node *&head)
{
    node *del = head;
    head = head->next;
    head->prev = NULL;

    delete del;
}

//function for deletion from desired position
void deletion(node *&head, int pos)
{
    //if value to be deleted at position 1
    if (pos == 1)
    {
        delete_head(head);
        return;
    }

    node *temp = head;
    int count = 1;
    //reach to the desired position of to be deleted value
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

//display function of doubly linked list
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;

    //insertion from tail
    insert_tail(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    insert_tail(head, 4);
    display(head);

    //insertion of 5 at head
    insert_head(head, 5);
    display(head);

    //deletion at position 5
    deletion(head, 5);
    display(head);

    //deletion at position head
    deletion(head, 1);
    display(head);
}

/*
DOUBLY LINKED LIST AFTER INSERTION AT TAIL OF 1,2,3,4 : 
1 2 3 4

DOUBLY LINKED LIST AFTER INSERTION AT TAIL OF 5: 
5 1 2 3 4

DOUBLY LINKED LIST AFTER DELETION FROM POSITION 5:
5 1 2 3

DOUBLY LINKED LIST AFTER DELETION FROM HEAD OR POSITION 1:
1 2 3

TIME COMPLEXITY OF INSERTION AT TAIL: O(n)
TIME COMPLEXITY OF INSERTION AT HEAD: O(1),since traversal of linked list is not required

TIME COMPLEXITY OF DELETION : O(1),since traversal of linked list is not required
*/