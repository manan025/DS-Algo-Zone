// Deletion in Binary Search Tree (BST)
#include <bits/stdc++.h>
using namespace std;
 
struct node 
{
    int data;
    struct node *left, *right;
};
 
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 

void inorder(struct node* root)
{
    if (root != NULL) 
    {
        inorder(root->left);
        cout << root->data<<" ";
        inorder(root->right);
    }
}
 

struct node* insert(struct node* root, int key)
{
    // If the key is already present in the tree
    // return the root (as duplicate keys are not allowed in BST)
    if(root!= NULL && root->data == key)
    return root;
    
    // If root is NULL, insert the first node
    if (!root)
    return newNode(key);
 
    // If key value is greater than the node data
    // Search in right subtree
    if (key > root->data)
    root->right = insert(root->right, key);
    
    // If key value is lesser than the node data
    // Search in left subtree
    else
    root->left = insert(root->left, key);
    
    return root;
}
 
// Return the node with minimum key value found in that tree. 
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 

struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
    return root;
 
    // If the key to be deleted is less than node data then 
    // search in left subtree
    if (key < root->data)
    root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than node data then 
    // search in right subtree
    else if (key > root->data)
    root->right = deleteNode(root->right, key);
 
    // If key is same as node data
    else {
        
        // node has no child
        if (root->left==NULL and root->right==NULL)
            return NULL;
       
        // If node has only right child
        else if (root->left == NULL) 
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        
        // If node has only left child
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16 };
 
    struct node* root = NULL;
    for (int key: keys)
    root = insert(root, key);

    inorder(root);
    cout<<"\n";
    deleteNode(root, 10);
    inorder(root);
 
    return 0;
}

//Time Complexity: The time complexity for insertion in a BST in O(h) where h is the height of the Binary Search Tree