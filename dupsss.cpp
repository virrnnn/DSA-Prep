#include<bits/stdc++.h>
using namespace std;

void finduniq(vector<int>&a,int n){
    int x = 0;
    for(int i=0;i<n;i++)
    {
        x^=a[i];
    }
    cout<<"Unique element :"<<x<<endl;
}

void findalldup(vector<int>&a,int n){
    unordered_set<int> s1;
    unordered_set<int> printed;
    for(int i=0;i<n;i++){
        if(s1.count(a[i])!=0){
            if(printed.count(a[i])==0)
                cout<<"Duplicate : "<<a[i]<<endl;
        }
        else
        {
            s1.insert(a[i]);
        }
    }
}

int main(){
    vector <int> v = {1,2,1,2,3,4,5,3,4};
    finduniq(v,9);
}