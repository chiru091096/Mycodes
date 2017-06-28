/*
@Chiranjeevi
Date: 28-Jun-17
*/

/*
    stl priority queue c++ using functor
*/

#include <iostream>
#include <queue>

using namespace std;

struct node{
    int a, b;    
};

struct compare {
    bool operator()(node x, node y) {
         if(x.a<y.a)                
             return  true;  // returning true means swap first and second argument i.e greater will be at first in the array , i.e array is max priority queue as index 0 stroes max element.
         else 
             return false;
    } 
};


int main(){
    priority_queue<node, vector<node>, compare> pq;
    node x,y,z;
    x.a=100;
    x.b=11;
    
    y.a=101;
    y.b=12;
    
    z.a=99;
    z.b=100;
    
    pq.push(x);
    pq.push(y);
    pq.push(z);
        
    while(!pq.empty()){
        cout<<pq.top().a<<endl;
        pq.pop();
    }
    
     
    return 0;
}