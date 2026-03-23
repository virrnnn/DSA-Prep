#include<bits/stdc++.h>
using namespace std;

void movezero(vector <int> &a){
    int zeroidx = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=0){
            swap(a[i],a[zeroidx]);
            zeroidx++;
        }
    }
}

int main(){
    vector<int> v = {1,1,0,0,0,5,4,3,0,8};
    movezero(v);
    for(auto it:v){
        cout<<it<<endl;
    }
}