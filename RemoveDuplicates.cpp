#include<bits/stdc++.h>
using namespace std;

int main(){
//remove duplicate from sorted array
    int j=0;
    for(int i=1;i<n;i++){
        if(a[i]!=a[j]){
            j++;
            a[j]=a[i];
        }
    }
    cout<<"remove dup"<<endl;
    for(int x=0;x<j+1;x++){
        cout<<a[x]<<endl;
    }
}