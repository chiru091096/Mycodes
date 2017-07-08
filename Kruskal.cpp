/*
    @Chiranjeevi
    Date: 08-Jul-17
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node{
    int src;
    int dst;
    float wgt;
    node *next;
};

struct compare{
    bool operator() (node *e1, node *e2){
        if(e1->wgt > e2->wgt)
            return true;
        else
            return false;
    }
};

node *newNode(int src, int dst, float wgt){
    node *temp=new node;
    temp->src=src;
    temp->dst=dst;
    temp->wgt=wgt;
    temp->next=NULL;
 
    return temp;
}

void addUWEdge(vector<node *> &uwgph, int a, int b, float wgt){
   
    node *ptr=uwgph[a];
    node *temp=ptr;
    
    if(ptr==NULL)
        uwgph[a]=temp=newNode(a, b, wgt);
    else{
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=temp=newNode(a, b, wgt);
    }
    
    ptr=uwgph[b];
    
    if(ptr==NULL)
        uwgph[b]=newNode(b, a, wgt);
    else{
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newNode(b, a, wgt);
    }
 
}

void createUWGraph(vector<node *> &uwgph , int E){
    int a,b;
    float wgt;
    
    for(int i=0; i<E; i++){
        cin>>a>>b>>wgt;
        addUWEdge(uwgph, a, b, wgt);
    }
}

void printUWGraph(vector<node *> &uwgph){
    int V=uwgph.size();
    node *ptr=NULL;
        
    for(int i=0; i<V; i++){
        ptr=uwgph[i];
        
        while(ptr!=NULL){
            cout<<ptr->src<<"--"<<ptr->dst<<" "<<ptr->wgt<<endl;
            ptr=ptr->next;
        }
    }
}

void initializeUF(int parent[], int size[], int V){
    for(int i=0; i<V; i++){
        parent[i]=i;
        size[i]=1;
    }
}

int root(int a, int parent[]){
    int i=a;
    while(parent[i]!=i)
        i=parent[i];
    return i;
}

bool connected(int a, int b, int parent[], int size[]){
    if(root(a, parent)==root(b, parent))
        return true;
    else
        return false;
}

void unify(int a, int b, int parent[], int size[]){
    if(connected(a, b, parent, size))
        return;
    else{
        int par_a=root(a, parent);
        int par_b=root(b, parent);
        
        if(size[par_a] > size[par_b]){
            parent[par_b]=par_a;
            size[par_a]+=size[par_b];
        }
        
        else{
            parent[par_a]=par_b;
            size[par_b]+=size[par_a];
        }
    }
}

void buildMinPQ(vector<node *> &uwgph, priority_queue<node *, vector<node *>, compare> &pq){
    int V=uwgph.size();
    node *ptr=NULL;
    
    for(int i=0; i<V; i++){
        ptr=uwgph[i];
        
        while(ptr!=NULL){
            if(ptr->src>=i and ptr->dst>=i )
                pq.push(ptr);
            ptr=ptr->next;
        }
    }
}

void kruskalMST(vector<node *> &uwgph, queue<node *> &mst_edges, int parent[], int size[]){
    int V=uwgph.size();
    int count = 0;
    priority_queue<node *, vector<node *>, compare> pq;
    node *ptr=NULL;
    
    buildMinPQ(uwgph, pq);
    
    while(!pq.empty() and count<V-1){
        ptr=pq.top();
        pq.pop();
        if(!connected(ptr->src, ptr->dst, parent, size)){
            unify(ptr->src, ptr->dst, parent, size);
            mst_edges.push(ptr);
            count++;
        }   
    }
}

void printMST(queue<node *> &mst_edges){
    node *ptr;
    
    while(!mst_edges.empty()){
        ptr=mst_edges.front();
        mst_edges.pop();
        
        cout<<ptr->src<<"--"<<ptr->dst<<" "<<ptr->wgt<<endl;
    }
}

int main(){
    int V, E;
    cin>>V>>E;
    
    int parent[V];
    int size[V];
    
    initializeUF(parent, size, V);
    
    vector<node *> uwgph(V, NULL);
    queue<node *> mst_edges;
    
    createUWGraph(uwgph, E); 
    kruskalMST(uwgph, mst_edges, parent, size);
    printMST(mst_edges);
   
    return 0;
}
