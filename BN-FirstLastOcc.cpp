#include<bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> &v, int n){
    int low = 0;
    int high = v.size()-1;
    int mid = 0;
    int ans = -1;
    // while(low<=high){
    //     mid = low +(high-low)/2;
    //     if(v[mid]==n){
    //         ans = mid;
    //         high = mid-1;
    //         continue;
    //     }
    //     if(n<v[mid]){
    //         high = mid-1;
    //     }
    //     else
    //     {
    //         low = mid+1;
    //     }
    // }
    while(low<=high){
        mid=low+(high-low)/2;
        if(v[mid]>=n){
            if(v[mid]==n)
                ans=mid;
            high = mid-1;
        }
        else    
            low = mid+1;
    }
    cout<<"First Occ - "<<ans<<endl;
    return ans;
}

int lastOcc(vector<int>&a,int n){
    int low=0,high=a.size()-1,ans=-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(a[mid]<=n){
            if(a[mid]==n)   
                ans = mid;
            low = mid+1;
        }
        else
            high = mid -1;
    }
    cout<<"Last Occ - "<<ans<<endl;
    return ans;
}
int firsss(vector<int>&v,int a){
    int low=0,high=v.size()-1,ans=-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(v[mid]>=a){
            if(v[mid]==a){
                ans = mid;
            }
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<"First Occ - "<<ans<<endl;
    return ans;
}
int findpeak(vector<int> &v){
    int left=0,right=v.size()-1;
    while(left<right){
        int mid = left+(right-left)/2;
        if(v[mid]<v[mid+1]){
            left = mid +1;
        }
        else{
            right = mid;
        }
    }
    cout<<"Peak Element - "<<v[left]<<endl;
    return left;
}

int main(){
    vector<int> v = {1,2,3,4,4,4,4,5,5,6,7};
    firsss(v,4);
    lastOcc(v,4);
    vector<int> v1 = {1,2,3,4,4,5,6,3,2,1};
    findpeak(v1);
}