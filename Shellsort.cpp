@chiranjeevi

#include <iostream>
using namespace std;

void shellSort(int arr[], int n){
    int h=1,temp;
    
    while(3*h+1<n){
        h=3*h+1;
    }
    
    while(h>0){
        for(int i=h;i<n;i++){
            for(int j=i;j>=h;j-=h){
                if(arr[j]<arr[j-h]){
                    temp=arr[j];
                    arr[j]=arr[j-h];
                    arr[j-h]=temp;
                }
                else{
                    break;
                }
            }
        }
        /*for(int i=0;i<n;i++){  cout<<arr[i]<<" ";}*/
        cout<<endl;
        h/=3;        //same as h-1/3
    }
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    shellSort(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
	return 0;
}
