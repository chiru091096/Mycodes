#include <iostream>
#include <random>
using namespace std;

void exchange(int arr[], int i, int j){
    if(i<0)
        return;
    
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void print(int arr[], int n){
    for(int i=0;i<n;i++){
	    cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main() {
	int n=2;
	int ptr1=-1,ptr2=0,ptr3=n-1,current,flag=0;
	default_random_engine gen;
	uniform_int_distribution<int> dist(1,3);
	
	int arr[n];
	
	for(int i=0;i<n;i++){
	    arr[i]=dist(gen);
	}
	print(arr,n);
	
	while(ptr2<ptr3){
	    current=arr[ptr2];
	    if(current==1){
	        exchange(arr,ptr1,ptr2);
	        if(ptr1>=0){
	            ptr1++;
	        }
	        ptr2++;
	    }
	    else if(current==3){
	        while(arr[ptr3]==3 and ptr3>ptr2){
	            ptr3--;
	        }
	        exchange(arr,ptr2,ptr3);
	    }
	    else{
	        if(!flag){
	            ptr1=ptr2;
	            flag=1;
	        }
	        ptr2++;
	    }
	}
	
	print(arr,n);
	
	return 0;
}
