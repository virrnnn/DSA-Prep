#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int left=low,right=mid+1;
    vector<int> v;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            v.push_back(arr[left++]);
        }
        else{
            v.push_back(arr[right++]);
        }
    }
    while(left<=mid){
        v.push_back(arr[left++]);
    }
    while(right<=high){
        v.push_back(arr[right++]);
    }   
    for(int i=low;i<=high;i++){
        arr[i]=v[i-low];
    }
}
void mergesort(int arr[],int low,int high){
    if(low>=high) return;
    int mid=low+(high-low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
void ms(int arr[],int n){
    mergesort(arr,0,n-1);
}
int main(){
    int arr[10] = {7,4,12,34,6,8,99,0,6,4};
    ms(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<endl;
    }
}

// void Merge(int arr[],int low,int mid,int high){
//     int left = low;
//     int right = mid+1;
//     vector<int> v;
//     while(left<=mid && right<=high){
//         if(arr[left]<=arr[right]){
//             v.push_back(arr[left++]);
//         }
//         else{
//             v.push_back(arr[right++]);
//         }
//     }
//     while(left<=mid){
//         v.push_back(arr[left++]);
//     }
//     while(right<=high){
//         v.push_back(arr[right++]);
//     }

//     for(int i=low;i<=high;i++){
//         arr[i] = v[i-low];
//     }
// }
// void MergeSort(int arr[],int low, int high){
//     if(low>=high) return;
//     int mid = low+(high-low)/2;
//     MergeSort(arr,low,mid);
//     MergeSort(arr,mid+1,high);
// Merge(arr,low,mid,high);
// }
// void MS(int arr[],int n){
//     MergeSort(arr,0,n-1);
// }