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
void verticalTraversalHelper( Node* root , unordered_map<int,vector<int>> &levels , int &minLevel , int &maxLevel , int currentLevel){
    if(root==NULL) return;
    minLevel = min( currentLevel,minLevel );
    maxLevel = max( currentLevel,maxLevel );
    levels[currentLevel].push_back(root->data);
    verticalTraversalHelper(root->left , levels , minLevel , maxLevel, currentLevel-1 );
    verticalTraversalHelper(root->right , levels , minLevel , maxLevel, currentLevel+1 );
}
void verticalTraversal(Node* root){
    if(root==NULL) return;
    unordered_map<int,vector<int>> levels;
    int minLevel = 0,maxLevel = 0;
    verticalTraversalHelper( root , levels , minLevel , maxLevel , 0);
    for( int i=minLevel; i<=maxLevel; i++ ){
        auto v=levels[i];
        for(auto j : v) cout<<j<<" ";
        cout<<endl;
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

    cout<<":::::: Vertical Traversal ::::::\n\n";
    verticalTraversal(root);

    return 0;
}