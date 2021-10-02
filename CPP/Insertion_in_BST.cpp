// Insertion In Binary Search Tree (BST)

#include<bits/stdc++.h>
using namespace std;

// Data structure for storing a BST node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    // To create a new node with given data
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to perform inorder traversal
void inorder(struct Node* root)
{
    if (root == NULL) 
    return;
 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
// Function to insert a node in BST
struct Node* insert(struct Node* root, int key) 
{
    // If key is already present in tree
    if(root!= NULL && root->data == key)
    return root;
    
    // If root is NULL
    if (!root )
    return new Node(key);
 
    // If given key value is greater than root data
    if (key > root->data)
    root->right = insert(root->right, key);
    
    // If given key value is less than root data
    else
    root->left = insert(root->left, key);
    
    return root;
}

int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    struct Node* root = NULL;
    
    // Inserting all elements of keys array
    for (int key: keys)
    root = insert(root, key);
 
    inorder(root);
 
    return 0;
}
