#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    //constructor
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

//Function to merge two linked list using dummy node
/*
    This function uses temporary dummy node as the start of the desired merged list.
    This dummy node approach is efficient,as it's temporary and is allocated in stack.
*/
node *merge_dummy_node(node *&head1, node *head2)
{
    //pointers to the head of the given two sorted linked list
    node *p1 = head1;
    node *p2 = head2;
    // a dummy first node for the new merged linked list to be created
    node *dummynode = new node(-1);
    node *p3 = dummynode;

    // traverse through the both lists and advance p3 and p1 or p2 after comparison
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    //add the list if other linked list is completed
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    //tricky- return next of dummynode
    return dummynode->next;
}

//RECURSIVE function for merging two linked list
node *merge_recursive(node *&head1, node *&head2)
{
    //Base cases
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    node *result = NULL;
    //pick the less value between head1 and head2 and recur
    if (head1->data <= head2->data)
    {
        result = head1;
        result->next = merge_recursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = merge_recursive(head1, head2->next);
    }
    return result;
}

//display function for linked list
void display(node *head)
{
    node *view = head;
    while (view != NULL)
    {
        cout << view->data << "->";
        view = view->next;
    }
    cout << "NULL" << endl;
}

//function to insert elements in linked list from tail
void insert_tail(node *&head, int val)
{

    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;
    node *head4 = NULL;

    //elements of first linked list to be merged using dummy node approach
    int arr1[] = {1, 4, 5, 8};
    //elements of second linked list to be merged using dummy node approach
    int arr2[] = {2, 3, 7};

    //elements of first linked list to be merged using recursive approach
    int arr3[] = {4, 7, 9, 10};
    //elements of second linked list to be merged using recursive approach
    int arr4[] = {2, 3, 8};

    //inserting elements in linked list from tail
    for (int i = 0; i < 4; i++)
    {
        insert_tail(head1, arr1[i]);
        insert_tail(head3, arr3[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        insert_tail(head2, arr2[i]);
        insert_tail(head4, arr4[i]);
    }

    cout << "linked lists to be merged using dummy node approach: " << endl;
    display(head1);
    display(head2);
    cout << "Merged linked list: " << endl;
    node *newhead = merge_dummy_node(head1, head2);
    display(newhead);

    cout << endl;

    cout << "linked lists to be merged using recursive approach: " << endl;
    display(head3);
    display(head4);
    cout << "Merged linked list: " << endl;
    node *new_head = merge_recursive(head3, head4);
    display(new_head);
}

/* 

-->> Input of linked lists to be merged using DUMMY NODE APPROACH:  
1->4->5->8->NULL
2->3->7->NULL
Output : 1->2->3->4->5->7->8->NULL

Time complexity = O(n) , if n is the bigger length between the two linked list

-------------------------------------------------------------------

-->> Input of linked lists to be merged using RECURSIVE APPROACH: 
4->7->9->10->NULL
2->3->8->NULL
Output : 2->3->4->7->8->9->10->NULL

Time complexity : O(m+n) ,if m and n are the lengths of the two lists to be merged

*/