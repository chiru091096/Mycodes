/*
    @Chiranjeevi
    Date: 17-07-17

    Prims Algorithm using eager version (uses O(V) extraspace in set)
    Cant be implemented using stl priority queue as needs decrease key(edge weight) operation
*/


#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include<set>
#include <cfloat>

using namespace std;

struct node{
    int a;
    int b;
    float wgt;
    node *next;
};

typedef pair<int, node *> in_pair;
typedef pair<float, int> fi_pair;

node *newNode(int a, int b, float wgt){
    node *temp=new node;
    
    temp->a=a;
    temp->b=b;
    temp->wgt=wgt;
    temp->next=NULL;
    
    return temp;
}

void addEdge(vector<node *> &gph, int a, int b, float wgt){
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
        addEdge(gph, a, b, wgt);
    }
}

void printGraph(vector<node *> &gph){
    int V=gph.size();
    node *ptr;
    
    for(int i=0; i<V; i++){
        ptr=gph[i];
        
        while(ptr!=NULL){
            cout<<ptr->a<<"--"<<ptr->b<<" "<<ptr->wgt<<endl;
            ptr=ptr->next;
        }
        cout<<endl;
    }
}

void visit(int vertex, vector<node *> &gph, set<fi_pair> &min_dst, vector<float> &dst, set<in_pair> &min_edg, vector<node *> &edg, vector<bool> &mark){
    node *ptr=gph[vertex];
    
    while(ptr!=NULL){
        if(!mark[ptr->b] and ptr->wgt < dst[ptr->b]){
            min_dst.erase(make_pair(dst[ptr->b], ptr->b));
            min_edg.erase(make_pair(ptr->b, edg[ptr->b]));
            dst[ptr->b]=ptr->wgt;
            edg[ptr->b]=ptr;
            min_dst.insert(make_pair(dst[ptr->b], ptr->b));
            min_edg.insert(make_pair(ptr->b, ptr));
        }
        ptr=ptr->next;
    }
}

void primsMST(vector<node *> &gph, set<in_pair> &min_edg){
    int V=gph.size();
    set<fi_pair> min_dst;
    set<fi_pair> :: iterator it_fi;
    vector<bool> mark(V, false);
    vector<float> dst(V, FLT_MAX);
    vector<node *> edg(V, NULL);
    
    visit(0, gph, min_dst, dst, min_edg, edg, mark);
    mark[0]=true;
    dst[0]=0;
    
    for(int i=1; i<V; i++){
        it_fi=min_dst.begin();
        mark[it_fi->second]=true;
        visit(it_fi->second, gph, min_dst, dst, min_edg, edg, mark);
        min_dst.erase(it_fi); 
    }
}

void printMST(set<in_pair> &min_edg){
    node *ptr;
    set<in_pair> :: iterator in_it;
    while(!min_edg.empty()){
        in_it=min_edg.begin();
        cout<<in_it->second->a<<"--"<<in_it->second->b<<" "<<in_it->second->wgt<<endl;
        min_edg.erase(in_it);
    }
}

int main(){
    int V, E;
    cin>>V>>E;
    
    vector<node *> gph(V, NULL);
    set<in_pair> min_edg;
    
    createUWGraph(gph, E);
    
    //printGraph(gph);
    
    primsMST(gph, min_edg);
    cout<<min_edg.size()<<endl;
    printMST(min_edg);
}
