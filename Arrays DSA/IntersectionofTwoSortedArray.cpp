#include<bits/stdc++.h>
using namespace std;

vector<int> Intersection1(vector<int>&a,vector<int>&b){
    vector<int> v;
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]==b[j]){
            v.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return v;
}

int main(){
    vector<int> a =  {2, 3, 4};
    vector<int> b = {1, 3, 5};
    for(auto it:Intersection1(a,b)){
        cout<<it<<endl;
    }
}