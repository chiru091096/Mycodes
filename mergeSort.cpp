@chiranjeevi
Date: 14/5/17
#include <iostream>
#include <random>

using namespace std;

void merge(int arr[], int aux[], int lo, int mid, int hi){
    for(int i=lo; i<=hi; i++)
        aux[i]=arr[i];
    
    for(int k=lo,i=lo,j=mid+1; k<=hi; k++){
        if(i>mid)
            arr[k]=aux[j++];
        else if(j>hi)
            arr[k]=aux[i++];
        else if(aux[i]>aux[j])          //compare from aux array
            arr[k]=aux[j++];
        else
            arr[k]=aux[i++];            //maintains stability
    }
}

void mergesort(int arr[], int aux[], int lo, int hi){
    if(hi<=lo)
        return;
    int mid=lo+(hi-lo)/2;
    mergesort(arr,aux,lo,mid);
    mergesort(arr,aux,mid+1,hi);
    merge(arr,aux,lo,mid,hi);
}

void print(int arr[], int n){
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }    
    cout<<endl;
}
int main() {
	int n,range;
	cin>>n>>range;
	int arr[n],aux[n];
	
	default_random_engine gen;
	uniform_int_distribution<int> dist(1,range);
	
	for(int i=0;i<n;i++){
	    arr[i]=dist(gen);
	}
	
	print(arr,n);
	
	mergesort(arr,aux,0,n-1);
	
	print(arr,n);
	return 0;
}
