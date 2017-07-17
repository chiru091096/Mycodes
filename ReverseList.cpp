//Reversing linked list using recursion

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

void PrintList (node *head);
node *InsertList (node *head,int data);
node *ReverseList (node *head);
struct node *root=NULL;
int main() {
	int n,data;
	node *head=NULL;
	node *temp=NULL;
	cout<<"Enter the total number of elements in the list"<<endl;
	cin>>n;
	
	for(int i=0;i<n;i++){
	    cin>>data;
	    head=InsertList(head,data);
	}
	
	PrintList(head);
	cout<<endl;
	temp=ReverseList(head);
	temp->next=NULL;
	PrintList(root);
	return 0;
}
node *GetNode (int data){
    node *ptr=new node();
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

node *InsertList(node *head,int data){
    if(head==NULL){
        head=GetNode(data);
        return head;
    }
    
    node *ptr=GetNode(data);
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    temp->next=ptr;
    return head;
}

void PrintList (node *head){
    if(head==NULL){
        return;
    }
    
    cout<<head->data<<" ";
    PrintList(head->next);
}

node *ReverseList (node *head){
    if(head==NULL or head->next==NULL){
        root=head;
        return head;
    }
    node *temp=ReverseList(head->next);
    temp->next=head;
    return head;
}
/* 
void ReverseList (node *head){
    if(head==NULL or head->next==NULL){
        root=head;
        return;
    }
    
    ReverseList(head->next);
    node *temp=head->next;
    temp->next=head;
}
*/
