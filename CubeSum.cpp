/*
@Chiranjeevi
Date: 06-June-2017
*/

#include <iostream>
using namespace std;

struct node{
    int sum;
    int i;
    int j;
};

void exchange(struct node minPQ[], int i, int j){
    struct node temp;
    temp=minPQ[i];
    minPQ[i]=minPQ[j];
    minPQ[j]=temp;
}

void swim(struct node minPQ[], int k){
    while(k>0 and (minPQ[k].sum < minPQ[(k-1)/2].sum)){
        exchange(minPQ, k, (k-1)/2);
        k=(k-1)/2;
    }
}

void insert(struct node minPQ[], int i, int j, int *np){
    int sum=i*i*i+j*j*j;
    minPQ[++(*np)].sum=sum;
    minPQ[*np].i=i;
    minPQ[*np].j=j;
    swim(minPQ,*np);
}

bool isEmpty(struct node minPQ[], int n){
    return n<0;
}


void sink(struct node minPQ[], int k, int n){
    int j;
    while(2*k+1 <= n and k>=0){
        j=2*k+1;
        if(j+1 <= n and minPQ[j+1].sum < minPQ[j].sum)
            j++;
        if(minPQ[k].sum <= minPQ[j].sum)
            break;
        exchange(minPQ, k, j);
        k=j;
    }
}

struct node delMin(struct node minPQ[], int *np){
    struct node temp=minPQ[0];
    minPQ[0]=minPQ[(*np)--];
    sink(minPQ, 0, *np);
    return temp;
}

void createminPQ(struct node minPQ[], int *np){

    for(int i=0; i<*np; i++){
        minPQ[i].sum=2*i*i*i;
        minPQ[i].i=i;
        minPQ[i].j=i;
    }
    (*np)--;
}

int main() {
    int n;
    cin>>n;
 
    struct node minPQ[n*n];
    struct node num;
    int N=n;
       
    createminPQ(minPQ, &n);
    
    while(!isEmpty(minPQ, n)){
        num=delMin(minPQ, &n);
        cout<<num.i<<"^3 + "<<num.j<<"^3 = "<<num.sum<<endl;
        
        if(num.j+1 < N){
            insert(minPQ,num.i, num.j+1, &n);
        }
    }
    
	return 0;
}
