#include<bits/stdc++.h>
using namespace std;
//left rotate array by one place
void reverse(vector<int> &a,int s,int e){
    while(s<e){
        int temp = a[s];
        a[s]=a[e];
        a[e]=temp;
        s++;
        e--;
    }
}
void LeftRotateByK(vector<int>&v,int k){
    k = k%v.size();
    reverse(v,0,k-1);
    reverse(v,k,v.size()-1);
    reverse(v,0,v.size()-1);
}
void RightRotateByK(vector<int>&v,int k){
    reverse(v,0,v.size()-1-k);
    reverse(v,v.size()-k,v.size()-1);
    reverse(v,0,v.size()-1);
}
int main(){
    vector<int> v = {4,5,6,7,8};
    //BRUTE
    // int x = v[0];
    // for(int i=0;i<v.size()-1;i++){
    //     v[i]=v[i+1];
    // }
    // v[v.size()-1]=x;

    RightRotateByK(v,3);
    for(auto it:v){
        cout<<it<<endl;
    }
}
