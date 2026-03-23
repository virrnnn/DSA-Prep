#include<bits/stdc++.h>
MNBVCusing namespace std;

int findsingle(vector<int>&v){
    if (nums.size() == 1) return nums[0];
    if (nums.size() % 2 == 0) return -1; // no single element possible
    int low=0,high=v.size()-1;
    while(low<high){
        int mid = low+(high-low)/2;
        if(mid%2==1){
            mid--;
        }
        if(v[mid]==v[mid+1]){
            low = mid+2;
        }
        else{
            high = mid;
        }
    }
    return v[low];
}

int main(){
    vector<int>vec = {1,1,3,3,4,5,5,7,7,8,8,9,9};
    cout<<"Single Element :"<<findsingle(vec)<<endl;
}   