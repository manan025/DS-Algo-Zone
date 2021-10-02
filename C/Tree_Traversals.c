//A recursive Algorithm in C

#include<stdio.h>
#include<stdlib.h>

//Defining the structure of node
struct node{ 
    int data;
    struct node*left;
    struct node*right;
};

//Function to create a new node which sets its data to num and its children to null
struct node* create(int num){
    struct node*p=(struct node*)malloc(sizeof(struct node));
    p->data=num;
    p->left=NULL;
    p->right=NULL;
    return p;
}

//Function to implement pre-order traversal
void preOrder(struct node*root){
    if(root!=NULL){
        printf("%d ",root->data); // 1. data of root is printed
        preOrder(root->left); // 2. Left child of root is visited 
        preOrder(root->right); // 3. Right child of root is visites
    }
}

void postOrder(struct node*root){
    if(root!=NULL){
        postOrder(root->left); // 1. Left child of root is visited 
        postOrder(root->right); // 3. Right child of root is visites
        printf("%d ",root->data); // 3. data of root is printed
    }
}

void inOrder(struct node*root){
    if(root!=NULL){
        inOrder(root->left); // 2. Left child of root is visited 
        printf("%d ",root->data); // 2. data of root is printed
        inOrder(root->right); // 3. Right child of root is visites
    }
}

int main(){

    //Nodes have been created by calling create() funciton 
    struct node* p = create(4);
    struct node* p1 = create(1);
    struct node* p2 = create(6);
    struct node* p3 = create(5);
    struct node* p4 = create(2);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    //Preorder Traveral
    printf("Preorder Traversal: \t");
    preOrder(p); // preOrder() function has been called
    printf("\n");

    //Postorder Traveral
    printf("Postorder Traversal: \t");
    postOrder(p); // postOrder() function has been called
    printf("\n");

    // Inorder Traversal
    printf("Inorder Traversal: \t"); 
    inOrder(p); // inOrder() function has been called

   return 0;
}