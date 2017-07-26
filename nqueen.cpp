#include <iostream>
#include <utility>
#include <stack>

using namespace std;

bool isSafe(int row, int col, stack<pair<int, int>> queens){
    int q_row, q_col;
    pair<int, int> curr;
    
    

    while(!queens.empty()){
        curr=queens.top();
        queens.pop();
        
        q_row=curr.first;
        q_col=curr.second;
        
        if(col==q_col)
            return false;
        if(row-col==q_row-q_col)
            return false;
        if(row+col==q_row+q_col)
            return false;
        
    }
    return true;
}

bool get_valid_col(int row, int n, stack<pair<int, int>> &queens){
    bool check;
    
    if(row==n)
        return true;
    
    for(int i=0; i<n; i++){
        if(isSafe(row, i, queens)){
            queens.push(make_pair(row, i));
            check=get_valid_col(row+1, n, queens);
            
            if(check)
                return true;
            
            queens.pop();
        }
    }
    return false;
}


void getPosition(int n, stack<pair<int, int>> &queens){
    bool check;
    
    for(int i=0; i<n; i++){
        queens.push(make_pair(0, i));
        if(get_valid_col(1, n, queens))
            break;
       
        queens.pop();
    }
}


int main(){
    int n;
    cin>>n;

    stack<pair<int, int>> queens;
    
    getPosition(n, queens);
    
    if(queens.empty())
        cout<<"not possible";
    else
        cout<<"possible"<<endl;
    
    while(!queens.empty()){
        cout<<queens.top().first<<" "<<queens.top().second<<endl;
        queens.pop();
    }
    return 0;
}
