#include<bits/stdc++.h>
using namespace std;
//       SEARCH IN SORTED ARRAY - 1   (without the duplicates)
int SearchInRotated(vector <int>&v,int n){
    int low=0,high=v.size()-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(v[mid]==n){
            cout<<"INX = "<<mid;
            return mid;
        }
        else if(v[mid]>=v[low]){
            if(n>=v[low] && n<v[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(n>v[mid] && n<=v[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int seearchRA(vector<int>&v,int n){
    int low=0,high=v.size()-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(v[mid]==n){
            cout<<"IDX = "<<mid;
            return mid;
        }
        else if(v[mid]>=v[low]){   // LEFT HALF IS SORTED
            if(n>=v[low] && n<v[mid]){   // CHECK IF TARGET LIE IN LEFT SIDE
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        else{                      // RIGHT HALF IS SORTED                          
            if(n>v[mid] && n<=v[high]){    // CHECK IF TARGET LIE IN LEFT SIDE
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
    return -1;       //TARGET NOT FOUND
}

int  search(const vector<int>&v,int n){
    int low=0,high=v.size()-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(v[mid]==n)
            return mid;
        else if(v[mid] == v[low] && v[mid] == v[high]){
            low++;
            high--;
            continue;
        }
        else if(v[mid]>=v[low]){
            if(v[low]<=n && v[mid]>n){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(v[mid]<n && v[high]>=n){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    vector<int>vec = {7,8,9,1,2,2,2,2,3,4,5};
    cout<<search(vec,5)<<endl;
}