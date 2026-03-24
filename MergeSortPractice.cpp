#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[],int low,int mid,int high){
    int left = low;
    int right = mid+1;
    vector <int> v;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            v.push_back(arr[left++]);
        }
        else{
            v.push_back(arr[right++]);
        }
    }
    while(left<=mid)
    {
        v.push_back(arr[left++]);
    }
    while(right<=high)
    {
        v.push_back(arr[right++]);
    }
    for(int i=low;i<=high;i++){
        arr[i] = v[i-low];
    }
}

void MergeSort(int arr[],int low,int high){
    if(low>=high) return;
    int mid = low+(high-low)/2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}

void MG(int arr[],int n){
    MergeSort(arr,0,n-1);
}

int selection(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[min],arr[i]);
    }
}

void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool IsSwap = false;
        for(int j=0;j<n-i;j++){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
                IsSwap = true;
            }
        }
        if(!IsSwap) break;
    }
}

void Insertion(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

int main(){
    int arr[] = {5,43,3,2,8,9,8,1,0,0};
    int n = 10;
    Insertion(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
