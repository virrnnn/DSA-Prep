#include<bits/stdc++.h>
using namespace std;

int FindMissingNumberBrute(vector<int>&a){
    int n = a.size()+1;
    int sum = (n*(n+1))/2;
    for(auto it:a){
        sum-=it;
    }
    return sum;
}
int FindMissingNumberXOR(vector<int>&a){
    int n = a.size()+1;
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum^=i;
    }
    for(auto it:a){
        sum^=it;
    }
    return sum;
}
int FindMissingNumberBS(vector<int>&a){  //ONLY IF SORTED
    int low =0,high=a.size()-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(a[mid]==mid+1){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low+1;
}

int main(){
    vector<int> a = {1,2,3,5,6,7};
    cout<<FindMissingNumberBS(a)<<endl;
}