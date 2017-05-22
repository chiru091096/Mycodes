@chiranjeevi
Date : 21-May-17

#include <iostream>
#include <random>

using namespace std;

typedef struct Node
{
	int data;
	struct Node *next;
}node;


void print(node *ptr){
	while(ptr!=NULL){
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<endl;
}

node *createNode(int num){
	node *newnode = new node;
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

node *mergeLists(node *ptr1, node *ptr2){
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

node *linkedMergeSort(node *ptr){
	if(ptr->next==NULL)
		return ptr;

	node *ptr1=ptr,*ptr2=ptr;

	while(ptr2->next!=NULL && ptr2->next->next!=NULL){
		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
	}
	node *temp=ptr1->next;
	ptr1->next=NULL;
	ptr1=temp;

	ptr=linkedMergeSort(ptr);
	ptr1=linkedMergeSort(ptr1);
	ptr=mergeLists(ptr,ptr1);
	return ptr;
}


int main(){
	int n,range;
	cin>>n>>range;

	node *head=NULL,*tail=NULL;

	default_random_engine gen;
	uniform_int_distribution<int> dist(1,range);

	for(int i=0; i<n; i++)
		insert(&head,&tail,dist(gen));
	
	cout<<"Input list:"<<endl;
	print(head);

	head=linkedMergeSort(head);

	cout<<"Sorted list:"<<endl;
	print(head);
}