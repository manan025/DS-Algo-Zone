/// Insertion of node in a linked list

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

// Insert node in front of linked list
void push(Node** head, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    
    *head = new_node;
}


// Insert node after a given node of linked list
void insertAfter(Node* prev_node, int new_data)
{
    if(prev_node == NULL)  // if linked list is empty
    return;
    
    Node* new_node = new Node();
    
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Add node at the end of linked list
void append(Node** head, int new_data)
{
    Node* last = *head;
    
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    
    if(*head == NULL)  // if linked list is empty
    {
        *head = new_node;
        return;
    }
    
    while(last->next != NULL)
    last = last->next;
    
    last->next = new_node;
    
}

void display(Node* head)
{
    while(head!= NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    
    head = new Node();
    second = new Node();
    third = new Node();
    
    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;
    
    third->data = 3;
    third->next = NULL;
    
    cout<<"original linked list -> ";
    display(head);
    cout<<"\n";
    
    push(&head,5);  // Insert node in front of linked list
    cout<<"linked list after insertion of 5 -> ";
    display(head);
    cout<<"\n";
    
    insertAfter(head->next->next, 4);  // Insert node after a given node of linked list
    cout<<"linked list after insertion of 4 -> ";
    display(head);
    cout<<"\n";
    
    append(&head,7); // Add node at the end of linked list
    cout<<"linked list after insertion of 7 -> ";
    display(head);
    cout<<"\n";
    
}


// Time complexity
// insert in beginning -> O(1)
// insert in between -> O(1)
// insert at last -> O(n)