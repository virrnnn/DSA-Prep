#include<bits/stdc++.h>
using  namespace std;

int binarys(vector<int>&a,int n){
    int low = 0;
    int high = a.size()-1;
    int mid = 0;
    while(low<=high){
        mid = low+(high-low)/2;
        if(a[mid]==n) {
            cout<<"IDX - "<<mid<<endl;
            return mid;
        }  
        if(n<a[mid]){
            high = mid-1;
        }   
        else{
            low = mid+1;
        }
    }
    cout<<"IDX - "<<mid<<endl;
    return -1;
}

int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    binarys(vec,9);
}
