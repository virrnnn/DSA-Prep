#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5};
    try{
        v.at(2);
    }
    catch(out_of_range e){
        cout<<"Accessing OB";
    }
    return 0;
}