/*
    @Chiranjeevi
    Date: 12-Jun-2017
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

struct node{
    int data;
    int count;
    node *left;
    node *right;
};

node *newNode (int data){
    node *temp = new node;
    temp->data = data;
    temp->count = 1;
    temp->left = temp->right = NULL;
    return temp;
}

int returnCount (node *ptr){
    
    if (ptr==NULL)
        return 0;
    else
        return ptr->count;
}

node *insert (int data, node *ptr){
    
    if (ptr == NULL)
        return newNode(data);
    else if (data < ptr->data)
        ptr->left = insert(data, ptr->left);
    else if (data >= ptr->data)
        ptr->right = insert(data, ptr->right);

    ptr->count += 1;
    return ptr;
}

bool search (int data, node *ptr){
    
    if (ptr == NULL)
        return false;
    else if (data < ptr->data)
        return search(data, ptr->left);
    else if (data > ptr->data)
        return search(data, ptr->right);
    else return true;
}

int floor (int data, node *ptr){
    
    if (ptr == NULL)
        return INT_MIN;
    else if (data < ptr->data)
        return floor(data, ptr->left);
    else if (data > ptr->data)
        return max(ptr->data, floor(data, ptr->right));
    else
        return data;
}

int ceil (int data, node *ptr){
    
    if (ptr == NULL)
        return INT_MAX;
    else  if(data < ptr->data)
        return min(ptr->data, ceil(data, ptr->left));
    else if (data > ptr->data)
        return ceil(data, ptr->right);
    else
        return data;
}

int rankOfNode (int data, node *ptr){
    
    if (ptr == NULL)
        return 0;
    else if (data < ptr->data )
        return rankOfNode(data, ptr->left);
    else if (data > ptr->data)
        return 1 + returnCount(ptr->left)  + rankOfNode(data, ptr->right);
    else 
        return returnCount(ptr->left);
}

void inorder (node *ptr){

    if(ptr == NULL)
        return;
    inorder(ptr->left);
    cout<<char(ptr->data)<<" ";
    inorder(ptr->right);
}

node *deleteNode (int data, node *ptr){

    if (ptr == NULL)
        return ptr;
    else if (data < ptr->data)
        ptr->left = deleteNode(data, ptr->left);
    else if (data > ptr->data)
        ptr->right = deleteNode(data, ptr->right);
    else{
        if (ptr->left == NULL)
            return ptr->right;
        if (ptr->right == NULL)
            return ptr->left;
        
        node *temp = ptr->right;
        
        while (temp->left != NULL)
            temp = temp->left;
        
        ptr->data = temp->data;

        ptr->right = deleteNode(temp->data, ptr->right);
    }
    
    ptr->count -= 1; 
    return ptr;    
}

void levelorder (node *ptr){
    queue<node *> levelt;
    node *temp;

    if (ptr != NULL)
        levelt.push(ptr);
    
    while (!levelt.empty()){
        temp = levelt.front();
        levelt.pop();
        
        cout<<char(temp->data)<<" ";
        
        if(temp->left != NULL)
            levelt.push(temp->left);
        if(temp->right != NULL)
            levelt.push(temp->right);
    }
}

int main(){
    
    node *root = NULL;
    
    root = insert('S', root);
    root = insert('E', root);
    root = insert('X', root);
    root = insert('A', root);
    root = insert('R', root);
    root = insert('C', root);
    root = insert('H', root);
    root = insert('G', root);
    root = insert('M', root);
    
    inorder(root);
     
    return 0;
}


