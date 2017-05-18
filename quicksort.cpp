@chiranjeevi
Date: 18-May-2017

#include <iostream>
#include <random>

using namespace std;

void exchange(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[], int lo, int hi){
    int i=lo,j=hi+1;
    int pivot=lo;
    while(true){
        while(arr[++i]<arr[pivot]){     //most important step (for equal keys)
            if(i>hi)
                break;
        }
        while(arr[--j]>arr[pivot]){     //cant decrement inside loop-creates problem for 1, 1, 1
            if(j<lo)
                break;
        }
        
        if(i>=j)
            break;
        exchange(arr,i,j);
    }
    exchange(arr,pivot,j);
    return j;
}

void quicksort(int arr[], int lo, int hi){
    if(hi<=lo)
        return;
    int j=partition(arr,lo,hi);
    quicksort(arr,lo,j-1);
    quicksort(arr,j+1,hi);
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
	int n,range;
	cin>>n>>range;
	int arr[n];
	
	default_random_engine gen;
	uniform_int_distribution<int> dist(1,range);
	
	for(int i=0; i<n; i++)
	    arr[i]=dist(gen);
	   
	print(arr,n);
	
	quicksort(arr,0,n-1);
	
	print(arr,n);
	
	return 0;
}
