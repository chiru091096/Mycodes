@chiranjeevi
Date: 19-May-17

#include <iostream>
#include <algorithm>

using namespace std;

void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int countInversions(int arr[], int aux[], int lo, int mid, int hi, int count){
    for(int i=lo; i<=hi; i++)
        aux[i]=arr[i];
        
    for(int k=lo,i=lo,j=mid+1; k<=hi; k++){
        if(i>mid){
            arr[k]=aux[j++];
        }
        
        else if(j>hi){
            arr[k]=aux[i++];
        }
        
        else if(aux[i]<aux[j]){
            arr[k]=aux[i++];
            count+=hi-j+1;
        }
        
        else{
            arr[k]=aux[j++];
        }
    }
    return count;
}

int findInversions(int arr[], int aux[], int lo, int hi, int count){
    if(hi<=lo)
        return count;
    int mid=lo+(hi-lo)/2;
    count=findInversions(arr,aux,lo,mid,count) + findInversions(arr,aux,mid+1,hi,count);
    return countInversions(arr,aux,lo,mid,hi,count);
}


int main() {
	int n,no_of_invers;
	cin>>n;
	int arr[n],aux[n];
	
	for(int i=0; i<n; i++){
	    arr[i]=20-i;
	}
	
	random_shuffle(arr,arr+n);
	
	print(arr,n);
	
	no_of_invers=findInversions(arr,aux,0,n-1,0);
	
	print(arr,n);
	
	cout<<"No of inversions "<<(n*(n-1))/2-no_of_invers;
	return 0;
}
