@chiranjeevi
Date: 18-May-2017

#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void exchange(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[], int lo, int hi){
    int i=lo,j=hi+1;
    int pivot=lo;
    if(lo==hi)
        return lo;
        
    while(true){
        while(arr[++i]<arr[pivot]){
            if(i>=hi)
                break;
        }
        
        while(arr[--j]>arr[pivot]){
            if(j<=lo)
                break;
        }
        
        if(i>=j)
            break;
        exchange(arr,i,j);
    }
    exchange(arr,pivot,j);
    return j;
}

int findKthLargest(int arr[], int lo, int hi, int k){
    if(k>hi || k<lo)
        return -1;
    
    while(true){
        int j=partition(arr,lo,hi);
        if(j==k)
            return arr[j];
        else if(k<j){
            hi=j-1;
        }
        else{
            lo=j+1;
        }
    }
}

int main() {
	int n,range,k,element;
	cin>>n>>range>>k;
	int arr[n];
	
	default_random_engine gen;
	uniform_int_distribution<int> dist(1,range);
	
	for(int i=0; i<n; i++)
	    arr[i]=19-i;
	
	random_shuffle(arr,arr+n);    //if input taken from user
	print (arr,n);
	
	element=findKthLargest(arr,0,n-1,k);
	cout<<element<<endl;
	
	print(arr,n);
	return 0;
}
