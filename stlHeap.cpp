/*
@Chiranjeevi
Date: 28-Jun-17
*/

/*
making a heap , deleting from it and adding , sorting heap
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct compare{
    bool operator()(int a, int b){
        if(a>b)
            return true;
        else
            return false;
    }
};

int main(){
    vector<int> vec = {1, 7, 3, 6, 5, 4, 2, 9, 8, 10};
    
    make_heap(vec.begin(), vec.end(), compare());
    cout<<vec.front()<<endl;
    
    pop_heap(vec.begin(), vec.end(), compare());
    vec.pop_back();                             //important otherwise remains at the endl
 
    cout<<vec.front()<<endl;
    vec.push_back(1);
    
    push_heap(vec.begin(), vec.end(), compare());
    cout<<vec.front()<<endl;
 
    sort_heap(vec.begin(), vec.end(), compare());  //compare must be given otherwise behaves erratically if 
                                                   //earlier given now not given (give same one)
    for(int i: vec)
        cout<<i<<" ";
   
}