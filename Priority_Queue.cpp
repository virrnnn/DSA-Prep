#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    for(auto it:{2,7,4,5,9,4,1,10}){
        minheap.push(it);
        maxheap.push(it);
    }

    int k=3;

    //TOP K Largest elements 
    while(minheap.size()>k){
        minheap.pop();
    }
    while(!minheap.empty()){
        cout<<"TOP K Largest element: "<<minheap.top()<<endl;
        minheap.pop();
    }

    //TOP K Smallest elements 
    while(maxheap.size()>k){
        maxheap.pop();
    }
    while(!maxheap.empty()){
        cout<<"TOP K Smallest element: "<<maxheap.top()<<endl;
        maxheap.pop();
    }
}