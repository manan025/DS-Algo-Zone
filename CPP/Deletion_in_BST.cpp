// Deletion In Binary Search Tree (BST)
#include <bits/stdc++.h>
using namespace std;
 
// Data structure for storing a BST node 
struct node 
{
    int data;
    struct node *left, *right;
};
 
// To create a new node
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Function to perform inorder traversal
void inorder(struct node* root)
{
    if (root == NULL) 
    return;
 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
 
// Function to insert a node in BST
struct node* insert(struct node* node, int key)
{
    // If root is NULL
    if (node == NULL)
    return newNode(key);
 
    // If given key value is less than root data
    if (key < node->data)
    node->left = insert(node->left, key);
    
    // If given key value is greater than root data
    else
    node->right = insert(node->right, key);
 
    return node;
}
 
// function to return the minimum node value in the tree node
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    while (current && current->left != NULL)
    current = current->left;
 
    return current;
}
 
// Delete a node from tree
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If key is less than root data then 
    // search in left subtree
    if (key < root->data)
    root->left = deleteNode(root->left, key);
 
    // If key is greater than root data then 
    // search in right subtree
    else if (key > root->data)
    root->right = deleteNode(root->right, key);
 
    // If key is equal to root data
    else 
    {
        // node has no child
        if (root->left==NULL and root->right==NULL)
        return NULL;
       
        // node with only one child
        else if (root->left == NULL) 
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        
        // node with only one child
        else if (root->right == NULL) 
        {
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
    struct node* root = NULL;
    
    int keys[] = {50, 30, 20, 40, 70, 60};
    
    for(int key : keys)
    root = insert(root,key);
 
    cout << "Inorder traversal of the given tree \n";
    inorder(root);
 
    root = deleteNode(root, 20);
    cout << "\nInorder traversal of the modified tree \n";
    inorder(root);
 
    root = deleteNode(root, 60);
    cout << "\nInorder traversal of the modified tree \n";
    inorder(root);
 
    return 0;
}