#include<bits/stdc++.h>
using namespace std;

int UniqueElement(vector<int>&a){
    int ans = 0;
    for(auto it:a){
        ans = ans^it;
    }
    return ans;
}

int main(){
    vector<int> a = {1,1,2,5,2,3,3};
    cout<<UniqueElement(a)<<endl;
}