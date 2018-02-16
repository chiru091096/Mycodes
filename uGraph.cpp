/*
  @Chiranjeevi
  Date: 18-Jun-17
*/

/*
    assumptions: no self loop, no parallel edges, all inputs are valid
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct node{
    int v;
    node *next;
};


node *newNode(int a){
    node *temp = new node();
    temp->v = a;
    temp->next = NULL;
    return temp;
}

void initialize(int V, bool mark[], int parent[], int distance[], int cc[]){
    for(int i=0; i<V; i++){
        mark[i]=false;
        parent[i]=-1;
        distance[i]=0;
        cc[i]=0;
    }    
}

void addUEdge(vector<node *> &vertices, int a, int b){
    
    if(vertices[a] == NULL){
        vertices[a]=newNode(b);
    }
    
    else{
        node *ptr = vertices[a];
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newNode(b);
    }
    
    if(vertices[b] == NULL){
        vertices[b] = newNode(a);
    }
    
    else{
        node *ptr = vertices[b];
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next=newNode(a);
    }
}

void createUGraph(int E, vector<node *> &vertices){
    int a, b;
    for(int i=0; i<E; i++){
        cin>>a>>b;
        addUEdge(vertices,a,b);
    }
}

int getDegree(vector<node *> &vertices, int a){
    node *ptr=vertices[a];
    int count = 0;
    
    while(ptr!=NULL){
        ptr=ptr->next;
        count++;
    }
    
    return count;
}

int getMaxDegree(vector<node *> &vertices, int V){
    int max=getDegree(vertices, 0);
    int temp;
    
    for(int i=1; i<V; i++){
        temp = getDegree(vertices, i);
        if(temp>max)
            max=temp;  
    }
    
    return max;
}

void printUGraph(vector<node *> &vertices, int V){
    node *ptr=NULL;
    for(int i=0; i<V; i++){
        ptr = vertices[i];
        
        while(ptr!=NULL){
            cout<<i<<"--"<<ptr->v<<endl;
            ptr=ptr->next;
        }
    }    
}

void printAdjOfv(vector<node *> &vertices, int a){
    node *ptr = vertices[a];
    
    while(ptr!=NULL){
        cout<<a<<"--"<<ptr->v<<endl;
        ptr=ptr->next;
    }
}

void dfs(int w, vector<node *> &vertices, bool mark[], int parent[], int cc[], int id){
        node *ptr=vertices[w];
        mark[w]=true;
        cc[w]=id;
        while(ptr!=NULL){
            if(!mark[ptr->v]){
                parent[ptr->v]=w;
                dfs(ptr->v, vertices, mark, parent, cc, id);
            }
            ptr=ptr->next;
        }
}

void printPath(int source, int v, int parent[]){
    if(v!=source)
        printPath(source, parent[v], parent);
    cout<<v<<"-->";
}

void bfs(int source, vector<node *> &vertices, bool mark[], int parent[], int distance[]){
    queue<int> q;
    int element, count=1;
    node *ptr=NULL;
    q.push(source);
    mark[source]=true;
    
    while(!q.empty()){
        element=q.front();
        q.pop();
        ptr=vertices[element];
        while(ptr!=NULL){
            if(!mark[ptr->v]){
                q.push(ptr->v);
                mark[ptr->v]=true;
                parent[ptr->v]=element;
                distance[ptr->v]=count;
            }
            ptr=ptr->next;
        }
        count++;
    }
}

int connectedComponents(vector<node *> &vertices, bool mark[], int parent[], int cc[]){
    int V=vertices.size(), id=1;
    
    for(int i=0; i<V; i++){
        mark[i]=false;
        parent[i]=0;
    }
    
    for(int i=0; i<V; i++){
        if(!mark[i]){
            dfs(i, vertices, mark, parent, cc, id++);            
        }
    }
    return *max_element(cc, cc+V);
}

void checkIfCycleExists(int w, vector<node *> &vertices, bool mark[], int parent[]){
    mark[w]=true;
    node *ptr=vertices[w];
    
    while(ptr!=NULL){
        if(mark[ptr->v] and parent[w]!=ptr->v){
            cout<<"Cycle exists--"<<w<<"---"<<ptr->v<<endl;
        }
        
        if(!mark[ptr->v]){
            parent[ptr->v]=w;
            cout<<w<<"--"<<ptr->v<<endl;
            checkCycle(ptr->v, vertices, mark, parent);
        }
        ptr=ptr->next;
    }
}


int main(){
    int V,E;
    cin>>V>>E;
    
    bool mark[V];
    int parent[V];
    int distance[V];
    int cc[V];
    vector<node *> vertices(V, NULL);   //initialize all V to NULL
    
    initialize(V, mark, parent, distance, cc);
    createUGraph(E, vertices);
    
}
