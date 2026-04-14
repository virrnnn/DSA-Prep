#include<bits/stdc++.h>
using namespace std;
//FOR SORTED ONLY
// 1,2,3,3 & //2,2,4,5  - ANS -> 1,2,3,4,5
set<int> Brute(vector<int>&a,vector<int>&b){
    set<int>Uset;
    for(auto it:a){
        Uset.insert(it);
    }
    for(auto it:b){
        Uset.insert(it);
    }
    return Uset;
}

vector<int> Opt(vector<int>&a,vector<int>&b){
    int i=0,j=0;
    vector<int>v;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            if(v.back()!=a[i]){
                v.push_back(a[i]);
            }
            i++;
        }
        else{
            if(v.back()!=b[j]){
                v.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<a.size()){
        if(v.back()!=a[i]){
            v.push_back(a[i]);
        }
        j++;
    }
    while(i<b.size()){
        if(v.back()!=b[j]){
            v.push_back(b[j]);
        }
        j++;
    }
}
int main(){
    vector<int> a = {0,0,1,1,1};
    vector<int> b = {0,2,3,4,4};
    
    for(auto it:Opt(a,b)){
        cout<<it<<endl;
    }
}