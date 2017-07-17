/*
    @Chiranjeevi
    Date: 17-07-17
    
    Finding shortest path in DAGs 
    Uses reverse Topological order for relaxing edges
    Like Topological sort and unlike Dijkstra's algorithm this works even if negative edges are present    
    Running time (V+E)
*/

#include <iostream>
#include <stack>
#include <vector>
#include <climits>

using namespace std;

struct node{
    int src;
    int dst;
    int wgt;
    node *next;
};

node *newNode(int src, int dst, int wgt){
    node *temp=new node;
    
    temp->src=src;
    temp->dst=dst;
    temp->wgt=wgt;
    temp->next=NULL;
    
    return temp;
}

void addEdge(vector<node *> &gph, int src, int dst, int wgt){
    node *ptr=gph[src];
    
    if(ptr==NULL)
        gph[src]=newNode(src, dst, wgt);
    else{
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newNode(src, dst, wgt);
    }
}

void createGraph(vector<node *> &gph, int E){
    int src, dst, wgt;
    
    for(int i=0; i<E; i++){
        cin>>src>>dst>>wgt;
        addEdge(gph, src, dst, wgt);
    }
}

void topologicalSort(int vertex, vector<node *> &gph, vector<bool> &mark, stack<int> &rev_topo){
    node *ptr=gph[vertex];
    
    while(ptr!=NULL){
        if(!mark[ptr->dst]){
            mark[ptr->dst]=true;
            topologicalSort(ptr->dst, gph, mark, rev_topo);
        }
        ptr=ptr->next;
    }
    rev_topo.push(vertex);
}

void getReverseTopoOrder(vector<node *> &gph, stack<int> &rev_topo){
    int V=gph.size();
    vector<bool> mark(V, false);
    
    for(int i=0; i<V; i++){
        if(!mark[i]){
            mark[i]=true;
            topologicalSort(i, gph, mark, rev_topo);
        }
    }
}

void relaxEdges(node *ptr, vector<node *> &gph, vector<int> &dist, vector<int> &edge_to){
    while(ptr!=NULL){
        if(ptr->wgt+dist[ptr->src] < dist[ptr->dst]){
            dist[ptr->dst]=ptr->wgt+dist[ptr->src];
            edge_to[ptr->dst]=ptr->src;
        }
        ptr=ptr->next;
    }
}

void getShortestPath(vector<node *> &gph, stack<int> &rev_topo, vector<int> &dist, vector<int> &edge_to){
    int vertex;
    node *ptr;
    
    dist[rev_topo.top()]=0;
    while(!rev_topo.empty()){
        vertex=rev_topo.top();
        rev_topo.pop();
        
        ptr=gph[vertex];
        relaxEdges(ptr, gph, dist, edge_to);
    }    
}

void printSPT(vector<int> &dist, vector<int> &edge_to){
    int V=dist.size();
    
    cout<<"vertex\t"<<"dist\t"<<"edge_to\t"<<endl;
    for(int i=0; i<V; i++)
        cout<<i<<"\t"<<dist[i]<<"\t"<<edge_to[i]<<endl;
}

int main(){
    int V,E;
    cin>>V>>E;
    
    vector<node *> gph(V, NULL);
    stack<int> rev_topo;
    vector<int> dist(V, INT_MAX);
    vector<int> edge_to(V, -1);
    
    createGraph(gph, E);
    
    getReverseTopoOrder(gph, rev_topo);
    
    getShortestPath(gph, rev_topo, dist, edge_to);
    
    printSPT(dist, edge_to);
    
    return 0;
}