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

vector<int> UnionOfTwoArr(vector<int>&a,vector<int>&b){
    int i=0,j=0;
    vector<int>v;
    while(i<a.size() && j<b.size())
    {
        if(a[i]<b[j])
        {
            if(v.empty() || v.back()!=a[i] )
            {
                v.push_back(a[i]);
            }
            i++;
        }
        else if(b[j]<a[i]){
            if(v.empty() || v.back()!=b[j])
            {
                v.push_back(b[j]);
            }
            j++;
        }
        else { // equal case
            if (v.empty() || v.back() != a[i])
                v.push_back(a[i]);
            i++;
            j++;
        }
    }
    while(i<a.size()){
        if(v.empty() || v.back()!=a[i])
        {
            v.push_back(a[i]);
        }
        i++;
    }
    while(j<b.size())
    {
        if(v.empty() || v.back()!=b[j])
        {
            v.push_back(b[j]);
        }
        j++;
    }
    return v;
}
int main(){
    vector<int> a = {0,0,1,1,1};
    vector<int> b = {0,2,3,4,4,5,5,5};
    
    for(auto it:UnionOfTwoArr(a,b)){
        cout<<it<<endl;
    }
}