#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct node{
    int v;
    node *next;
};

node *newNode(int b){
    node *temp=new node();
    temp->v=b;
    temp->next=NULL;
    return temp;
}

void addDEdge(vector<node *> &dgph, int a, int b){
    if(dgph[a]==NULL){
        dgph[a]=newNode(b);
    }
    
    else{
        node *ptr=dgph[a];
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newNode(b);
    }
}

void createDGraph(vector<node *> &dgph, int E){
    int a, b;
    
    for(int i=0; i<E; i++){
        cin>>a>>b;
        addDEdge(dgph, a, b);
    }
}

void printDGraph(vector<node *> &dgph){
    int V=dgph.size();
    node *ptr=NULL;
    
    for(int i=0; i<V; i++){
        ptr=dgph[i];
        while(ptr!=NULL){
            cout<<i<<"->"<<ptr->v<<endl;
            ptr=ptr->next;
        }
    }
}

void DGraphDFS(int vertex, vector<node *> &dgph, bool mark[], int parent[]){
    node *ptr=dgph[vertex];
    mark[vertex]=true;
    
    while(ptr!=NULL){
        if(!mark[ptr->v]){
            parent[ptr->v]=vertex;
            DGraphDFS(ptr->v, dgph, mark, parent);
        }
        ptr=ptr->next;
    }
}

void DGraphBFS(int vertex, vector<node *> &dgph, bool mark[], int distance[]){
    int count=1;
    queue<int> q;
    
    node *ptr=NULL;
    q.push(vertex);

    while(!q.empty()){
        ptr=dgph[q.front()];
        q.pop();
        
        while(ptr!=NULL){
            if(!mark[ptr->v]){
                mark[ptr->v]=true;
                distance[ptr->v]=count;
                q.push(ptr->v);
            }
            ptr=ptr->next;
        }
        count++;
    }
}

void DgraphDFS(int vertex, vector<node *> &dgph, bool mark[], stack<int> &topo_sort){
    mark[vertex]=true;
    
    node *ptr=dgph[vertex];
    
    while(ptr!=NULL){
        if(!mark[ptr->v]){
            DgraphDFS(ptr->v, dgph, mark, topo_sort);  
        }
        ptr=ptr->next;
    }
    topo_sort.push(vertex);
}

void TopologicalSort(vector<node *> &dgph, bool mark[], stack<int> &topo_sort){
    int V=dgph.size();
    
    for(int i=0; i<V; i++){
        if(!mark[i]){
            DgraphDFS(i, dgph, mark, topo_sort);
        }
    }
}

int main(){
    int V,E;
    cin>>V>>E;
    
    vector<node *> dgph(V, NULL);
    stack<int> topo_sort;
    bool mark[V] = {false};
    
    createDGraph(dgph, E);
    
    printDGraph(dgph);
    
    TopologicalSort(dgph, mark, topo_sort);
    
    while(!topo_sort.empty()){
        cout<<topo_sort.top()<<"->";
        topo_sort.pop();
    }
}