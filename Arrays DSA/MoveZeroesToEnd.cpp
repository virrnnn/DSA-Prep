#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {1,0,1,1,0,0,1,1,1};
    int n = a.size();
    int j = 0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            int temp = a[j];
            a[j]=a[i];
            a[i] = temp;
            j++;
        }
    }
    for(auto it:a){
        cout<<it<<endl;
    }
}