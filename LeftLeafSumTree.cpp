@Chiranjeevi
Date: 30-July-17

http://www.geeksforgeeks.org/find-sum-left-leaves-given-binary-tree/


#include <iostream>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};



node *newNode(int data){
    node *temp= new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    
    return temp;
}

bool isLeaf(node *ptr){
    if(ptr==NULL)
        return false;
    else if(ptr->left==NULL and ptr->right==NULL)
        return true;
    else
        return false;
}

int leftLeafSum(node *root){
    if(root==NULL)
        return 0;
    
    if(isLeaf(root->left))
        return(root->left->data+leftLeafSum(root->right));
    else
        return(leftLeafSum(root->left)+leftLeafSum(root->right));
}

int main() {
    node *root=NULL;
    
    root=newNode(20);
    
    root->left=newNode(9);
    root->right=newNode(49);
    
    root->left->left=newNode(5);
    root->left->right=newNode(12);
    
    root->right->left=newNode(23);
    root->right->right=newNode(52);
    
    
    root->left->right->right=newNode(15);
    root->right->right->left=newNode(50);
    
    
    cout<<leftLeafSum(root);
    
    
    return 0;
}
