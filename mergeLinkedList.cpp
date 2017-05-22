@Chiranjeevi
Date : 21-May-2017
#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

typedef struct Node node;


void print(node *ptr){
	while(ptr!=NULL){
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<endl;
}

node *createNode(int num){
	node *newnode=(node *)malloc(sizeof(node));
	newnode->data=num;
	newnode->next=NULL;
	return newnode;
}

void insert(node **ptr2head, node **ptr2tail, int num){
	node *tempnode=createNode(num);
	if(*ptr2head==NULL){
		*ptr2head=tempnode;
		*ptr2tail=tempnode;
	}
	else{
		(*ptr2tail)->next=tempnode;
		*ptr2tail=(*ptr2tail)->next;
	}
}

node *mergeLinkedList(node *ptr1,node *ptr2){
	if(ptr1==NULL)
		return ptr2;
	if(ptr2==NULL)
		return ptr1;

	node *head=NULL,*tail=NULL;
	while(ptr1!=NULL || ptr2!=NULL){
		if(ptr1==NULL){
			tail->next=ptr2;
			break;
		}
		else if(ptr2==NULL){
			tail->next=ptr1;
			break;
		}
		else if(ptr1->data>ptr2->data){
			if(head==NULL){
				head=tail=ptr2;
			}
			else{
				tail->next=ptr2;
				tail=tail->next;
			}
			ptr2=ptr2->next;
			tail->next=NULL;
		}
		else{
			if(head==NULL){
				head=tail=ptr1;
			}
			else{
				tail->next=ptr1;
				tail=tail->next;
			}
			ptr1=ptr1->next;
			tail->next=NULL;
		}
	}
	return head;
}

int main(){
	int n1,n2;
	cin>>n1>>n2;
	node *head1=NULL,*head2=NULL,*tail1=NULL,*tail2=NULL,*mergedhead=NULL;

	for(int i=1; i<=n1; i++)
		insert(&head1,&tail1,i*i);
	for(int i=1; i<=n2; i++)
		insert(&head2,&tail2,i*i/2);

	cout<<"First list:"<<endl;
	print(head1);
	cout<<"Second list:"<<endl;
	print(head2);

	cout<<"Merged list:"<<endl;
	mergedhead=mergeLinkedList(head1,head2);

	print(mergedhead);
}
