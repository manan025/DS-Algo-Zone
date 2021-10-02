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
Node* findPredecessor( Node* root ){
    auto temp=root->left;
    while( temp->right!=NULL && temp->right!=root ){
        temp=temp->right;
    }
    return temp;
}
void morrisPreorderTraversal(Node* root){
    Node* curr = root;
    while( curr != NULL){
        if( curr->left == NULL ){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            auto predecessor = findPredecessor(curr);
            if( predecessor->right==curr ){
                curr = curr->right;
                predecessor->right = NULL;
            }
            else{
                cout<<curr->data<<" ";
                predecessor->right = curr;
                curr = curr->left;
            }
        }
    }
}
void morrisInorderTraversal(Node* root){
    Node* curr = root;
    while( curr != NULL){
        if( curr->left == NULL ){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            auto predecessor = findPredecessor(curr);
            if( predecessor->right==curr ){
                cout<<curr->data<<" ";
                curr = curr->right;
                predecessor->right = NULL;
            }
            else{
                predecessor->right = curr;
                curr = curr->left;
            }
        }
    }
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

    cout<<"\n\n\n:::::: Morris Preorder Traversal O(1) Space ::::::\n\n";
    morrisPreorderTraversal(root);
    cout<<"\n\n";

    cout<<":::::: Morris Inorder Traversal O(1) Space ::::::\n\n";
    morrisInorderTraversal(root);
    cout<<"\n\n";
    return 0;
}