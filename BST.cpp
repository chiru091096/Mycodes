#include <iostream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *InsertBST (node *,int);
node *Getnode (int );
void Inorder (node *);
void Preorder (node *);
void Postorder (node *);
void PrintBST (node *);
node *DeleteNode (node *,int);
int HeightBT (node *);
void LevelOrder (node *);
bool CheckBST (node *);
node *InorderSucc (node *,int);
node *Find (node *,int);
int main() {
    int n,data,choice=1;
    node *root=NULL;
    
    cout<<"Enter the number of nodes in the tree"<<endl;
    cin>>n;
    cout<<"Enter the data"<<endl;
    
    for(int i=0;i<n;i++){
        cin>>data;
        root=InsertBST(root,data);
    }
    
    cout<<"Enter 1-Print Inorder"<<endl;
    cout<<"      2-Print Postorder"<<endl;
    cout<<"      3-Print Preorder"<<endl;
    cout<<"      4-Print LevelOrder"<<endl;
    cout<<"      5-Delete node"<<endl;
    cout<<"      6-Find height"<<endl;
    cout<<"      7-Check if tree is BST"<<endl;
    cout<<"      8-Find Inorder successor"<<endl;
    cout<<"      9-exit"<<endl;
    
    while(choice!=9){
        cin>>choice;
        switch(choice){
            case 1: Inorder(root);
                    cout<<endl;
                    break;
            case 2: Postorder(root);
                    cout<<endl;
                    break;
            case 3: Preorder(root);
                    cout<<endl;
                    break;
            case 4: LevelOrder(root);
                    cout<<endl;
                    break;
            case 5: cout<<"Enter data"<<endl;
                    cin>>data;
                    root=DeleteNode(root,data);
                    break;
            case 6: cout<<HeightBT(root)<<endl;
                    break;
            case 7: cout<<"Tree is ";
                    if(CheckBST){
                        cout<<"BST";
                    }
                    
                    else{
                        cout<<"not BST";
                    }
                    break;
            case 8: cout<<"Enter the data"<<endl;
                    cin>>data;
                    
                    node *ptr;
                    ptr=InorderSucc(root,data);
                    if(ptr==NULL){
                        cout<<"No inorder successor"<<endl;
                    }
                    else{
                        cout<<"Inorder successor is "<<ptr->data<<endl;
                    }
                    break;
            case 9: exit(0);
        }
    }
    
    return 0;
}

node *DeleteNode (node *root,int data){
    node *temp=root;
    if(root==NULL)
        return root;
    
    else if (root->data==data){
        if(root->left==NULL and root->right==NULL){
            delete root;
             root=NULL;
        }
        
        else if (root->left==NULL){
            node *temp=root->right;
            delete root;
            root=temp;;
        }
        
        else if (root->right==NULL){
            node *temp=root->left;
            delete root;
            return temp;
        }
        
        else{
            node *ptr=root->right;
            while(ptr->left!=NULL){
                ptr=ptr->left;
            }
            
            root->data=ptr->data;
            root->right=DeleteNode(root->right,root->data);
        }
    }
    
    else if (data<root->data)
        root->left=DeleteNode(root->left,data);
        
    else 
        root->right=DeleteNode(root->right,data);
        
    return root;
        
}

node *Getnode (int data){
    node *ptr=new node();
    ptr->data=data;
    ptr->left=ptr->right=NULL;
    return ptr;
}

node *InsertBST (node *root,int data){
    if(root==NULL){
        root=Getnode(data);
    }
    
    else if (data<=root->data){
        root->left=InsertBST(root->left,data);
    }
    
    else{
        root->right=InsertBST(root->right,data);
    }
    
    return root;
}

void PrintBST (node *root){
    cout<<"Inorder traversal "<<endl;
    Inorder(root);
    cout<<endl;
}

void Preorder (node *root){
    if(root==NULL)
        return;
        
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder (node *root){
    if(root==NULL)
        return;
    
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Postorder (node *root){
    if(root==NULL)
        return;
        
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

int HeightBT (node *root){
    int leftHeight,rightHeight;
    if(root==NULL){
        return -1;
    }
    
    leftHeight=HeightBT(root->left);
    rightHeight=HeightBT(root->right);
    
    return max(leftHeight,rightHeight)+1;
}

void LevelOrder (node *root){
    queue<node *> q;
    node *temp=NULL;
    if(root==NULL)
        return;
    q.push(root);
    
    while(!q.empty()){
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}

int value=INT_MIN;
bool flag=true;

bool CheckBST (node *root){
    if(root==NULL)
        return flag;
    
    flag=CheckBST(root->left);
    
    if(root->data>=value && flag!=false){
        value=root->data;
    }
    
    else{
        flag=false;
    }
        
    flag=CheckBST(root->right);
    return flag;
}

node *InorderSucc (node *root,int data){
    node *ptr=Find(root,data);
    
    if(ptr==NULL){
        return ptr;
    }
    
    else if(ptr->data==data){
        if(ptr->right!=NULL){
            ptr=ptr->right;
            while(ptr->left!=NULL){
                ptr=ptr->left;
            }
            return ptr;
        }
        
        else{
            ptr=root;
            node *ancestor=NULL;
            while(data!=ptr->data){
                if(data<ptr->data){
                    ancestor=ptr;
                    ptr=ptr->left;
                }
            
                else if(data>ptr->data){
                    ptr=ptr->right;
                }
            }
            return ancestor;
        }
    }
}

node *Find (node *root,int data){
    if(root==NULL or root->data==data)
        return root;
    else if(data<root->data)
        return Find(root->left,data);
    else 
        return Find(root->right,data);
}
