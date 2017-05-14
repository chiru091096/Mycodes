@chiranjeevi
Date: 14-May-17

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
        else if(aux[i]>aux[j])
            arr[k]=aux[j++];
        else 
            arr[k]=aux[i++];
    }
}

void bottomupMergeSort(int arr[], int aux[], int n){
    int sz=1;
    
    while(sz<n){
        for(int i=0; i+sz<n; i+=sz+sz) //                  // till mid+1<n  to prevent redundant merge of arrays smaller the size sz
            merge(arr,aux,i,min(i+sz-1,n-1),min(i+sz+sz-1,n-1));        //lo=i,mid=lo+(hi-lo)/2=i+(sz+sz-1)/2,hi=i+sz+sz-1
            
        sz+=sz;
    }
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int n,range;
    cin>>n>>range;
    int arr[n],aux[n];
    
    default_random_engine gen;
    uniform_int_distribution<int> dist(1,range);
    
    for(int i=0; i<n; i++){
        arr[i]=dist(gen);
    }
    
    print(arr,n);
    
    bottomupMergeSort(arr,aux,n);
    
    print(arr,n);
}
