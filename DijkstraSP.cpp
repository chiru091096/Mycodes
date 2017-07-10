/*
    @Chiranjeevi
    Date: 10-Jul-17
*/

/* 
    Dijkstra's algorithm for finding shortest paths from given source in a Digraph
    Running time O(Elog(V))
    Can't use STL priority_queue as it doesn't provide decrease key operation 
*/


#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <cfloat>

using namespace std;

typedef pair<float, int> fi_pair;

struct node{
    int src;
    int dst;
    float wgt;
    node *next;
};

node *newNode(int a, int b, float wgt){
    node *temp=new node;
    
    temp->src=a;
    temp->dst=b;
    temp->wgt=wgt;
    temp->next=NULL;
    
    return temp;
}

void addDWEdge(vector<node *> &gph, int a, int b, float wgt){
    node *ptr=gph[a];
    
    if(ptr==NULL)
        gph[a]=newNode(a, b, wgt);
    else{
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newNode(a, b, wgt);
    }
}

void createDWGraph(vector<node *> &gph, int E){
    int a, b;
    float wgt;
    
    for(int i=0; i<E; i++){
        cin>>a>>b>>wgt;
        addDWEdge(gph, a, b, wgt);
    }
}

void printDWGraph(vector<node *> &gph){
    int V=gph.size();
    node *ptr;
    
    for(int i=0; i<V; i++){
        ptr=gph[i];
        
        while(ptr!=NULL){
            cout<<ptr->src<<"-->"<<ptr->dst<<" "<<ptr->wgt<<endl;
            ptr=ptr->next;
        }
    }
}

void relaxEdges(int vertex, set<fi_pair> &dj, vector<node *> &gph, vector<float> &dist, vector<int> &edgeTo){
    node *ptr=gph[vertex];
    
    while(ptr!=NULL){
        if(dist[ptr->dst] > dist[vertex] + ptr->wgt){
            dj.erase(make_pair(dist[ptr->dst], ptr->dst));  
             
            dist[ptr->dst]=dist[vertex]+ptr->wgt;
            edgeTo[ptr->dst]=vertex;
            dj.insert(make_pair(dist[ptr->dst], ptr->dst));
            
        }
        
        ptr=ptr->next;
    }
}

void dijkstra(int src, vector<node *> &gph, vector<float> &dist, vector<int> &edgeTo){
    int V=gph.size();
    set<fi_pair> dj;
    set<fi_pair> :: iterator it;
    
    for(int i=0; i<V; i++){
        if(i!=src)
            dj.insert(make_pair(FLT_MAX, i));
    }
    
    dj.insert(make_pair(0, src));
    dist[src]=0;
    
    for(int i=0; i<V; i++){
        it=dj.begin();
        relaxEdges(it->second, dj, gph, dist, edgeTo);
        dj.erase(it);
    }
}

void printPath(int i, vector<int> &edgeTo){
    
    if(edgeTo[i]!=-1){
        printPath(edgeTo[i], edgeTo);
    }
    cout<<i<<"-->";
}

void printShortestDist(int src, vector<float> &dist, vector<int> &edgeTo){
    
    int V=dist.size();
    
    for(int i=0; i<V; i++){
        cout<<src<<"-->"<<i<<'\t'<<dist[i]<<'\t';
        printPath(i, edgeTo);
        cout<<endl;
    }
}

int main(){
    int V, E, src;
    cin>>V>>E>>src;
    
    vector<node *> gph(V, NULL);
    vector<float> dist(V, FLT_MAX);
    vector<int> edgeTo(V, -1);
    
    createDWGraph(gph, E);
    printDWGraph(gph);
    
    dijkstra(src, gph, dist, edgeTo);
       
    printShortestDist(src, dist, edgeTo);
}
