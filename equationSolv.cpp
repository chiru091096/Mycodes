/*
@Chiranjeevi
Date: 07-June-2017
*/

#include <iostream>
using namespace std;

struct node{
    long long int sum;
    long int i;
    long int j;
};

void exchange(struct node minPQ[], long int i, long int j){
    struct node temp;
    temp=minPQ[i];
    minPQ[i]=minPQ[j];
    minPQ[j]=temp;
}

void swim(struct node minPQ[], long int k){
    while(k>0 and (minPQ[k].sum < minPQ[(k-1)/2].sum)){
        exchange(minPQ, k, (k-1)/2);
        k=(k-1)/2;
    }
}

void insert(struct node minPQ[], long int i, long int j, long int *np, int flag){
    long long int sum;
    if(flag==0){
        sum=i+2*j*j;
    }
    else{
        sum=3*i*i*i+4*j*j*j*j;
    }
    
    minPQ[++(*np)].sum=sum;
    minPQ[*np].i=i;
    minPQ[*np].j=j;
    swim(minPQ,*np);
}

bool isEmpty(struct node minPQ[], long int n){
    return n<0;
}

void sink(struct node minPQ[], long int k, long int n){
    long int j;
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

struct node delMin(struct node minPQ[], long int *np){
    struct node temp=minPQ[0];
    minPQ[0]=minPQ[(*np)--];
    sink(minPQ, 0, *np);
    return temp;
}

void createminPQ(struct node minPQ[], long int *np, int flag){   
    for(int i=0; i<*np; i++){
        if(flag==0)
            minPQ[i].sum=i;                //i+2*0*0
        else
            minPQ[i].sum=3*i*i*i;          //3*i*i*i+4*0*0*0*0
       
        minPQ[i].i=i;
        minPQ[i].j=0;
    }
    (*np)--;
}

int main() {
    long int n1;
    cin>>n1;
    struct node minPQ1[n1+5], minPQ2[n1+5];
    struct node num1, num2;
    num1.i=-1;
    num2.i=-1;
    
    long int N=n1, n2=n1;
    
    createminPQ(minPQ1, &n1, 0);
    createminPQ(minPQ2, &n2, 1);
    
    while(!isEmpty(minPQ1, n1) and !isEmpty(minPQ2, n2)){
        if(num1.i<0)
            num1=delMin(minPQ1, &n1);
        if(num2.i<0)
            num2=delMin(minPQ2, &n2);
        
        
        if(num1.sum==num2.sum){
            cout<<num1.i<<"+2*"<<num1.j<<"^2 = 3*"<<num2.i<<"^3+4*"<<num2.j<<"^4"<<endl;
            if(num1.j+1 < N)
                insert(minPQ1, num1.i, num1.j+1, &n1, 0);
            if(num2.j+1 < N)
                insert(minPQ2,num2.i, num2.j+1, &n2, 1);
            num1.i=-1;
            num2.i=-1;
        }
        else if(num1.sum < num2.sum){
            if(num1.j+1 < N)
                insert(minPQ1, num1.i, num1.j+1, &n1, 0);;
            num1.i=-1;
        }
        if(num2.sum < num1.sum){
            if(num2.j+1 < N)
                insert(minPQ2,num2.i, num2.j+1, &n2, 1);
            num2.i=-1;
        }
    }
	return 0;
}
