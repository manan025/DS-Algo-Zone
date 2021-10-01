// Insertion in Binary Search Tree (BST)

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root)
{
    if (root == NULL) 
    return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

struct Node* insert(struct Node* root, int key) 
{
    // If the key is already present in the tree
    // return the root (as duplicate keys are not allowed in BST)
    if(root!= NULL && root->data == key)
    return root;
    
    // If root is NULL, insert the first node
    if (!root)
    return new Node(key);
 
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

int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    Node* root = NULL;
    for (int key: keys) 
    root = insert(root, key);
 
    inorder(root);
 
    return 0;
}

//Time Complexity: The time complexity for insertion in a BST in O(h) where h is the height of the Binary Search Tree