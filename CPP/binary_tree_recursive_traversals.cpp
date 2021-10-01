/*  Lets take the tree as::::::::

                    1
                   / \
                  2   3
                 /   / \
                4   5   6
               /     \
              7       8
*/

#include<bits/stdc++.h>
using namespace std;
class Node{
    public : 
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left=NULL;
            this->right=NULL;
        }
};

void inorderTraversal(Node* root){
    if(root==NULL) return;
    inorderTraversal( root->left );
    cout<<" "<<root->data<<" ";
    inorderTraversal( root->right );
}
void preorderTraversal(Node* root){
    if(root==NULL) return;
    cout<<" "<<root->data<<" ";
    preorderTraversal( root->left );
    preorderTraversal( root->right );
}
void postorderTraversal(Node* root){
    if(root==NULL) return;
    postorderTraversal( root->left );
    postorderTraversal( root->right );
    cout<<" "<<root->data<<" ";
}
int main(){
    Node* root = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);
    Node* six = new Node(6);
    Node* seven = new Node(7);
    Node* eight = new Node(8);

    root->left = two;
    root->right = three;
    two->left=four;
    three->left=five;
    three->right=six;
    four->left=seven;
    five->right=eight;

    cout<<":::::: Inorder Traversal ::::::"<<endl;
    inorderTraversal(root);

    cout<<"\n\n:::::: Preorder Traversal ::::::"<<endl;
    preorderTraversal(root);

    cout<<"\n\n:::::: Postorder Traversal ::::::"<<endl;
    postorderTraversal(root);

    return 0;
}