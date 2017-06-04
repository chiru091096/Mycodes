/*
@chiranjeevi
Date: 04-June-2017
*/

#include <iostream>
using namespace std;

void exchange(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void swim(int arr[], int k){
    while(k > 1 and arr[k] > arr[k/2]){
            exchange(arr, k, k/2);
        k/=2;
    }
}

void sink(int arr[], int n, int k){
    int j;
    while(2*k <= n){
        j=2*k;
        if(j < n and arr[j] < arr[j+1])
            j+=1;
        
        
        if(arr[k] < arr[j]){
            exchange(arr, k, j);
            k=j;
        }
        else
            break;
    }
}

void insert(int arr[], int *np, int value){
    arr[++(*np)]=value;
    swim(arr, *np);
}

void delMax(int arr[], int *np){
    int max=arr[1];
    arr[1]=arr[*np];
    (*np)--;
    sink(arr, *np, 1);
}

int max(int arr[]){
    return arr[1];
}

bool isEmpty(int n){
    return n==0;
}

void print(int arr[], int n){
    for(int i=1; i<=n; i++)
        cout<<(char)arr[i]<<' ';
    cout<<endl;
}

int main() {
	int arr[100] = {0, 'T', 'P', 'R', 'N', 'H', 'O', 'A', 'E', 'I', 'G'};
	int n = 10;
	insert(arr, &n, 'S');
	delMax(arr, &n);
	delMax(arr, &n);
	insert(arr, &n, 'S');
	print(arr, n);
	return 0;
}
