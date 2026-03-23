#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]<target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}
int main(){
    vector<int>vec = {1,2,3,4,7,8,9};
    cout<<searchInsert(vec,5)<<endl;
}