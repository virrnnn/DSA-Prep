#include<bits/stdc++.h>
using namespace std;



int main(){

    vector<int> v = {1,5,4,3,2,6,87,9};
    vector<int>::iterator it;
    for(it = v.begin(); it!=v.end();){
        if(*it==3){
            it = v.erase(it);
        }
        else{
            cout<<*it<<endl;
            ++it;
        }
    }
}