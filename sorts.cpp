/*
 * sortAlg.cpp
 *
 *  Created on: 19-Dec-2016
 *      Author: ChiranjeeviAR
 */

// Sorting algorithms

#include <iostream>
#include <cmath>
using namespace std;

void print (int [] ,int );
void selectionSort (int [] ,int  );
void insertionSort (int [] ,int  );
void bubbleSort (int [] ,int );
void mergeSort (int [] ,int );
void merge (int [] ,int [] ,int [] ,int );
void quickSort (int [] ,int ,int );
int partition (int [] ,int ,int );

int main(){
	int n,choice;
	cout<<"Enter the no of elements"<<endl;
	cin>>n;
	int arr[n];

	cout<<"Enter the elements one by one\n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	cout<<"Enter 1-Selection Sort"<<endl;
	cout<<"      2-Insertion Sort"<<endl;
	cout<<"      3-Bubble Sort"<<endl;
	cout<<"      4-Merge Sort"<<endl;
	cout<<"      5-Quick Sort"<<endl;
	cout<<"      6-Exit"<<endl;

	cin>>choice;

	while(choice!=6){
		switch(choice){
			case 1: selectionSort(arr,n);
					print(arr,n);
				break;
			case 2: insertionSort(arr,n);
					print(arr,n);
				break;
			case 3: bubbleSort(arr,n);
					print(arr,n);
				break;
			case 4: mergeSort(arr,n);
					print(arr,n);
				break;
			case 5: quickSort(arr,0,n-1);
					print(arr,n);
				break;
			case 6: exit(0);
		}
		cout<<"Enter choice\n";
		cin>>choice;
	}

	return 0;
}

int min (int arr[] ,int start ,int n ){
	int index,min=INT_MAX;

	for(int i=start;i<n;i++){
		if(arr[i]<min){
			index=i;
			min=arr[i];
		}
	}
	return index;
}

void print (int arr[],int n){

	cout<<"Sorted list is\n";
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
}

void selectionSort (int arr[] ,int n ){

	for(int i=0,index=0,temp;i<n-1;i++){
			index=min(arr,i,n);
			temp=arr[i];
			arr[i]=arr[index];
			arr[index]=temp;
		}
}

void bubbleSort (int arr[] ,int n){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int k=0;k<n-i-1;k++){
			if(arr[i]>arr[i+1]){
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
	}
}

void insertionSort (int arr[] ,int n){

	for(int i=1,value;i<n;i++){
		value=arr[i];
		for(int j=i-1;j>=0;j++){
			if(arr[j]>value){
				arr[j+1]=arr[j];
			}
			else{
				arr[j+1]=value;
				break;
			}
		}
	}
}

void mergeSort(int arr[] ,int n){

	if(n<2)
		return;
	else{
		int mid=n/2;
		int left[mid],right[n-mid];

		for(int i=0;i<mid;i++){
			left[i]=arr[i];
		}

		for(int i=0;i<n-mid;i++){
			right[i]=arr[mid+i];
		}
		mergeSort(left,mid);
		mergeSort(right,n-mid);
		merge(left,right,arr,n);
	}
}

void merge (int left[] ,int right[] ,int arr[] ,int n){
	int mid=n/2;
	int i=0,j=0,k=0;

	while(i<mid and j<n-mid){
		if(left[i]<right[j]){
			arr[k++]=left[i++];
		}
		else{
			arr[k++]=right[j++];
		}
	}
	while(i<mid){
		arr[k++]=left[i++];
	}
	while(j<n-mid){
		arr[k++]=right[j++];
	}
}

void quickSort (int arr[] ,int start , int end ){
	int pIndex;

	if(start<end){
		pIndex=partition(arr,start,end);
		quickSort(arr,start,pIndex-1);
		quickSort(arr,pIndex+1,end);
	}
}

int partition (int arr[] ,int start ,int end){
	int partIndex=start;  //index to first element greater than pivot element
	int pivot=end;
	int temp;

	for(int i=start;i<end;i++){
		if(arr[i]<arr[pivot]){
			temp=arr[partIndex];
			arr[partIndex++]=arr[i];
			arr[i]=temp;
		}
	}

	temp=arr[partIndex];
	arr[partIndex]=arr[pivot];
	arr[pivot]=temp;

	return partIndex;
}










