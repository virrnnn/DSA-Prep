#include<bits/stdc++.h>
using namespace std;
// MOVE Zeros
void movezero(vector <int>a,int n){
    int zeroidx = 0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            swap(a[zeroidx],a[i]);
            zeroidx++;
        }
    }
    //print the vector
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }

}

int main(){
    vector<int> vec = {1,3,5,0,0,8,0,4,3};
    movezero(vec,9);
}