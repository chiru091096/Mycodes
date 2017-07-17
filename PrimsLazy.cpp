/*
    @Chiranjeevi
    Date: 09-Jul-17
*/

/*
    Prim's Algorithm for finding MST 
    Running time O(ElogE)
    Extra Space Complexity O(E)
    Uses lazy version of selecting edges from priority queue
    Eager version(not implemented here) uses O(E) extra space (other than for graph representation)
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node{
    int src;
    int dst;
    float wgt;
    node *next;
};

struct compare{
    bool operator()(node *e1, node *e2){
        if(e1->wgt > e2->wgt)
            return true;
        else
            return false;
    }
};

node *newNode(int a, int b, float wgt){
    node *temp=new node;
    
    temp->src=a;
    temp->dst=b;
    temp->wgt=wgt;
    temp->next=NULL;
    
    return temp;
}

void addUWEdge(vector<node *> &gph, int a, int b, float wgt){
    node *ptr=gph[a];
    
    if(ptr==NULL)
        gph[a]=newNode(a, b, wgt);
    else{
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newNode(a, b, wgt);
    }
    
    ptr=gph[b];
    
    if(ptr==NULL)
        gph[b]=newNode(b, a, wgt);
    else{
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newNode(b, a, wgt);
    }
}

void createUWGraph(vector<node *> &gph, int E){
    int a, b;
    float wgt;
    
    for(int i=0; i<E; i++){
        cin>>a>>b>>wgt;
        addUWEdge(gph, a, b, wgt);
    }
}

void printUWGraph(vector<node *> &gph){
    int V=gph.size();
    node *ptr;
    
    for(int i=0; i<V; i++){
        ptr=gph[i];
        
        while(ptr!=NULL){
            cout<<ptr->src<<"--"<<ptr->dst<<" "<<ptr->wgt<<endl;
            ptr=ptr->next;
        }
    }
}

void visit(int vertex, vector<node *> &gph, priority_queue<node *, vector<node *>, compare> &pq, bool mark[]){
    node *ptr=gph[vertex];
    
    mark[vertex]=true;
    
    while(ptr!=NULL){
        if(!mark[ptr->dst])
            pq.push(ptr);
        ptr=ptr->next;
    }
    
}

void primsMST(vector<node *> &gph, queue<node *> &mst, bool mark[]){
    priority_queue<node *, vector<node *>, compare> pq;
    node *ptr;
    int count=1;
    int V=gph.size();
    
    visit(0, gph, pq, mark);
    
    while(!pq.empty() and count<V){
        ptr=pq.top();
        pq.pop();
        
        if(mark[ptr->src] and mark[ptr->dst])
            continue;
        else
            mst.push(ptr);
        
        if(!mark[ptr->src])
            visit(ptr->src, gph, pq, mark);
        else
            visit(ptr->dst, gph, pq, mark);
        count++;
    }
}

void printMST(queue<node *> mst){
    node *ptr;
    while(!mst.empty()){
        ptr=mst.front();
        mst.pop();
        cout<<ptr->src<<"--"<<ptr->dst<<" "<<ptr->wgt<<endl;
    }
}

int main(){
    int V, E;
    cin>>V>>E;
    
    vector<node *> gph(V, NULL); 
    queue<node *> mst;
    
    bool mark[V]={false};
    
    createUWGraph(gph, E);
    
    printUWGraph(gph);
    
    primsMST(gph, mst, mark);
    
    printMST(mst);
}
