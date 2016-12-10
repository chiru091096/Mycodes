//Reversing a linked list : Iterative method

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

void PrintList (node *head);
node *InsertList (node *head,int data);
node *ReverseList (node *head);

int main() {
	int n,data;
	node *head=NULL;
	cout<<"Enter the total number of elements in the list"<<endl;
	cin>>n;
	
	for(int i=0;i<n;i++){
	    cin>>data;
	    head=InsertList(head,data);
	}
	
	PrintList(head);
	cout<<endl;
	head=ReverseList(head);
	PrintList(head);
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
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

node *ReverseList (node *head){
    node *temp;
    node *current=head;
    node *prev=NULL;
    
    while(current!=NULL){
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    
    head=prev;
    return head;
}
