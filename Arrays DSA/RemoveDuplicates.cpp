#include<bits/stdc++.h>
using namespace std;

int removedups(vector<int>&a){
    int n = a.size();
    int j = 0;
    for(int i=1;i<n;i++){
        if(a[i]!=a[j]){
            j++;
            a[j]=a[i];
        }
    }
    return j+1;
}

int main(){
    vector<int> a = {1,1,1,2,2,3,3};
    int x= removedups(a);
    for(int i=0;i<x;i++){
        cout<<a[i]<<endl;
    }
}